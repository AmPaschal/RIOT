#include <stdlib.h>
#include <stddef.h>
#include "net/gcoap/dns.h"

void harness() {
    char *proxy;
    size_t proxy_len;

    size_t proxy_alloc_len;
    proxy = malloc(proxy_alloc_len);

    gcoap_dns_server_proxy_get(proxy, proxy_len);
}
