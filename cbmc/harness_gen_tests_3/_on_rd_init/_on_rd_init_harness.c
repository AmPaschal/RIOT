#include <stdlib.h>
#include "net/gcoap.h"

/* Forward declaration of the target function */
void _on_rd_init(const gcoap_request_memo_t *memo, coap_pkt_t *pdu,
                 const sock_udp_ep_t *remote);

void harness() {
    /* Declare parameters exactly as in the function signature */
    const gcoap_request_memo_t *memo;
    coap_pkt_t *pdu;
    const sock_udp_ep_t *remote;

    /* Allocate and constrain pointer arguments */
    size_t memo_len;
    __CPROVER_assume(memo_len >= sizeof(gcoap_request_memo_t));
    memo = (const gcoap_request_memo_t *)malloc(memo_len);

    size_t pdu_len;
    __CPROVER_assume(pdu_len >= sizeof(coap_pkt_t));
    pdu = (coap_pkt_t *)malloc(pdu_len);

    size_t remote_len;
    __CPROVER_assume(remote_len >= sizeof(sock_udp_ep_t));
    remote = (const sock_udp_ep_t *)malloc(remote_len);

    /* Call the target function */
    _on_rd_init(memo, pdu, remote);
}
