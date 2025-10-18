#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

/* Forward declaration since base64_encode_base is defined in sys/base64/base64.c */
extern int base64_encode_base(const void *data_in, size_t data_in_size,
                              void *base64_out, size_t *base64_out_size,
                              bool urlsafe);

void harness(void) {
    /* Declare parameters exactly as in the function signature */
    const void *data_in;
    size_t data_in_size;
    void *base64_out;
    size_t *base64_out_size;
    bool urlsafe;

    /* Allocate input buffer for data_in (pointer to primitive bytes) */
    uint8_t *data_in_buf = malloc(sizeof(uint8_t) * data_in_size);
    data_in = data_in_buf;

    /* Prepare output size and allocate output buffer (pointer to primitive bytes) */
    size_t base64_out_size_val;
    base64_out = malloc(base64_out_size_val);
    base64_out_size = &base64_out_size_val;

    /* Call the function under test */
    (void)base64_encode_base(data_in, data_in_size,
                             base64_out, base64_out_size,
                             urlsafe);
}
