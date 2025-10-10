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

/*Stub to improve coverage*/
ssize_t coap_opt_get_next(const coap_pkt_t *pkt, coap_optpos_t *opt,
                          uint8_t **value, bool init_opt) {
                            uint8_t value_havoc;
                            *value = value_havoc;

                            uint16_t opt_num;
                            uint16_t offset;

                            opt->opt_num = opt_num;
                            opt->offset = offset;

                            ssize_t ret;
                            return ret;
                          }

void harness(void)
{
    coap_pkt_t *pkt = malloc(sizeof(coap_pkt_t));
    coap_pkt_t *client_pkt = malloc(sizeof(coap_pkt_t));
    __CPROVER_assume(client_pkt != NULL);
    client_ep_t *cep = malloc(sizeof(client_ep_t));
    uri_parser_result_t *urip = malloc(sizeof(uri_parser_result_t));
    
    /* Call the function under test */
    (void)_gcoap_forward_proxy_copy_options(pkt, client_pkt, cep, urip);
}
