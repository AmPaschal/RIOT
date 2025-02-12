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

#include "sys/include/net/gnrc/rpl/structs.h"
#include "net/ipv6.h"
#include "evtimer_msg.h"
#include "sched.h"

#include "sys/include/net/gnrc/rpl/structs.h"

void harness(void)
{
    uint16_t dao_len;
    __CPROVER_assume(dao_len <= 100);
    gnrc_rpl_dao_t *dao = malloc(dao_len);
    __CPROVER_assume(dao != NULL);

    kernel_pid_t iface;
    ipv6_addr_t src;
    ipv6_addr_t dst;

    gnrc_rpl_recv_DAO(dao, iface, &src, &dest, dao_len);
}
