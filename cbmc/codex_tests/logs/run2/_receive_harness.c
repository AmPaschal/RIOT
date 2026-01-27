#include <stdlib.h>
#include <stdint.h>

#define MODULE_GNRC_IPV6 1

#include "sys/net/gnrc/transport_layer/tcp/gnrc_tcp_eventloop.c"

static _gnrc_tcp_common_tcb_list_t tcb_list;

static gnrc_pktsnip_t *alloc_snip(size_t data_len)
{
    gnrc_pktsnip_t *snip = malloc(sizeof(gnrc_pktsnip_t));
    __CPROVER_assume(snip != NULL);
    if (data_len > 0) {
        snip->data = malloc(data_len);
        __CPROVER_assume(snip->data != NULL);
    }
    else {
        snip->data = NULL;
    }
    snip->size = data_len;
    snip->next = NULL;
    snip->users = 1;
    return snip;
}

gnrc_pktsnip_t *gnrc_pktbuf_start_write(gnrc_pktsnip_t *pkt)
{
    _Bool can_write;
    if (!can_write) {
        return NULL;
    }
    return pkt;
}

void gnrc_pktbuf_release(gnrc_pktsnip_t *pkt)
{
    (void)pkt;
}

gnrc_pktsnip_t *gnrc_pktsnip_search_type(gnrc_pktsnip_t *pkt, gnrc_nettype_t type)
{
    if (pkt == NULL) {
        return NULL;
    }
    if (pkt->type == type) {
        return pkt;
    }
    gnrc_pktsnip_t *next = pkt->next;
    if (next == NULL) {
        return NULL;
    }
    if (next->type == type) {
        return next;
    }
    gnrc_pktsnip_t *next2 = next->next;
    if (next2 == NULL) {
        return NULL;
    }
    if (next2->type == type) {
        return next2;
    }
    return NULL;
}

gnrc_pktsnip_t *gnrc_pktbuf_mark(gnrc_pktsnip_t *pkt, size_t size, gnrc_nettype_t type)
{
    (void)size;
    (void)type;
    _Bool mark_ok;
    if (!mark_ok) {
        return NULL;
    }
    return pkt;
}

uint16_t _gnrc_tcp_pkt_calc_csum(const gnrc_pktsnip_t *hdr,
                                 const gnrc_pktsnip_t *pseudo_hdr,
                                 const gnrc_pktsnip_t *payload)
{
    (void)hdr;
    (void)pseudo_hdr;
    (void)payload;
    return 0;
}

_gnrc_tcp_common_tcb_list_t *_gnrc_tcp_common_get_tcb_list(void)
{
    return &tcb_list;
}

_gnrc_tcp_fsm_state_t _gnrc_tcp_fsm_get_state(gnrc_tcp_tcb_t *tcb)
{
    (void)tcb;
    _gnrc_tcp_fsm_state_t state = FSM_STATE_LISTEN;
    return state;
}

int _gnrc_tcp_fsm(gnrc_tcp_tcb_t *tcb, _gnrc_tcp_fsm_event_t event,
                  gnrc_pktsnip_t *in_pkt, void *buf, size_t len)
{
    (void)tcb;
    (void)event;
    (void)in_pkt;
    (void)buf;
    (void)len;
    return 0;
}

int _gnrc_tcp_pkt_build_reset_from_pkt(gnrc_pktsnip_t **out_pkt,
                                       gnrc_pktsnip_t *in_pkt)
{
    *out_pkt = in_pkt;
    return 0;
}

int _gnrc_netapi_send_recv(kernel_pid_t pid, gnrc_pktsnip_t *pkt, uint16_t type)
{
    (void)pid;
    (void)pkt;
    (void)type;
    int res;
    return res;
}

bool ipv6_addr_equal(const ipv6_addr_t *a, const ipv6_addr_t *b)
{
    (void)a;
    (void)b;
    return 1;
}

bool ipv6_addr_is_unspecified(const ipv6_addr_t *a)
{
    (void)a;
    return 0;
}

void harness(void)
{
    gnrc_pktsnip_t *payload = alloc_snip(0);
    gnrc_pktsnip_t *tcp_snip = alloc_snip(sizeof(tcp_hdr_t));
    gnrc_pktsnip_t *ip_snip = alloc_snip(sizeof(ipv6_hdr_t));

    payload->type = GNRC_NETTYPE_UNDEF;
    _Bool has_tcp_type;
    tcp_snip->type = has_tcp_type ? GNRC_NETTYPE_TCP : GNRC_NETTYPE_UNDEF;
    ip_snip->type = GNRC_NETTYPE_IPV6;

    payload->next = tcp_snip;
    _Bool include_ip;
    tcp_snip->next = include_ip ? ip_snip : NULL;

    size_t tcp_size;
    tcp_snip->size = tcp_size;

    tcp_hdr_t *hdr = (tcp_hdr_t *)tcp_snip->data;
    uint16_t off_ctl;
    uint16_t src_port;
    uint16_t dst_port;
    uint16_t checksum;
    hdr->off_ctl = byteorder_htons(off_ctl);
    hdr->src_port = byteorder_htons(src_port);
    hdr->dst_port = byteorder_htons(dst_port);
    hdr->checksum = byteorder_htons(checksum);

    gnrc_tcp_tcb_t *tcb = malloc(sizeof(gnrc_tcp_tcb_t));
    __CPROVER_assume(tcb != NULL);
    tcb->next = NULL;
    tcb->address_family = AF_INET6;
    tcb->local_port = 0;
    tcb->peer_port = 0;

    tcb_list.head = tcb;
    tcb_list.lock = (mutex_t)MUTEX_INIT;

    _Bool start_at_payload;
    gnrc_pktsnip_t *pkt = start_at_payload ? payload : tcp_snip;

    _receive(pkt);
}
