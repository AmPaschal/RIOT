#include <stdint.h>
#include <stdlib.h>

#include "pkg/nimble/scanlist/include/nimble_scanlist.h"

void harness(void) {
    // Declare parameters exactly as in the function signature
    uint8_t type;

    // const ble_addr_t *addr; allocate underlying storage and bind to const pointer
    ble_addr_t *addr_mut = (ble_addr_t *)malloc(sizeof(ble_addr_t));
    __CPROVER_assume(addr_mut != NULL);
    const ble_addr_t *addr = addr_mut;

    // const nimble_scanner_info_t *info; allocate underlying storage and bind to const pointer
    nimble_scanner_info_t *info_mut = (nimble_scanner_info_t *)malloc(sizeof(nimble_scanner_info_t));
    __CPROVER_assume(info_mut != NULL);
    const nimble_scanner_info_t *info = info_mut;

    // size for the primitive array pointer parameter
    size_t len;

    // const uint8_t *ad; allocate underlying storage and bind to const pointer
    uint8_t *ad_mut = (uint8_t *)malloc(sizeof(uint8_t) * len);
    const uint8_t *ad = ad_mut;

    // Call the function under test
    nimble_scanlist_update(type, addr, info, ad, len);
}
