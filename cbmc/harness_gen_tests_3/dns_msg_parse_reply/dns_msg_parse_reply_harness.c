#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

#include "net/dns/msg.h"

void harness() {
    /* Declare parameters exactly as in the function signature */
    const uint8_t *buf;
    size_t len;
    int family;
    void *addr_out;
    uint32_t *ttl;

    /* Allocate memory for pointer arguments using size variables */
    size_t buf_len;
    uint8_t *buf_alloc = malloc(buf_len);
    buf = buf_alloc;

    size_t addr_out_len;
    void *addr_out_alloc = malloc(addr_out_len);
    addr_out = addr_out_alloc;

    size_t ttl_len;
    uint32_t *ttl_alloc = malloc(ttl_len);
    ttl = ttl_alloc;

    /* Call the function under test */
    (void)dns_msg_parse_reply(buf, len, family, addr_out, ttl);
}
