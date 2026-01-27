#include "sys/event/timeout_ztimer.c"
#include <stdlib.h>
#include <stdbool.h>

/* Minimal models with observable side effects to keep calls relevant */
static volatile bool event_post_called;
static volatile bool ztimer_set_called;
static volatile bool ztimer_remove_called;

void event_post(event_queue_t *queue, event_t *event) {
    (void)queue; (void)event;
    event_post_called = true;
}

uint32_t ztimer_set(ztimer_clock_t *clock, ztimer_t *t, uint32_t offset) {
    (void)clock; (void)t; (void)offset;
    ztimer_set_called = true;
    uint32_t ret; return ret; /* nondet */
}

bool ztimer_remove(ztimer_clock_t *clock, ztimer_t *t) {
    (void)clock; (void)t;
    ztimer_remove_called = true;
    bool removed; return removed; /* nondet */
}

void harness() {
    size_t event_timeout_len;
    __CPROVER_assume(event_timeout_len >= sizeof(event_timeout_t));
    event_timeout_t *event_timeout = malloc(event_timeout_len);
    __CPROVER_assume(event_timeout != NULL);

    /* Nondet dependencies; no extra constraints to preserve coverage */
    ztimer_clock_t *clock;
    event_queue_t *queue;
    event_t *event;

    event_post_called = false;
    ztimer_set_called = false;
    ztimer_remove_called = false;

    event_timeout_ztimer_init(event_timeout, clock, queue, event);

    uint32_t timeout;
    event_timeout_set(event_timeout, timeout);

    /* Keep clear reachable as well */
    event_timeout_clear(event_timeout);

    /* Make the effects of event_timeout_set relevant so code isn’t sliced */
    __CPROVER_assert(event_post_called || ztimer_set_called, "event_timeout_set invoked a backend action");
}
