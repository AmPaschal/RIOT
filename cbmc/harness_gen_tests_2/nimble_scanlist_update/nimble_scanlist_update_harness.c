#include <assert.h>
#include <limits.h>

#include "ztimer.h"
#include "net/bluetil/ad.h"

#include "nimble_scanlist.h"

// Provide a stub for ZTIMER_USEC so ztimer_now(ZTIMER_USEC) can be evaluated.
ztimer_clock_t * ZTIMER_USEC;

static uint32_t now_stub(ztimer_clock_t *clock)
{
    uint32_t val; // nondet under CBMC
    return val;
}

void harness(void) {
    // Parameters exactly as in the function signature
    uint8_t type;

    const ble_addr_t *addr = (ble_addr_t *)malloc(sizeof(ble_addr_t));
    __CPROVER_assume(addr != NULL);

    const nimble_scanner_info_t *info = (nimble_scanner_info_t *)malloc(sizeof(nimble_scanner_info_t));
    __CPROVER_assume(info != NULL);

    size_t ad_size; // size variable for allocation of primitive pointer
    const uint8_t *ad = (uint8_t *)malloc(sizeof(uint8_t) * ad_size);

    size_t len;

    // Initialize ZTIMER_USEC minimal state so ztimer_now() can dereference ops->now
    ZTIMER_USEC = (ztimer_clock_t *)malloc(sizeof(ztimer_clock_t));
    __CPROVER_assume(ZTIMER_USEC != NULL);
    ZTIMER_USEC->ops = (ztimer_ops_t *)malloc(sizeof(ztimer_ops_t));
    __CPROVER_assume(ZTIMER_USEC->ops != NULL);
    ZTIMER_USEC->ops->now = now_stub;

    // Call the function under test
    nimble_scanlist_update(type, addr, info, ad, len);
}
