#include <stdlib.h>
#include "net/gnrc/sixlowpan/frag/sfr.h"

void harness() {
    // Declare parameters exactly as in the function signature
    gnrc_pktsnip_t *pkt;
    void *ctx;
    unsigned page;

    // Allocate and initialize pointer parameters per instructions
    size_t pkt_len;
    __CPROVER_assume(pkt_len >= sizeof(gnrc_pktsnip_t));
    pkt = (gnrc_pktsnip_t *)malloc(pkt_len);

    size_t ctx_len;
    ctx = malloc(ctx_len);

    // Call the target function
    gnrc_sixlowpan_frag_sfr_send(pkt, ctx, page);
}
