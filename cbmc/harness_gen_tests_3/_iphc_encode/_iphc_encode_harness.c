#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

#include "net/gnrc/pkt.h"
#include "net/gnrc/netif/hdr.h"
#include "net/gnrc/netif.h"

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
