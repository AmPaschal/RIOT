#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include "sched.h"
#include "net/gnrc/rpl.h"

void harness() {
    // Pointer argument: gnrc_rpl_dao_t *dao
    size_t dao_len;
    __CPROVER_assume(dao_len >= sizeof(gnrc_rpl_dao_t));
    gnrc_rpl_dao_t *dao = (gnrc_rpl_dao_t *)malloc(dao_len);

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

    gnrc_rpl_recv_DAO(dao, iface, src, dst, len);
}
