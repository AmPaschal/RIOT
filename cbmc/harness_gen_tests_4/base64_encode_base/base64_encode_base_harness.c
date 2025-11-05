#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include "sys/include/base64.h"

/* Forward declaration since base64_encode_base is internal to base64.c */
extern int base64_encode_base(const void *data_in, size_t data_in_size,
                              void *base64_out, size_t *base64_out_size,
                              bool urlsafe);

void harness() {
    /* Parameters as per the function signature */
    const void *data_in;
    size_t data_in_size;
    void *base64_out;
    size_t *base64_out_size;
    bool urlsafe;

    /* Allocate memory for pointer parameters using size variables */
    size_t data_in_len;
    data_in = malloc(data_in_len);

    size_t base64_out_len;
    base64_out = malloc(base64_out_len);

    size_t base64_out_size_len = sizeof(size_t);
    base64_out_size = (size_t *)malloc(base64_out_size_len);

    /* Call the function under test */
    base64_encode_base(data_in, data_in_size, base64_out, base64_out_size, urlsafe);
}
