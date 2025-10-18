#include <stdlib.h>
#include "net/gnrc/pkt.h"

/* Forward declaration of the function under test */
int _receive(gnrc_pktsnip_t *pkt);

void harness() {
    gnrc_pktsnip_t *pkt = (gnrc_pktsnip_t *)malloc(sizeof(gnrc_pktsnip_t));
    __CPROVER_assume(pkt != NULL);

    _receive(pkt);
}
