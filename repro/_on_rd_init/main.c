/**
 * @file main.c
 * @author Owen Cochell (owencochell@gmail.com)
 * @brief Reproduction for vulnerability in _on_rd_init
 * @version 0.1
 * @date 2025-02-03
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <stdlib.h>
#include "net/nanocoap.h"
#include "net/gcoap.h"
#include "thread_flags.h"

extern char* _result_buf;
extern size_t _result_buf_len;

#define MAIN_QUEUE_SIZE     (8)
static msg_t _main_msg_queue[MAIN_QUEUE_SIZE];

/// Should we put an actual version here? Could not find after simple search
static coap_pkt_t* alloc_coap_pkt(void) {
    //Paschal's implementation

    coap_pkt_t* pkt = malloc(sizeof(coap_pkt_t));
    // __CPROVER_assume(pkt != NULL);


    // Model the attributes of this packet:

    pkt->hdr = NULL;
    pkt->payload = NULL;
    pkt->snips = NULL;
    pkt->payload_len = 0;
    pkt->options_len = 0;

    uint8_t pkt_size = 40;
    // __CPROVER_assume(pkt_size > sizeof(coap_hdr_t));
    coap_hdr_t *hdr = malloc(sizeof(coap_hdr_t));

    // __CPROVER_assume(hdr != NULL);
    pkt->hdr = hdr;
    uint8_t payload_offset = 39;
    // __CPROVER_assume(payload_offset >= sizeof(coap_hdr_t) && payload_offset <= pkt_size);
    pkt->payload = hdr + payload_offset;
    pkt->payload_len = pkt_size - payload_offset;

    //Max number of options is 16
    uint16_t opt_len = 1;
    // __CPROVER_assume(opt_len <= 16);
    pkt -> options_len = opt_len;

    return pkt;
}

// Declare function to be linked in
void _on_rd_init(const gcoap_request_memo_t *memo, coap_pkt_t *pdu,
                       const sock_udp_ep_t *remote);

int main(void)
{

    // Create a message queue?

    /* we need a message queue for the thread running the shell in order to
     * receive potentially fast incoming networking packets */
    msg_init_queue(_main_msg_queue, MAIN_QUEUE_SIZE);


    // Create the input arguments:

    gcoap_request_memo_t memo;

    coap_pkt_t *pdu = alloc_coap_pkt();  // Using custom allocator function

    sock_udp_ep_t remote;

    // __CPROVER_assume(_result_buf_len <= 100);

    // Set result buffer len to be zero:

    _result_buf_len = 0;

    _result_buf = malloc(_result_buf_len);
    // __CPROVER_assume(_result_buf != NULL);

    _on_rd_init(&memo, pdu, &remote);


    return 0;
}
