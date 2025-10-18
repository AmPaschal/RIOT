#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>

extern int dns_msg_parse_reply(const uint8_t *buf, size_t len, int family,
                        void *addr_out, uint32_t *ttl);

void harness() {
    // Parameters as in the function signature
    size_t len;
    const uint8_t *buf = malloc(sizeof(uint8_t) * len);

    int family;

    size_t addr_out_len;
    void *addr_out = malloc(sizeof(uint8_t) * addr_out_len);

    size_t ttl_len;
    uint32_t *ttl = malloc(sizeof(uint32_t) * ttl_len);

    // Call the function under test
    (void)dns_msg_parse_reply(buf, len, family, addr_out, ttl);
}
