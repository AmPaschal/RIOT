// Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
// SPDX-License-Identifier: MIT-0

/*
 * Insert copyright notice
 */

/**
 * @file _rbuf_add_harness.c
 * @brief Implements the proof harness for _rbuf_add function.
 */

/*
 * Insert project header files that
 *   - include the declaration of the function
 *   - include the types needed to declare function arguments
 */

/**
 * @brief Starting point for formal analysis
 * 
 */

#include <stdlib.h>


void harness(void)
{
    uint16_t port;

    size_t str_size;
    __CPROVER_assume(str_size <= 20);
    char* id = malloc(str_size);
    __CPROVER_assume(id != NULL);

    emcute_run(port, id);
}
