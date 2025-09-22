#include <stdlib.h>
#include <stdint.h>
#include "net/gcoap.h"

/* Extern globals used by _on_rd_init */
extern char *_result_buf;
extern size_t _result_buf_len;

/* Prototype of the function under test (not exposed in a public header) */
void _on_rd_init(const gcoap_request_memo_t *memo, coap_pkt_t *pdu, const sock_udp_ep_t *remote);

void harness() {
    /* Declare parameters exactly as in the function signature */
    const gcoap_request_memo_t *memo;
    coap_pkt_t *pdu;
    const sock_udp_ep_t *remote;

    /* Allocate struct pointers and assume non-NULL (instruction 3) */
    memo = (const gcoap_request_memo_t *)malloc(sizeof(struct gcoap_request_memo));
    __CPROVER_assume(memo != NULL);

    pdu = (coap_pkt_t *)malloc(sizeof(coap_pkt_t));
    __CPROVER_assume(pdu != NULL);

    remote = (const sock_udp_ep_t *)malloc(sizeof(sock_udp_ep_t));
    __CPROVER_assume(remote != NULL);

    /* Initialize coap_pkt_t fields used by the function and by coap_get_content_type */
    /* Allocate header */
    pdu->hdr = (coap_hdr_t *)malloc(sizeof(coap_hdr_t));
    __CPROVER_assume(pdu->hdr != NULL);

    /* Create a symbolic payload length and allocate payload buffer */
    uint16_t payload_len;
    /* Allocate at least 1 byte so that pdu->payload is never NULL even if payload_len == 0 */
    uint16_t alloc_len = (payload_len == 0) ? 1u : payload_len;
    pdu->payload = (uint8_t *)malloc((size_t)alloc_len);
    __CPROVER_assume(pdu->payload != NULL);
    pdu->payload_len = payload_len;

    /* Keep options_len zero by default to avoid option parsing; snips/opt_crit left nondet */
    pdu->options_len = 0;

    /* Initialize globals used by _on_rd_init */
    size_t res_len;
    size_t res_alloc = (res_len == 0) ? 1u : res_len;
    _result_buf = (char *)malloc(res_alloc);
    __CPROVER_assume(_result_buf != NULL);
    _result_buf_len = res_len;

    /* Pointers are used without NULL checks inside _on_rd_init */
    __CPROVER_assume(memo != NULL);
    __CPROVER_assume(pdu != NULL);

    /* Call the function under test */
    _on_rd_init(memo, pdu, remote);
}
