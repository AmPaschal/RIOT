#include <stdlib.h>
#include "clif.h"

void harness() {
    // clif_t *link
    clif_t *link = malloc(sizeof(clif_t));
    __CPROVER_assume(link != NULL);

    // clif_attr_t *attrs
    clif_attr_t *attrs = malloc(sizeof(clif_attr_t));
    __CPROVER_assume(attrs != NULL);

    // unsigned attrs_len
    unsigned attrs_len;

    // const char *buf (pointer to primitive)
    size_t buf_len;
    char *buf_mut = malloc(sizeof(char) * buf_len);
    __CPROVER_assume(buf_mut != NULL);
    const char *buf = buf_mut;

    // size_t maxlen
    size_t maxlen;

    // Safety constraints to avoid overruns and respect allocation rules
    __CPROVER_assume(buf_len >= maxlen);
    __CPROVER_assume(attrs_len <= 1);

    // Call the function under test
    clif_decode_link(link, attrs, attrs_len, buf, maxlen);
}
