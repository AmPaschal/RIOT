#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

/* Forward declaration of the function under test */
void _parse_advertise(uint8_t *adv, size_t len);

void harness() {
    /* Allocate buffer for adv (pointer to primitive type) */
    size_t adv_len;
    uint8_t *adv = malloc(sizeof(uint8_t) * adv_len);

    /* Non-deterministic length parameter */
    size_t len;

    /* Call the function under test */
    _parse_advertise(adv, len);
}
