/**
 * @file _rbuf_add_harness.c
 * @brief Implements the proof harness for _rbuf_add function.
 */

#include "net/gnrc/pkt.h"
#include "net/gnrc/netif/hdr.h"
#include "net/gnrc/netif.h"

void mutex_lock(mutex_t *mutex) {}

void mutex_unlock(mutex_t *mutex) {}

uint8_t bitarithm_clzb(uint8_t x) {
    uint8_t val;

    return val;
}

uint8_t ipv6_addr_match_prefix(const ipv6_addr_t *a, const ipv6_addr_t *b)
{
    // Read from values 

    uint8_t prefix_len;

    return prefix_len;
}

bool _compressible_nh(uint8_t nh)
{
    bool val;
    return false;
}

void _assert_panic(void) {
    __CPROVER_assume(false);
}

/**
 * @brief Starting point for formal analysis
 * 
 */
void harness(void)
{

    // Input structs:

    gnrc_pktsnip_t pkt;
    gnrc_netif_hdr_t netif_hdr;
    gnrc_netif_t *iface;

    // Determine if we are adding IPv6 header:

    bool add;

    if (add) {

        // Packet immediately after MUST be ipv6_hdr_t

        pkt.next = (gnrc_pktsnip_t *)malloc(sizeof(gnrc_pktsnip_t));

        __CPROVER_assume(pkt.next != NULL);

        // Allocate IPV6 header data:

        pkt.next->size = sizeof(ipv6_hdr_t);
        pkt.next->data = (ipv6_hdr_t *)malloc(sizeof(ipv6_hdr_t));

        __CPROVER_assume(pkt.next->data != NULL);

        // Determine how many packet snips to model:
        // For now we will only model 11, there will be one modeled for the header: 

        uint32_t snips;

        __CPROVER_assume(snips <= 10);

        gnrc_pktsnip_t *npkt = pkt.next;

        // Properly model each packet snip:

        for (int i = 0; i < snips; ++i) {

            // Allocate this snip:

            npkt->next = (gnrc_pktsnip_t *)malloc(sizeof(gnrc_pktsnip_t));

            // Will NOT be NULL:

            __CPROVER_assume(npkt->next != NULL);

            // Model some input data:

            __CPROVER_assume(npkt->next->size <= 50);

            npkt->next->data = malloc(npkt->next->size);

            __CPROVER_assume(npkt->next->data != NULL);

            // Update new snip to model:

            npkt = npkt->next;
        }

        // Finally, make next pointer NULL:

        npkt->next = NULL;
    }

    else {
        // Just make next pointer NULL:

        pkt.next = NULL;
    }

    gnrc_pktsnip_t *res = _iphc_encode(&pkt, &netif_hdr, &iface);
}
