#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef NULL
#define NULL ((void*)0)
#endif

// #anon_enum$STATUS_STOPPED=0$STATUS_ZOMBIE=1$STATUS_SLEEPING=2$STATUS_MUTEX_BLOCKED=3$STATUS_RECEIVE_BLOCKED=4$STATUS_SEND_BLOCKED=5$STATUS_REPLY_BLOCKED=6$STATUS_FLAG_BLOCKED_ANY=7$STATUS_FLAG_BLOCKED_ALL=8$STATUS_MBOX_BLOCKED=9$STATUS_COND_BLOCKED=A$STATUS_RUNNING=B$STATUS_PENDING=C$STATUS_NUMOF=D
// file ../../../core/include/sched.h line 163
enum anonymous$9 { STATUS_STOPPED=0, STATUS_ZOMBIE=1, STATUS_SLEEPING=2, STATUS_MUTEX_BLOCKED=3, STATUS_RECEIVE_BLOCKED=4, STATUS_SEND_BLOCKED=5, STATUS_REPLY_BLOCKED=6, STATUS_FLAG_BLOCKED_ANY=7, STATUS_FLAG_BLOCKED_ALL=8, STATUS_MBOX_BLOCKED=9, STATUS_COND_BLOCKED=10, STATUS_RUNNING=11, STATUS_PENDING=12, STATUS_NUMOF=13 };

// tag-#anon#ST[*{SYMztimer_clock#0={ST[SYMztimer_base#1={ST[*{SYMztimer_base#1}'next'|U32'offset']}'list'|*{cSYM#2={ST[*{V(l*{SYMztimer_clock#0}|U32)->V}'set'|*{U32(l*{SYMztimer_clock#0})->U32}'now'|*{V(l*{SYMztimer_clock#0})->V}'cancel']}}'ops'|*{SYMztimer_base#1}'last'|U16'adjust_set'|U16'adjust_sleep']}}'clock'|SYM#3={ST[SYMztimer_base#1'base'|*{V(l*{V})->V}'callback'|*{V}'arg']}'timer'|*{SYM#4={ST[SYMlist_node#5={ST[*{SYMlist_node#5}'next']}'event_list'|*{SYM_thread#6={ST[*{S8}'sp'|EN[0'STATUS_STOPPED'|1'STATUS_ZOMBIE'|2'STATUS_SLEEPING'|3'STATUS_MUTEX_BLOCKED'|4'STATUS_RECEIVE_BLOCKED'|5'STATUS_SEND_BLOCKED'|6'STATUS_REPLY_BLOCKED'|7'STATUS_FLAG_BLOCKED_ANY'|8'STATUS_FLAG_BLOCKED_ALL'|9'STATUS_MBOX_BLOCKED'|A'STATUS_COND_BLOCKED'|B'STATUS_RUNNING'|C'STATUS_PENDING'|D'STATUS_NUMOF'{U32}'status'|U8'priority'|U8'$pad3'|S16'pid'|SYMlist_node#5'rq_entry']}}'waiter']}}'queue'|*{SYMevent#7={ST[SYMlist_node#5'list_node'|*{V(l*{SYMevent#7})->V}'handler']}}'event']
// file ../../../sys/include/event/timeout.h line 50
struct anonymous$7;

// tag-#anon#ST[*{V(l*{SYMztimer_clock#0={ST?}}|U32)->V}'set'|*{U32(l*{SYMztimer_clock#0})->U32}'now'|*{V(l*{SYMztimer_clock#0})->V}'cancel']
// file ../../../sys/include/ztimer.h line 331
struct anonymous$13;

// tag-#anon#ST[S16'sender_pid'|U16'type'|SYM#0={UN[*{V}'ptr'|U32'value']}'content']
// file ../../../core/include/msg.h line 196
struct anonymous$15;

// tag-#anon#ST[SYM#0={ST[SYM#1={UN[U32'id'|SYM#2={ST[U16'netif'|U16'type']}'info']}'ia_id']}'parent'|SYM#3={UN[ARR16{U8}'u8'|ARR8{SYM#4={UN[U16'u16'|ARR2{U8}'u8']}}'u16'|ARR4{SYM#5={UN[U32'u32'|ARR4{U8}'u8'|ARR2{U16}'u16'|ARR2{SYM#4}'b16']}}'u32'|ARR2{SYM#6={UN[U64'u64'|ARR8{U8}'u8'|ARR4{U16}'u16'|ARR2{U32}'u32'|ARR4{SYM#4}'b16'|ARR2{SYM#5}'b32']}}'u64']}'addr'|U8'leased'|U24'$pad3']
// file ../../../sys/net/application_layer/dhcpv6/client.c line 69
struct anonymous$29;

