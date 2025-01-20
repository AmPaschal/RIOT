/**
 * @file nimble_scanlist_harness.c
 * @brief Implements the proof harness for nimble_scanlist_update function.
 */

#include <stdint.h>
#include <stdlib.h>

#include "net/ble.h"
#include "clist.h"

static clist_node_t _pool;
static clist_node_t _list;

/**
 * @brief Starting point for formal analysis
 * 
 */

typedef struct {
    uint8_t type;
    uint8_t val[6];
} ble_addr_t;

typedef struct {
    /**
     * Status of received packet. Possible values:
     * - NIMBLE_SCANNER_COMPLETE
     * - NIMBLE_SCANNER_INCOMPLETE
     * - NIMBLE_SCANNER_TRUNCATED
     */
    uint8_t status;
    uint8_t phy_pri; /**< PHY used on primary advertisement channels */
    uint8_t phy_sec; /**< PHY used on secondary advertisement channels */
    int8_t rssi;     /**< RSSI value of received advertisement */
} nimble_scanner_info_t;

/**
 * @brief   Data structure for holding a single scanlist entry
 */
typedef struct {
    clist_node_t node;           /**< list node */
    ble_addr_t addr;             /**< a node's BLE address */
    uint8_t ad[BLE_ADV_PDU_LEN]; /**< the received raw advertising data */
    uint8_t ad_len;              /**< length of the advertising data */
    int8_t last_rssi;            /**< last RSSI of a scanned node */
    uint32_t adv_msg_cnt;        /**< number of adv packets by a node */
    uint32_t first_update;       /**< first packet timestamp */
    uint32_t last_update;        /**< last packet timestamp */
    uint8_t type;                /**< advertising packet type */
    uint8_t phy_pri;             /**< primary PHY used */
    uint8_t phy_sec;             /**< secondary PHY advertised */
} nimble_scanlist_entry_t;

void nimble_scanlist_update(uint8_t type, const ble_addr_t *addr,
                            const nimble_scanner_info_t *info,
                            const uint8_t *ad, size_t len)
{
    assert(addr);

    /* Ignore bogus advertisements */
    if (len > BLE_ADV_PDU_LEN) {
        assert(0);
        return;
    }

    uint32_t now = (uint32_t)ztimer_now(0);
    nimble_scanlist_entry_t *e = _find(addr);

    if (!e) {
        e = (nimble_scanlist_entry_t *)clist_lpop(&_pool);
        if (!e) {
            /* no space available, dropping newly discovered node */
            return;
        }
        memcpy(&e->addr, addr, sizeof(ble_addr_t));
        if (ad) {
            memcpy(e->ad, ad, len);
        }
        e->ad_len = len;
        e->last_rssi = info->rssi;
        e->first_update = now;
        e->adv_msg_cnt = 1;
        e->type = type;
        e->phy_pri = info->phy_pri;
        e->phy_sec = info->phy_sec;
        clist_rpush(&_list, (clist_node_t *)e);
    }
    else {
        e->adv_msg_cnt++;
    }

    e->last_update = now;
}

void harness(void)
{
    // Model input variables:

    uint8_t type;

    ble_addr_t addr;
    nimble_scanner_info_t info;

    // Allocate array:

    size_t len;

    uint8_t *ad = (uint8_t *)malloc(sizeof(uint8_t) * len);

    // Call the function with inputs:

    nimble_scanlist_update(type, &addr, &info, *ad, len);
}
