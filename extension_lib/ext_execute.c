/**
 * @brief this file contains the execution related functions for the extension
 * CLogic
 */

#include "ext_execute.h"
#include "ext_structs.h"

/**
 * @brief Helper function to execute and operation and recursively
 * @param node : logic node
 * @return boolean value of the execution
 */
bool execute_and(logic_node *node) {
  for (int i = 0; i < node->num_of_inputs; ++i)
    if (!execute((node->gate_inputs[i])))
      return false;
  return true;
}

/**
 * @brief Helper function to execute or operation and recursively
 * @param node : logic node
 * @return boolean value of the execution
 */
bool execute_or(logic_node *node) {
  for (int i = 0; i < node->num_of_inputs; ++i)
    if (execute((node->gate_inputs[i])))
      return true;
  return false;
}

/**
 * @brief Helper function to execute not operation and recursively
 * @param node : logic node
 * @return boolean value of the execution
 */
bool execute_not(logic_node *node) { return !execute((node->gate_inputs[0])); }

/**
 * @brief Helper function to execute xor operation and recursively
 * @param node : logic node
 * @return boolean value of the execution
 */
bool execute_xor(logic_node *node) {
  bool curr_state = execute((node->gate_inputs[0]));
  for (int i = 1; i < node->num_of_inputs; ++i)
    curr_state = (curr_state != execute((node->gate_inputs[i])));
  return curr_state;
}

/**
 * @brief Helper function to execute xand operation and recursively
 * @param node : logic node
 * @return boolean value of the execution
 */
bool execute_xand(logic_node *node) {
  bool curr_state = execute((node->gate_inputs[0]));
  for (int i = 1; i < node->num_of_inputs; ++i)
    curr_state = curr_state == execute((node->gate_inputs[i]));
  return curr_state;
}

/**
 * @brief Helper function to execute nor operation and recursively
 * @param node : logic node
 * @return boolean value of the execution
 */
bool execute_nor(logic_node *node) {
  for (int i = 0; i < node->num_of_inputs; ++i)
    if (execute((node->gate_inputs[i])))
      return false;
  return true;
}

/**
 * @brief Helper function to execute nand operation and recursively
 * @param node : logic node
 * @return boolean value of the execution
 */
bool execute_nand(logic_node *node) {
  for (int i = 0; i < node->num_of_inputs; ++i)
    if (!execute((node->gate_inputs[i])))
      return true;
  return false;
}

/**
 * @brief Checks the gate type of the node, then prints if needed
 * @param node : logic node
 * @param val : boolean value of execution from execute
 * @return val
 */
bool print_check(logic_node *node, bool val) {
  if (node->gate_type == OUTPUT)
    printf("Output Gate: %s Value: %d\n", node->name, val);
  return val;
}

/**
 * @brief Executes operation and allocates the function to it's respective
 * helper functions
 * @param node : logic node
 * @return boolean value of the execution
 */
bool execute(logic_node *node) {
  if (node->gate_type == INPUT)
    return node->input_value;
  else {
    switch (node->operation) {
    case AND:
      return print_check(node, execute_and(node));
    case OR:
      return print_check(node, execute_or(node));
    case NOT:
      return print_check(node, execute_not(node));
    case XOR:
      return print_check(node, execute_xor(node));
    case XAND:
      return print_check(node, execute_xand(node));
    case NOR:
      return print_check(node, execute_nor(node));
    case NAND:
      return print_check(node, execute_nand(node));
    default:
      perror("Wrong Operation");
      return false;
    }
  }
}