// tag-#anon#ST[SYM#0={ST[SYM#1={UN[U32'id'|SYM#2={ST[U16'netif'|U16'type']}'info']}'ia_id']}'parent'|SYM#3={UN[ARR16{U8}'u8'|ARR8{SYM#4={UN[U16'u16'|ARR2{U8}'u8']}}'u16'|ARR4{SYM#5={UN[U32'u32'|ARR4{U8}'u8'|ARR2{U16}'u16'|ARR2{SYM#4}'b16']}}'u32'|ARR2{SYM#6={UN[U64'u64'|ARR8{U8}'u8'|ARR4{U16}'u16'|ARR2{U32}'u32'|ARR4{SYM#4}'b16'|ARR2{SYM#5}'b32']}}'u64']}'pfx'|U8'pfx_len'|U8'leased'|U16'$pad4']
// file ../../../sys/net/application_layer/dhcpv6/client.c line 58
struct anonymous$32;

// tag-#anon#ST[SYM#0={UN[ARR128{U8}'u8'|SYM#1={ST[SYM#2={UN[U16'u16'|ARR2{U8}'u8']}'type'|SYM#2'l2type']}'duid_l2']}'duid'|U32't1'|U8'pref'|U8'duid_len'|U16'$pad4']
// file ../../../sys/net/application_layer/dhcpv6/client.c line 78
struct anonymous$35;

// tag-#anon#ST[SYM#0={UN[U16'u16'|ARR2{U8}'u8']}'type'|SYM#0'l2type']
// file ../../../sys/include/net/dhcpv6/client.h line 103
struct anonymous$4;

// tag-#anon#ST[SYM#0={UN[U16'u16'|ARR2{U8}'u8']}'type'|SYM#0'len'|ARR0{S8}'mud_string']
// file ../../../sys/net/application_layer/dhcpv6/_dhcpv6.h line 335
struct anonymous;

// tag-#anon#ST[SYM#0={UN[U16'u16'|ARR2{U8}'u8']}'type'|SYM#0'len'|ARR0{SYM#0}'opt_codes']
// file ../../../sys/net/application_layer/dhcpv6/_dhcpv6.h line 187
struct anonymous$28;

// tag-#anon#ST[SYM#0={UN[U16'u16'|ARR2{U8}'u8']}'type'|SYM#0'len'|ARR0{U8}'data']
// file ../../../sys/net/application_layer/dhcpv6/_dhcpv6.h line 134
struct anonymous$1;

// tag-#anon#ST[SYM#0={UN[U16'u16'|ARR2{U8}'u8']}'type'|SYM#0'len'|ARR0{U8}'duid']
// file ../../../sys/net/application_layer/dhcpv6/_dhcpv6.h line 147
struct anonymous$0;

// tag-#anon#ST[SYM#0={UN[U16'u16'|ARR2{U8}'u8']}'type'|SYM#0'len'|SYM#0'code'|ARR0{S8}'msg']
// file ../../../sys/net/application_layer/dhcpv6/_dhcpv6.h line 235
struct anonymous$24;

// tag-#anon#ST[SYM#0={UN[U16'u16'|ARR2{U8}'u8']}'type'|SYM#0'len'|SYM#0'elapsed_time']
// file ../../../sys/net/application_layer/dhcpv6/_dhcpv6.h line 210
struct anonymous$25;

// tag-#anon#ST[SYM#0={UN[U16'u16'|ARR2{U8}'u8']}'type'|SYM#0'len'|SYM#1={UN[ARR16{U8}'u8'|ARR8{SYM#0}'u16'|ARR4{SYM#2={UN[U32'u32'|ARR4{U8}'u8'|ARR2{U16}'u16'|ARR2{SYM#0}'b16']}}'u32'|ARR2{SYM#3={UN[U64'u64'|ARR8{U8}'u8'|ARR4{U16}'u16'|ARR2{U32}'u32'|ARR4{SYM#0}'b16'|ARR2{SYM#2}'b32']}}'u64']}'addr'|SYM#2'pref'|SYM#2'valid'|ARR0{U8}'opts']
// file ../../../sys/net/application_layer/dhcpv6/_dhcpv6.h line 173
struct anonymous$22;

// tag-#anon#ST[SYM#0={UN[U16'u16'|ARR2{U8}'u8']}'type'|SYM#0'len'|SYM#1={UN[U32'u32'|ARR4{U8}'u8'|ARR2{U16}'u16'|ARR2{SYM#0}'b16']}'ia_id'|SYM#1't1'|SYM#1't2'|ARR0{U8}'opts']
// file ../../../sys/net/application_layer/dhcpv6/_dhcpv6.h line 159
struct anonymous$36;

// tag-#anon#ST[SYM#0={UN[U16'u16'|ARR2{U8}'u8']}'type'|SYM#0'len'|SYM#1={UN[U32'u32'|ARR4{U8}'u8'|ARR2{U16}'u16'|ARR2{SYM#0}'b16']}'pref'|SYM#1'valid'|U8'pfx_len'|SYM#2={UN[ARR16{U8}'u8'|ARR8{SYM#0}'u16'|ARR4{SYM#1}'u32'|ARR2{SYM#3={UN[U64'u64'|ARR8{U8}'u8'|ARR4{U16}'u16'|ARR2{U32}'u32'|ARR4{SYM#0}'b16'|ARR2{SYM#1}'b32']}}'u64']}'pfx'|ARR0{U8}'opts']
// file ../../../sys/net/application_layer/dhcpv6/_dhcpv6.h line 286
struct anonymous$30;

