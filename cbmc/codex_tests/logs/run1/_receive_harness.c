#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#include "sys/net/gnrc/transport_layer/tcp/gnrc_tcp_eventloop.c"

extern _Bool __CPROVER_nondet_bool(void);
extern uint16_t __CPROVER_nondet_ushort(void);
extern uint32_t __CPROVER_nondet_uint(void);
extern size_t __CPROVER_nondet_size_t(void);
extern int __CPROVER_nondet_int(void);

static _gnrc_tcp_common_tcb_list_t tcb_list;
static gnrc_tcp_tcb_t tcb1;
static gnrc_tcp_tcb_t tcb2;

gnrc_pktsnip_t *gnrc_pktbuf_start_write(gnrc_pktsnip_t *pkt)
{
    if (pkt == NULL) {
        return NULL;
    }
    return __CPROVER_nondet_bool() ? pkt : NULL;
}

void gnrc_pktbuf_release(gnrc_pktsnip_t *pkt)
{
    (void)pkt;
}

gnrc_pktsnip_t *gnrc_pktsnip_search_type(gnrc_pktsnip_t *pkt, gnrc_nettype_t type)
{
    while (pkt != NULL) {
        if (pkt->type == type) {
            return pkt;
        }
        pkt = pkt->next;
    }
    return NULL;
}

gnrc_pktsnip_t *gnrc_pktbuf_mark(gnrc_pktsnip_t *pkt, size_t size, gnrc_nettype_t type)
{
    (void)size;
    (void)type;
    if (pkt == NULL) {
        return NULL;
    }
    return __CPROVER_nondet_bool() ? pkt : NULL;
}

uint16_t _gnrc_tcp_pkt_calc_csum(const gnrc_pktsnip_t *hdr,
                                 const gnrc_pktsnip_t *pseudo_hdr,
                                 const gnrc_pktsnip_t *payload)
{
    (void)hdr;
    (void)pseudo_hdr;
    (void)payload;
    return __CPROVER_nondet_ushort();
}

_gnrc_tcp_common_tcb_list_t *_gnrc_tcp_common_get_tcb_list(void)
{
    return &tcb_list;
}

void mutex_lock(mutex_t *mutex)
{
    (void)mutex;
}

void mutex_unlock(mutex_t *mutex)
{
    (void)mutex;
}

