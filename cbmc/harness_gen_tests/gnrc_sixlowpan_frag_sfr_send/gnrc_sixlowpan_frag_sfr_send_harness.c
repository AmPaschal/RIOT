#include <stdlib.h>
#include <stdint.h>
#include "net/gnrc/pkt.h"
#include "net/gnrc/nettype.h"
#include "net/gnrc/netif/hdr.h"
#include "net/gnrc/sixlowpan/frag/sfr.h"

void harness() {
    // Parameters as in the function signature
    gnrc_pktsnip_t *pkt = (gnrc_pktsnip_t *)malloc(sizeof(gnrc_pktsnip_t));
    __CPROVER_assume(pkt != NULL);

    // Allocate and assign a netif header for pkt->data
    gnrc_netif_hdr_t *netif_hdr = (gnrc_netif_hdr_t *)malloc(sizeof(gnrc_netif_hdr_t));
    __CPROVER_assume(netif_hdr != NULL);
    // Minimal initialization of the netif header
    gnrc_netif_hdr_init(netif_hdr, 0, 0);

    // Initialize pkt fields
    pkt->next = NULL;
    pkt->data = (void *)netif_hdr;
    pkt->size = 0;
    pkt->type = GNRC_NETTYPE_NETIF;
    pkt->users = 0;

    // Allocate fragmentation buffer context and link it to pkt
    gnrc_sixlowpan_frag_fb_t *fbuf = (gnrc_sixlowpan_frag_fb_t *)malloc(sizeof(gnrc_sixlowpan_frag_fb_t));
    __CPROVER_assume(fbuf != NULL);
    fbuf->pkt = pkt;
    fbuf->datagram_size = 0;
    fbuf->tag = 0;
    fbuf->offset = 0;
    // The sfr extension is left uninitialized; deeper initialization can be added if needed

    void *ctx = (void *)fbuf;

    unsigned page;

    // Call the function under test
    gnrc_sixlowpan_frag_sfr_send(pkt, ctx, page);
}