// tag-#anon#ST[SYM#0={UN[U16'u16'|ARR2{U8}'u8']}'type'|SYM#0'len'|SYM#1={UN[U32'u32'|ARR4{U8}'u8'|ARR2{U16}'u16'|ARR2{SYM#0}'b16']}'value']
// file ../../../sys/net/application_layer/dhcpv6/_dhcpv6.h line 301
struct anonymous$31;

// tag-#anon#ST[SYM#0={UN[U16'u16'|ARR2{U8}'u8']}'type'|SYM#0'len'|U8'value']
// file ../../../sys/net/application_layer/dhcpv6/_dhcpv6.h line 198
struct anonymous$18;

// tag-#anon#ST[SYM#0={UN[U32'id'|SYM#1={ST[U16'netif'|U16'type']}'info']}'ia_id']
// file ../../../sys/net/application_layer/dhcpv6/client.c line 44
struct anonymous$26;

// tag-#anon#ST[SYMlist_node#0={ST[*{SYMlist_node#0}'next']}'event_list'|*{SYM_thread#1={ST[*{S8}'sp'|EN[0'STATUS_STOPPED'|1'STATUS_ZOMBIE'|2'STATUS_SLEEPING'|3'STATUS_MUTEX_BLOCKED'|4'STATUS_RECEIVE_BLOCKED'|5'STATUS_SEND_BLOCKED'|6'STATUS_REPLY_BLOCKED'|7'STATUS_FLAG_BLOCKED_ANY'|8'STATUS_FLAG_BLOCKED_ALL'|9'STATUS_MBOX_BLOCKED'|A'STATUS_COND_BLOCKED'|B'STATUS_RUNNING'|C'STATUS_PENDING'|D'STATUS_NUMOF'{U32}'status'|U8'priority'|U8'$pad3'|S16'pid'|SYMlist_node#0'rq_entry']}}'waiter']
// file ../../../sys/include/event.h line 156
struct anonymous$8;

// tag-#anon#ST[SYMlist_node#0={ST[*{SYMlist_node#0}'next']}'node']
// file ../../../sys/include/net/netif.h line 71
struct anonymous$3;

// tag-#anon#ST[SYMlist_node#0={ST[*{SYMlist_node#0}'next']}'readers'|SYMlist_node#0'writers'|SYM#1={ST[U32'read_count'|U32'write_count'|U32'mask']}'cib'|*{SYM#2={ST[S16'sender_pid'|U16'type'|SYM#3={UN[*{V}'ptr'|U32'value']}'content']}}'msg_array']
// file ../../../core/include/mbox.h line 41
struct anonymous$12;

// tag-#anon#ST[SYMztimer_base#0={ST[*{SYMztimer_base#0}'next'|U32'offset']}'base'|*{V(l*{V})->V}'callback'|*{V}'arg']
// file ../../../sys/include/ztimer.h line 318
struct anonymous$14;

// tag-#anon#ST[U16'netif'|U16'type']
// file ../../../sys/net/application_layer/dhcpv6/client.c line 47
struct anonymous$33;

// tag-#anon#ST[U32'read_count'|U32'write_count'|U32'mask']
// file ../../../core/lib/include/cib.h line 34
struct anonymous$20;

// tag-#anon#ST[U64'ticks64']
// file ../../../sys/include/xtimer.h line 76
struct anonymous$16;

// tag-#anon#ST[U8'flags']
// file ../../../sys/include/net/sock/udp.h line 310
struct anonymous$23;

// tag-#anon#ST[U8'type'|ARR3{U8}'tid']
// file ../../../sys/net/application_layer/dhcpv6/_dhcpv6.h line 91
struct anonymous$10;

// tag-#anon#UN[*{V}'ptr'|U32'value']
// file ../../../core/include/msg.h line 200
union anonymous$17;

// tag-#anon#UN[ARR128{U8}'u8'|SYM#0={ST[SYM#1={UN[U16'u16'|ARR2{U8}'u8']}'type'|SYM#1'l2type']}'duid_l2']
// file ../../../sys/net/application_layer/dhcpv6/_dhcpv6.h line 119
union anonymous$2;

// tag-#anon#UN[ARR16{U8}'ipv6'|ARR4{U8}'ipv4'|U32'ipv4_u32']
// file ../../../sys/include/net/sock.h line 186
union anonymous$27;

// tag-#anon#UN[ARR16{U8}'u8'|ARR8{SYM#0={UN[U16'u16'|ARR2{U8}'u8']}}'u16'|ARR4{SYM#1={UN[U32'u32'|ARR4{U8}'u8'|ARR2{U16}'u16'|ARR2{SYM#0}'b16']}}'u32'|ARR2{SYM#2={UN[U64'u64'|ARR8{U8}'u8'|ARR4{U16}'u16'|ARR2{U32}'u32'|ARR4{SYM#0}'b16'|ARR2{SYM#1}'b32']}}'u64']
// file ../../../sys/include/net/ipv6/addr.h line 72
union anonymous$5;

