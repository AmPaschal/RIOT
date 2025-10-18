#include <stdlib.h>
#include "net/gcoap.h"

void harness() {
    const gcoap_request_memo_t *memo = (const gcoap_request_memo_t *)malloc(sizeof(gcoap_request_memo_t));
    __CPROVER_assume(memo != NULL);

    coap_pkt_t *pdu = (coap_pkt_t *)malloc(sizeof(coap_pkt_t));
    __CPROVER_assume(pdu != NULL);

    const sock_udp_ep_t *remote = (const sock_udp_ep_t *)malloc(sizeof(sock_udp_ep_t));
    __CPROVER_assume(remote != NULL);

    _on_rd_init(memo, pdu, remote);
}
