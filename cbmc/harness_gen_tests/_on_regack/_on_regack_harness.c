#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>

#include "net/asymcute.h"

/* Forward declaration of the function under test */
extern void _on_regack(asymcute_con_t *con, const uint8_t *data, size_t len);

/* Stub for user callback to avoid calling an uninitialized function pointer */
static void user_cb_stub(asymcute_req_t *req, unsigned evt_type) {
    (void)req;
    (void)evt_type;
}

void harness() {
    /* Parameter: asymcute_con_t *con */
    asymcute_con_t *con = (asymcute_con_t *)malloc(sizeof(asymcute_con_t));
    __CPROVER_assume(con != NULL);

    /* Initialize fields that are used by _on_regack to avoid UB */
    con->user_cb = user_cb_stub;

    /* Parameter: const uint8_t *data (pointer to primitive type) */
    size_t data_len;
    uint8_t *data = (uint8_t *)malloc(sizeof(uint8_t) * data_len);

    /* Parameter: size_t len */
    size_t len;

    _on_regack(con, data, len);
}
