#include <stdlib.h>
#include "net/gnrc/rpl/srh.h"

void harness() {
    // Declare parameters exactly as in the function signature
    ipv6_hdr_t *ipv6;
    gnrc_rpl_srh_t *rh;
    void **err_ptr;

    // Allocate ipv6 header pointer with minimum size constraint
    size_t ipv6_len;
    __CPROVER_assume(ipv6_len >= sizeof(ipv6_hdr_t));
    ipv6 = (ipv6_hdr_t *)malloc(ipv6_len);

    // Allocate RPL SRH pointer with minimum size constraint
    size_t rh_len;
    __CPROVER_assume(rh_len >= sizeof(gnrc_rpl_srh_t));
    rh = (gnrc_rpl_srh_t *)malloc(rh_len);

    // Allocate err_ptr (pointer to pointer), no extra constraints
    size_t err_ptr_len;
    err_ptr = (void **)malloc(err_ptr_len);

    // Call the target function
    gnrc_rpl_srh_process(ipv6, rh, err_ptr);
}
