#include <stdlib.h>
#include <string.h>

#include "net/gnrc/rpl/srh.h"

void harness() {
    ipv6_hdr_t *ipv6 = (ipv6_hdr_t *)malloc(sizeof(ipv6_hdr_t));
    __CPROVER_assume(ipv6 != NULL);

    uint8_t rh_len;
    __CPROVER_assume(rh_len >= sizeof(gnrc_rpl_srh_t));

    gnrc_rpl_srh_t *rh = (gnrc_rpl_srh_t *)malloc(rh_len);
    __CPROVER_assume(rh != NULL);

    void *err_target = NULL;
    void **err_ptr = &err_target;

    gnrc_rpl_srh_process(ipv6, rh, err_ptr);
}
