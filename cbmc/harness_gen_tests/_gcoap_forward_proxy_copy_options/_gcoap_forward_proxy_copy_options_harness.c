#include <stdlib.h>
#include <stdint.h>
#include "net/nanocoap.h"
#include "net/application_layer/gcoap/include/forward_proxy_internal.h"
#include "uri_parser.h"

/* Prototype of the function under test (defined in forward_proxy.c) */
int _gcoap_forward_proxy_copy_options(coap_pkt_t *pkt,
                                     coap_pkt_t *client_pkt,
                                     client_ep_t *cep,
                                     uri_parser_result_t *urip);

void harness(void) {
    /* Allocate coap_pkt_t *pkt */
    coap_pkt_t *pkt = (coap_pkt_t *)malloc(sizeof(coap_pkt_t));
    __CPROVER_assume(pkt != NULL);

    /* Allocate coap_pkt_t *client_pkt */
    coap_pkt_t *client_pkt = (coap_pkt_t *)malloc(sizeof(coap_pkt_t));
    __CPROVER_assume(client_pkt != NULL);

    /* Allocate client_ep_t *cep */
    client_ep_t *cep = (client_ep_t *)malloc(sizeof(client_ep_t));
    __CPROVER_assume(cep != NULL);

    /* Allocate uri_parser_result_t *urip */
    uri_parser_result_t *urip = (uri_parser_result_t *)malloc(sizeof(uri_parser_result_t));
    __CPROVER_assume(urip != NULL);

    (void)_gcoap_forward_proxy_copy_options(pkt, client_pkt, cep, urip);
}
