#include <stdlib.h>
#include <string.h>

#include "net/nanocoap.h"
#include "forward_proxy_internal.h"
#include "uri_parser.h"

/* Prototype of the function under test */
extern int _gcoap_forward_proxy_copy_options(coap_pkt_t *pkt,
                                             coap_pkt_t *client_pkt,
                                             client_ep_t *cep,
                                             uri_parser_result_t *urip);

void harness(void) {
    /* Allocate and assume non-NULL for struct pointer parameters */
    coap_pkt_t *pkt = (coap_pkt_t *)malloc(sizeof(coap_pkt_t));
    __CPROVER_assume(pkt != NULL);

    coap_pkt_t *client_pkt = (coap_pkt_t *)malloc(sizeof(coap_pkt_t));
    __CPROVER_assume(client_pkt != NULL);

    client_ep_t *cep = (client_ep_t *)malloc(sizeof(client_ep_t));
    __CPROVER_assume(cep != NULL);

    uri_parser_result_t *urip = (uri_parser_result_t *)malloc(sizeof(uri_parser_result_t));
    __CPROVER_assume(urip != NULL);

    /* Call the function under test */
    (void)_gcoap_forward_proxy_copy_options(pkt, client_pkt, cep, urip);
}
