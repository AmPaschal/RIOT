#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>


/* Prototype for the function under test */
extern void _parse_advertise(uint8_t *adv, size_t len);

void harness(void)
{
    /* Declare parameters exactly as in the function signature */
    uint8_t *adv;
    size_t len;

    /* Allocate memory for the primitive pointer based on len */
    adv = (uint8_t *)malloc(sizeof(uint8_t) * len);

    /* The function uses adv without a NULL check */
    __CPROVER_assume(adv != NULL);

    /* adv and len are related; adv points to a buffer of size len */
    /* The allocation above already used len; this assumption states the relation explicitly */
    __CPROVER_assume(__CPROVER_objects_size(adv) >= len);

    /* Call the function under test */
    _parse_advertise(adv, len);
}
