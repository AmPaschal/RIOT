#include <stdlib.h>
#include <stdint.h>
#include "net/asymcute.h"

/* Forward declaration since _on_regack is defined in asymcute.c but not in a public header */
void _on_regack(asymcute_con_t *con, const uint8_t *data, size_t len);

void harness() {
    /* Allocate struct pointer parameter */
    asymcute_con_t *con = (asymcute_con_t *)malloc(sizeof(asymcute_con_t));
    __CPROVER_assume(con != NULL);

    /* Allocate primitive pointer parameter with a size variable */
    size_t data_len;
    uint8_t *data_buf = (uint8_t *)malloc(sizeof(uint8_t) * data_len);
    const uint8_t *data = data_buf;

    /* Declare remaining scalar parameter */
    size_t len;

    /* Call the target function */
    _on_regack(con, data, len);
}
