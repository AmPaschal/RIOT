#include <stdlib.h>
#include "sys/include/uri_parser.h"

void harness() {
    uri_parser_result_t *result = malloc(sizeof(uri_parser_result_t));
    __CPROVER_assume(result != NULL);

    size_t uri_len;
    char *uri = malloc(sizeof(char) * uri_len);

    uri_parser_process(result, uri, uri_len);
}