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

// #include "net/gnrc/pkt.h"
// #include "net/gnrc/netif/hdr.h"

// #include "sys/net/gnrc/network_layer/sixlowpan/iphc/gnrc_sixlowpan_iphc.c"
// #include "sys/net/gnrc/network_layer/sixlowpan/frag/rb/gnrc_sixlowpan_frag_rb.c"

#include <assert.h>
#include <inttypes.h>
#include <stdbool.h>

#include "net/ieee802154.h"
#include "net/eui64.h"
#include "net/ipv6.h"
#include "net/ipv6/hdr.h"
#include "net/ipv6/addr.h"
#include "net/gnrc.h"
#include "net/gnrc/netif.h"
#include "net/gnrc/sixlowpan.h"
#include "net/gnrc/sixlowpan/config.h"
#include "net/gnrc/sixlowpan/ctx.h"
#ifdef  MODULE_GNRC_SIXLOWPAN_FRAG_STATS
#include "net/gnrc/sixlowpan/frag/stats.h"
#endif  /* MODULE_GNRC_SIXLOWPAN_FRAG_STATS */
#include "net/gnrc/sixlowpan/frag/minfwd.h"
#include "net/gnrc/sixlowpan/frag/vrb.h"
#include "net/sixlowpan.h"
#include "net/sixlowpan/sfr.h"
#include "thread.h"
#include "xtimer.h"
#include "utlist.h"
#include "net/gnrc/nettype.h"

#include "net/gnrc/sixlowpan/frag/rb.h"


// extern gnrc_sixlowpan_frag_rb_t rbuf[CONFIG_GNRC_SIXLOWPAN_FRAG_RBUF_SIZE];

// gnrc_sixlowpan_frag_vrb_t *gnrc_sixlowpan_frag_vrb_get(const uint8_t *src, size_t src_len, unsigned src_tag) {
//     //I believe this can return null
//     gnrc_sixlowpan_frag_vrb_t* vrb = malloc(sizeof(gnrc_sixlowpan_frag_vrb_t));
//     if(vrb == NULL) {
//         return vrb;
//     }

//     //Need super defined
//     gnrc_sixlowpan_frag_rb_base_t super;
//     gnrc_sixlowpan_frag_rb_int_t* interval = malloc(sizeof(gnrc_sixlowpan_frag_rb_int_t));
//     __CPROVER_assume(interval != NULL);
//     //Assume it's a 1 entry LL
//     //Can we assume this?
//     __CPROVER_assume(interval -> next == NULL);

//     super.ints = interval;
//     vrb -> super = super;

//     return vrb;
// }

// gnrc_pktsnip_t *gnrc_pktbuf_mark(gnrc_pktsnip_t *pkt, size_t size, gnrc_nettype_t type) {
//     //Original function can change pkt data and size

//     // This exposes CVE-2023-24825 but makes the run time far longer so I'm leaving it commented
//     // __CPROVER_havoc_object(pkt);

//     gnrc_pktsnip_t *new_pkt = malloc(sizeof(gnrc_pktsnip_t));
//     //Based on the original function this can return null
//     if(new_pkt == NULL) {
//         return new_pkt;
//     }

//     uint8_t size;
//     uint8_t *data = malloc(size);
//     __CPROVER_assume(data != NULL);
//     new_pkt->data = data;
//     new_pkt->size = size;
//     new_pkt->next = NULL;

//     return new_pkt;
// }

gnrc_sixlowpan_ctx_t *gnrc_sixlowpan_ctx_lookup_id(uint8_t id) {
    gnrc_sixlowpan_ctx_t* context = malloc(sizeof(gnrc_sixlowpan_ctx_t));
    return context;
}

gnrc_pktsnip_t *gnrc_pktsnip_search_type(gnrc_pktsnip_t *pkt,
                                         gnrc_nettype_t type) {
    gnrc_pktsnip_t* new_pkt = malloc(sizeof(gnrc_pktsnip_t));
    __CPROVER_assume(new_pkt != NULL);
    // pkt -> next = NULL;

    size_t size;

    //This part of the buffer can be read as quite a few different things
    //sixlowpan_sfr_rfrag_t I think is the biggest of the possible options

    __CPROVER_assume(size <= 100 && size >= sizeof(gnrc_netif_hdr_t));

    uint8_t* data = malloc(size);
    __CPROVER_assume(data != NULL);
    
    new_pkt -> data = data;
    new_pkt -> size = size;
    new_pkt -> next = NULL;

    return new_pkt;
}

gnrc_netif_t *gnrc_netif_get_by_pid(kernel_pid_t pid) {
    gnrc_netif_t *new_netif = malloc(sizeof(gnrc_netif_t));
    //It CAN be NULL
    //Kind of just praying it doesn't need those function pointers in ops
    return new_netif;

}

void harness(void)
{

    gnrc_pktsnip_t* pkt = malloc(sizeof(gnrc_pktsnip_t));
    __CPROVER_assume(pkt != NULL);

    size_t size;

    //This recieves direct user input, so I'm not going to put a lower bound except to fit the check on the first 2 bytes
    __CPROVER_assume(size <= 100 && size >= 2);
    uint8_t* data = malloc(size);
    __CPROVER_assume(data != NULL);
    __CPROVER_assume(sixlowpan_iphc_is(data))
    
    pkt -> data = data;
    pkt -> size = size;
    pkt -> next = NULL;

    gnrc_sixlowpan_frag_rb_t rbuf_entry;

    gnrc_pktsnip_t* rbuf_pkt = malloc(sizeof(gnrc_pktsnip_t));
    
    if(rbuf_pkt != NULL) {
        size_t entry_size;
        __CPROVER_assume(entry_size > 0);
        uint8_t* entry_data = malloc(entry_size);
        __CPROVER_assume(entry_data != NULL);
        rbuf_pkt -> data = entry_data;
        rbuf_pkt -> size = entry_size;
        rbuf_pkt -> next = NULL;

        gnrc_sixlowpan_frag_rb_base_t super;

        gnrc_sixlowpan_frag_rb_int_t* interval = malloc(sizeof(gnrc_sixlowpan_frag_rb_int_t));
        __CPROVER_assume(interval != NULL);
        __CPROVER_assume(interval -> next == NULL);

        // uint16_t datagram_size;
        // __CPROVER_assume(datagram_size <= entry_size);
        // super.datagram_size = datagram_size;

        super.ints = interval;

        entry.super = super;

        // // Added this to fix a bug. Not sure how best to model it
        // int8_t offset_diff;
        // __CPROVER_assume(offset_diff >= 0); // Basically, offset diff should not be negative that it overflows.
        // entry.offset_diff = offset_diff;
    }

    unsigned page;

    gnrc_sixlowpan_iphc_recv(pkt, rbuf_pkt, page);
}
