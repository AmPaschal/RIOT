#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>

/* Forward declaration of the target function */
void _parse_advertise(uint8_t *adv, size_t len);

void harness() {
    /* Pointer to primitive type: allocate with a size variable */
    size_t adv_len;
    uint8_t *adv = malloc(sizeof(uint8_t) * adv_len);

    /* Size parameter as in function signature */
    size_t len;

    _parse_advertise(adv, len);
}
