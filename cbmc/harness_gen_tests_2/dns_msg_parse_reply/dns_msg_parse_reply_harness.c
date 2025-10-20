#include <stdlib.h>
#include <stdint.h>

#include "net/dns/msg.h"

void harness() {
    // Parameters as in the function signature
    const uint8_t *buf;
    size_t len;
    int family;
    void *addr_out;
    uint32_t *ttl;

    // Allocate memory for primitive pointer parameters using size variables
    size_t buf_len;
    buf = (const uint8_t *)malloc(sizeof(uint8_t) * buf_len);

    size_t addr_out_len;
    addr_out = malloc(addr_out_len);

    size_t ttl_len;
    ttl = (uint32_t *)malloc(sizeof(uint32_t) * ttl_len);

    // Call the function under test
    (void)dns_msg_parse_reply(buf, len, family, addr_out, ttl);
}
