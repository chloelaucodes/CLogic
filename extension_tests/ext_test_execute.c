/**
 * @brief This file is the test suite the ext_execute.c for the extension CLogic
 */

#include <assert.h>
#include <stdbool.h>

#include "../extension_lib/ext_execute.c"
#include "../extension_lib/ext_structs.h"

int main(void) { /**  testing execute.c functions */

  /** tests input nodes with true value */
  logic_node *node_input_true = malloc(sizeof(logic_node));
  assert(node_input_true);
  node_input_true->name = "node_input_true";
  node_input_true->num_of_inputs = 1;
  node_input_true->gate_type = INPUT;
  node_input_true->input_value = true;

  assert(execute(node_input_true));
  printf("node_input_true executes and works\n");

  /** tests input nodes with false value */
  logic_node *node_input_false = malloc(sizeof(logic_node));
  assert(node_input_false);
  node_input_false->name = "node_input_false";
  node_input_true->num_of_inputs = 1;
  node_input_false->gate_type = INPUT;
  node_input_false->input_value = false;
  assert(!execute(node_input_false));
  printf("node_input_false executes and works\n");

  /** tests gate nodes with operation and */
  logic_node *node_gate_and_1 = malloc(sizeof(logic_node));
  assert(node_gate_and_1);
  node_gate_and_1->name = "node_gate_and_1";
  node_gate_and_1->num_of_inputs = 2;
  node_gate_and_1->gate_type = GATE;
  node_gate_and_1->operation = AND;
  *node_gate_and_1->gate_inputs =
      calloc(node_gate_and_1->num_of_inputs, sizeof(logic_node *));
  assert(node_gate_and_1->gate_inputs);
  node_gate_and_1->gate_inputs[0] = node_input_true;
  node_gate_and_1->gate_inputs[1] = node_input_false;

  assert(!execute(node_gate_and_1));
  printf("node_gate_and_1 executes and works\n");

  logic_node *node_gate_and_2 = malloc(sizeof(logic_node));
  assert(node_gate_and_2);
  node_gate_and_2->name = "node_gate_and_2";
  node_gate_and_2->num_of_inputs = 2;
  node_gate_and_2->gate_type = GATE;
  node_gate_and_2->operation = AND;
  *node_gate_and_2->gate_inputs =
      calloc(node_gate_and_2->num_of_inputs, sizeof(logic_node *));
  assert(node_gate_and_2->gate_inputs);
  node_gate_and_2->gate_inputs[0] = node_input_true;
  node_gate_and_2->gate_inputs[1] = node_input_true;

  assert(execute(node_gate_and_2));
  printf("node_gate_and_2 executes and works\n");

  logic_node *node_gate_and_3 = malloc(sizeof(logic_node));
  assert(node_gate_and_3);
  node_gate_and_3->name = "node_gate_and_3";
  node_gate_and_3->num_of_inputs = 2;
  node_gate_and_3->gate_type = GATE;
  node_gate_and_3->operation = AND;
  *node_gate_and_3->gate_inputs =
      calloc(node_gate_and_3->num_of_inputs, sizeof(logic_node *));
  assert(node_gate_and_3->gate_inputs);
  node_gate_and_3->gate_inputs[0] = node_input_false;
  node_gate_and_3->gate_inputs[1] = node_input_false;

  assert(!execute(node_gate_and_3));
  printf("node_gate_and_3 executes and works\n");

  logic_node *node_gate_and_4 = malloc(sizeof(logic_node));
  assert(node_gate_and_4);
  node_gate_and_4->name = "node_gate_and_4";
  node_gate_and_4->num_of_inputs = 3;
  node_gate_and_4->gate_type = GATE;
  node_gate_and_4->operation = AND;
  *node_gate_and_4->gate_inputs =
      calloc(node_gate_and_4->num_of_inputs, sizeof(logic_node *));
  assert(node_gate_and_4->gate_inputs);
  node_gate_and_4->gate_inputs[0] = node_input_true;
  node_gate_and_4->gate_inputs[1] = node_input_false;
  node_gate_and_4->gate_inputs[2] = node_input_true;

  assert(!execute(node_gate_and_4));
  printf("node_gate_and_4 executes and works\n");

  /** tests gate nodes with operation or */
  logic_node *node_gate_or_1 = malloc(sizeof(logic_node));
  assert(node_gate_or_1);
  node_gate_or_1->name = "node_gate_or_1";
  node_gate_or_1->num_of_inputs = 2;
  node_gate_or_1->gate_type = GATE;
  node_gate_or_1->operation = OR;
  *node_gate_or_1->gate_inputs =
      calloc(node_gate_or_1->num_of_inputs, sizeof(logic_node *));
  assert(node_gate_or_1->gate_inputs);
  node_gate_or_1->gate_inputs[0] = node_input_true;
  node_gate_or_1->gate_inputs[1] = node_input_false;

  assert(execute(node_gate_or_1));
  printf("node_gate_or_1 executes and works\n");

  logic_node *node_gate_or_2 = malloc(sizeof(logic_node));
  assert(node_gate_or_2);
  node_gate_or_2->name = "node_gate_or_2";
  node_gate_or_2->num_of_inputs = 2;
  node_gate_or_2->gate_type = GATE;
  node_gate_or_2->operation = OR;
  *node_gate_or_2->gate_inputs =
      calloc(node_gate_or_2->num_of_inputs, sizeof(logic_node *));
  assert(node_gate_or_2->gate_inputs);
  node_gate_or_2->gate_inputs[0] = node_input_true;
  node_gate_or_2->gate_inputs[1] = node_input_true;

  assert(execute(node_gate_or_2));
  printf("node_gate_or_2 executes and works\n");

  logic_node *node_gate_or_3 = malloc(sizeof(logic_node));
  assert(node_gate_or_3);
  node_gate_or_3->name = "node_gate_or_3";
  node_gate_or_3->num_of_inputs = 2;
  node_gate_or_3->gate_type = GATE;
  node_gate_or_3->operation = OR;
  *node_gate_or_3->gate_inputs =
      calloc(node_gate_or_3->num_of_inputs, sizeof(logic_node *));
  assert(node_gate_or_3->gate_inputs);
  node_gate_or_3->gate_inputs[0] = node_input_false;
  node_gate_or_3->gate_inputs[1] = node_input_false;

  assert(!execute(node_gate_or_3));
  printf("node_gate_or_3 executes and works\n");

  logic_node *node_gate_or_4 = malloc(sizeof(logic_node));
  assert(node_gate_or_4);
  node_gate_or_4->name = "node_gate_or_4";
  node_gate_or_4->num_of_inputs = 3;
  node_gate_or_4->gate_type = GATE;
  node_gate_or_4->operation = OR;
  *node_gate_or_4->gate_inputs =
      calloc(node_gate_or_4->num_of_inputs, sizeof(logic_node *));
  assert(node_gate_or_4->gate_inputs);
  node_gate_or_4->gate_inputs[0] = node_input_true;
  node_gate_or_4->gate_inputs[1] = node_input_false;
  node_gate_or_4->gate_inputs[2] = node_input_true;

  assert(execute(node_gate_or_4));
  printf("node_gate_or_4 executes and works\n");

  /** tests gate nodes with operation not */
  logic_node *node_gate_not_1 = malloc(sizeof(logic_node));
  assert(node_gate_not_1);
  node_gate_not_1->name = "node_gate_not_1";
  node_gate_not_1->num_of_inputs = 1;
  node_gate_not_1->gate_type = GATE;
  node_gate_not_1->operation = NOT;
  *node_gate_not_1->gate_inputs = malloc(sizeof(logic_node));
  assert(node_gate_not_1->gate_inputs);
  node_gate_not_1->gate_inputs[0] = node_input_true;

  assert(!execute(node_gate_not_1));
  printf("node_gate_not_1 executes and works\n");

  logic_node *node_gate_not_2 = malloc(sizeof(logic_node));
  assert(node_gate_not_2);
  node_gate_not_2->name = "node_gate_not_1";
  node_gate_not_2->num_of_inputs = 1;
  node_gate_not_2->gate_type = GATE;
  node_gate_not_2->operation = NOT;
  *node_gate_not_2->gate_inputs = malloc(sizeof(logic_node *));
  assert(node_gate_not_2->gate_inputs);
  node_gate_not_2->gate_inputs[0] = node_gate_not_1;

  assert(execute(node_gate_not_2));
  printf("node_gate_not_2 executes and works\n");

  /** tests gate nodes with operation xand */
  logic_node *node_gate_xand_1 = malloc(sizeof(logic_node));
  assert(node_gate_xand_1);
  node_gate_xand_1->name = "node_gate_xand_1";
  node_gate_xand_1->num_of_inputs = 2;
  node_gate_xand_1->gate_type = GATE;
  node_gate_xand_1->operation = XAND;
  *node_gate_xand_1->gate_inputs =
      calloc(node_gate_xand_1->num_of_inputs, sizeof(logic_node *));
  assert(node_gate_xand_1->gate_inputs);
  node_gate_xand_1->gate_inputs[0] = node_input_true;
  node_gate_xand_1->gate_inputs[1] = node_input_false;

  assert(!execute(node_gate_xand_1));
  printf("node_gate_xand_1 executes and works\n");

  logic_node *node_gate_xand_2 = malloc(sizeof(logic_node));
  assert(node_gate_xand_2);
  node_gate_xand_2->name = "node_gate_xand_2";
  node_gate_xand_2->num_of_inputs = 2;
  node_gate_xand_2->gate_type = GATE;
  node_gate_xand_2->operation = XAND;
  *node_gate_xand_2->gate_inputs =
      calloc(node_gate_xand_2->num_of_inputs, sizeof(logic_node *));
  node_gate_xand_2->gate_inputs[0] = node_input_true;
  node_gate_xand_2->gate_inputs[1] = node_input_true;

  assert(execute(node_gate_xand_2));
  printf("node_gate_xand_2 executes and works\n");

  logic_node *node_gate_xand_3 = malloc(sizeof(logic_node));
  assert(node_gate_xand_3);
  node_gate_xand_3->name = "node_gate_xand_3";
  node_gate_xand_3->num_of_inputs = 2;
  node_gate_xand_3->gate_type = GATE;
  node_gate_xand_3->operation = XAND;
  *node_gate_xand_3->gate_inputs =
      calloc(node_gate_xand_3->num_of_inputs, sizeof(logic_node *));
  node_gate_xand_3->gate_inputs[0] = node_input_false;
  node_gate_xand_3->gate_inputs[1] = node_input_false;

  assert(execute(node_gate_xand_3));
  printf("node_gate_xand_3 executes and works\n");

  logic_node *node_gate_xand_4 = malloc(sizeof(logic_node));
  assert(node_gate_xand_4);
  node_gate_xand_4->name = "node_gate_xand_4";
  node_gate_xand_4->num_of_inputs = 2;
  node_gate_xand_4->gate_type = GATE;
  node_gate_xand_4->operation = XAND;
  *node_gate_xand_4->gate_inputs =
      calloc(node_gate_and_4->num_of_inputs, sizeof(logic_node *));
  node_gate_xand_4->gate_inputs[0] = node_input_true;
  node_gate_xand_4->gate_inputs[1] = node_gate_xand_3;
  node_gate_xand_4->gate_inputs[2] = node_input_true;

  assert(execute(node_gate_xand_4));
  printf("node_gate_xand_4 executes and works\n");

  /** tests gate nodes with operation xor */
  logic_node *node_gate_xor_1 = malloc(sizeof(logic_node));
  assert(node_gate_xor_1);
  node_gate_xor_1->name = "node_gate_xor_1";
  node_gate_xor_1->num_of_inputs = 2;
  node_gate_xor_1->gate_type = GATE;
  node_gate_xor_1->operation = XOR;
  *node_gate_xor_1->gate_inputs =
      calloc(node_gate_xor_1->num_of_inputs, sizeof(logic_node *));
  node_gate_xor_1->gate_inputs[0] = node_input_true;
  node_gate_xor_1->gate_inputs[1] = node_input_false;

  assert(execute(node_gate_xor_1));
  printf("node_gate_xor_1 executes and works\n");

  logic_node *node_gate_xor_2 = malloc(sizeof(logic_node));
  assert(node_gate_xor_2);
  node_gate_xor_2->name = "node_gate_xor_2";
  node_gate_xor_2->num_of_inputs = 2;
  node_gate_xor_2->gate_type = GATE;
  node_gate_xor_2->operation = XOR;
  *node_gate_xor_2->gate_inputs =
      calloc(node_gate_xor_2->num_of_inputs, sizeof(logic_node *));
  node_gate_xor_2->gate_inputs[0] = node_input_true;
  node_gate_xor_2->gate_inputs[1] = node_input_true;

  assert(!execute(node_gate_xor_2));
  printf("node_gate_xor_2 executes and works\n");

  logic_node *node_gate_xor_3 = malloc(sizeof(logic_node));
  assert(node_gate_xor_3);
  node_gate_xor_3->name = "node_gate_xor_3";
  node_gate_xor_3->num_of_inputs = 2;
  node_gate_xor_3->gate_type = GATE;
  node_gate_xor_3->operation = XOR;
  *node_gate_xor_3->gate_inputs =
      calloc(node_gate_xor_3->num_of_inputs, sizeof(logic_node *));
  node_gate_xor_3->gate_inputs[0] = node_input_false;
  node_gate_xor_3->gate_inputs[1] = node_input_false;

  assert(!execute(node_gate_xor_3));
  printf("node_gate_xor_3 executes and works\n");

  logic_node *node_gate_xor_4 = malloc(sizeof(logic_node));
  assert(node_gate_xor_4);
  node_gate_xor_4->name = "node_gate_xor_4";
  node_gate_xor_4->num_of_inputs = 3;
  node_gate_xor_4->gate_type = GATE;
  node_gate_xor_4->operation = XOR;
  *node_gate_xor_4->gate_inputs =
      calloc(node_gate_xor_4->num_of_inputs, sizeof(logic_node *));
  node_gate_xor_4->gate_inputs[0] = node_input_true;
  node_gate_xor_4->gate_inputs[1] = node_input_false;
  node_gate_xor_4->gate_inputs[2] = node_input_true;

  assert(!execute(node_gate_xor_4));
  printf("node_gate_xor_4 executes and works\n");

  /** tests gate nodes with operation nand */
  logic_node *node_gate_nand_1 = malloc(sizeof(logic_node));
  assert(node_gate_nand_1);
  node_gate_nand_1->name = "node_gate_nand_1";
  node_gate_nand_1->num_of_inputs = 2;
  node_gate_nand_1->gate_type = GATE;
  node_gate_nand_1->operation = NAND;
  *node_gate_nand_1->gate_inputs =
      calloc(node_gate_nand_1->num_of_inputs, sizeof(logic_node *));
  assert(node_gate_and_1->gate_inputs);
  node_gate_nand_1->gate_inputs[0] = node_input_true;
  node_gate_nand_1->gate_inputs[1] = node_input_false;

  assert(execute(node_gate_nand_1));
  printf("node_gate_nand_1 executes and works\n");

  logic_node *node_gate_nand_2 = malloc(sizeof(logic_node));
  assert(node_gate_and_2);
  node_gate_nand_2->name = "node_gate_nand_2";
  node_gate_nand_2->num_of_inputs = 2;
  node_gate_nand_2->gate_type = GATE;
  node_gate_nand_2->operation = NAND;
  *node_gate_nand_2->gate_inputs =
      calloc(node_gate_nand_2->num_of_inputs, sizeof(logic_node *));
  assert(node_gate_nand_2->gate_inputs);
  node_gate_nand_2->gate_inputs[0] = node_input_true;
  node_gate_nand_2->gate_inputs[1] = node_input_true;

  assert(!execute(node_gate_nand_2));
  printf("node_gate_nand_2 executes and works\n");

  logic_node *node_gate_nand_3 = malloc(sizeof(logic_node));
  assert(node_gate_nand_3);
  node_gate_nand_3->name = "node_gate_nand_3";
  node_gate_nand_3->num_of_inputs = 2;
  node_gate_nand_3->gate_type = GATE;
  node_gate_nand_3->operation = NAND;
  *node_gate_nand_3->gate_inputs =
      calloc(node_gate_nand_3->num_of_inputs, sizeof(logic_node *));
  assert(node_gate_nand_3->gate_inputs);
  node_gate_nand_3->gate_inputs[0] = node_input_false;
  node_gate_nand_3->gate_inputs[1] = node_input_false;

  assert(execute(node_gate_nand_3));
  printf("node_gate_nand_3 executes and works\n");

  logic_node *node_gate_nand_4 = malloc(sizeof(logic_node));
  assert(node_gate_nand_4);
  node_gate_nand_4->name = "node_gate_nand_4";
  node_gate_nand_4->num_of_inputs = 3;
  node_gate_nand_4->gate_type = GATE;
  node_gate_nand_4->operation = NAND;
  *node_gate_nand_4->gate_inputs =
      calloc(node_gate_nand_4->num_of_inputs, sizeof(logic_node *));
  assert(node_gate_nand_4->gate_inputs);
  node_gate_nand_4->gate_inputs[0] = node_input_true;
  node_gate_nand_4->gate_inputs[1] = node_input_false;
  node_gate_nand_4->gate_inputs[2] = node_input_true;

  assert(execute(node_gate_nand_4));
  printf("node_gate_nand_4 executes and works\n");

  /** tests gate nodes with operation nor */
  logic_node *node_gate_nor_1 = malloc(sizeof(logic_node));
  assert(node_gate_nor_1);
  node_gate_nor_1->name = "node_gate_nor_1";
  node_gate_nor_1->num_of_inputs = 2;
  node_gate_nor_1->gate_type = GATE;
  node_gate_nor_1->operation = NOR;
  *node_gate_nor_1->gate_inputs =
      calloc(node_gate_nor_1->num_of_inputs, sizeof(logic_node *));
  assert(node_gate_nor_1->gate_inputs);
  node_gate_nor_1->gate_inputs[0] = node_input_true;
  node_gate_nor_1->gate_inputs[1] = node_input_false;

  assert(!execute(node_gate_nor_1));
  printf("node_gate_nor_1 executes and works\n");

  logic_node *node_gate_nor_2 = malloc(sizeof(logic_node));
  assert(node_gate_nor_2);
  node_gate_nor_2->name = "node_gate_nor_2";
  node_gate_nor_2->num_of_inputs = 2;
  node_gate_nor_2->gate_type = GATE;
  node_gate_nor_2->operation = NOR;
  *node_gate_nor_2->gate_inputs =
      calloc(node_gate_nor_2->num_of_inputs, sizeof(logic_node *));
  assert(node_gate_nor_2->gate_inputs);
  node_gate_nor_2->gate_inputs[0] = node_input_true;
  node_gate_nor_2->gate_inputs[1] = node_input_true;

  assert(!execute(node_gate_nor_2));
  printf("node_gate_nor_2 executes and works\n");

  logic_node *node_gate_nor_3 = malloc(sizeof(logic_node));
  assert(node_gate_nor_3);
  node_gate_nor_3->name = "node_gate_nor_3";
  node_gate_nor_3->num_of_inputs = 2;
  node_gate_nor_3->gate_type = GATE;
  node_gate_nor_3->operation = NOR;
  *node_gate_nor_3->gate_inputs =
      calloc(node_gate_nor_3->num_of_inputs, sizeof(logic_node *));
  assert(node_gate_nor_3->gate_inputs);
  node_gate_nor_3->gate_inputs[0] = node_input_false;
  node_gate_nor_3->gate_inputs[1] = node_input_false;

  assert(execute(node_gate_nor_3));
  printf("node_gate_nor_3 executes and works\n");

  logic_node *node_gate_nor_4 = malloc(sizeof(logic_node));
  assert(node_gate_nor_4);
  node_gate_nor_4->name = "node_gate_nor_4";
  node_gate_nor_4->num_of_inputs = 3;
  node_gate_nor_4->gate_type = GATE;
  node_gate_nor_4->operation = NOR;
  *node_gate_nor_4->gate_inputs =
      calloc(node_gate_nor_4->num_of_inputs, sizeof(logic_node *));
  assert(node_gate_nor_4->gate_inputs);
  node_gate_nor_4->gate_inputs[0] = node_input_true;
  node_gate_nor_4->gate_inputs[1] = node_input_false;
  node_gate_nor_4->gate_inputs[2] = node_input_true;

  assert(!execute(node_gate_nor_4));
  printf("node_gate_nor_4 executes and works\n");

  /** returns all tests passed */
  printf("All tests pass\n");
  return 0;
}
