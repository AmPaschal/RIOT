#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>
#include "sched.h"
#include "net/gnrc/rpl.h"

#include "net/gnrc/netif.h"
#include "net/gnrc/netif/internal.h"
#include "net/gnrc/netif/hdr.h"
#include "net/ipv6/addr.h"
#include "net/gnrc/icmpv6.h"
#include "net/gnrc/ipv6/hdr.h"
#include "net/gnrc/rpl/of_manager.h"
#include "net/gnrc/rpl/dodag.h"
#include "net/gnrc/pkt.h"

// Global instance returned by gnrc_rpl_instance_get
static gnrc_rpl_instance_t *g_inst;

// Stub: gnrc_netif_get_by_pid
// Signature: gnrc_netif_t *gnrc_netif_get_by_pid(kernel_pid_t pid);
gnrc_netif_t *gnrc_netif_get_by_pid(kernel_pid_t pid) {
    size_t netif_len;
    __CPROVER_assume(netif_len >= sizeof(gnrc_netif_t));
    gnrc_netif_t *netif = (gnrc_netif_t *)malloc(netif_len);
    return netif;
}

// Stub: gnrc_netif_ipv6_addr_best_src
// Signature: ipv6_addr_t *gnrc_netif_ipv6_addr_best_src(gnrc_netif_t *netif, const ipv6_addr_t *dst, bool ll_only);
ipv6_addr_t *gnrc_netif_ipv6_addr_best_src(gnrc_netif_t *netif, const ipv6_addr_t *dst, bool ll_only) {
    size_t addr_len;
    __CPROVER_assume(addr_len >= sizeof(ipv6_addr_t));
    ipv6_addr_t *addr = (ipv6_addr_t *)malloc(addr_len);
    return addr;
}

// Stub: gnrc_netif_hdr_build
// Signature: gnrc_pktsnip_t *gnrc_netif_hdr_build(const uint8_t *src, uint8_t src_len, const uint8_t *dst, uint8_t dst_len);
gnrc_pktsnip_t *gnrc_netif_hdr_build(const uint8_t *src, uint8_t src_len, const uint8_t *dst, uint8_t dst_len) {
    size_t snip_len;
    __CPROVER_assume(snip_len >= sizeof(gnrc_pktsnip_t));
    gnrc_pktsnip_t *snip = (gnrc_pktsnip_t *)malloc(snip_len);
    return snip;
}

// Stub: ipv6_addr_to_str
// Signature: char *ipv6_addr_to_str(char *result, const ipv6_addr_t *addr, uint8_t result_len);
char *ipv6_addr_to_str(char *result, const ipv6_addr_t *addr, uint8_t result_len) {
    // Minimal model: return result without imposing constraints
    return result;
}

// Stub: gnrc_icmpv6_build
// Signature: gnrc_pktsnip_t *gnrc_icmpv6_build(gnrc_pktsnip_t *next, uint8_t type, uint8_t code, size_t size);
gnrc_pktsnip_t *gnrc_icmpv6_build(gnrc_pktsnip_t *next, uint8_t type, uint8_t code, size_t size) {
    size_t snip_len;
    __CPROVER_assume(snip_len >= sizeof(gnrc_pktsnip_t));
    gnrc_pktsnip_t *snip = (gnrc_pktsnip_t *)malloc(snip_len);
    return snip;
}

// Stub: gnrc_ipv6_hdr_build
// Signature: gnrc_pktsnip_t *gnrc_ipv6_hdr_build(gnrc_pktsnip_t *payload, const ipv6_addr_t *src, const ipv6_addr_t *dst);
gnrc_pktsnip_t *gnrc_ipv6_hdr_build(gnrc_pktsnip_t *payload, const ipv6_addr_t *src, const ipv6_addr_t *dst) {
    size_t snip_len;
    __CPROVER_assume(snip_len >= sizeof(gnrc_pktsnip_t));
    gnrc_pktsnip_t *snip = (gnrc_pktsnip_t *)malloc(snip_len);
    return snip;
}

// Stub: gnrc_rpl_get_of_for_ocp
// Signature: gnrc_rpl_of_t *gnrc_rpl_get_of_for_ocp(uint16_t ocp);
gnrc_rpl_of_t *gnrc_rpl_get_of_for_ocp(uint16_t ocp) {
    size_t of_len;
    __CPROVER_assume(of_len >= sizeof(gnrc_rpl_of_t));
    gnrc_rpl_of_t *of = (gnrc_rpl_of_t *)malloc(of_len);
    return of;
}

// Stub: gnrc_rpl_instance_get returns the prepared global instance
// Signature: gnrc_rpl_instance_t *gnrc_rpl_instance_get(uint8_t instance_id);
gnrc_rpl_instance_t *gnrc_rpl_instance_get(uint8_t instance_id) {
    return g_inst;
}

// Stub: gnrc_netif_iter
// Signature: gnrc_netif_t *gnrc_netif_iter(const gnrc_netif_t *prev);
gnrc_netif_t *gnrc_netif_iter(const gnrc_netif_t *prev) {
    size_t netif_len;
    __CPROVER_assume(netif_len >= sizeof(gnrc_netif_t));
    gnrc_netif_t *netif = (gnrc_netif_t *)malloc(netif_len);
    return netif;
}

void harness() {
    // Pointer argument: gnrc_rpl_dao_t *dao
    size_t dao_len;
    // Ensure room for DODAG ID immediately after DAO header (needed when D-bit is set)
    __CPROVER_assume(dao_len >= sizeof(gnrc_rpl_dao_t) + sizeof(ipv6_addr_t));
    gnrc_rpl_dao_t *dao = (gnrc_rpl_dao_t *)malloc(dao_len);

    // Prepare a global instance that gnrc_rpl_instance_get will return
    size_t inst_len;
    __CPROVER_assume(inst_len >= sizeof(gnrc_rpl_instance_t));
    g_inst = (gnrc_rpl_instance_t *)malloc(inst_len);

    // Force D-bit set so the DODAG ID branch is taken
    dao->k_d_flags |= GNRC_RPL_DAO_D_BIT;

    // Make the instance's DODAG ID equal to the DODAG ID carried in the DAO (at dao+1)
    ipv6_addr_t *dao_dodag_id = (ipv6_addr_t *)(dao + 1);
    g_inst->dodag.dodag_id = *dao_dodag_id;

    // Optional: avoid early leaf-node return (not required for 1209 but safe)
    g_inst->dodag.node_status = 0; // any value different from GNRC_RPL_LEAF_NODE is fine

    // Scalar argument: kernel_pid_t iface
    kernel_pid_t iface;

    // Pointer argument: ipv6_addr_t *src
    size_t src_len;
    __CPROVER_assume(src_len >= sizeof(ipv6_addr_t));
    ipv6_addr_t *src = (ipv6_addr_t *)malloc(src_len);

    // Pointer argument: ipv6_addr_t *dst
    size_t dst_len;
    __CPROVER_assume(dst_len >= sizeof(ipv6_addr_t));
    ipv6_addr_t *dst = (ipv6_addr_t *)malloc(dst_len);

    // Scalar argument: uint16_t len
    uint16_t len;
    // Ensure len satisfies validation when D-bit is set and allows skipping DODAG ID
    __CPROVER_assume(len >= sizeof(gnrc_rpl_dao_t) + sizeof(icmpv6_hdr_t) + sizeof(ipv6_addr_t));

    gnrc_rpl_recv_DAO(dao, iface, src, dst, len);
}
