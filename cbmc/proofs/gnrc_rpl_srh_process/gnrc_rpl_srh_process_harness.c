/**
 * @file _rbuf_add_harness.c
 * @brief Implements the proof harness for _rbuf_add function.
 */

#include "net/gnrc/rpl/srh.h"

/**
 * @brief Starting point for formal analysis
 * 
 */
void harness(void)
{

    // Unconstrained struts:

    ipv6_hdr_t ipv6;

    // Allocate two RPL SRH structs:

    gnrc_rpl_srh_t *rh = (gnrc_rpl_srh_t *)malloc(2 * sizeof(gnrc_rpl_srh_t));

    // Ensure we can't be NULL:

    __CPROVER_assume(rh != NULL);

    char *point;

    int res = gnrc_rpl_srh_process(&ipv6, rh, &point);
}
