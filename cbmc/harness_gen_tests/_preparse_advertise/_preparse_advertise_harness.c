#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>

/* Forward declaration of the target function */
int _preparse_advertise(uint8_t *adv, size_t len, uint8_t **buf);

void harness(void) {
    /* Allocate and initialize parameters exactly as in the signature */

    /* adv: pointer to primitive type (uint8_t) */
    size_t adv_len;
    uint8_t *adv = (uint8_t *)malloc(sizeof(uint8_t) * adv_len);

    /* len: size_t */
    size_t len;

    /* buf: pointer to pointer to primitive type (uint8_t **) */
    uint8_t **buf = (uint8_t **)malloc(sizeof(uint8_t *));
    if (buf != NULL) {
        size_t buf_data_len;
        uint8_t *buf_data = (uint8_t *)malloc(sizeof(uint8_t) * buf_data_len);
        /* Assign allocated data to *buf (can be NULL if malloc failed) */
        *buf = buf_data;
    }

    /* Call the function under test */
    (void)_preparse_advertise(adv, len, buf);
}
