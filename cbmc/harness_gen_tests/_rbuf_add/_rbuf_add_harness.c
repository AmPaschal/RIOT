#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>

#include "net/gnrc/netif/hdr.h"
#include "net/gnrc/pkt.h"

/* The target function is defined in
 * sys/net/gnrc/network_layer/sixlowpan/frag/rb/gnrc_sixlowpan_frag_rb.c
 * No public header declares it, so we declare it here. */
extern int _rbuf_add(gnrc_netif_hdr_t *netif_hdr, gnrc_pktsnip_t *pkt,
                     size_t offset, unsigned page);

void harness() {
    /* Allocate struct pointer parameters per instructions */
    gnrc_netif_hdr_t *netif_hdr = (gnrc_netif_hdr_t *)malloc(sizeof(gnrc_netif_hdr_t));
    __CPROVER_assume(netif_hdr != NULL);

    gnrc_pktsnip_t *pkt = (gnrc_pktsnip_t *)malloc(sizeof(gnrc_pktsnip_t));
    __CPROVER_assume(pkt != NULL);

    /* Scalars as in signature */
    size_t offset;
    unsigned page;

    /* Call the function under test */
    (void)_rbuf_add(netif_hdr, pkt, offset, page);
}
