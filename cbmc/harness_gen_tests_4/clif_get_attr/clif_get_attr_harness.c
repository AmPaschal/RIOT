#include <stdlib.h>
#include <stddef.h>
#include "clif.h"

void harness() {
    const char *input;
    size_t input_len;

    size_t input_buf_len;
    input = (const char *)malloc(input_buf_len);

    clif_attr_t *attr;
    size_t attr_len;
    __CPROVER_assume(attr_len >= sizeof(clif_attr_t));
    attr = (clif_attr_t *)malloc(attr_len);

    clif_get_attr(input, input_len, attr);
}