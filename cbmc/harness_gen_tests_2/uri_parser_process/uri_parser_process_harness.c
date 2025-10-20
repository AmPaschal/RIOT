#include <stdlib.h>
#include "sys/include/uri_parser.h"

void harness(void) {
    // Allocate struct pointer argument
    uri_parser_result_t *result = malloc(sizeof(uri_parser_result_t));
    __CPROVER_assume(result != NULL);

    // Allocate primitive pointer argument (char *) with a size variable
    size_t uri_len;
    char *uri = malloc(sizeof(char) * uri_len);

    // Call the function under test
    uri_parser_process(result, uri, uri_len);
}
