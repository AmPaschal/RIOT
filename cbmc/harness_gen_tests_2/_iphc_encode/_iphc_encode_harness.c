#include <stdlib.h>

#include "net/gnrc/pkt.h"
#include "net/gnrc/netif/hdr.h"
#include "net/gnrc/netif.h"

/* Forward declaration of the target function */
extern gnrc_pktsnip_t *_iphc_encode(gnrc_pktsnip_t *pkt,
                                    const gnrc_netif_hdr_t *netif_hdr,
                                    gnrc_netif_t *netif);

void harness() {
    /* Allocate pkt (pointer to struct) */
    gnrc_pktsnip_t *pkt = (gnrc_pktsnip_t *)malloc(sizeof(gnrc_pktsnip_t));
    __CPROVER_assume(pkt != NULL);

    /* Allocate netif_hdr (const pointer to struct) */
    gnrc_netif_hdr_t *netif_hdr_mut = (gnrc_netif_hdr_t *)malloc(sizeof(gnrc_netif_hdr_t));
    __CPROVER_assume(netif_hdr_mut != NULL);
    const gnrc_netif_hdr_t *netif_hdr = netif_hdr_mut;

    /* Allocate netif (pointer to struct) */
    gnrc_netif_t *netif = (gnrc_netif_t *)malloc(sizeof(gnrc_netif_t));
    __CPROVER_assume(netif != NULL);

    /* Call the function under test */
    (void)_iphc_encode(pkt, netif_hdr, netif);
}