_gnrc_tcp_fsm_state_t _gnrc_tcp_fsm_get_state(gnrc_tcp_tcb_t *tcb)
{
    (void)tcb;
    return (_gnrc_tcp_fsm_state_t)__CPROVER_nondet_uint();
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

int _gnrc_tcp_pkt_build_reset_from_pkt(gnrc_pktsnip_t **out_pkt, gnrc_pktsnip_t *in_pkt)
{
    (void)in_pkt;
    if (out_pkt == NULL) {
        return -1;
    }
    if (!__CPROVER_nondet_bool()) {
        *out_pkt = NULL;
        return -ENOMEM;
    }
    *out_pkt = malloc(sizeof(gnrc_pktsnip_t));
    if (*out_pkt == NULL) {
        return -ENOMEM;
    }
    (*out_pkt)->next = NULL;
    (*out_pkt)->data = NULL;
    (*out_pkt)->size = 0;
    (*out_pkt)->type = GNRC_NETTYPE_UNDEF;
    return 0;
}

int _gnrc_netapi_send_recv(kernel_pid_t pid, gnrc_pktsnip_t *pkt, uint16_t type)
{
    (void)pid;
    (void)pkt;
    (void)type;
    return __CPROVER_nondet_int();
}

int gnrc_netapi_dispatch(gnrc_nettype_t type, uint32_t demux_ctx, uint16_t cmd,
                         gnrc_pktsnip_t *pkt)
{
    (void)type;
    (void)demux_ctx;
    (void)cmd;
    (void)pkt;
    return __CPROVER_nondet_int();
}

int msg_receive(msg_t *msg)
{
    (void)msg;
    return 0;
}

int msg_reply(msg_t *msg, msg_t *reply)
{
    (void)msg;
    (void)reply;
    return 0;
}

void msg_init_queue(msg_t *queue, size_t size)
{
    (void)queue;
    (void)size;
}

kernel_pid_t thread_getpid(void)
{
    return (kernel_pid_t)__CPROVER_nondet_int();
}

kernel_pid_t thread_create(char *stack, int stacksize, char priority, int flags,
                           void *(*function)(void *), void *arg, const char *name)
{
    (void)stack;
    (void)stacksize;
    (void)priority;
    (void)flags;
    (void)function;
    (void)arg;
    (void)name;
    return (kernel_pid_t)__CPROVER_nondet_int();
}

void gnrc_netreg_entry_init_pid(gnrc_netreg_entry_t *entry, uint32_t demux_ctx,
                                kernel_pid_t pid)
{
    (void)entry;
    (void)demux_ctx;
    (void)pid;
}

int gnrc_netreg_register(gnrc_nettype_t type, gnrc_netreg_entry_t *entry)
{
    (void)type;
    (void)entry;
    return 0;
}

void evtimer_add_msg(evtimer_t *evtimer, evtimer_msg_event_t *event, kernel_pid_t pid)
{
    (void)evtimer;
    (void)event;
    (void)pid;
}

void evtimer_del(evtimer_t *evtimer, evtimer_event_t *event)
{
    (void)evtimer;
    (void)event;
}

void evtimer_init_msg(evtimer_t *evtimer)
{
    (void)evtimer;
}

bool ipv6_addr_equal(const ipv6_addr_t *a, const ipv6_addr_t *b)
{
    (void)a;
    (void)b;
    return __CPROVER_nondet_bool();
}

bool ipv6_addr_is_unspecified(const ipv6_addr_t *a)
{
    (void)a;
    return __CPROVER_nondet_bool();
}

void harness(void)
{
    gnrc_pktsnip_t *pkt = malloc(sizeof(gnrc_pktsnip_t));
    __CPROVER_assume(pkt != NULL);
    gnrc_pktsnip_t *ip = malloc(sizeof(gnrc_pktsnip_t));
    __CPROVER_assume(ip != NULL);
    tcp_hdr_t *tcp_hdr = malloc(sizeof(tcp_hdr_t));
    __CPROVER_assume(tcp_hdr != NULL);
    ipv6_hdr_t *ipv6_hdr = malloc(sizeof(ipv6_hdr_t));
    __CPROVER_assume(ipv6_hdr != NULL);

    pkt->next = __CPROVER_nondet_bool() ? ip : NULL;
    pkt->data = tcp_hdr;
    pkt->type = __CPROVER_nondet_bool() ? GNRC_NETTYPE_TCP : GNRC_NETTYPE_UNDEF;
    pkt->size = __CPROVER_nondet_size_t();

    ip->next = NULL;
    ip->data = ipv6_hdr;
    ip->type = GNRC_NETTYPE_IPV6;
    ip->size = sizeof(ipv6_hdr_t);

    uint16_t off_ctl = __CPROVER_nondet_ushort();
    uint16_t src_port = __CPROVER_nondet_ushort();
    uint16_t dst_port = __CPROVER_nondet_ushort();
    uint16_t checksum = __CPROVER_nondet_ushort();

    tcp_hdr->off_ctl = byteorder_htons(off_ctl);
    tcp_hdr->src_port = byteorder_htons(src_port);
    tcp_hdr->dst_port = byteorder_htons(dst_port);
    tcp_hdr->checksum = byteorder_htons(checksum);

    _Bool use_tcb1 = __CPROVER_nondet_bool();
    _Bool use_tcb2 = __CPROVER_nondet_bool();

    if (use_tcb1) {
        tcb_list.head = &tcb1;
        tcb1.next = use_tcb2 ? &tcb2 : NULL;
    }
    else {
        tcb_list.head = NULL;
    }
    tcb2.next = NULL;

    tcb1.address_family = AF_INET6;
    tcb1.local_port = dst_port;
    tcb1.peer_port = src_port;
    memcpy(tcb1.local_addr, &ipv6_hdr->dst, sizeof(ipv6_addr_t));
    memcpy(tcb1.peer_addr, &ipv6_hdr->src, sizeof(ipv6_addr_t));

    _receive(pkt);
}
