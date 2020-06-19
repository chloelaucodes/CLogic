/**
 * @brief This file contains the decoding and parsing instructions for our
 * extension CLogic.
 */

#include "ext_decode.h"

/**
 * @brief Checks if two strings are equal
 * @param str1 : first string
 * @param str2 : second string
 * @return boolean whether they are equal
 */
bool are_equal(char *str1, char *str2) { return strcmp(str1, str2) == 0; }

/**
 * @brief converts lines to tokens
 * @param line : input line
 * @param tokens : array of pointers of where the words are stored
 * @param num_tokens : number of words in the array
 */
void to_tokens(char *line, char **tokens, int *num_tokens) {
  char delim[] = " \n\r";
  *num_tokens = 0;
  char *token_pointer = strtok(line, delim);
  for (int i = 0; token_pointer != NULL; i++) {
    (*num_tokens)++;
    tokens[i] = token_pointer;
    token_pointer = strtok(NULL, delim);
  }
}

/**
 * @brief searches for a specific node given the number of nodes and the name
 * @param nodes : list of nodes
 * @param num_nodes : number of nodes
 * @param name : name of node to be searched
 * @return the specific node
 */
logic_node *search_nodes(logic_node *nodes[], int num_nodes, char *name) {
  for (int i = 0; i < num_nodes; i++) {
    if (are_equal(nodes[i]->name, name)) {
      return nodes[i];
    }
  }
  printf("No node found with name %s\n", name);
  return NULL;
}

/**
 * @brief prints the nodes
 * @param nodes : list of nodes to be printed
 * @param size : number of nodes to be printed
 */
void print_nodes(logic_node *nodes[], int size) {
  printf("Size %d\n", size);
  for (int i = 0; i < size; i++) {
    printf("I: %d and name %s\n", i, nodes[i]->name);
  }
}
/**
 * @brief reads file
 * PRE: File exists and can be read
 * @param file : file to be imported
 * @param inputs : array of pointers where the input nodes are stored
 * @param num_inputs : pointer where the number of input nodes are
 * @return array of pointers of logic nodes of the file
 */
logic_node **read_file(FILE *file, logic_node **inputs, int *num_inputs) {
  char buffer[BUFFER_SIZE];
  char *tokens[MAX_TOKENS];
  int num_outputs = 0;
  int num_nodes = 0;

  logic_node *nodes[MAX_NUMBER_GATES];

  logic_node **outputs =
      (logic_node **)malloc(sizeof(*outputs) * MAX_NUMBER_GATES);

  while (fgets(buffer, BUFFER_SIZE, file) != NULL) {
    int line_tokens = 0;

    to_tokens(buffer, tokens, &line_tokens);

    logic_node *new_node = (logic_node *)malloc(sizeof(logic_node));
    char *name = strdup(tokens[0]);
    new_node->name = name;
    new_node->num_of_inputs = 0;

    if (are_equal(tokens[1], "INPUT")) {
      new_node->gate_type = INPUT;
      new_node->input_value = false;
    } else {
      int shift;
      if (are_equal(tokens[1], "OUTPUT")) {
        new_node->gate_type = OUTPUT;
        shift = 1;
      } else {
        // SHOULD BE IF COMPARING IF IS VALID GATE
        new_node->gate_type = GATE;
        shift = 0;
      }

      char *function = tokens[1 + shift];
      int max_args = -1;

      if (are_equal(function, "AND")) {
        new_node->operation = AND;
      } else if (are_equal(function, "OR")) {
        new_node->operation = OR;
      } else if (are_equal(function, "NOT")) {
        max_args = 1;
        new_node->operation = NOT;
      } else if (are_equal(function, "XOR")) {
        new_node->operation = XOR;
      } else if (are_equal(function, "XAND")) {
        new_node->operation = XAND;
      } else if (are_equal(function, "NOR")) {
        new_node->operation = NOR;
      } else if (are_equal(function, "NAND")) {
        new_node->operation = NAND;
      } else {
        printf("Error: Unrecognised operation! Token: %s!", function);
        return NULL;
      }

      for (int i = shift + 2;
           i < line_tokens && (max_args < 0 || i - (shift + 2) < max_args);
           i++) {
        struct node *gate_input = search_nodes(nodes, num_nodes, tokens[i]);
        if (gate_input == NULL) {
          printf("Error: Node with %s not declared\n", name);
        }
        new_node->gate_inputs[new_node->num_of_inputs] = gate_input;
        (new_node->num_of_inputs)++;
      }
    }

    nodes[num_nodes] = new_node;
    if (new_node->gate_type == OUTPUT) {
      outputs[num_outputs] = new_node;
      num_outputs++;
    }
    if (new_node->gate_type == INPUT) {
      inputs[*num_inputs] = new_node;
      (*num_inputs)++;
    }
    num_nodes++;
  }
  // print_nodes(nodes, num_nodes);
  fclose(file);
  return outputs;
}
