/**
 * @file _iphc_ipv6_encode.c
 * @brief Implements the proof harness for _iphc_ipv6_encode function.
 */

#include "net/gnrc.h"

// Do nothing when locking a mutex
inline void mutex_lock(mutex_t *mutex) {}

void rmutex_lock(rmutex_t *rmutex) {}

void rmutex_unlock(rmutex_t *rmutex) {}

uint32_t _xtimer_now(void) {}

void _assert_panic(void) {
    __CPROVER_assume(false);
}

uint8_t ipv6_addr_match_prefix(const ipv6_addr_t *a, const ipv6_addr_t *b) {
    uint8_t prefix_len;

    return prefix_len;
}

int gnrc_netif_ipv6_get_iid(gnrc_netif_t *netif, eui64_t *iid) {

    // Create iid:

    iid = (eui64_t*)malloc(sizeof(eui64_t));

    int res;

    return res;
}

int gnrc_netif_hdr_ipv6_iid_from_dst(const gnrc_netif_t *netif,
                                     const gnrc_netif_hdr_t *hdr,
                                     eui64_t *iid)
{

    // Allocate some iid data:

    iid = (eui64_t *)malloc(sizeof(eui64_t));

    // Just return unconstrained int:

    int val;

    return val;
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

        // pkt.next->data = malloc(sizeof(ipv6_hdr_t));
        pkt.next->data = malloc(pkt.next->size);  // Use unconstrained size

        // Allocated data will NOT be null:

        // __CPROVER_assume(pkt.next->data != NULL);

        // Unconstrained size
        // pkt.next->size = sizeof(ipv6_hdr_t);
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
