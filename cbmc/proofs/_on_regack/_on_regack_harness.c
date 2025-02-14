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
#include "net/asymcute.h"


void harness(void)
{
    asymcute_con_t *con = malloc(sizeof(asymcute_con_t));
    __CPROVER_assume(con != NULL);

    asymcute_req_t *pending = malloc(sizeof(asymcute_req_t ));
    __CPROVER_assume(pending != NULL);
    pending -> next = NULL;
    con -> pending = pending;

    asymcute_sub_t *subscriptions = malloc(sizeof(asymcute_req_t));
    __CPROVER_assume(subscriptions != NULL);
    subscriptions -> next = NULL;
    con -> subscriptions = subscriptions;

    size_t len;
    __CPROVER_assume(len <= 100);
    uint8_t* data = malloc(len);
    __CPROVER_assume(data != NULL);

    _on_regack(con, data, len);
}
