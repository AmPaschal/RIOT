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
#include "sys/include/net/gnrc/netif/hdr.h"

void harness(void)
{
    //Length of PDU after header struct
    //Will also use this to calculate length of the src/dest addr bytes
    size_t header_len;
    __CPROVER_assume(header_len >= sizeof(gnrc_netif_hdr_t) && header_len <= 100);

    gnrc_netif_hdr_t* netif_hdr = malloc(header_len);

    //For the 2 fields represent length of src/addr in bytes, I'll just assume they fit in the PDU
    // uint8_t src_addr;
    // __CPROVER_assume(src_addr <= header_len - sizeof(gnrc_netif_hdr_t));

    // uint8_t dest_addr;
    // __CPROVER_assume(dest_addr <= header_len - sizeof(gnrc_netif_hdr_t) - src_addr);
    // netif_hdr -> src_l2addr_len = src_addr;
    // netif_hdr -> dest_l2addr_len = dest_addr;    

    gnrc_pktsnip_t* pkt = malloc(sizeof(gnrc_pktsnip_t));
    __CPROVER_assume(pkt != NULL);
    // pkt -> next = NULL;

    size_t size;

    //Data buffer is read as gnrc_netif_hdr_t, I'm going to assume it's at least that size
    //However if it is less than that size I think it can cause an OOB read
    __CPROVER_assume(size <= 100 && size >= sizeof(gnrc_netif_hdr_t));
    uint8_t* data = malloc(size);
    __CPROVER_assume(data != NULL);
    
    pkt -> data = data;
    pkt -> size = size;

    size_t offset;

    unsigned page;
    _rbuf_add(netif_hdr, pkt, offset, page);
}
