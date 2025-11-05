#include <stdlib.h>
#include <stddef.h>

#include "net/gnrc/netif.h"
#include "net/l2util.h"
#include "net/gnrc/pktbuf.h"
#include "net/gnrc/sixlowpan/frag/vrb.h"

#include "net/gnrc/pkt.h"
#include "net/gnrc/netif/hdr.h"

/* Stubs */

gnrc_netif_t *gnrc_netif_get_by_pid(kernel_pid_t pid) {
    size_t netif_len;
    __CPROVER_assume(netif_len >= sizeof(gnrc_netif_t));
    gnrc_netif_t *ret = (gnrc_netif_t *)malloc(netif_len);
    return ret;
}

char *l2util_addr_to_str(const uint8_t *addr, size_t addr_len, char *out) {
    size_t out_len;
    char *ret = (char *)malloc(out_len);
    return ret;
}

gnrc_pktsnip_t *gnrc_pktbuf_mark(gnrc_pktsnip_t *pkt, size_t size, gnrc_nettype_t type) {
    size_t snip_len;
    __CPROVER_assume(snip_len >= sizeof(gnrc_pktsnip_t));
    gnrc_pktsnip_t *ret = (gnrc_pktsnip_t *)malloc(snip_len);
    return ret;
}

gnrc_pktsnip_t *gnrc_pktbuf_add(gnrc_pktsnip_t *next, const void *data, size_t size, gnrc_nettype_t type) {
    size_t snip_len;
    __CPROVER_assume(snip_len >= sizeof(gnrc_pktsnip_t));
    gnrc_pktsnip_t *ret = (gnrc_pktsnip_t *)malloc(snip_len);
    return ret;
}

gnrc_pktsnip_t *gnrc_pktbuf_remove_snip(gnrc_pktsnip_t *pkt, gnrc_pktsnip_t *snip) {
    size_t snip_len;
    __CPROVER_assume(snip_len >= sizeof(gnrc_pktsnip_t));
    gnrc_pktsnip_t *ret = (gnrc_pktsnip_t *)malloc(snip_len);
    return ret;
}

gnrc_sixlowpan_frag_vrb_t *gnrc_sixlowpan_frag_vrb_from_route(
        const gnrc_sixlowpan_frag_rb_base_t *base, gnrc_netif_t *netif, const gnrc_pktsnip_t *hdr) {
    size_t vrb_len;
    __CPROVER_assume(vrb_len >= sizeof(gnrc_sixlowpan_frag_vrb_t));
    gnrc_sixlowpan_frag_vrb_t *ret = (gnrc_sixlowpan_frag_vrb_t *)malloc(vrb_len);
    return ret;
}

gnrc_sixlowpan_frag_vrb_t *gnrc_sixlowpan_frag_vrb_get(const uint8_t *src, size_t src_len, unsigned src_tag) {
    size_t vrb_len;
    __CPROVER_assume(vrb_len >= sizeof(gnrc_sixlowpan_frag_vrb_t));
    gnrc_sixlowpan_frag_vrb_t *ret = (gnrc_sixlowpan_frag_vrb_t *)malloc(vrb_len);
    return ret;
}

/* Forward declaration of the function under test */
int _rbuf_add(gnrc_netif_hdr_t *netif_hdr, gnrc_pktsnip_t *pkt,
              size_t offset, unsigned page);

void harness() {
    /* Declare and initialize gnrc_netif_hdr_t *netif_hdr */
    size_t netif_hdr_len;
    __CPROVER_assume(netif_hdr_len >= sizeof(gnrc_netif_hdr_t));
    gnrc_netif_hdr_t *netif_hdr = (gnrc_netif_hdr_t *)malloc(netif_hdr_len);

    /* Declare and initialize gnrc_pktsnip_t *pkt */
    size_t pkt_len;
    __CPROVER_assume(pkt_len >= sizeof(gnrc_pktsnip_t));
    gnrc_pktsnip_t *pkt = (gnrc_pktsnip_t *)malloc(pkt_len);

    /* Primitive parameters */
    size_t offset;
    unsigned page;

    /* Call the function under test */
    (void)_rbuf_add(netif_hdr, pkt, offset, page);
}
