#include <stddef.h>
#include <stdlib.h>
#include "net/gcoap.h"

/* Forward declaration of the function under test */
extern void _on_rd_init(const gcoap_request_memo_t *memo, coap_pkt_t *pdu,
                        const sock_udp_ep_t *remote);

void harness() {
    /* memo parameter */
    size_t memo_len;
    __CPROVER_assume(memo_len >= sizeof(gcoap_request_memo_t));
    const gcoap_request_memo_t *memo = malloc(memo_len);

    /* pdu parameter */
    size_t pdu_len;
    __CPROVER_assume(pdu_len >= sizeof(coap_pkt_t));
    coap_pkt_t *pdu = malloc(pdu_len);

    /* remote parameter */
    size_t remote_len;
    __CPROVER_assume(remote_len >= sizeof(sock_udp_ep_t));
    const sock_udp_ep_t *remote = malloc(remote_len);

    _on_rd_init(memo, pdu, remote);
}
