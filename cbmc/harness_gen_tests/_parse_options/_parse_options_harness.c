#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#include "net/gnrc/rpl/structs.h"
#include "net/ipv6/addr.h"

/* extern declaration for the target function */
extern bool _parse_options(int msg_type, gnrc_rpl_instance_t *inst, gnrc_rpl_opt_t *opt,
                           uint16_t len, ipv6_addr_t *src, uint32_t *included_opts);

void harness(void) {
    /* Declare parameters exactly as in the function signature */
    int msg_type;
    gnrc_rpl_instance_t *inst;
    gnrc_rpl_opt_t *opt;
    uint16_t len;
    ipv6_addr_t *src;
    uint32_t *included_opts;

    /* Allocate and assume non-NULL for pointers to structs */
    inst = (gnrc_rpl_instance_t *)malloc(sizeof(gnrc_rpl_instance_t));
    __CPROVER_assume(inst != NULL);

    opt = (gnrc_rpl_opt_t *)malloc(sizeof(gnrc_rpl_opt_t));
    __CPROVER_assume(opt != NULL);

    src = (ipv6_addr_t *)malloc(sizeof(ipv6_addr_t));
    __CPROVER_assume(src != NULL);

    /* For pointer to primitive type, allocate with a size variable */
    uint16_t included_opts_len = 1;
    included_opts = (uint32_t *)malloc(sizeof(uint32_t) * included_opts_len);
    __CPROVER_assume(included_opts != NULL);

    /* Call the function under test */
    (void)_parse_options(msg_type, inst, opt, len, src, included_opts);
}
