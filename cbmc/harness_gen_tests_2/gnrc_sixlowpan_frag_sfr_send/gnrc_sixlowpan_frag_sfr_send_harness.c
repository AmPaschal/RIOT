#include <stdlib.h>
#include <stdint.h>

#include "net/gnrc/pkt.h"
#include "net/gnrc/nettype.h"
#include "net/gnrc/sixlowpan/frag/fb.h"
#include "net/gnrc/sixlowpan/frag/sfr.h"

void harness() {
    // Parameters as in the function signature
    gnrc_pktsnip_t *pkt = malloc(sizeof(gnrc_pktsnip_t));
    __CPROVER_assume(pkt != NULL);

    // The context is a void*, but expected to be a gnrc_sixlowpan_frag_fb_t
    gnrc_sixlowpan_frag_fb_t *fbuf = malloc(sizeof(gnrc_sixlowpan_frag_fb_t));
    __CPROVER_assume(fbuf != NULL);
    void *ctx = (void *)fbuf;

    unsigned page; // nondet

    // Minimal initialization to help satisfy internal assertions
    fbuf->pkt = pkt;
    pkt->type = GNRC_NETTYPE_NETIF;

    // Provide a data buffer for pkt->data (not required by rules, but safe)
    size_t data_len;
    uint8_t *data = malloc(sizeof(uint8_t) * data_len);
    pkt->data = data;

    // Other fields can remain nondeterministic

    gnrc_sixlowpan_frag_sfr_send(pkt, ctx, page);
}
