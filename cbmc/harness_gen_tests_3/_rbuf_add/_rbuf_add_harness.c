#include <stdlib.h>
#include <stddef.h>
#include "net/gnrc/netif/hdr.h"
#include "net/gnrc/pkt.h"

/* Declare the target function */
extern int _rbuf_add(gnrc_netif_hdr_t *netif_hdr, gnrc_pktsnip_t *pkt,
                     size_t offset, unsigned page);

void harness() {
    /* gnrc_netif_hdr_t *netif_hdr */
    size_t netif_hdr_len;
    __CPROVER_assume(netif_hdr_len >= sizeof(gnrc_netif_hdr_t));
    gnrc_netif_hdr_t *netif_hdr = (gnrc_netif_hdr_t *)malloc(netif_hdr_len);

    /* gnrc_pktsnip_t *pkt */
    size_t pkt_len;
    __CPROVER_assume(pkt_len >= sizeof(gnrc_pktsnip_t));
    gnrc_pktsnip_t *pkt = (gnrc_pktsnip_t *)malloc(pkt_len);

    /* size_t offset */
    size_t offset;

    /* unsigned page */
    unsigned page;

    /* Call the function under test */
    (void)_rbuf_add(netif_hdr, pkt, offset, page);
}
