#include <stdlib.h>
#include <stdint.h>
#include "net/gnrc/pkt.h"
#include "net/gnrc/netif/hdr.h"
#include "net/gnrc/sixlowpan/frag/rb.h"
#include "net/ipv6/hdr.h"

/* Declaration of the function under test */
void gnrc_sixlowpan_iphc_recv(gnrc_pktsnip_t *sixlo, void *rbuf_ptr, unsigned page);

void harness() {
    /* Parameters as in signature */
    gnrc_pktsnip_t *sixlo = malloc(sizeof(gnrc_pktsnip_t));
    __CPROVER_assume(sixlo != NULL);

    /* Prepare sixlo->data as a primitive byte buffer with a size variable */
    size_t sixlo_size;
    uint8_t *sixlo_data = malloc(sizeof(uint8_t) * sixlo_size);

    sixlo->data = sixlo_data;
    sixlo->size = sixlo_size;
    sixlo->type = GNRC_NETTYPE_SIXLOWPAN;
    sixlo->users = 0;

    /* Create a NETIF snip so gnrc_pktsnip_search_type can find it */
    gnrc_pktsnip_t *netif_snip = malloc(sizeof(gnrc_pktsnip_t));
    __CPROVER_assume(netif_snip != NULL);

    gnrc_netif_hdr_t *netif_hdr = malloc(sizeof(gnrc_netif_hdr_t));
    __CPROVER_assume(netif_hdr != NULL);

    netif_snip->data = netif_hdr;
    netif_snip->size = sizeof(gnrc_netif_hdr_t);
    netif_snip->type = GNRC_NETTYPE_NETIF;
    netif_snip->users = 0;
    netif_snip->next = NULL;

    /* Link NETIF snip after SIXLOWPAN snip */
    sixlo->next = netif_snip;

    /* Prepare reassembly buffer (void *) argument */
    gnrc_sixlowpan_frag_rb_t *rbuf = malloc(sizeof(gnrc_sixlowpan_frag_rb_t));
    __CPROVER_assume(rbuf != NULL);

    /* Initialize rbuf->pkt so that ipv6 = rbuf->pkt; __CPROVER_assume(ipv6 != NULL); can hold */
    gnrc_pktsnip_t *ipv6_snip = malloc(sizeof(gnrc_pktsnip_t));
    __CPROVER_assume(ipv6_snip != NULL);

    size_t ipv6_data_size;
    __CPROVER_assume(ipv6_data_size >= sizeof(ipv6_hdr_t));
    void *ipv6_data = malloc(ipv6_data_size);

    ipv6_snip->data = ipv6_data;
    ipv6_snip->size = ipv6_data_size;
    ipv6_snip->type = GNRC_NETTYPE_IPV6;
    ipv6_snip->users = 0;
    ipv6_snip->next = NULL;

    rbuf->pkt = ipv6_snip;
    /* Other rbuf->super fields left unconstrained for CBMC to explore */

    void *rbuf_ptr = (void *)rbuf;

    unsigned page;

    /* Call the function under test */
    gnrc_sixlowpan_iphc_recv(sixlo, rbuf_ptr, page);
}
