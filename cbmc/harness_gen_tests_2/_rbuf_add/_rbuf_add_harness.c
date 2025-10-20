#include <stddef.h>
#include <stdlib.h>

#include "net/gnrc/netif/hdr.h"   /* gnrc_netif_hdr_t */
#include "net/gnrc/pkt.h"         /* gnrc_pktsnip_t */

/* _rbuf_add is defined in
 * sys/net/gnrc/network_layer/sixlowpan/frag/rb/gnrc_sixlowpan_frag_rb.c
 * It is not declared in a public header, so we declare it here. */
extern int _rbuf_add(gnrc_netif_hdr_t *netif_hdr, gnrc_pktsnip_t *pkt,
                     size_t offset, unsigned page);

void harness() {
    /* Parameters as in the function signature */
    gnrc_netif_hdr_t *netif_hdr = malloc(sizeof(gnrc_netif_hdr_t));
    __CPROVER_assume(netif_hdr != NULL);

    gnrc_pktsnip_t *pkt = malloc(sizeof(gnrc_pktsnip_t));
    __CPROVER_assume(pkt != NULL);

    size_t offset;
    unsigned page;

    (void)_rbuf_add(netif_hdr, pkt, offset, page);
}
