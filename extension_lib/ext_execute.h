/**
 * @brief This file is the header file for ext_execute.c
 */

#ifndef EXT_EXECUTE_H
#define EXT_EXECUTE_H

#include "ext_structs.h"
#include <stdbool.h>
#include <stdio.h>

bool execute(logic_node *node);

bool execute_and(logic_node *node);

bool execute_or(logic_node *node);

bool execute_not(logic_node *node);

bool execute_xor(logic_node *node);

bool execute_xand(logic_node *node);

bool execute_nor(logic_node *node);

bool execute_nand(logic_node *node);

bool print_check(logic_node *node, bool val);

#endif
