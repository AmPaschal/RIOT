#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

#include "net/gnrc/pkt.h"
#include "net/gnrc/nettype.h"
#include "net/ipv6/addr.h"
#include "net/gnrc/sixlowpan/ctx.h"
#include "net/gnrc/netif/hdr.h"
#include "net/gnrc/netif.h"

/* Stubs */

gnrc_pktsnip_t *gnrc_pktbuf_add(gnrc_pktsnip_t *next, const void *data, size_t size, gnrc_nettype_t type) {
    size_t ret_len;
    __CPROVER_assume(ret_len >= sizeof(gnrc_pktsnip_t));
    gnrc_pktsnip_t *ret = malloc(ret_len);
    return ret;
}

gnrc_pktsnip_t *gnrc_pktbuf_start_write(gnrc_pktsnip_t *pkt) {
    size_t ret_len;
    __CPROVER_assume(ret_len >= sizeof(gnrc_pktsnip_t));
    gnrc_pktsnip_t *ret = malloc(ret_len);
    return ret;
}

gnrc_sixlowpan_ctx_t *gnrc_sixlowpan_ctx_lookup_addr(const ipv6_addr_t *addr) {
    size_t ctx_len;
    __CPROVER_assume(ctx_len >= sizeof(gnrc_sixlowpan_ctx_t));
    gnrc_sixlowpan_ctx_t *ctx = malloc(ctx_len);
    return ctx;
}

gnrc_pktsnip_t *gnrc_pktbuf_remove_snip(gnrc_pktsnip_t *pkt, gnrc_pktsnip_t *snip) {
    size_t ret_len;
    __CPROVER_assume(ret_len >= sizeof(gnrc_pktsnip_t));
    gnrc_pktsnip_t *ret = malloc(ret_len);
    return ret;
}

/* Forward declaration of the function under test */
extern gnrc_pktsnip_t *_iphc_encode(gnrc_pktsnip_t *pkt,
                                    const gnrc_netif_hdr_t *netif_hdr,
                                    gnrc_netif_t *netif);

void harness() {
    /* Allocate and initialize pkt (gnrc_pktsnip_t *) */
    size_t pkt_len;
    __CPROVER_assume(pkt_len >= sizeof(gnrc_pktsnip_t));
    gnrc_pktsnip_t *pkt = malloc(pkt_len);

    /* Allocate and initialize netif_hdr (const gnrc_netif_hdr_t *) */
    size_t netif_hdr_len;
    __CPROVER_assume(netif_hdr_len >= sizeof(gnrc_netif_hdr_t));
    gnrc_netif_hdr_t *netif_hdr = malloc(netif_hdr_len);

    /* Allocate and initialize netif (gnrc_netif_t *) */
    size_t netif_len;
    __CPROVER_assume(netif_len >= sizeof(gnrc_netif_t));
    gnrc_netif_t *netif = malloc(netif_len);

    (void)_iphc_encode(pkt, netif_hdr, netif);
}
