#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

#include "net/asymcute.h"

/* Declare the target function */
extern void _on_regack(asymcute_con_t *con, const uint8_t *data, size_t len);

/* Provide a valid user callback to avoid calling through an uninitialized function pointer */
static void dummy_user_cb(asymcute_req_t *req, unsigned evt_type)
{
    (void)req;
    (void)evt_type;
}

void harness(void)
{
    /* Parameters as per function signature */
    asymcute_con_t *con;
    const uint8_t *data;
    size_t len;

    /* Allocate and constrain the struct pointer parameter */
    con = (asymcute_con_t *)malloc(sizeof(struct asymcute_con));
    __CPROVER_assume(con != NULL);
    /* Set a valid user callback to avoid NULL function pointer deref inside _on_regack */
    con->user_cb = dummy_user_cb;

    /* For the primitive pointer parameter, allocate with a size variable and relate it to len */
    size_t data_len;
    uint8_t *data_buf = (uint8_t *)malloc(sizeof(uint8_t) * data_len);
    __CPROVER_assume(data_buf != NULL);
    data = (const uint8_t *)data_buf;

    /* Assume the size relationship */
    __CPROVER_assume(data_len == len);

    /* Pointers used without explicit NULL checks inside the function should be non-NULL */
    __CPROVER_assume(con != NULL);
    __CPROVER_assume(data != NULL);

    /* Invoke the function under test */
    _on_regack(con, data, len);
}
