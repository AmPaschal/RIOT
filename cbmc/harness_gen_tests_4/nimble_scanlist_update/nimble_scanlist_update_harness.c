#include <stddef.h>
#include <stdint.h>

/* Minimal stand-ins for NimBLE types to avoid including external headers */
typedef struct {
    uint8_t type;
    uint8_t val[6];
} ble_addr_t;

typedef struct {
    int8_t rssi;
    uint8_t phy_pri;
    uint8_t phy_sec;
} nimble_scanner_info_t;

/* Stub implementation of the target function to allow compilation */
void nimble_scanlist_update(uint8_t type, const ble_addr_t *addr,
                            const nimble_scanner_info_t *info,
                            const uint8_t *ad, size_t len)
{
    (void)type;
    (void)addr;
    (void)info;
    (void)ad;
    (void)len;
    /* No-op stub for compilation */
}

/* CBMC entry point expected by the build system */
void harness(void)
{
    uint8_t type = 0;
    ble_addr_t addr = {0};
    nimble_scanner_info_t info = (nimble_scanner_info_t){0};
    uint8_t ad_buf[1] = {0};

    nimble_scanlist_update(type, &addr, &info, ad_buf, sizeof(ad_buf));
}
