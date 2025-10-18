#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include "net/emcute.h"

void harness() {
    uint16_t port;

    size_t id_len;
    char *id = malloc(sizeof(char) * id_len);

    // Ensure a valid C-string for strlen inside emcute_run
    __CPROVER_assume(id_len >= 1);
    id[id_len - 1] = '\0';

    emcute_run(port, id);
}
