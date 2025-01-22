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
#include "net/gnrc/pkt.h"
#include "net/gnrc/sixlowpan/frag/fb.h"


void harness(void)
{
    gnrc_pktsnip_t* pkt = malloc(sizeof(gnrc_pktsnip_t));
    __CPROVER_assume(pkt != NULL);
    pkt -> next = NULL;

    size_t size;
    __CPROVER_assume(size <= 100);
    uint8_t* data = malloc(size);
    __CPROVER_assume(data != NULL);
    
    pkt -> data = data;
    pkt -> size = size;

    gnrc_sixlowpan_frag_fb_t* ctx = malloc(sizeof(gnrc_sixlowpan_frag_fb_t));
    __CPROVER_assume(ctx != NULL);
    ctx -> pkt = pkt;

    uint8_t page;

    gnrc_sixlowpan_frag_sfr_send(pkt, ctx, page);

}
