#include <stdlib.h>
#include <stdint.h>
#include "net/gnrc/netif.h"
#include "net/gnrc/tx_sync.h"
#include "net/gnrc/pktbuf.h"
#include "net/gnrc/netif/hdr.h"
#include "net/gnrc/sixlowpan/frag/sfr.h"

/* Stubs */

gnrc_netif_t *gnrc_netif_get_by_pid(kernel_pid_t pid) {
    size_t netif_len;
    __CPROVER_assume(netif_len >= sizeof(gnrc_netif_t));
    gnrc_netif_t *ret = (gnrc_netif_t *)malloc(netif_len);
    return ret;
}

gnrc_pktsnip_t * gnrc_tx_sync_split(gnrc_pktsnip_t *pkt) {
    size_t pktsnip_len;
    __CPROVER_assume(pktsnip_len >= sizeof(gnrc_pktsnip_t));
    gnrc_pktsnip_t *ret = (gnrc_pktsnip_t *)malloc(pktsnip_len);
    return ret;
}

gnrc_pktsnip_t *gnrc_pktbuf_add(gnrc_pktsnip_t *next, const void *data, size_t size, gnrc_nettype_t type) {
    size_t pktsnip_len;
    __CPROVER_assume(pktsnip_len >= sizeof(gnrc_pktsnip_t));
    gnrc_pktsnip_t *ret = (gnrc_pktsnip_t *)malloc(pktsnip_len);
    return ret;
}

gnrc_pktsnip_t *gnrc_netif_hdr_build(const uint8_t *src, uint8_t src_len, const uint8_t *dst, uint8_t dst_len) {
    size_t pktsnip_len;
    __CPROVER_assume(pktsnip_len >= sizeof(gnrc_pktsnip_t));
    gnrc_pktsnip_t *ret = (gnrc_pktsnip_t *)malloc(pktsnip_len);
    return ret;
}

/* Provided harness */
void harness() {
    // Declare parameters exactly as in the function signature
    gnrc_pktsnip_t *pkt;
    void *ctx;
    unsigned page;

    // Allocate and initialize pointer parameters per instructions
    size_t pkt_len;
    __CPROVER_assume(pkt_len >= sizeof(gnrc_pktsnip_t));
    pkt = (gnrc_pktsnip_t *)malloc(pkt_len);

    size_t ctx_len;
    ctx = malloc(ctx_len);

    // Call the target function
    gnrc_sixlowpan_frag_sfr_send(pkt, ctx, page);
}