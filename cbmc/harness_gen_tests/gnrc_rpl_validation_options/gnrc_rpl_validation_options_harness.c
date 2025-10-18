#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

#include "net/gnrc/rpl.h"
#include "gnrc_rpl_internal/validation.h"

void harness() {
    int msg_type;

    gnrc_rpl_instance_t *inst = (gnrc_rpl_instance_t *)malloc(sizeof(gnrc_rpl_instance_t));
    __CPROVER_assume(inst != NULL);

    gnrc_rpl_opt_t *opt = (gnrc_rpl_opt_t *)malloc(sizeof(gnrc_rpl_opt_t));
    __CPROVER_assume(opt != NULL);

    uint16_t len;

    /* Safety assumptions to avoid out-of-bounds due to pointer advances in the function */
    __CPROVER_assume(opt->type != GNRC_RPL_OPT_PAD1);
    __CPROVER_assume((len == 0) || (len <= (uint16_t)(opt->length + (uint16_t)sizeof(gnrc_rpl_opt_t))));

    (void)gnrc_rpl_validation_options(msg_type, inst, opt, len);
}
