#include <stdlib.h>
#include "clif.h"

void harness() {
    // Parameters as in the function signature
    clif_t *link;
    clif_attr_t *attrs;
    unsigned attrs_len;
    const char *buf;
    size_t maxlen;

    // Allocation sizes for pointer parameters
    size_t link_len;
    __CPROVER_assume(link_len >= sizeof(clif_t));
    link = (clif_t *)malloc(link_len);

    size_t attrs_buf_len;
    __CPROVER_assume(attrs_buf_len >= sizeof(clif_attr_t));
    attrs = (clif_attr_t *)malloc(attrs_buf_len);

    size_t buf_len;
    char *buf_mut = (char *)malloc(buf_len);
    buf = (const char *)buf_mut;

    // Call the function under test
    clif_decode_link(link, attrs, attrs_len, buf, maxlen);
}
