#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#include "net/gnrc/rpl/structs.h"

/* Forward declaration of the function under test */
extern bool _parse_options(int msg_type,
                           gnrc_rpl_instance_t *inst,
                           gnrc_rpl_opt_t *opt,
                           uint16_t len,
                           ipv6_addr_t *src,
                           uint32_t *included_opts);

void harness() {
    /* Parameters */
    int msg_type;

    gnrc_rpl_instance_t *inst = (gnrc_rpl_instance_t *)malloc(sizeof(gnrc_rpl_instance_t));
    __CPROVER_assume(inst != NULL);

    gnrc_rpl_opt_t *opt = (gnrc_rpl_opt_t *)malloc(sizeof(gnrc_rpl_opt_t));
    __CPROVER_assume(opt != NULL);

    /* Set len to 0 to avoid parsing beyond the single option header we allocated */
    uint16_t len = 0;

    ipv6_addr_t *src = (ipv6_addr_t *)malloc(sizeof(ipv6_addr_t));
    __CPROVER_assume(src != NULL);

    /* Pointer to primitive type: allocate with a size variable */
    size_t included_opts_len;
    __CPROVER_assume(included_opts_len > 0);
    uint32_t *included_opts = (uint32_t *)malloc(sizeof(uint32_t) * included_opts_len);
    __CPROVER_assume(included_opts != NULL);

    /* Call the function under test */
    (void)_parse_options(msg_type, inst, opt, len, src, included_opts);
}
