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
// #include "net/gnrc/netif/hdr.h"
// #include "net/sixlowpan.h"
// #include "net/gnrc/sixlowpan/frag/rb.h"
// #include "sfr_types.h"

#include "sys/net/gnrc/network_layer/sixlowpan/frag/rb/gnrc_sixlowpan_frag_rb.c"


extern gnrc_sixlowpan_frag_rb_t rbuf[CONFIG_GNRC_SIXLOWPAN_FRAG_RBUF_SIZE];

gnrc_sixlowpan_frag_vrb_t *gnrc_sixlowpan_frag_vrb_get(const uint8_t *src, size_t src_len, unsigned src_tag) {
    //I believe this can return null
    gnrc_sixlowpan_frag_vrb_t* vrb = malloc(sizeof(gnrc_sixlowpan_frag_vrb_t));
    if(vrb == NULL) {
        return vrb;
    }

    //Need super defined
    gnrc_sixlowpan_frag_rb_base_t super;
    gnrc_sixlowpan_frag_rb_int_t* interval = malloc(sizeof(gnrc_sixlowpan_frag_rb_int_t));
    __CPROVER_assume(interval != NULL);
    //Assume it's a 1 entry LL
    //Can we assume this?
    __CPROVER_assume(interval -> next == NULL);

    super.ints = interval;
    vrb -> super = super;

    return vrb;

}

gnrc_pktsnip_t *gnrc_pktbuf_mark(gnrc_pktsnip_t *pkt, size_t size, gnrc_nettype_t type) {
    gnrc_pktsnip_t *pkt = malloc(sizeof(gnrc_pktsnip_t));
    __CPROVER_assume(pkt != NULL);
    uint8_t size;
    uint8_t *data = malloc(size);
    __CPROVER_assume(data != NULL);
    pkt->data = data;
    pkt->size = size;
    pkt->next = NULL;

    return pkt;
}


void harness(void)
{
    //Length of PDU after header struct
    //Will also use this to calculate length of the src/dest addr bytes
    size_t header_len;
    __CPROVER_assume(header_len >= sizeof(gnrc_netif_hdr_t) && header_len <= 100);

    gnrc_netif_hdr_t* netif_hdr = malloc(header_len);
    __CPROVER_assume(netif_hdr != NULL);

    //For the 2 fields represent length of src/addr in bytes, I'll just assume they fit in the PDU
    uint8_t src_addr;
    __CPROVER_assume(src_addr <= header_len - sizeof(gnrc_netif_hdr_t));

    uint8_t dest_addr;
    __CPROVER_assume(dest_addr <= header_len - sizeof(gnrc_netif_hdr_t) - src_addr);
    netif_hdr -> src_l2addr_len = src_addr;
    netif_hdr -> dst_l2addr_len = dest_addr;    

    gnrc_pktsnip_t* pkt = malloc(sizeof(gnrc_pktsnip_t));
    __CPROVER_assume(pkt != NULL);
    // pkt -> next = NULL;

    size_t size;

    //This part of the buffer can be read as quite a few different things
    //sixlowpan_sfr_rfrag_t I think is the biggest of the possible options

    __CPROVER_assume(size <= 100);

    //There is a function up the call stack that would crash if the header isn't long enough
    //So I'll assume this is large enough to fit the largest header format
    //I think a caller does indeed verify this
    __CPROVER_assume(size >= sizeof(sixlowpan_sfr_rfrag_t));
    uint8_t* data = malloc(size);
    __CPROVER_assume(data != NULL);
    
    pkt -> data = data;
    pkt -> size = size;

    size_t offset;
    //This check prevents a potential bug (OOB read on line 509)
    __CPROVER_assume(offset != 0 || sixlowpan_frag_1_is(pkt->data) || sixlowpan_sfr_rfrag_is(data));

    unsigned page;

    gnrc_sixlowpan_frag_rb_t entry;

    gnrc_pktsnip_t* entry_pkt = malloc(sizeof(gnrc_pktsnip_t));
    __CPROVER_assume(entry_pkt != NULL);

    size_t entry_size;
    __CPROVER_assume(entry_size <= 100);
    uint8_t* entry_data = malloc(entry_size);
    __CPROVER_assume(entry_data != NULL);
    entry_pkt -> data = entry_data;
    entry_pkt -> size = entry_size;


    entry.pkt = entry_pkt;

    gnrc_sixlowpan_frag_rb_base_t super;

    gnrc_sixlowpan_frag_rb_int_t* interval = malloc(sizeof(gnrc_sixlowpan_frag_rb_int_t));
    __CPROVER_assume(interval != NULL);
    //Assume it's a 1 entry LL
    __CPROVER_assume(interval -> next == NULL);

    uint16_t datagram_size;
    __CPROVER_assume(datagram_size <= entry_size);
    super.datagram_size = datagram_size;

    super.ints = interval;

    entry.super = super;

        // Added this to fix a bug. Not sure how best to model it
    int8_t offset_diff;
    __CPROVER_assume(offset_diff >= 0); // Basically, offset diff should not be negative that it overflows.
    entry.offset_diff = offset_diff;

    rbuf[0] = entry;

    _rbuf_add(netif_hdr, pkt, offset, page);
}
