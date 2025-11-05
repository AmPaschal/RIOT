#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <net/dns/msg.h>

void harness() {
    size_t buf_len;
    const uint8_t *buf = malloc(buf_len);

    size_t len;

    int family;

    size_t addr_out_len;
    void *addr_out = malloc(addr_out_len);

    size_t ttl_len;
    uint32_t *ttl = malloc(ttl_len);

    (void)dns_msg_parse_reply(buf, len, family, addr_out, ttl);
}
