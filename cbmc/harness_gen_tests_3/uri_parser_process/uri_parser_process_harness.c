#include <stddef.h>
#include <stdlib.h>

#include "uri_parser.h"

void harness() {
    // Parameters as in the function signature
    uri_parser_result_t *result;
    const char *uri;
    size_t uri_len;

    // Allocate memory for result (struct pointer)
    size_t result_len;
    __CPROVER_assume(result_len >= sizeof(uri_parser_result_t));
    result = (uri_parser_result_t *)malloc(result_len);

    // Allocate memory for uri (pointer argument)
    size_t uri_buf_len;
    uri = (const char *)malloc(uri_buf_len);

    // Call the function under test
    uri_parser_process(result, uri, uri_len);
}
