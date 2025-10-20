#include <stddef.h>
#include <stdlib.h>

#include "net/nanocoap.h"
#include "forward_proxy_internal.h"
#include "uri_parser.h"

/* Function under test */
extern int _gcoap_forward_proxy_copy_options(coap_pkt_t *pkt,
                                             coap_pkt_t *client_pkt,
                                             client_ep_t *cep,
                                             uri_parser_result_t *urip);

void harness() {
    /* pkt */
    size_t pkt_len;
    __CPROVER_assume(pkt_len >= sizeof(coap_pkt_t));
    coap_pkt_t *pkt = malloc(pkt_len);

    /* client_pkt */
    size_t client_pkt_len;
    __CPROVER_assume(client_pkt_len >= sizeof(coap_pkt_t));
    coap_pkt_t *client_pkt = malloc(client_pkt_len);

    /* cep */
    size_t cep_len;
    __CPROVER_assume(cep_len >= sizeof(client_ep_t));
    client_ep_t *cep = malloc(cep_len);

    /* urip */
    size_t urip_len;
    __CPROVER_assume(urip_len >= sizeof(uri_parser_result_t));
    uri_parser_result_t *urip = malloc(urip_len);

    (void)_gcoap_forward_proxy_copy_options(pkt, client_pkt, cep, urip);
}
