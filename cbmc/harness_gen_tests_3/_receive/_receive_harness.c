#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>

#include "net/gnrc/pkt.h"
#include "net/ipv6/addr.h"

/* TCP internal headers for types */
#include "sys/net/gnrc/transport_layer/tcp/include/gnrc_tcp_common.h"
#include "sys/net/gnrc/transport_layer/tcp/include/gnrc_tcp_fsm.h"

/* Target under test */
int _receive(gnrc_pktsnip_t *pkt);

/* Stub: Provide a non-empty TCB list so _receive() can find a matching TCB */
_gnrc_tcp_common_tcb_list_t *_gnrc_tcp_common_get_tcb_list(void)
{
    static _gnrc_tcp_common_tcb_list_t list;
    static gnrc_tcp_tcb_t tcb;
    tcb.next = NULL;
    list.head = &tcb;
    return &list;
}

/* Stub: No-op FSM so the success path can proceed without side effects */
int _gnrc_tcp_fsm(gnrc_tcp_tcb_t *tcb, _gnrc_tcp_fsm_event_t event,
                  gnrc_pktsnip_t *in_pkt, void *buf, size_t len)
{
    (void)tcb; (void)event; (void)in_pkt; (void)buf; (void)len;
    int ret; /* nondet */
    return ret;
}

/* Stub: Return nondet state for potential SYN+LISTEN path */
_gnrc_tcp_fsm_state_t _gnrc_tcp_fsm_get_state(gnrc_tcp_tcb_t *tcb)
{
    (void)tcb;
    _gnrc_tcp_fsm_state_t st; /* nondet */
    return st;
}

/* Stubs for IPv6 address helpers used in matching logic */
bool ipv6_addr_equal(const ipv6_addr_t *a, const ipv6_addr_t *b)
{
    (void)a; (void)b;
    bool r; /* nondet */
    return r;
}

bool ipv6_addr_is_unspecified(const ipv6_addr_t *a)
{
    (void)a;
    bool r; /* nondet */
    return r;
}

void harness(void)
{
    size_t pkt_len;
    __CPROVER_assume(pkt_len >= sizeof(gnrc_pktsnip_t));
    gnrc_pktsnip_t *pkt = (gnrc_pktsnip_t *)malloc(pkt_len);

    _receive(pkt);
}
