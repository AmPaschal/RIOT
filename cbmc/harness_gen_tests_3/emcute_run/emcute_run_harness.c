#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>

/* Forward declaration of the target function */
void emcute_run(uint16_t port, const char *id);

void harness() {
    uint16_t port;

    size_t id_len;
    char *id_buf = malloc(id_len);
    const char *id = id_buf;

    emcute_run(port, id);
}
