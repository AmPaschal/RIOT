/**
 * @file _iphc_ipv6_encode.c
 * @brief Implements the proof harness for _iphc_ipv6_encode function.
 */

#include "net/gnrc.h"

// Do nothing when locking a mutex
inline void mutex_lock(mutex_t *mutex) {}

uint8_t ipv6_addr_match_prefix(const ipv6_addr_t *a, const ipv6_addr_t *b) {
    uint8_t prefix_len;

    return prefix_len;
}

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

    // Create a next value for the packetsnip:

    pkt.next = (gnrc_pktsnip_t *)malloc(sizeof(gnrc_pktsnip_t));

    // Determine if next is NULL:

    if (pkt.next != NULL) {
        // Allocate a IPv6 header in the data:

        pkt.next->data = malloc(sizeof(ipv6_hdr_t));

        // Allocated data will NOT be null:

        __CPROVER_assume(pkt.next->data != NULL);

        pkt.next->size = sizeof(ipv6_hdr_t);
    }

    // Allocate some data
    // (Not sure what size to use yet)

    size_t len;

    __CPROVER_assume(len >= 50);

    uint8_t *data = (uint8_t*)malloc(sizeof(uint8_t) * len);

    // Data will NOT be NULL:

    __CPROVER_assume(data != NULL);

    size_t size = _iphc_ipv6_encode(&pkt, &netif_hdr, &iface, data);
}
