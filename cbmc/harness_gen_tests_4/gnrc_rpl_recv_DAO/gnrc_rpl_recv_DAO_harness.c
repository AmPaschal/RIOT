#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include "net/gnrc/netif.h"
#include "net/gnrc/netif/hdr.h"
#include "net/gnrc/netif/internal.h"
#include "net/gnrc/icmpv6.h"
#include "net/gnrc/ipv6/hdr.h"
#include "net/ipv6/addr.h"
#include "net/gnrc/rpl/dodag.h"
#include "net/gnrc/rpl/of_manager.h"
#include "net/gnrc/rpl/structs.h"
#include "net/gnrc/rpl.h"

/* Stubs */

gnrc_netif_t *gnrc_netif_get_by_pid(kernel_pid_t pid) {
    size_t netif_len;
    __CPROVER_assume(netif_len >= sizeof(gnrc_netif_t));
    gnrc_netif_t *netif = (gnrc_netif_t *)malloc(netif_len);
    return netif;
}

gnrc_rpl_instance_t *gnrc_rpl_instance_get(uint8_t instance_id) {
    size_t inst_len;
    __CPROVER_assume(inst_len >= sizeof(gnrc_rpl_instance_t));
    gnrc_rpl_instance_t *inst = (gnrc_rpl_instance_t *)malloc(inst_len);
    return inst;
}

gnrc_pktsnip_t *gnrc_icmpv6_build(gnrc_pktsnip_t *next, uint8_t type, uint8_t code, size_t size) {
    size_t snip_len;
    __CPROVER_assume(snip_len >= sizeof(gnrc_pktsnip_t));
    gnrc_pktsnip_t *snip = (gnrc_pktsnip_t *)malloc(snip_len);
    return snip;
}

gnrc_pktsnip_t *gnrc_netif_hdr_build(const uint8_t *src, uint8_t src_len, const uint8_t *dst, uint8_t dst_len) {
    size_t snip_len;
    __CPROVER_assume(snip_len >= sizeof(gnrc_pktsnip_t));
    gnrc_pktsnip_t *snip = (gnrc_pktsnip_t *)malloc(snip_len);
    return snip;
}

char *ipv6_addr_to_str(char *result, const ipv6_addr_t *addr, uint8_t result_len) {
    size_t ret_len;
    char *ret = (char *)malloc(ret_len);
    return ret;
}

gnrc_rpl_of_t *gnrc_rpl_get_of_for_ocp(uint16_t ocp) {
    size_t of_len;
    __CPROVER_assume(of_len >= sizeof(gnrc_rpl_of_t));
    gnrc_rpl_of_t *of = (gnrc_rpl_of_t *)malloc(of_len);
    return of;
}

gnrc_netif_t *gnrc_netif_iter(const gnrc_netif_t *prev) {
    size_t netif_len;
    __CPROVER_assume(netif_len >= sizeof(gnrc_netif_t));
    gnrc_netif_t *netif = (gnrc_netif_t *)malloc(netif_len);
    return netif;
}

ipv6_addr_t *gnrc_netif_ipv6_addr_best_src(gnrc_netif_t *netif, const ipv6_addr_t *dst, bool ll_only) {
    size_t addr_len;
    __CPROVER_assume(addr_len >= sizeof(ipv6_addr_t));
    ipv6_addr_t *addr = (ipv6_addr_t *)malloc(addr_len);
    return addr;
}

gnrc_pktsnip_t *gnrc_ipv6_hdr_build(gnrc_pktsnip_t *payload, const ipv6_addr_t *src, const ipv6_addr_t *dst) {
    size_t snip_len;
    __CPROVER_assume(snip_len >= sizeof(gnrc_pktsnip_t));
    gnrc_pktsnip_t *snip = (gnrc_pktsnip_t *)malloc(snip_len);
    return snip;
}

void harness() {
    size_t dao_len;
    __CPROVER_assume(dao_len >= sizeof(gnrc_rpl_dao_t));
    gnrc_rpl_dao_t *dao = (gnrc_rpl_dao_t *)malloc(dao_len);

    kernel_pid_t iface;

    size_t src_len;
    ipv6_addr_t *src = (ipv6_addr_t *)malloc(src_len);

    size_t dst_len;
    ipv6_addr_t *dst = (ipv6_addr_t *)malloc(dst_len);

    uint16_t len;

    gnrc_rpl_recv_DAO(dao, iface, src, dst, len);
}
