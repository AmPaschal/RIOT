#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

#include "net/nanocoap.h"
#include "net/gcoap.h"
#include "sys/net/application_layer/gcoap/include/forward_proxy_internal.h"
#include "uri_parser.h"

/* The function is defined in forward_proxy.c but not declared in a public header */
extern int _gcoap_forward_proxy_copy_options(coap_pkt_t *pkt,
                                             coap_pkt_t *client_pkt,
                                             client_ep_t *cep,
                                             uri_parser_result_t *urip);

void harness() {
    /* Declare parameters exactly as in the signature */
    coap_pkt_t *pkt;
    coap_pkt_t *client_pkt;
    client_ep_t *cep;
    uri_parser_result_t *urip;

    /* Allocate and constrain struct pointer sizes */
    size_t pkt_len;
    __CPROVER_assume(pkt_len >= sizeof(coap_pkt_t));
    pkt = (coap_pkt_t *)malloc(pkt_len);

    size_t client_pkt_len;
    __CPROVER_assume(client_pkt_len >= sizeof(coap_pkt_t));
    client_pkt = (coap_pkt_t *)malloc(client_pkt_len);

    size_t cep_len;
    __CPROVER_assume(cep_len >= sizeof(client_ep_t));
    cep = (client_ep_t *)malloc(cep_len);

    size_t urip_len;
    __CPROVER_assume(urip_len >= sizeof(uri_parser_result_t));
    urip = (uri_parser_result_t *)malloc(urip_len);

    /* Call the function under test */
    (void)_gcoap_forward_proxy_copy_options(pkt, client_pkt, cep, urip);
}
