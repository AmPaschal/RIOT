#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#include "net/gnrc.h"
#include "net/gnrc/netif/internal.h"
#include "net/ipv6/hdr.h"
#include "net/gnrc/sixlowpan/iphc.h"

/* Prototype of the function under test */
extern size_t _iphc_ipv6_encode(gnrc_pktsnip_t *pkt,
                                const gnrc_netif_hdr_t *netif_hdr,
                                gnrc_netif_t *iface,
                                uint8_t *iphc_hdr);

void harness(void)
{
    /* Declare parameters exactly as in function signature */
    gnrc_pktsnip_t *pkt;
    const gnrc_netif_hdr_t *netif_hdr;
    gnrc_netif_t *iface;
    uint8_t *iphc_hdr;

    /* Allocate and initialize pkt and its next/data chain */
    pkt = (gnrc_pktsnip_t *)malloc(sizeof(gnrc_pktsnip_t));
    __CPROVER_assume(pkt != NULL);

    gnrc_pktsnip_t *pkt_next = (gnrc_pktsnip_t *)malloc(sizeof(gnrc_pktsnip_t));
    __CPROVER_assume(pkt_next != NULL);

    ipv6_hdr_t *ipv6_hdr = (ipv6_hdr_t *)malloc(sizeof(ipv6_hdr_t));
    __CPROVER_assume(ipv6_hdr != NULL);

    /* Link the structures to satisfy the function's expectations */
    pkt->next = pkt_next;
    pkt_next->data = ipv6_hdr;

    /* netif header */
    gnrc_netif_hdr_t *netif_hdr_nc = (gnrc_netif_hdr_t *)malloc(sizeof(gnrc_netif_hdr_t));
    __CPROVER_assume(netif_hdr_nc != NULL);
    netif_hdr = netif_hdr_nc; /* assign to const pointer */

    /* network interface */
    iface = (gnrc_netif_t *)malloc(sizeof(gnrc_netif_t));
    __CPROVER_assume(iface != NULL);

    /* iphc header buffer (primitive pointer) */
    uint16_t iphc_len;
    /* Constrain to a positive, reasonable size */
    __CPROVER_assume(iphc_len > 0 && iphc_len <= 256);
    iphc_hdr = (uint8_t *)malloc(sizeof(uint8_t) * iphc_len);
    __CPROVER_assume(iphc_hdr != NULL);

    /* Call the function under test */
    (void)_iphc_ipv6_encode(pkt, netif_hdr, iface, iphc_hdr);
}
