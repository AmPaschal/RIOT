#include <stdlib.h>
#include "net/gnrc/rpl.h"
#include "net/ipv6/addr.h"
#include "sched.h"

void harness(void) {
    gnrc_rpl_dao_t *dao = malloc(sizeof(gnrc_rpl_dao_t));
    __CPROVER_assume(dao != NULL);

    kernel_pid_t iface;

    ipv6_addr_t *src = malloc(sizeof(ipv6_addr_t));
    __CPROVER_assume(src != NULL);

    ipv6_addr_t *dst = malloc(sizeof(ipv6_addr_t));
    __CPROVER_assume(dst != NULL);

    uint16_t len;

    gnrc_rpl_recv_DAO(dao, iface, src, dst, len);
}
