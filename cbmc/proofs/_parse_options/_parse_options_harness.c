/**
 * @file _rbuf_add_harness.c
 * @brief Implements the proof harness for _parse_options function.
 */

#include <stdint.h>

#include "net/gnrc/rpl/structs.h"

/**
 * @brief Starting point for formal analysis
 * 
 */
void harness(void)
{
    // Model input arguments
    int msg_type;

    gnrc_rpl_instance_t inst;
    gnrc_rpl_opt_t opt;

    ipv6_addr_t src;

    uint16_t len;
    uint32_t included_opts;

    bool res = _parse_options(msg_type, &inst, &opt, len, &src, &included_opts);
}
