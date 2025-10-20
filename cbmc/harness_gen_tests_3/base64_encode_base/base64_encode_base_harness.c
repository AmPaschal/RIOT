#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

#include "sys/include/base64.h"

/* Prototype since base64_encode_base is not declared in the public header */
extern int base64_encode_base(const void *data_in, size_t data_in_size,
                              void *base64_out, size_t *base64_out_size,
                              bool urlsafe);

void harness() {
    const void *data_in;
    size_t data_in_size;
    void *base64_out;
    size_t *base64_out_size;
    bool urlsafe;

    size_t data_in_len;
    data_in = malloc(data_in_len);

    size_t base64_out_len;
    base64_out = malloc(base64_out_len);

    size_t base64_out_size_len;
    base64_out_size = malloc(base64_out_size_len);

    base64_encode_base(data_in, data_in_size, base64_out, base64_out_size, urlsafe);
}