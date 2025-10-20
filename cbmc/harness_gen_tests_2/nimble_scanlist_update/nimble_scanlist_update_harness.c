#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>

#include "nimble_scanlist.h"

void harness() {
    // Parameters as in the function signature
    uint8_t type;

    // const ble_addr_t *addr; allocate underlying storage and bind to const pointer
    ble_addr_t *addr_mut = (ble_addr_t *)malloc(sizeof(ble_addr_t));
    __CPROVER_assume(addr_mut != NULL);
    const ble_addr_t *addr = addr_mut;

    // const nimble_scanner_info_t *info; allocate underlying storage and bind to const pointer
    nimble_scanner_info_t *info_mut = (nimble_scanner_info_t *)malloc(sizeof(nimble_scanner_info_t));
    __CPROVER_assume(info_mut != NULL);
    const nimble_scanner_info_t *info = info_mut;

    // const uint8_t *ad and size_t len; allocate ad using len
    size_t len;
    // Respect function precondition to avoid assert(0) on oversize advertisements
    __CPROVER_assume(len <= BLE_ADV_PDU_LEN);
    uint8_t *ad = (uint8_t *)malloc(sizeof(uint8_t) * len);

    // Call the function under test
    nimble_scanlist_update(type, addr, info, ad, len);
}
