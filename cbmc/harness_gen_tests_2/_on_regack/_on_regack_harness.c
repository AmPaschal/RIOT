#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>

#include "net/asymcute.h"

/* Function under test */
extern void _on_regack(asymcute_con_t *con, const uint8_t *data, size_t len);

void harness(void) {
    /* struct pointer parameter */
    asymcute_con_t *con = (asymcute_con_t *)malloc(sizeof(asymcute_con_t));
    __CPROVER_assume(con != NULL);

    /* primitive pointer parameter: allocate with its own size variable */
    size_t data_len;
    uint8_t *data = (uint8_t *)malloc(sizeof(uint8_t) * data_len);

    /* remaining parameter */
    size_t len;

    _on_regack(con, data, len);
}
