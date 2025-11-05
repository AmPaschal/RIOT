#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

/* Forward declaration of the function under test */
void _parse_advertise(uint8_t *adv, size_t len);

void harness() {
    size_t adv_len;
    uint8_t *adv = malloc(adv_len);

    size_t len;

    _parse_advertise(adv, len);
}
