/**
 * @file _rbuf_add_harness.c
 * @brief Implements the proof harness for _rbuf_add function.
 */

#include "net/gnrc/rpl/srh.h"
#include "net/gnrc/netif.h"

gnrc_netif_t *gnrc_netif_get_by_ipv6_addr(const ipv6_addr_t *addr)
{
    gnrc_netif_t *netif = (gnrc_netif_t *)malloc(sizeof(gnrc_netif_t));

    return netif;
}

// Stubbed function for speed reasons
void *_contains_multiple_of_my_addr(const ipv6_addr_t *dst,
                                    const gnrc_rpl_srh_t *rh,
                                    unsigned num_addr,
                                    unsigned compri_addr_len)
{

    // Allocate some junk data to return:
    // (Could be NULL)

    return malloc(1);
}

/**
 * @brief Starting point for formal analysis
 * 
 */
void harness(void)
{

    // Unconstrained struts:

    ipv6_hdr_t ipv6;

    // Allocate input headers
    // The function can read a LOT of data, so we allocate a good amount

    gnrc_rpl_srh_t *rh = (gnrc_rpl_srh_t *)malloc(sizeof(gnrc_rpl_srh_t) + 500);

    // Ensure we can't be NULL:

    __CPROVER_assume(rh != NULL);

    char *point;

    int res = gnrc_rpl_srh_process(&ipv6, rh, &point);
}
