#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#include "net/ipv6/addr.h"
#include "net/gnrc/rpl/structs.h"

// Target function declaration
extern bool _parse_options(int msg_type,
                           gnrc_rpl_instance_t *inst,
                           gnrc_rpl_opt_t *opt,
                           uint16_t len,
                           ipv6_addr_t *src,
                           uint32_t *included_opts);

void harness() {
    // Parameters as in the function signature
    int msg_type;

    gnrc_rpl_instance_t *inst = (gnrc_rpl_instance_t *)malloc(sizeof(gnrc_rpl_instance_t));
    __CPROVER_assume(inst != NULL);

    gnrc_rpl_opt_t *opt = (gnrc_rpl_opt_t *)malloc(sizeof(gnrc_rpl_opt_t));
    __CPROVER_assume(opt != NULL);

    uint16_t len;

    ipv6_addr_t *src = (ipv6_addr_t *)malloc(sizeof(ipv6_addr_t));
    __CPROVER_assume(src != NULL);

    uint16_t included_opts_len;
    uint32_t *included_opts = (uint32_t *)malloc(sizeof(uint32_t) * included_opts_len);

    (void)_parse_options(msg_type, inst, opt, len, src, included_opts);
}
