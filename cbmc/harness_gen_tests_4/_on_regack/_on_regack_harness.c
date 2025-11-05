#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

#include "net/asymcute.h"

extern void _on_regack(asymcute_con_t *con, const uint8_t *data, size_t len);

void harness() {
    // Parameter: asymcute_con_t *con
    size_t con_len;
    __CPROVER_assume(con_len >= sizeof(asymcute_con_t));
    asymcute_con_t *con = malloc(con_len);

    // Parameter: const uint8_t *data
    size_t data_len;
    uint8_t *data_buf = malloc(data_len);
    const uint8_t *data = data_buf;

    // Parameter: size_t len
    size_t len;

    _on_regack(con, data, len);
}
