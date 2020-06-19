/**
 * @brief This is the general structure for the extension CLogic
 */

#ifndef EXT_STRUCT_H
#define EXT_STRUCT_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME_SIZE 20
#define MAX_INPUT_GATES 5
#define BUFFER_SIZE 1000
#define MAX_NUMBER_GATES 1000
#define MAX_TOKENS 6
#define MAX_OUTPUT_GATES 10

/** Logical operations defined */
typedef enum op { AND, OR, NOT, XOR, XAND, NOR, NAND } operation;

/** defines external input value */
typedef bool external_input;

/** Gate types */
typedef enum gate_type { INPUT, OUTPUT, GATE } type;

/** Logical node structure */
typedef struct node {
  char *name;
  type gate_type;
  operation operation;
  external_input input_value;
  struct node *gate_inputs[MAX_NUMBER_GATES];
  int num_of_inputs;
} logic_node;

#endif