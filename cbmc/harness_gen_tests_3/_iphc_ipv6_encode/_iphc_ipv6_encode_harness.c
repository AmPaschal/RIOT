#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

#include "sys/include/net/gnrc/pkt.h"
#include "sys/include/net/gnrc/netif/hdr.h"
#include "sys/include/net/gnrc/netif.h"

extern size_t _iphc_ipv6_encode(gnrc_pktsnip_t *pkt,
                                const gnrc_netif_hdr_t *netif_hdr,
                                gnrc_netif_t *iface,
                                uint8_t *iphc_hdr);

void harness() {
    // gnrc_pktsnip_t *pkt
    size_t pkt_len;
    __CPROVER_assume(pkt_len >= sizeof(gnrc_pktsnip_t));
    gnrc_pktsnip_t *pkt = malloc(pkt_len);

    // const gnrc_netif_hdr_t *netif_hdr
    size_t netif_hdr_len;
    __CPROVER_assume(netif_hdr_len >= sizeof(gnrc_netif_hdr_t));
    const gnrc_netif_hdr_t *netif_hdr = malloc(netif_hdr_len);

    // gnrc_netif_t *iface
    size_t iface_len;
    __CPROVER_assume(iface_len >= sizeof(gnrc_netif_t));
    gnrc_netif_t *iface = malloc(iface_len);

    // uint8_t *iphc_hdr
    size_t iphc_hdr_len;
    uint8_t *iphc_hdr = malloc(iphc_hdr_len);

    (void)_iphc_ipv6_encode(pkt, netif_hdr, iface, iphc_hdr);
}
