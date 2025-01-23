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

#include "irq.h"
#include "kernel_defines.h"
#ifdef MODULE_GNRC_IPV6_NIB
#include "net/ipv6/addr.h"
#endif
#ifdef MODULE_GNRC_IPV6
#include "net/ipv6/hdr.h"
#endif
#include "net/gnrc/neterr.h"
#include "net/gnrc/netif/internal.h"
#include "net/gnrc/netif/pktq.h"
#include "net/gnrc/pkt.h"
#include "net/gnrc/sixlowpan.h"
#include "net/gnrc/sixlowpan/config.h"
#include "net/gnrc/sixlowpan/frag/fb.h"
#include "net/gnrc/sixlowpan/frag/rb.h"
#include "net/gnrc/sixlowpan/frag/vrb.h"
#include "net/gnrc/tx_sync.h"
#include "net/sixlowpan/sfr.h"
#include "thread.h"
#include "unaligned.h"
#include "xtimer.h"

#include "net/gnrc/sixlowpan/frag/sfr.h"
#include "net/gnrc/sixlowpan/frag/sfr/congure.h"

uint16_t _send_1st_fragment(gnrc_netif_t *netif,
                                   gnrc_sixlowpan_frag_fb_t *fbuf,
                                   unsigned page, gnrc_pktsnip_t **tx_sync) {
    uint16_t res;
    return res;   
}

uint16_t _send_nth_fragment(gnrc_netif_t *netif,
                                   gnrc_sixlowpan_frag_fb_t *fbuf,
                                   unsigned page,
                                   gnrc_pktsnip_t **tx_sync) {
    uint16_t res;
    return res;   
}

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
