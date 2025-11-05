#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

#include "net/gnrc/pkt.h"
#include "net/gnrc/pktbuf.h"
#include "sys/net/gnrc/transport_layer/tcp/include/gnrc_tcp_common.h"

/* Stubs */

gnrc_pktsnip_t *gnrc_pktbuf_start_write(gnrc_pktsnip_t *pkt) {
    (void)pkt; /* parameter unused in stub */
    size_t ret_len;
    __CPROVER_assume(ret_len >= sizeof(gnrc_pktsnip_t));
    gnrc_pktsnip_t *ret = (gnrc_pktsnip_t *)malloc(ret_len);
    return ret;
}

_gnrc_tcp_common_tcb_list_t *_gnrc_tcp_common_get_tcb_list(void) {
    size_t list_len;
    __CPROVER_assume(list_len >= sizeof(_gnrc_tcp_common_tcb_list_t));
    _gnrc_tcp_common_tcb_list_t *list = (_gnrc_tcp_common_tcb_list_t *)malloc(list_len);
    return list;
}

gnrc_pktsnip_t *gnrc_pktbuf_mark(gnrc_pktsnip_t *pkt, size_t size, gnrc_nettype_t type) {
    (void)pkt; (void)size; (void)type; /* parameters unused in stub */
    size_t ret_len;
    __CPROVER_assume(ret_len >= sizeof(gnrc_pktsnip_t));
    gnrc_pktsnip_t *ret = (gnrc_pktsnip_t *)malloc(ret_len);
    return ret;
}


gnrc_pktsnip_t *gnrc_pktsnip_search_type(gnrc_pktsnip_t *pkt, gnrc_nettype_t type) {
    (void)pkt; (void)type; /* parameters unused in stub */
    size_t ret_len;
    __CPROVER_assume(ret_len >= sizeof(gnrc_pktsnip_t));
    gnrc_pktsnip_t *ret = (gnrc_pktsnip_t *)malloc(ret_len);
    return ret;
}

/* Prototype of the function under test */
int _receive(gnrc_pktsnip_t *pkt);

void harness(void) {
    size_t pkt_len;
    __CPROVER_assume(pkt_len >= sizeof(gnrc_pktsnip_t));
    gnrc_pktsnip_t *pkt = (gnrc_pktsnip_t *)malloc(pkt_len);

    _receive(pkt);
}
