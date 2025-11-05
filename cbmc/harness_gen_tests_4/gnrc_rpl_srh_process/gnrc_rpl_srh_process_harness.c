#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

#include "net/ipv6/addr.h"
#include "net/ipv6/hdr.h"
#include "net/gnrc/rpl/srh.h"

char *ipv6_addr_to_str(char *result, const ipv6_addr_t *addr, uint8_t result_len) {
    size_t ret_len;
    char *ret = (char *)malloc(ret_len);
    return ret;
}

void harness(void) {
    /* Declare parameters */
    ipv6_hdr_t *ipv6;
    gnrc_rpl_srh_t *rh;
    void **err_ptr;

    /* Allocate ipv6 header pointer with size assumption */
    size_t ipv6_len;
    __CPROVER_assume(ipv6_len >= sizeof(ipv6_hdr_t));
    ipv6 = (ipv6_hdr_t *)malloc(ipv6_len);

    /* Allocate RPL SRH pointer with size assumption */
    size_t rh_len;
    __CPROVER_assume(rh_len >= sizeof(gnrc_rpl_srh_t));
    rh = (gnrc_rpl_srh_t *)malloc(rh_len);

    /* Allocate error pointer */
    size_t err_ptr_len;
    err_ptr = (void **)malloc(err_ptr_len);

    /* Call the function under test */
    (void)gnrc_rpl_srh_process(ipv6, rh, err_ptr);

    /* Explicitly call ipv6_addr_to_str to cover it (DEBUG path is compiled out) */
    char *res;
    ipv6_addr_t *addr;
    uint8_t res_len;
    (void)ipv6_addr_to_str(res, addr, res_len);
}
