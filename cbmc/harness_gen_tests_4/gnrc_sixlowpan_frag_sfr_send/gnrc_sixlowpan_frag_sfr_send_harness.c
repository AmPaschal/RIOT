#include <stdlib.h>
#include <stdint.h>

#include "net/gnrc/netif/hdr.h"
#include "net/gnrc/netif.h"
#include "net/gnrc/pktbuf.h"
#include "net/gnrc/tx_sync.h"
#include "net/gnrc/pkt.h"
#include "net/gnrc/sixlowpan/frag/sfr.h"

/* Stub implementations */

gnrc_pktsnip_t *gnrc_netif_hdr_build(const uint8_t *src, uint8_t src_len, const uint8_t *dst, uint8_t dst_len) {
    (void)src; (void)src_len; (void)dst; (void)dst_len;
    size_t pktsnip_len;
    __CPROVER_assume(pktsnip_len >= sizeof(gnrc_pktsnip_t));
    gnrc_pktsnip_t *ret = (gnrc_pktsnip_t *)malloc(pktsnip_len);
    if (ret) {
        /* Ensure data points to a valid gnrc_netif_hdr_t object */
        size_t hdr_sz;
        __CPROVER_assume(hdr_sz >= sizeof(gnrc_netif_hdr_t));
        void *hdr = malloc(hdr_sz);
        ret->data = hdr;
    }
    return ret;
}

gnrc_netif_t *gnrc_netif_get_by_pid(kernel_pid_t pid) {
    (void)pid;
    size_t netif_len;
    __CPROVER_assume(netif_len >= sizeof(gnrc_netif_t));
    gnrc_netif_t *ret = (gnrc_netif_t *)malloc(netif_len);
    return ret;
}

gnrc_pktsnip_t *gnrc_pktbuf_add(gnrc_pktsnip_t *next, const void *data, size_t size, gnrc_nettype_t type) {
    (void)next; (void)data; (void)size; (void)type;
    size_t pktsnip_len;
    __CPROVER_assume(pktsnip_len >= sizeof(gnrc_pktsnip_t));
    gnrc_pktsnip_t *ret = (gnrc_pktsnip_t *)malloc(pktsnip_len);
    return ret;
}

gnrc_pktsnip_t * gnrc_tx_sync_split(gnrc_pktsnip_t *pkt) {
    (void)pkt;
    size_t pktsnip_len;
    __CPROVER_assume(pktsnip_len >= sizeof(gnrc_pktsnip_t));
    gnrc_pktsnip_t *ret = (gnrc_pktsnip_t *)malloc(pktsnip_len);
    return ret;
}

void harness() {
    /* gnrc_pktsnip_t *pkt */
    size_t pkt_len;
    __CPROVER_assume(pkt_len >= sizeof(gnrc_pktsnip_t));
    gnrc_pktsnip_t *pkt = (gnrc_pktsnip_t *)malloc(pkt_len);

    /* void *ctx */
    size_t ctx_len;
    void *ctx = malloc(ctx_len);

    /* unsigned page */
    unsigned page;

    gnrc_sixlowpan_frag_sfr_send(pkt, ctx, page);
}
