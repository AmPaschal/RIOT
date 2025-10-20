#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#include "gnrc_rpl_internal/validation.h"

void harness() {
    int msg_type;

    gnrc_rpl_instance_t *inst = malloc(sizeof(gnrc_rpl_instance_t));
    __CPROVER_assume(inst != NULL);

    gnrc_rpl_opt_t *opt = malloc(sizeof(gnrc_rpl_opt_t));
    __CPROVER_assume(opt != NULL);

    uint16_t len;

    gnrc_rpl_validation_options(msg_type, inst, opt, len);
}
