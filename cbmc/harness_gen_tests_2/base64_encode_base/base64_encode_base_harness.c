#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

#include "base64.h"

/* Forward declaration since base64_encode_base is not in the public header */
int base64_encode_base(const void *data_in, size_t data_in_size,
                       void *base64_out, size_t *base64_out_size,
                       bool urlsafe);

void harness() {
    /* Inputs */
    size_t data_in_size;
    /* Allocate input buffer as bytes and ensure non-NULL to avoid UB in pointer arithmetic */
    uint8_t *data_in_buf = (uint8_t *)malloc(sizeof(uint8_t) * data_in_size);
    __CPROVER_assume(data_in_buf != NULL);
    const void *data_in = (const void *)data_in_buf;

    /* Output size pointer must be non-NULL (function dereferences it unconditionally) */
    size_t *base64_out_size = (size_t *)malloc(sizeof(size_t));
    __CPROVER_assume(base64_out_size != NULL);

    /* Allocate an output buffer with a nondet capacity and set *base64_out_size accordingly */
    size_t base64_out_alloc_len;
    uint8_t *base64_out_buf = (uint8_t *)malloc(sizeof(uint8_t) * base64_out_alloc_len);
    void *base64_out = (void *)base64_out_buf;
    *base64_out_size = base64_out_alloc_len;

    bool urlsafe;

    /* Call function under test */
    (void)base64_encode_base(data_in, data_in_size, base64_out, base64_out_size, urlsafe);
}
