#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <string.h>

#include "net/gcoap.h"

void harness() {
    // Parameters as in the function signature
    const gcoap_request_memo_t *memo = (const gcoap_request_memo_t *)malloc(sizeof(gcoap_request_memo_t));
    __CPROVER_assume(memo != NULL);

    coap_pkt_t *pdu = (coap_pkt_t *)malloc(sizeof(coap_pkt_t));
    __CPROVER_assume(pdu != NULL);

    const sock_udp_ep_t *remote = (const sock_udp_ep_t *)malloc(sizeof(sock_udp_ep_t));
    __CPROVER_assume(remote != NULL);

    // Optional initialization to provide a consistent state for fields used by _on_rd_init
    // Zero-out the packet, then set a payload buffer and its length
    memset(pdu, 0, sizeof(*pdu));

    size_t payload_len;
    uint8_t *payload = (uint8_t *)malloc(sizeof(uint8_t) * payload_len);
    // payload may be NULL for payload_len == 0; CBMC explores both. If desired, one could assume when len>0 then payload!=NULL.
    pdu->payload = payload;
    // coap_pkt_t::payload_len is uint16_t; truncate nondet size_t accordingly
    if (payload_len > UINT16_MAX) {
        payload_len = UINT16_MAX;
    }
    pdu->payload_len = (uint16_t)payload_len;

    _on_rd_init(memo, pdu, remote);
}
