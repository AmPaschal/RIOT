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
#include <stdbool.h>

void harness(void)
{
    size_t data_in_size;
    __CPROVER_assume(data_in_size <= 20);

    char* data_in = malloc(sizeof(data_in_size));
    __CPROVER_assume(data_in != NULL);


    size_t base64_out_size;
    __CPROVER_assume(base64_out_size <= 20);

    char* base64_out = malloc(sizeof(base64_out_size));
    __CPROVER_assume(base64_out != NULL);

    bool urlsafe;
    // We can assume this var behaves as needed because it does not seem user defined

    base64_encode_base(data_in, data_in_size,
                              base64_out, base64_out_size, urlsafe);
}
