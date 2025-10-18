#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#include "net/gnrc/pkt.h"
#include "net/gnrc/netif/hdr.h"
#include "net/gnrc/netif.h"

/* Prototype of the function under test */
size_t _iphc_ipv6_encode(gnrc_pktsnip_t *pkt,
                         const gnrc_netif_hdr_t *netif_hdr,
                         gnrc_netif_t *iface,
                         uint8_t *iphc_hdr);

void harness() {
    /* Allocate and assume non-NULL for struct pointer parameters */
    gnrc_pktsnip_t *pkt = (gnrc_pktsnip_t *)malloc(sizeof(gnrc_pktsnip_t));
    __CPROVER_assume(pkt != NULL);

    const gnrc_netif_hdr_t *netif_hdr = (const gnrc_netif_hdr_t *)malloc(sizeof(gnrc_netif_hdr_t));
    __CPROVER_assume(netif_hdr != NULL);

    gnrc_netif_t *iface = (gnrc_netif_t *)malloc(sizeof(gnrc_netif_t));
    __CPROVER_assume(iface != NULL);

    /* For pointers to primitive types, create a size variable and allocate */
    size_t iphc_hdr_len;
    uint8_t *iphc_hdr = (uint8_t *)malloc(sizeof(uint8_t) * iphc_hdr_len);

    /* Call the function under test */
    (void)_iphc_ipv6_encode(pkt, netif_hdr, iface, iphc_hdr);
}
