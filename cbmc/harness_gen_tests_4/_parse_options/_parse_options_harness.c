#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>

#include "net/ipv6/addr.h"
#include "net/gnrc/netif.h"
#include "net/gnrc/rpl/of_manager.h"
#include "net/gnrc/rpl/structs.h"

/* Stubs required by the harness */
/* Signature: char *ipv6_addr_to_str(char *result, const ipv6_addr_t *addr, uint8_t result_len); */
char *ipv6_addr_to_str(char *result, const ipv6_addr_t *addr, uint8_t result_len) {
    size_t retval_len;
    char *retval = (char *)malloc(retval_len);
    return retval;
}

/* Signature: gnrc_netif_t *gnrc_netif_get_by_pid(kernel_pid_t pid); */
gnrc_netif_t *gnrc_netif_get_by_pid(kernel_pid_t pid) {
    size_t netif_len;
    __CPROVER_assume(netif_len >= sizeof(gnrc_netif_t));
    gnrc_netif_t *netif = (gnrc_netif_t *)malloc(netif_len);
    return netif;
}

/* Signature: gnrc_rpl_of_t *gnrc_rpl_get_of_for_ocp(uint16_t ocp); */
gnrc_rpl_of_t *gnrc_rpl_get_of_for_ocp(uint16_t ocp) {
    size_t of_len;
    __CPROVER_assume(of_len >= sizeof(gnrc_rpl_of_t));
    gnrc_rpl_of_t *of = (gnrc_rpl_of_t *)malloc(of_len);
    return of;
}

/* Extern declaration of the function under test */
bool _parse_options(int msg_type, gnrc_rpl_instance_t *inst, gnrc_rpl_opt_t *opt,
                    uint16_t len, ipv6_addr_t *src, uint32_t *included_opts);

void harness() {
    int msg_type;

    size_t inst_len;
    __CPROVER_assume(inst_len >= sizeof(gnrc_rpl_instance_t));
    gnrc_rpl_instance_t *inst = (gnrc_rpl_instance_t *)malloc(inst_len);

    size_t opt_len;
    __CPROVER_assume(opt_len >= sizeof(gnrc_rpl_opt_t));
    gnrc_rpl_opt_t *opt = (gnrc_rpl_opt_t *)malloc(opt_len);

    uint16_t len;

    size_t src_len;
    __CPROVER_assume(src_len >= sizeof(ipv6_addr_t));
    ipv6_addr_t *src = (ipv6_addr_t *)malloc(src_len);

    size_t included_opts_len;
    uint32_t *included_opts = (uint32_t *)malloc(included_opts_len);

    (void)_parse_options(msg_type, inst, opt, len, src, included_opts);
}
