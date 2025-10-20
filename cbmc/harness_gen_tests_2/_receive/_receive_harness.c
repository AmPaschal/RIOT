#include <stdlib.h>
#include "net/gnrc/pkt.h"

/* Forward declaration of the target function */
int _receive(gnrc_pktsnip_t *pkt);

void harness(void) {
    /* Allocate the struct pointer parameter as required */
    gnrc_pktsnip_t *pkt = (gnrc_pktsnip_t *)malloc(sizeof(gnrc_pktsnip_t));
    __CPROVER_assume(pkt != NULL);

    /* Optionally, fields may be left unconstrained for CBMC to explore */

    /* Invoke the target function */
    (void)_receive(pkt);
}
