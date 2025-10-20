#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>

int _preparse_advertise(uint8_t *adv, size_t len, uint8_t **buf);

void harness(void) {
    size_t adv_len;
    uint8_t *adv = malloc(adv_len);

    size_t len;

    size_t buf_len;
    uint8_t **buf = malloc(buf_len);

    (void)_preparse_advertise(adv, len, buf);
}
