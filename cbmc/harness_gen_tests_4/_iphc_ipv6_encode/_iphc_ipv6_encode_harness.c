#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>

#include "net/gnrc/pkt.h"
#include "net/gnrc/netif/hdr.h"
#include "net/gnrc/netif.h"
#include "net/gnrc/sixlowpan/ctx.h"
#include "net/ipv6/addr.h"

// Stub implementation

gnrc_sixlowpan_ctx_t *gnrc_sixlowpan_ctx_lookup_addr(const ipv6_addr_t *addr) {
    size_t ctx_len;
    __CPROVER_assume(ctx_len >= sizeof(gnrc_sixlowpan_ctx_t));
    gnrc_sixlowpan_ctx_t *ctx = (gnrc_sixlowpan_ctx_t *)malloc(ctx_len);
    return ctx;
}

extern size_t _iphc_ipv6_encode(gnrc_pktsnip_t *pkt,
                                const gnrc_netif_hdr_t *netif_hdr,
                                gnrc_netif_t *iface,
                                uint8_t *iphc_hdr);

void harness() {
    // pkt: gnrc_pktsnip_t *
    size_t pkt_len;
    __CPROVER_assume(pkt_len >= sizeof(gnrc_pktsnip_t));
    gnrc_pktsnip_t *pkt = (gnrc_pktsnip_t *)malloc(pkt_len);

    // netif_hdr: const gnrc_netif_hdr_t *
    size_t netif_hdr_len;
    __CPROVER_assume(netif_hdr_len >= sizeof(gnrc_netif_hdr_t));
    const gnrc_netif_hdr_t *netif_hdr = (const gnrc_netif_hdr_t *)malloc(netif_hdr_len);

    // iface: gnrc_netif_t *
    size_t iface_len;
    __CPROVER_assume(iface_len >= sizeof(gnrc_netif_t));
    gnrc_netif_t *iface = (gnrc_netif_t *)malloc(iface_len);

    // iphc_hdr: uint8_t *
    size_t iphc_hdr_len;
    uint8_t *iphc_hdr = (uint8_t *)malloc(iphc_hdr_len);

    (void)_iphc_ipv6_encode(pkt, netif_hdr, iface, iphc_hdr);
}
