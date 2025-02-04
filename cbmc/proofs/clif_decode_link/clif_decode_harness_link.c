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
#include <stdint.h>

#include "clif.h"

void harness(void)
{
    clif_t* link = malloc(sizeof(clif_t));
    __CPROVER_assume(link != NULL);

    size_t attrs_len;
    __CPROVER_assume(attrs_len <= 6);

    //Seems like this can be NULL
    clif_attr_t* attrs = malloc(sizeof(clif_attr_t) * attrs_len);
    
    size_t maxlen;
    __CPROVER_assume(maxlen <= 10);

    char* buf = malloc(input_len);
    __CPROVER_assume(buf != NULL);

    clif_decode_link(link, attrs, attrs_len, buf, maxlen)
}
