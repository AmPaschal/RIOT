#include <stdint.h>
#include <stdlib.h>

#include "sys/net/application_layer/dhcpv6/_dhcpv6.h"
#include "sys/include/net/dhcpv6/client.h"

// Forward declaration of the function under test
int _preparse_advertise(uint8_t *adv, size_t len, uint8_t **buf);

void harness() {
    // Declare parameters exactly as in the function signature
    uint8_t *adv;
    size_t len;
    uint8_t **buf;

    // Allocate memory for the uint8_t* adv using its size variable len
    adv = (uint8_t *)malloc(sizeof(uint8_t) * len);

    // Allocate memory for the pointer-to-pointer parameter and its pointee
    buf = (uint8_t **)malloc(sizeof(uint8_t *));
    __CPROVER_assume(buf != NULL);

    size_t buf_len;
    *buf = (uint8_t *)malloc(sizeof(uint8_t) * buf_len);

    // Call the function under test
    (void)_preparse_advertise(adv, len, buf);
}
