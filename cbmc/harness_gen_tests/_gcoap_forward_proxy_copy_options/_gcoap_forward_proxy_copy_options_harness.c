#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "net/nanocoap.h"
#include "uri_parser.h"
#include "net/application_layer/gcoap/include/forward_proxy_internal.h"

/* Prototype for the function under test (not exposed via a public header) */
extern int _gcoap_forward_proxy_copy_options(coap_pkt_t *pkt,
                                             coap_pkt_t *client_pkt,
                                             client_ep_t *cep,
                                             uri_parser_result_t *urip);

/* Nondet helpers for CBMC */
extern uint16_t nondet_uint16_t(void);
extern uint8_t nondet_uint8_t(void);

void harness(void)
{
    /* Declare parameters exactly as in the function signature */
    coap_pkt_t *pkt = (coap_pkt_t *)malloc(sizeof(coap_pkt_t));
    __CPROVER_assume(pkt != NULL);

    coap_pkt_t *client_pkt = (coap_pkt_t *)malloc(sizeof(coap_pkt_t));
    // __CPROVER_assume(client_pkt != NULL);

    client_ep_t *cep = (client_ep_t *)malloc(sizeof(client_ep_t));
    __CPROVER_assume(cep != NULL);

    uri_parser_result_t *urip = (uri_parser_result_t *)malloc(sizeof(uri_parser_result_t));
    __CPROVER_assume(urip != NULL);

    /* Initialize/assume fields used by the function */

    /* Set client options length to a nondet value; bound it reasonably */
    uint16_t opt_count = nondet_uint16_t();
    /* Limit to CONFIG_NANOCOAP_NOPTS_MAX to match internal options array size */
    // __CPROVER_assume(opt_count <= CONFIG_NANOCOAP_NOPTS_MAX);
    // client_pkt->options_len = opt_count;

    /* Allocate payload buffers for client and pkt. Ensure sizes are related. */
    uint16_t client_payload_size = nondet_uint16_t();
    /* Keep sizes modest to avoid excessive allocation; still allow 0 as valid */
    /* No strict upper bound is necessary here, but CBMC benefits from finite bounds */
    /* Assume some upper bound, e.g., 1024, to keep state space manageable (optional) */
    __CPROVER_assume(client_payload_size <= 1024u);

    uint16_t pkt_payload_size = nondet_uint16_t();
    __CPROVER_assume(pkt_payload_size <= 1024u);

    // client_pkt->payload = (uint8_t *)malloc(sizeof(uint8_t) * client_payload_size);
    // __CPROVER_assume(client_pkt->payload != NULL);
    // client_pkt->payload_len = client_payload_size;

    pkt->payload = (uint8_t *)malloc(sizeof(uint8_t) * pkt_payload_size);
    __CPROVER_assume(pkt->payload != NULL);
    /* Ensure destination buffer is large enough for memcpy */
    // __CPROVER_assume(pkt_payload_size >= client_pkt->payload_len);
    pkt->payload_len = 0; /* will be set by the function */

    /* The function also relies on other coap_pkt_t internals through called helpers. */
    /* We do not need to fully initialize them for compilation. */

    /* urip is passed down; keep it zero-initialized/benign by default */
    memset(urip, 0, sizeof(*urip));

    /* Call the function under test */
    (void)_gcoap_forward_proxy_copy_options(pkt, client_pkt, cep, urip);
}
