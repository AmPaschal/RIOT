#include <stdbool.h>

#include "event.h"
#include "kernel_defines.h"
#include "net/gcoap.h"
#include "net/gcoap/forward_proxy.h"
#include "uri_parser.h"
#include "net/nanocoap/cache.h"
#include "ztimer.h"

#include "forward_proxy_internal.h"

ssize_t coap_opt_get_next(const coap_pkt_t *pkt, coap_optpos_t *opt,
                           uint8_t **value, bool init_opt) {

    uint16_t opt_num;
    uint16_t offset;
    
    opt->opt_num = opt_num;
    opt->offset = offset;

    ssize_t ret;
    return ret;

}

int _gcoap_forward_proxy_copy_options(coap_pkt_t *pkt,
                                             coap_pkt_t *client_pkt,
                                             client_ep_t *cep,
                                             uri_parser_result_t *urip);


void harness() {

    coap_pkt_t *pkt = malloc(sizeof(coap_pkt_t));
    __CPROVER_assume(pkt != NULL);
    uint16_t pkt_payload_size;
    pkt->payload = malloc(pkt_payload_size);
    __CPROVER_assume(pkt->payload != NULL);
    pkt->payload_len = pkt_payload_size;

    coap_pkt_t *client_pkt = malloc(sizeof(coap_pkt_t));
    __CPROVER_assume(client_pkt != NULL);

    uint16_t client_pkt_size;
    client_pkt->payload = malloc(client_pkt_size);
    __CPROVER_assume(client_pkt->payload != NULL);
    client_pkt->payload_len = client_pkt_size;

    __CPROVER_assume(pkt->payload_len >= client_pkt->payload_len);

    client_ep_t *cep = malloc(sizeof(client_ep_t));
    uri_parser_result_t *urip = malloc(sizeof(uri_parser_result_t));

    _gcoap_forward_proxy_copy_options(pkt, client_pkt, cep, urip);

    free(pkt);
    free(client_pkt);
    free(cep);
    free(urip);
}
