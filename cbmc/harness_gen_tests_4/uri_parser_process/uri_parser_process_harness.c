#include <stddef.h>
#include <stdlib.h>
#include "sys/include/uri_parser.h"

void harness() {
    // Declare parameters exactly as in the function signature
    uri_parser_result_t *result;
    const char *uri;
    size_t uri_len;

    // Allocate result (struct pointer) with size assumption
    size_t result_len;
    __CPROVER_assume(result_len >= sizeof(uri_parser_result_t));
    result = (uri_parser_result_t *)malloc(result_len);

    // Allocate uri using its length parameter
    uri = (const char *)malloc(uri_len);

    // Call the target function
    (void)uri_parser_process(result, uri, uri_len);
}
