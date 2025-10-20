#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>

/* Minimal typedefs needed for parameter sizing and type compatibility */
typedef struct {
    uint8_t type;
    uint8_t val[6];
} ble_addr_t;

typedef struct {
    uint8_t status;
    uint8_t phy_pri;
    uint8_t phy_sec;
    int8_t rssi;
} nimble_scanner_info_t;

/* Forward declaration of the target function */
void nimble_scanlist_update(uint8_t type, const ble_addr_t *addr,
                            const nimble_scanner_info_t *info,
                            const uint8_t *ad, size_t len);

void harness() {
    uint8_t type;

    /* const ble_addr_t *addr */
    size_t addr_len;
    __CPROVER_assume(addr_len >= sizeof(ble_addr_t));
    ble_addr_t *addr_mut = (ble_addr_t *)malloc(addr_len);
    const ble_addr_t *addr = addr_mut;

    /* const nimble_scanner_info_t *info */
    size_t info_len;
    __CPROVER_assume(info_len >= sizeof(nimble_scanner_info_t));
    nimble_scanner_info_t *info_mut = (nimble_scanner_info_t *)malloc(info_len);
    const nimble_scanner_info_t *info = info_mut;

    /* const uint8_t *ad */
    size_t ad_buf_len;
    uint8_t *ad_mut = (uint8_t *)malloc(ad_buf_len);
    const uint8_t *ad = ad_mut;

    size_t len;

    nimble_scanlist_update(type, addr, info, ad, len);
}
