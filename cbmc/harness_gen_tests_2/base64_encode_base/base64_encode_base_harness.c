#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>

/* Forward declaration since base64_encode_base is defined in sys/base64/base64.c */
extern int base64_encode_base(const void *data_in, size_t data_in_size,
                              void *base64_out, size_t *base64_out_size,
                              bool urlsafe);

void harness(void) {
    /* Declare parameters exactly as in the target function signature */
    const void *data_in;
    size_t data_in_size;
    void *base64_out;
    size_t *base64_out_size;
    bool urlsafe;

    /* For pointers to primitive types, create a size variable and allocate */
    /* data_in: allocate data_in_size bytes */
    data_in = malloc(data_in_size);

    /* base64_out: create allocation size and allocate */
    size_t base64_out_alloc_size;
    base64_out = malloc(base64_out_alloc_size);

    /* base64_out_size: create a length for the size_t array and allocate */
    size_t base64_out_size_len;
    base64_out_size = malloc(sizeof(size_t) * base64_out_size_len);
    __CPROVER_assume(base64_out_size != NULL);

    /* Call the function under test */
    (void)base64_encode_base(data_in, data_in_size,
                             base64_out, base64_out_size,
                             urlsafe);
}