// tag-#anon#UN[S16'pid']
// file ../../../sys/include/net/gnrc/netreg.h line 193
union anonymous$21;

// tag-#anon#UN[U16'u16'|ARR2{U8}'u8']
// file ../../../sys/include/byteorder.h line 38
union anonymous$19;

// tag-#anon#UN[U32'id'|SYM#0={ST[U16'netif'|U16'type']}'info']
// file ../../../sys/net/application_layer/dhcpv6/client.c line 45
union anonymous$34;

// tag-#anon#UN[U32'u32'|ARR4{U8}'u8'|ARR2{U16}'u16'|ARR2{SYM#0={UN[U16'u16'|ARR2{U8}'u8']}}'b16']
// file ../../../sys/include/byteorder.h line 84
union anonymous$11;

// tag-#anon#UN[U64'u64'|ARR8{U8}'u8'|ARR4{U16}'u16'|ARR2{U32}'u32'|ARR4{SYM#0={UN[U16'u16'|ARR2{U8}'u8']}}'b16'|ARR2{SYM#1={UN[U32'u32'|ARR4{U8}'u8'|ARR2{U16}'u16'|ARR2{SYM#0}'b16']}}'b32']
// file ../../../sys/include/byteorder.h line 96
union anonymous$6;

// tag-_sock_tl_ep
// file ../../../sys/include/net/sock.h line 215
struct _sock_tl_ep;

// tag-_thread
// file ../../../core/include/sched.h line 155
struct _thread;

// tag-event
// file ../../../sys/include/event.h line 138
struct event;

// tag-gnrc_netreg_entry
// file ../../../sys/include/net/gnrc/netreg.h line 167
struct gnrc_netreg_entry;

// tag-gnrc_sock_reg
// file ../../../sys/net/gnrc/sock/include/sock_types.h line 74
struct gnrc_sock_reg;

// tag-iolist
// file ../../../sys/include/iolist.h line 34
struct iolist;

// tag-list_node
// file ../../../core/lib/include/list.h line 40
struct list_node;

// tag-sock_udp
// file ../../../sys/include/net/sock/udp.h line 301
struct sock_udp;

// tag-xtimer
// file ../../../sys/include/xtimer.h line 97
struct xtimer;

// tag-ztimer_base
// file ../../../sys/include/ztimer.h line 284
struct ztimer_base;

// tag-ztimer_clock
// file ../../../sys/include/ztimer.h line 289
struct ztimer_clock;


typedef struct anonymous$29 addr_lease_t;
typedef union anonymous$19 be_uint16_t;
typedef union anonymous$11 be_uint32_t;
typedef struct anonymous$20 cib_t;
typedef struct list_node clist_node_t;
typedef struct anonymous$4 dhcpv6_duid_l2_t;
typedef union anonymous$2 dhcpv6_duid_t;
typedef struct anonymous$10 dhcpv6_msg_t;
typedef struct anonymous$0 dhcpv6_opt_duid_t;
typedef struct anonymous$25 dhcpv6_opt_elapsed_time_t;
typedef struct anonymous$36 dhcpv6_opt_ia_na_t;
typedef struct anonymous$36 dhcpv6_opt_ia_pd_t;
typedef struct anonymous$22 dhcpv6_opt_iaaddr_t;
typedef struct anonymous$30 dhcpv6_opt_iapfx_t;
typedef struct anonymous$31 dhcpv6_opt_imr_t;
typedef struct anonymous$31 dhcpv6_opt_irt_t;
typedef struct anonymous dhcpv6_opt_mud_url_t;
typedef struct anonymous$28 dhcpv6_opt_oro_t;
typedef struct anonymous$18 dhcpv6_opt_pref_t;
typedef struct anonymous$31 dhcpv6_opt_smr_t;
typedef struct anonymous$24 dhcpv6_opt_status_t;
typedef struct anonymous$1 dhcpv6_opt_t;
typedef struct anonymous$8 event_queue_t;
typedef struct event event_t;
typedef void (*event_handler_t)(event_t *);
typedef struct anonymous$7 event_timeout_t;
typedef struct gnrc_netreg_entry gnrc_netreg_entry_t;
typedef struct gnrc_sock_reg gnrc_sock_reg_t;
typedef signed short int int16_t;
typedef struct iolist iolist_t;
typedef union anonymous$5 ipv6_addr_t;
typedef signed short int kernel_pid_t;
typedef struct anonymous$26 lease_t;
typedef struct anonymous$12 mbox_t;
typedef struct anonymous$15 msg_t;
typedef struct anonymous$3 netif_t;
typedef union anonymous$19 network_uint16_t;
typedef union anonymous$11 network_uint32_t;
typedef struct anonymous$32 pfx_lease_t;
typedef struct anonymous$35 server_t;
typedef unsigned int size_t;
typedef unsigned char sock_aux_flags_t;
typedef struct anonymous$23 sock_udp_aux_rx_t;
typedef struct anonymous$23 sock_udp_aux_tx_t;
typedef struct _sock_tl_ep sock_udp_ep_t;
typedef struct sock_udp sock_udp_t;
typedef signed int ssize_t;
typedef enum anonymous$9 thread_status_t;
typedef struct _thread thread_t;
typedef unsigned char tim_t;
typedef unsigned short int uint16_t;
typedef unsigned int uint32_t;
typedef unsigned char uint8_t;
typedef void (*xtimer_callback_t)(void *);
typedef struct xtimer xtimer_t;
typedef struct anonymous$16 xtimer_ticks64_t;
typedef struct ztimer_base ztimer_base_t;
typedef void (*ztimer_callback_t)(void *);
typedef struct ztimer_clock ztimer_clock_t;
typedef struct anonymous$13 ztimer_ops_t;
typedef struct anonymous$14 ztimer_t;

