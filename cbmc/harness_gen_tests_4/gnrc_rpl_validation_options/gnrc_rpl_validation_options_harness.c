#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>

#include "net/gnrc/rpl.h"

void harness() {
    int msg_type;

    size_t inst_len;
    __CPROVER_assume(inst_len >= sizeof(gnrc_rpl_instance_t));
    gnrc_rpl_instance_t *inst = (gnrc_rpl_instance_t *)malloc(inst_len);

    size_t opt_len;
    __CPROVER_assume(opt_len >= sizeof(gnrc_rpl_opt_t));
    gnrc_rpl_opt_t *opt = (gnrc_rpl_opt_t *)malloc(opt_len);

    uint16_t len;

    gnrc_rpl_validation_options(msg_type, inst, opt, len);
}
