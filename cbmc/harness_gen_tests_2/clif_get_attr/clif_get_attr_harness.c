#include <stdlib.h>
#include <sys/types.h>
#include "sys/include/clif.h"

void harness() {
    // Parameters as in the function signature
    const char *input;
    size_t input_len;
    clif_attr_t *attr;

    // Allocate struct pointer parameter
    attr = (clif_attr_t *)malloc(sizeof(clif_attr_t));
    __CPROVER_assume(attr != NULL);

    // Allocate buffer for primitive pointer parameter using a size variable
    char *input_buf = (char *)malloc(sizeof(char) * input_len);
    input = (const char *)input_buf;

    // Respect documented preconditions
    __CPROVER_assume(input != NULL);

    // Call the target function
    (void)clif_get_attr(input, input_len, attr);
}
