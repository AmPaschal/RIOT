#include <stdlib.h>
#include <stddef.h>
#include "net/gnrc/pkt.h"

/* Forward declaration in case no public header declares it */
int _receive(gnrc_pktsnip_t *pkt);

void harness(void) {
    size_t pkt_len;
    __CPROVER_assume(pkt_len >= sizeof(gnrc_pktsnip_t));
    gnrc_pktsnip_t *pkt = (gnrc_pktsnip_t *)malloc(pkt_len);

    _receive(pkt);
}