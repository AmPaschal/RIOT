#include <stdlib.h>
#include <stddef.h>
#include <sys/types.h>

#include "net/gcoap/dns.h"

void harness() {
    size_t proxy_size;
    char *proxy = malloc(sizeof(char) * proxy_size);

    size_t proxy_len;

    gcoap_dns_server_proxy_get(proxy, proxy_len);
}
