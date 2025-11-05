#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

#include "net/nanocoap.h"
#include "net/gcoap.h"
#include "sys/net/application_layer/gcoap/include/forward_proxy_internal.h"
#include "uri_parser.h"

/* Model: allow opt.opt_num/value and return value to be nondet so we can enter option handling */
ssize_t coap_opt_get_next(const coap_pkt_t *pkt, coap_optpos_t *opt,
                          uint8_t **value, bool first)
{
    (void)pkt;
    (void)first;
    ssize_t ret;        /* nondet */
    uint16_t opt_num;   /* nondet */
    uint8_t *val_ptr;   /* nondet */

    opt->opt_num = opt_num;
    *value = val_ptr;
    return ret;
}

/* Model: coap_opt_add_chars should not dereference inputs; just return nondet */
ssize_t coap_opt_add_chars(coap_pkt_t *pkt, uint16_t optnum, const char *str, size_t len, char sep)
{
    (void)pkt;
    (void)optnum;
    (void)str;
    (void)len;
    (void)sep;
    ssize_t ret; /* nondet */
    return ret;
}

/* Function under test */
extern int _gcoap_forward_proxy_copy_options(coap_pkt_t *pkt,
                                             coap_pkt_t *client_pkt,
                                             client_ep_t *cep,
                                             uri_parser_result_t *urip);

void harness(void) {
    coap_pkt_t *pkt;
    coap_pkt_t *client_pkt;
    client_ep_t *cep;
    uri_parser_result_t *urip;

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
