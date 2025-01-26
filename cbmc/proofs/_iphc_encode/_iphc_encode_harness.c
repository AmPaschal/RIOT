/**
 * @file _rbuf_add_harness.c
 * @brief Implements the proof harness for _rbuf_add function.
 */

#include "net/gnrc/pkt.h"
#include "net/gnrc/netif/hdr.h"
#include "net/gnrc/netif.h"

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

    gnrc_pktsnip_t *res = _iphc_encode(&pkt, &netif_hdr, &iface);
}