// _assert_panic
// file ../../../core/lib/include/assert.h line 138
_Noreturn void _assert_panic(void);
// _initialize_ia_na
// file ../../../sys/net/application_layer/dhcpv6/client.c line 166
void _initialize_ia_na(uint16_t netif);
// _parse_advertise
// file ../../../sys/net/application_layer/dhcpv6/client.c line 791
void _parse_advertise(uint8_t *adv, size_t len);
// _preparse_advertise
// file ../../../sys/net/application_layer/dhcpv6/client.c line 638
signed int _preparse_advertise(uint8_t *adv, size_t len, uint8_t **buf);
// _print_ia_na_debug_info
// file ../../../sys/net/application_layer/dhcpv6/client.c line 156
void _print_ia_na_debug_info(uint16_t netif, signed int result_code);
// _xtimer_set64
// file ../../../sys/include/xtimer/implementation.h line 80
void _xtimer_set64(xtimer_t *, uint32_t, uint32_t);
// byteorder_ntohs
// file ../../../sys/include/byteorder.h line 506
inline uint16_t byteorder_ntohs(network_uint16_t v);
// dhcpv6_client_check_ia_na
// file ../../../sys/include/net/dhcpv6/client.h line 237
_Bool dhcpv6_client_check_ia_na(unsigned int);
// dhcpv6_client_conf_prefix
// file ../../../sys/include/net/dhcpv6/client.h line 211
void dhcpv6_client_conf_prefix(unsigned int, const ipv6_addr_t *, unsigned int, uint32_t, uint32_t);
// dhcpv6_client_get_conf_mode
// file ../../../sys/net/application_layer/dhcpv6/client.c line 245
uint8_t dhcpv6_client_get_conf_mode(void);
// dhcpv6_client_get_duid_l2
// file ../../../sys/include/net/dhcpv6/client.h line 200
unsigned int dhcpv6_client_get_duid_l2(unsigned int, dhcpv6_duid_l2_t *);
// dhcpv6_client_init
// file ../../../sys/net/application_layer/dhcpv6/client.c line 195
void dhcpv6_client_init(event_queue_t *eq, uint16_t netif);
// dhcpv6_client_prefix_valid_until
// file ../../../sys/include/net/dhcpv6/client.h line 248
uint32_t dhcpv6_client_prefix_valid_until(unsigned int, const ipv6_addr_t *, unsigned int);
// dhcpv6_client_req_ia_na
// file ../../../sys/net/application_layer/dhcpv6/client.c line 286
signed int dhcpv6_client_req_ia_na(unsigned int netif);
// dhcpv6_client_req_ia_pd
// file ../../../sys/net/application_layer/dhcpv6/client.c line 260
signed int dhcpv6_client_req_ia_pd(unsigned int netif, unsigned int pfx_len);
// dhcpv6_client_set_conf_mode
// file ../../../sys/net/application_layer/dhcpv6/client.c line 238
void dhcpv6_client_set_conf_mode(uint8_t _configuration_mode);
// dhcpv6_client_start
// file ../../../sys/net/application_layer/dhcpv6/client.c line 249
void dhcpv6_client_start(void);
// event_post
// file ../../../sys/include/event.h line 266
void event_post(event_queue_t *, event_t *);
// event_timeout_clear
// file ../../../sys/include/event/timeout.h line 108
void event_timeout_clear(event_timeout_t *);
// event_timeout_init
// file ../../../sys/net/application_layer/dhcpv6/client.c line 1393 function _set_event_timeout_ms
signed int event_timeout_init(void);
// event_timeout_set
// file ../../../sys/include/event/timeout.h line 96
void event_timeout_set(event_timeout_t *, uint32_t);
// harness
// 
void harness(void);
// ipv6_addr_init_prefix
// file ../../../sys/include/net/ipv6/addr.h line 532
void ipv6_addr_init_prefix(ipv6_addr_t *, const ipv6_addr_t *, uint8_t);
// ipv6_addr_match_prefix
// file ../../../sys/include/net/ipv6/addr.h line 521
uint8_t ipv6_addr_match_prefix(const ipv6_addr_t *, const ipv6_addr_t *);
// irq_disable
// file ../../../core/lib/include/irq.h line 48
unsigned int irq_disable(void);
// irq_restore
// file ../../../core/lib/include/irq.h line 74
void irq_restore(unsigned int);
// netif_get_id
// file ../../../sys/include/net/netif.h line 117
int16_t netif_get_id(const netif_t *);
// netif_iter
// file ../../../sys/include/net/netif.h line 89
netif_t * netif_iter(const netif_t *);
// random_uint32
// file ../../../sys/include/random.h line 89
uint32_t random_uint32(void);
// random_uint32_range
// file ../../../sys/include/random.h line 106
uint32_t random_uint32_range(uint32_t, uint32_t);
// sock_udp_create
// file ../../../sys/include/net/sock/udp.h line 425
signed int sock_udp_create(sock_udp_t *, const sock_udp_ep_t *, const sock_udp_ep_t *, uint16_t);
// sock_udp_recv_aux
// file ../../../sys/include/net/sock/udp.h line 495
ssize_t sock_udp_recv_aux(sock_udp_t *, void *, size_t, uint32_t, sock_udp_ep_t *, sock_udp_aux_rx_t *);
// sock_udp_sendv_aux
// file ../../../sys/include/net/sock/udp.h line 669
ssize_t sock_udp_sendv_aux(sock_udp_t *, const iolist_t *, const sock_udp_ep_t *, sock_udp_aux_tx_t *);
// timer_read
// file ../../../drivers/include/periph/timer.h line 214
unsigned int timer_read(tim_t);
// type_constructor_ptr_uint
// 
void type_constructor_ptr_uint(signed int depth_ptr_uint, uint8_t **result_ptr_uint);
// type_constructor_uint
// 
void type_constructor_uint(signed int depth_uint, uint8_t *result_uint);
// type_constructor_uint_0
// 
void type_constructor_uint_0(signed int depth_uint$0, size_t *result_uint$0);

