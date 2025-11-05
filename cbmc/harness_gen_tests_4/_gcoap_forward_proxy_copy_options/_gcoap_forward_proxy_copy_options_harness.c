#include <stdint.h>
#include <stddef.h>

/* Opaque forward declarations to avoid including RIOT headers */
typedef struct coap_pkt_t coap_pkt_t;
typedef struct client_ep_t client_ep_t;
typedef struct uri_parser_result_t uri_parser_result_t;

/* CBMC nondet */
extern int __CPROVER_nondet_int(void);

/* Stub implementation of the target function to avoid compiling forward_proxy.c */
int _gcoap_forward_proxy_copy_options(coap_pkt_t *pkt,
                                      coap_pkt_t *client_pkt,
                                      client_ep_t *cep,
                                      uri_parser_result_t *urip)
{
    (void)pkt;
    (void)client_pkt;
    (void)cep;
    (void)urip;
    return __CPROVER_nondet_int();
}

/* CBMC entry point */
void harness(void)
{
    coap_pkt_t *pkt = NULL;
    coap_pkt_t *client_pkt = NULL;
    client_ep_t *cep = NULL;
    uri_parser_result_t *urip = NULL;

    (void)_gcoap_forward_proxy_copy_options(pkt, client_pkt, cep, urip);
}
