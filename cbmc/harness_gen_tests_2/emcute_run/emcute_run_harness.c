#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include "net/emcute.h"
#include "net/mqttsn.h"

void harness() {
    // Parameters as in the target function signature
    uint16_t port;

    // Pointer to primitive type: const char *id
    size_t id_len;
    // Constrain length to satisfy emcute_run's assertion
    __CPROVER_assume(id_len >= MQTTSN_CLI_ID_MINLEN);
    __CPROVER_assume(id_len <= MQTTSN_CLI_ID_MAXLEN);

    char *id_buf = (char *)malloc(id_len + 1);
    __CPROVER_assume(id_buf != NULL);

    // Initialize id_buf with non-null characters and null-terminate
    for (size_t i = 0; i < id_len; i++) {
        unsigned char c;
        // leave c nondet and ensure not '\0' to maintain exact length
        __CPROVER_assume(c != '\0');
        id_buf[i] = (char)c;
    }
    id_buf[id_len] = '\0';

    const char *id = id_buf;

    // Invoke the target function
    emcute_run(port, id);
}
