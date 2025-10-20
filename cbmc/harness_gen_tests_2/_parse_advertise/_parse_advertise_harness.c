#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>

/* Forward declaration of the function under test */
void _parse_advertise(uint8_t *adv, size_t len);

void harness(void) {
    /* Allocate buffer for adv with a nondeterministic length */
    size_t adv_len;
    uint8_t *adv = (uint8_t *)malloc(sizeof(uint8_t) * adv_len);

    /* Nondeterministic message length parameter */
    size_t len;

    _parse_advertise(adv, len);
}
