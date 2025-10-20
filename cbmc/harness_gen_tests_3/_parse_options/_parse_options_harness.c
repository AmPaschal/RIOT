#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include "net/gnrc/rpl/structs.h"

// Function prototype for the target under test
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
