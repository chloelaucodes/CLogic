/**
 * @brief This is the header file for ext_decode.c
 */

#ifndef EXT_DECODE_H
#define EXT_DECODE_H

#include "ext_structs.h"
#include <stdio.h>
#include <string.h>

bool are_equal(char *str1, char *str2);

void to_tokens(char *line, char **tokens, int *num_tokens);

logic_node *search_nodes(logic_node *nodes[], int num_nodes, char *name);

void print_nodes(logic_node *nodes[], int size);

logic_node **read_file(FILE *file, logic_node **inputs, int *num_inputs);

#endif
