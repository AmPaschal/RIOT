#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

#include "net/nanocoap.h"
#include "net/gcoap.h"
#include "sys/net/application_layer/gcoap/include/forward_proxy_internal.h"
#include "uri_parser.h"

/* Minimal function model to havoc opt and value so that opt.opt_num can become COAP_OPT_ETAG */
ssize_t coap_opt_get_next(const coap_pkt_t *pkt, coap_optpos_t *opt,
                          uint8_t **value, bool init_opt) {
    uint16_t opt_num_nd;
    opt->opt_num = opt_num_nd;

    uint8_t *val_nd;
    *value = val_nd;

    ssize_t len_nd;
    return len_nd; /* nondet; CBMC may pick >=0 to enter the branch */
}

/* Stub for gcoap_req_send to invoke the response handler, reaching _forward_resp_handler */
ssize_t gcoap_req_send(const uint8_t *buf, size_t len,
                       const sock_udp_ep_t *remote, const sock_udp_ep_t *local,
                       gcoap_resp_handler_t resp_handler, void *context,
                       gcoap_socket_type_t tl_type) {
    if (resp_handler) {
        gcoap_request_memo_t memo_nd;      /* fields left nondet */
        /* Ensure context is passed through as expected by _forward_resp_handler */
        memo_nd.context = context;
        coap_pkt_t pdu_nd;                 /* nondet packet */
        resp_handler(&memo_nd, &pdu_nd, remote);
    }
    ssize_t ret_nd;
    return ret_nd;
}

/* Externs from forward_proxy.c not declared in public headers */
extern int _gcoap_forward_proxy_copy_options(coap_pkt_t *pkt,
                                             coap_pkt_t *client_pkt,
                                             client_ep_t *cep,
                                             uri_parser_result_t *urip);
extern int gcoap_forward_proxy_req_send(client_ep_t *cep);

/* Access the global listener to reach the static matcher through its function pointer */
extern gcoap_listener_t forward_proxy_listener;

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

    /* Exercise the copy options path (existing) */
    (void)_gcoap_forward_proxy_copy_options(pkt, client_pkt, cep, urip);

    /* Exercise the response path (existing) */
    (void)gcoap_forward_proxy_req_send(cep);

    /* NEW: Exercise the forward proxy request matcher via the listener */
    const coap_resource_t *res_out;
    (void)forward_proxy_listener.request_matcher(&forward_proxy_listener, &res_out, pkt);
}
