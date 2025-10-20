#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>

#include "net/ipv6/hdr.h"
#include "net/gnrc/rpl/srh.h"

void harness() {
    ipv6_hdr_t *ipv6 = (ipv6_hdr_t *)malloc(sizeof(ipv6_hdr_t));
    __CPROVER_assume(ipv6 != NULL);

    gnrc_rpl_srh_t *rh = (gnrc_rpl_srh_t *)malloc(sizeof(gnrc_rpl_srh_t));
    __CPROVER_assume(rh != NULL);

    void *err_local = NULL;
    void **err_ptr = &err_local;

    gnrc_rpl_srh_process(ipv6, rh, err_ptr);
}
