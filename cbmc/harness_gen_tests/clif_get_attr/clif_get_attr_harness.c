#include <stdlib.h>
#include "sys/include/clif.h"

void harness() {
    /* Declare parameters exactly as in the function signature */
    const char *input;
    size_t input_len;
    clif_attr_t *attr;

    /* Allocate buffer for the primitive pointer parameter using a size variable */
    char *input_buf = (char *)malloc(sizeof(char) * input_len);
    __CPROVER_assume(input_buf != NULL);
    input = input_buf;

    /* Allocate memory for the struct pointer parameter and assume non-NULL */
    attr = (clif_attr_t *)malloc(sizeof(clif_attr_t));
    __CPROVER_assume(attr != NULL);

    /* Call the function under test */
    clif_get_attr(input, input_len, attr);
}
