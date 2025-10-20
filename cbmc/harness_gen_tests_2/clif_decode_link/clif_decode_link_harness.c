#include <stdlib.h>
#include "clif.h"

void harness() {
    // clif_t *link
    clif_t *link = (clif_t *)malloc(sizeof(clif_t));
    __CPROVER_assume(link != NULL);

    // clif_attr_t *attrs
    clif_attr_t *attrs = (clif_attr_t *)malloc(sizeof(clif_attr_t));
    __CPROVER_assume(attrs != NULL);

    // unsigned attrs_len
    unsigned attrs_len;

    // const char *buf
    size_t maxlen;
    const char *buf = (const char *)malloc(sizeof(char) * maxlen);
    __CPROVER_assume(buf != NULL);

    // size_t maxlen declared above

    // Call the function under test
    clif_decode_link(link, attrs, attrs_len, buf, maxlen);
}
