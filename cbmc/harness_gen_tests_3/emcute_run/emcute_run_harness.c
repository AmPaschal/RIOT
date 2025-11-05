#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>

void emcute_run(uint16_t port, const char *id);

void harness(void) {
    uint16_t port;

    size_t id_len;
    const char *id = (const char *)malloc(id_len);

    emcute_run(port, id);
}