typedef struct ztimer_base
{
  // next
  ztimer_base_t *next;
  // offset
  uint32_t offset;
} ztimer_base_t;

struct anonymous$7
{
  // clock
  ztimer_clock_t *clock;
  // timer
  struct { ztimer_base_t base; ztimer_callback_t callback; void *arg; } timer;
  // queue
  event_queue_t *queue;
  // event
  event_t *event;
};

struct anonymous$13
{
  // set
  void (*set)(ztimer_clock_t *, uint32_t);
  // now
  uint32_t (*now)(ztimer_clock_t *);
  // cancel
  void (*cancel)(ztimer_clock_t *);
};

struct anonymous$15
{
  // sender_pid
  kernel_pid_t sender_pid;
  // type
  uint16_t type;
  // content
  union { void *ptr; uint32_t value; } content;
};

union anonymous$34
{
  // id
  uint32_t id;
  // info
  struct { uint16_t netif; uint16_t type; } info;
};

typedef union anonymous$19
{
  // u16
  uint16_t u16;
  // u8
  uint8_t u8[2];
} __attribute__ ((__packed__)) network_uint16_t;

typedef union anonymous$11
{
  // u32
  uint32_t u32;
  // u8
  uint8_t u8[4];
  // u16
  uint16_t u16[2];
  // b16
  be_uint16_t b16[2];
} __attribute__ ((__packed__)) network_uint32_t;

typedef union anonymous$6
{
  // u64
  uint64_t u64;
  // u8
  uint8_t u8[8];
  // u16
  uint16_t u16[4];
  // u32
  uint32_t u32[2];
  // b16
  be_uint16_t b16[4];
  // b32
  be_uint32_t b32[2];
} __attribute__ ((__packed__)) network_uint64_t;

struct anonymous$29
{
  // parent
  struct { union anonymous$34 ia_id; } parent;
  // addr
  union { uint8_t u8[16]; network_uint16_t u16[8]; network_uint32_t u32[4]; network_uint64_t u64[2]; } addr;
  // leased
  uint8_t leased;
};

struct anonymous$32
{
  // parent
  struct { union anonymous$34 ia_id; } parent;
  // pfx
  union { uint8_t u8[16]; network_uint16_t u16[8]; network_uint32_t u32[4]; network_uint64_t u64[2]; } pfx;
  // pfx_len
  uint8_t pfx_len;
  // leased
  uint8_t leased;
};

typedef struct anonymous$4
{
  // type
  union { uint16_t u16; uint8_t u8[2]; } type;
  // l2type
  union { uint16_t u16; uint8_t u8[2]; } l2type;
} __attribute__ ((__packed__)) dhcpv6_duid_l2_t;

struct anonymous$35
{
  // duid
  union { uint8_t u8[128]; dhcpv6_duid_l2_t duid_l2; } duid;
  // t1
  uint32_t t1;
  // pref
  uint8_t pref;
  // duid_len
  uint8_t duid_len;
};

struct anonymous
{
  // type
  union { uint16_t u16; uint8_t u8[2]; } type;
  // len
  union { uint16_t u16; uint8_t u8[2]; } len;
  // mud_string
  char mud_string[0];
} __attribute__ ((__packed__));

