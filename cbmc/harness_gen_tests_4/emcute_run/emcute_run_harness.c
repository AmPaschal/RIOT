#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include "net/emcute.h"

/* Provide a dummy callback target and take its address so CBMC can dispatch sub->cb */
static void cb_dummy(const emcute_topic_t *topic, void *data, size_t len) {
    (void)topic; (void)data; (void)len;
}
/* Taking the address registers an address-taken function of type emcute_cb_t */
emcute_cb_t cb_dummy_ref = cb_dummy;

/* Stub Implementation */
const char *emcute_type_str(uint8_t type) {
    size_t ret_len;
    char *ret = malloc(ret_len);
    return ret;
}

void harness(void) {
    uint16_t port;

    size_t id_len;
    char *id = malloc(id_len);

    emcute_run(port, id);
}
