#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>

// Target under test
int _preparse_advertise(uint8_t *adv, size_t len, uint8_t **buf);

void harness(void) {
    // adv and len are symbolic; CBMC will consider all sizes/contents
    size_t len;
    uint8_t *adv = malloc(len);

    // Ensure buf is non-NULL and writable so the assignment at line 702 can execute
    uint8_t *out_ptr;
    uint8_t **buf = &out_ptr;

    (void)_preparse_advertise(adv, len, buf);
}
