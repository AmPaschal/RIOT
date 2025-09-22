#include <stdlib.h>
#include <stdint.h>

#include "net/gnrc/pkt.h"
#include "net/gnrc/netif/hdr.h"
#include "net/gnrc/netif.h"
#include "net/ipv6/hdr.h"
#include "net/protnum.h"
#include "net/gnrc/nettype.h"

/* Declaration of the function under test */
extern gnrc_pktsnip_t *_iphc_encode(gnrc_pktsnip_t *pkt,
                                    const gnrc_netif_hdr_t *netif_hdr,
                                    gnrc_netif_t *netif);

void harness()
{
    /* Parameters as in the signature */
    gnrc_pktsnip_t *pkt;
    const gnrc_netif_hdr_t *netif_hdr;
    gnrc_netif_t *netif;

    /* Allocate required structs and build a minimal valid packet chain:
     * pkt (NETIF header snip) -> IPv6 header snip
     */

    /* Allocate the head pktsnip (NETIF header snip) */
    pkt = (gnrc_pktsnip_t *)malloc(sizeof(gnrc_pktsnip_t));
    __CPROVER_assume(pkt != NULL);

    /* Allocate and initialize a gnrc_netif_hdr_t and point pkt->data to it */
    gnrc_netif_hdr_t *hdr = (gnrc_netif_hdr_t *)malloc(sizeof(gnrc_netif_hdr_t));
    __CPROVER_assume(hdr != NULL);
    pkt->data = (void *)hdr;
    pkt->size = 0; /* size is not used in _iphc_encode for the NETIF snip */
    pkt->type = GNRC_NETTYPE_NETIF;
    pkt->users = 0;
    pkt->next = NULL; /* will set below */

    /* Prepare the IPv6 snip as pkt->next */
    gnrc_pktsnip_t *ipv6_snip = (gnrc_pktsnip_t *)malloc(sizeof(gnrc_pktsnip_t));
    __CPROVER_assume(ipv6_snip != NULL);

    ipv6_hdr_t *ip6 = (ipv6_hdr_t *)malloc(sizeof(ipv6_hdr_t));
    __CPROVER_assume(ip6 != NULL);

    /* Set next header to a non-compressible value to avoid requiring further snips */
    ip6->nh = PROTNUM_RESERVED;

    ipv6_snip->data = (void *)ip6;
    ipv6_snip->size = sizeof(ipv6_hdr_t);
    ipv6_snip->type = GNRC_NETTYPE_IPV6;
    ipv6_snip->users = 0;
    ipv6_snip->next = NULL; /* minimal chain: no further headers */

    /* Link the chain */
    pkt->next = ipv6_snip;

    /* Allocate the separate netif_hdr parameter and the netif parameter */
    gnrc_netif_hdr_t *netif_hdr_mut = (gnrc_netif_hdr_t *)malloc(sizeof(gnrc_netif_hdr_t));
    __CPROVER_assume(netif_hdr_mut != NULL);
    netif_hdr = (const gnrc_netif_hdr_t *)netif_hdr_mut;

    netif = (gnrc_netif_t *)malloc(sizeof(gnrc_netif_t));
    __CPROVER_assume(netif != NULL);

    /* Additional preconditions for pointers used without explicit NULL checks */
    __CPROVER_assume(pkt != NULL);
    __CPROVER_assume(pkt->next != NULL);
    __CPROVER_assume(pkt->next->data != NULL);
    __CPROVER_assume(netif_hdr != NULL);
    __CPROVER_assume(netif != NULL);

    /* Call the function under test */
    (void)_iphc_encode(pkt, netif_hdr, netif);
}