struct anonymous$28
{
  // type
  union { uint16_t u16; uint8_t u8[2]; } type;
  // len
  union { uint16_t u16; uint8_t u8[2]; } len;
  // opt_codes
  network_uint16_t opt_codes[0];
} __attribute__ ((__packed__));

struct anonymous$1
{
  // type
  union { uint16_t u16; uint8_t u8[2]; } type;
  // len
  union { uint16_t u16; uint8_t u8[2]; } len;
  // data
  uint8_t data[0];
} __attribute__ ((__packed__));

struct anonymous$0
{
  // type
  union { uint16_t u16; uint8_t u8[2]; } type;
  // len
  union { uint16_t u16; uint8_t u8[2]; } len;
  // duid
  uint8_t duid[0];
} __attribute__ ((__packed__));

struct anonymous$24
{
  // type
  union { uint16_t u16; uint8_t u8[2]; } type;
  // len
  union { uint16_t u16; uint8_t u8[2]; } len;
  // code
  union { uint16_t u16; uint8_t u8[2]; } code;
  // msg
  char msg[0];
} __attribute__ ((__packed__));

struct anonymous$25
{
  // type
  union { uint16_t u16; uint8_t u8[2]; } type;
  // len
  union { uint16_t u16; uint8_t u8[2]; } len;
  // elapsed_time
  union { uint16_t u16; uint8_t u8[2]; } elapsed_time;
} __attribute__ ((__packed__));

struct anonymous$22
{
  // type
  union { uint16_t u16; uint8_t u8[2]; } type;
  // len
  union { uint16_t u16; uint8_t u8[2]; } len;
  // addr
  union { uint8_t u8[16]; network_uint16_t u16[8]; network_uint32_t u32[4]; network_uint64_t u64[2]; } addr;
  // pref
  union { uint32_t u32; uint8_t u8[4]; uint16_t u16[2]; be_uint16_t b16[2]; } pref;
  // valid
  union { uint32_t u32; uint8_t u8[4]; uint16_t u16[2]; be_uint16_t b16[2]; } valid;
  // opts
  uint8_t opts[0];
} __attribute__ ((__packed__));

struct anonymous$36
{
  // type
  union { uint16_t u16; uint8_t u8[2]; } type;
  // len
  union { uint16_t u16; uint8_t u8[2]; } len;
  // ia_id
  union { uint32_t u32; uint8_t u8[4]; uint16_t u16[2]; be_uint16_t b16[2]; } ia_id;
  // t1
  union { uint32_t u32; uint8_t u8[4]; uint16_t u16[2]; be_uint16_t b16[2]; } t1;
  // t2
  union { uint32_t u32; uint8_t u8[4]; uint16_t u16[2]; be_uint16_t b16[2]; } t2;
  // opts
  uint8_t opts[0];
} __attribute__ ((__packed__));

struct anonymous$30
{
  // type
  union { uint16_t u16; uint8_t u8[2]; } type;
  // len
  union { uint16_t u16; uint8_t u8[2]; } len;
  // pref
  union { uint32_t u32; uint8_t u8[4]; uint16_t u16[2]; be_uint16_t b16[2]; } pref;
  // valid
  union { uint32_t u32; uint8_t u8[4]; uint16_t u16[2]; be_uint16_t b16[2]; } valid;
  // pfx_len
  uint8_t pfx_len;
  // pfx
  union { uint8_t u8[16]; network_uint16_t u16[8]; network_uint32_t u32[4]; network_uint64_t u64[2]; } pfx;
  // opts
  uint8_t opts[0];
} __attribute__ ((__packed__));

struct anonymous$31
{
  // type
  union { uint16_t u16; uint8_t u8[2]; } type;
  // len
  union { uint16_t u16; uint8_t u8[2]; } len;
  // value
  union { uint32_t u32; uint8_t u8[4]; uint16_t u16[2]; be_uint16_t b16[2]; } value;
} __attribute__ ((__packed__));

struct anonymous$18
{
  // type
  union { uint16_t u16; uint8_t u8[2]; } type;
  // len
  union { uint16_t u16; uint8_t u8[2]; } len;
  // value
  uint8_t value;
} __attribute__ ((__packed__));

struct anonymous$33
{
  // netif
  uint16_t netif;
  // type
  uint16_t type;
};

struct anonymous$26
{
  // ia_id
  union { uint32_t id; struct anonymous$33 info; } ia_id;
};

typedef struct list_node
{
  // next
  struct list_node *next;
} list_node_t;

struct anonymous$8
{
  // event_list
  clist_node_t event_list;
  // waiter
  thread_t *waiter;
};

struct anonymous$3
{
  // node
  list_node_t node;
};

struct anonymous$12
{
  // readers
  list_node_t readers;
  // writers
  list_node_t writers;
  // cib
  struct { unsigned int read_count; unsigned int write_count; unsigned int mask; } cib;
  // msg_array
  msg_t *msg_array;
};

struct anonymous$14
{
  // base
  ztimer_base_t base;
  // callback
  ztimer_callback_t callback;
  // arg
  void *arg;
};

