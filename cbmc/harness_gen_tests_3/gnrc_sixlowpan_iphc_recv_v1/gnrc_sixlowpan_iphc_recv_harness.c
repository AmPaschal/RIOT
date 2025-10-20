#include <stddef.h>
#include <stdlib.h>
#include <stdint.h>

#include "net/gnrc/sixlowpan/iphc.h"

void harness() {
    /* Parameters as in the function signature */
    size_t sixlo_len;
    __CPROVER_assume(sixlo_len >= sizeof(gnrc_pktsnip_t));
    gnrc_pktsnip_t *sixlo = (gnrc_pktsnip_t *)malloc(sixlo_len);

    size_t rbuf_ptr_len;
    void *rbuf_ptr = malloc(rbuf_ptr_len);

    unsigned page;

    gnrc_sixlowpan_iphc_recv(sixlo, rbuf_ptr, page);
}
