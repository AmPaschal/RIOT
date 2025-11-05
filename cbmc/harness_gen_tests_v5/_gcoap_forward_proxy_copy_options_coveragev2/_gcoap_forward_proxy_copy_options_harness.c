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

/* Function model that ensures at least one ETAG option is observed while preserving
   nondeterminism for other iterations to avoid coverage regression. */
ssize_t coap_opt_get_next(const coap_pkt_t *pkt, coap_optpos_t *opt,
                          uint8_t **value, bool first)
{
    (void)pkt;
    (void)first;

    static int first_call_handled = 0;

    if (!first_call_handled) {
        /* Force one satisfiable iteration for the guarded block */
        first_call_handled = 1;
        opt->opt_num = COAP_OPT_ETAG;
        ssize_t len;
        /* Ensure non-negative length for the ETAG case */
        __CPROVER_assume(len >= 0);
        size_t buf_size;
        __CPROVER_assume(buf_size >= (size_t)len);
        uint8_t *buf = (uint8_t *)malloc(buf_size);
        *value = buf;
        return len;
    }

    /* Subsequent calls: behave nondeterministically as in the original stub */
    ssize_t len;
    uint16_t opt_num;
    opt->opt_num = opt_num;
    size_t buf_size;
    __CPROVER_assume(buf_size >= (len >= 0 ? (size_t)len : 0));
    uint8_t *buf = (uint8_t *)malloc(buf_size);
    *value = buf;
    return len;
}

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

    (void)_gcoap_forward_proxy_copy_options(pkt, client_pkt, cep, urip);
}