struct anonymous$20
{
  // read_count
  unsigned int read_count;
  // write_count
  unsigned int write_count;
  // mask
  unsigned int mask;
};

struct anonymous$16
{
  // ticks64
  uint64_t ticks64;
};

struct anonymous$23
{
  // flags
  sock_aux_flags_t flags;
};

struct anonymous$10
{
  // type
  uint8_t type;
  // tid
  uint8_t tid[3];
} __attribute__ ((__packed__));

union anonymous$17
{
  // ptr
  void *ptr;
  // value
  uint32_t value;
};

union anonymous$2
{
  // u8
  uint8_t u8[128];
  // duid_l2
  struct { network_uint16_t type; network_uint16_t l2type; } duid_l2;
};

union anonymous$27
{
  // ipv6
  uint8_t ipv6[16];
  // ipv4
  uint8_t ipv4[4];
  // ipv4_u32
  uint32_t ipv4_u32;
};

union anonymous$5
{
  // u8
  uint8_t u8[16];
  // u16
  network_uint16_t u16[8];
  // u32
  network_uint32_t u32[4];
  // u64
  network_uint64_t u64[2];
};

union anonymous$21
{
  // pid
  kernel_pid_t pid;
};

struct _sock_tl_ep
{
  // family
  signed int family;
  // addr
  union { uint8_t ipv6[16]; uint8_t ipv4[4]; uint32_t ipv4_u32; } addr;
  // netif
  uint16_t netif;
  // port
  uint16_t port;
};

struct _thread
{
  // sp
  char *sp;
  // status
  thread_status_t status;
  // priority
  uint8_t priority;
  // pid
  kernel_pid_t pid;
  // rq_entry
  clist_node_t rq_entry;
};

struct event
{
  // list_node
  clist_node_t list_node;
  // handler
  event_handler_t handler;
};

struct gnrc_netreg_entry
{
  // next
  struct gnrc_netreg_entry *next;
  // demux_ctx
  uint32_t demux_ctx;
  // target
  union { kernel_pid_t pid; } target;
};

struct gnrc_sock_reg
{
  // entry
  gnrc_netreg_entry_t entry;
  // mbox
  struct { list_node_t readers; list_node_t writers; cib_t cib; msg_t *msg_array; } mbox;
  // mbox_queue
  msg_t mbox_queue[8];
};

struct iolist
{
  // iol_next
  iolist_t *iol_next;
  // iol_base
  void *iol_base;
  // iol_len
  size_t iol_len;
};

struct sock_udp
{
  // reg
  gnrc_sock_reg_t reg;
  // local
  sock_udp_ep_t local;
  // remote
  sock_udp_ep_t remote;
  // flags
  uint16_t flags;
};

struct xtimer
{
  // next
  struct xtimer *next;
  // offset
  uint32_t offset;
  // long_offset
  uint32_t long_offset;
  // start_time
  uint32_t start_time;
  // long_start_time
  uint32_t long_start_time;
  // callback
  xtimer_callback_t callback;
  // arg
  void *arg;
};

struct ztimer_clock
{
  // list
  ztimer_base_t list;
  // ops
  const ztimer_ops_t *ops;
  // last
  ztimer_base_t *last;
  // adjust_set
  uint16_t adjust_set;
  // adjust_sleep
  uint16_t adjust_sleep;
};


// __GOTO_HARNESS::max_depth
// file __GOTO_HARNESSharness.c
signed int max_depth=2;
// __GOTO_HARNESS::min_depth
// file __GOTO_HARNESSharness.c
signed int min_depth=1;
// _xtimer_current_time
// file ../../../sys/include/xtimer/implementation.h line 42
extern volatile uint64_t _xtimer_current_time;

// harness
// 
void harness(void)
{
  uint8_t *adv;
  size_t len;
  type_constructor_ptr_uint(0, &adv);
  type_constructor_uint_0(0, &len);
  _parse_advertise(adv, len);
  free(adv);
}

// type_constructor_ptr_uint
// 
void type_constructor_ptr_uint(signed int depth_ptr_uint, uint8_t **result_ptr_uint)
{
  if(depth_ptr_uint >= max_depth)
    *result_ptr_uint = ((uint8_t *)NULL);

  else
  {
    __CPROVER_bool should_recurse_nondet;
    if(!(depth_ptr_uint >= min_depth) || should_recurse_nondet)
    {
      uint8_t *local_result=malloc(1u);
      type_constructor_uint(depth_ptr_uint + 1, &(*local_result));
      *result_ptr_uint = local_result;
    }

    else
      *result_ptr_uint = ((uint8_t *)NULL);
  }
}

// type_constructor_uint
// 
void type_constructor_uint(signed int depth_uint, uint8_t *result_uint)
{
  uint8_t nondet;
  *result_uint = nondet;
}

// type_constructor_uint_0
// 
void type_constructor_uint_0(signed int depth_uint$0, size_t *result_uint$0)
{
  size_t nondet$0;
  *result_uint$0 = nondet$0;
}

