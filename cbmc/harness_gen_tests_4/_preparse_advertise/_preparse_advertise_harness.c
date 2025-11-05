#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

// Target function declaration (defined elsewhere in the project)
int _preparse_advertise(uint8_t *adv, size_t len, uint8_t **buf);

void harness() {
    // Declare parameters exactly as in the function signature
    uint8_t *adv;
    size_t len;
    uint8_t **buf;

    // Allocate memory for pointer parameters using size variables
    size_t adv_len;
    adv = (uint8_t *)malloc(adv_len);

    size_t buf_len;
    buf = (uint8_t **)malloc(buf_len);

    // Call the target function
    (void)_preparse_advertise(adv, len, buf);
}
