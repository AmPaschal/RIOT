/**
 * @file _iphc_ipv6_encode.c
 * @brief Implements the proof harness for _iphc_ipv6_encode function.
 */

#include "net/gnrc.h"

/**
 * @brief Starting point for formal analysis
 * 
 */
void harness(void)
{

    // Unconstrained structs:

    gnrc_pktsnip_t pkt;
    gnrc_netif_hdr_t netif_hdr;
    gnrc_netif_t iface;

    // Allocate some data
    // (Not sure what size to use yet)

    size_t len;

    __CPROVER_assume(len >= 100);

    uint8_t *data = (uint8_t*)malloc(sizeof(uint8_t) * len);

    size_t size = _iphc_ipv6_encode(&pkt, &netif_hdr, &iface, data);
}
