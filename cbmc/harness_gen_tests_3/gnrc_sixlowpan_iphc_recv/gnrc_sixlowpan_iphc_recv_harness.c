#include <stdlib.h>
#include <stddef.h>
#include "net/gnrc/pkt.h"

/* Forward declaration in case no public header declares it */
void gnrc_sixlowpan_iphc_recv(gnrc_pktsnip_t *sixlo, void *rbuf_ptr, unsigned page);

void harness(void) {
    /* Declare and initialize gnrc_pktsnip_t *sixlo */
    size_t sixlo_len;
    __CPROVER_assume(sixlo_len >= sizeof(gnrc_pktsnip_t));
    gnrc_pktsnip_t *sixlo = (gnrc_pktsnip_t *)malloc(sixlo_len);

    /* Declare and initialize void *rbuf_ptr */
    size_t rbuf_ptr_len;
    void *rbuf_ptr = malloc(rbuf_ptr_len);

    /* Declare unsigned page */
    unsigned page;

    /* Call the target function */
    gnrc_sixlowpan_iphc_recv(sixlo, rbuf_ptr, page);
}
