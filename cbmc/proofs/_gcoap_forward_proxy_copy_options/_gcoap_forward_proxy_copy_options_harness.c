// Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
// SPDX-License-Identifier: MIT-0

/*
 * Insert copyright notice
 */

/**
 * @file _rbuf_add_harness.c
 * @brief Implements the proof harness for _rbuf_add function.
 */

/*
 * Insert project header files that
 *   - include the declaration of the function
 *   - include the types needed to declare function arguments
 */

/**
 * @brief Starting point for formal analysis
 * 
 */

#include <stdlib.h>
#include <assert.h>
#include "net/nanocoap.h"
#include "sys/include/uri_parser.h"
#include "forward_proxy_internal.h"

static coap_pkt_t* alloc_coap_pkt_t()
{
    coap_pkt_t *pkt = malloc(sizeof(coap_pkt_t));
    __CPROVER_assume(pkt != NULL);

    //The target function requires a buffer of options in the packet, which based on _add_opt_pkt,
    //are kept in between the header and the payload. I think each option is 1-5 bytes long,
    //stores information about its own length and you can have up to 16 of them
    uint16_t opt_len;
    __CPROVER_assume(opt_len <= 16);
    pkt -> options_len = opt_len;



    uint16_t payload_len;
    __CPROVER_assume(payload_len <= 100);

    //Based on the comment in the header file, the payload pointer must point to
    //the end of the header at all times, so I'll allocate the space for the payload
    //after the end of the header and point payload to directly after it
    coap_hdr_t *hdr = malloc(sizeof(coap_hdr_t) + (opt_len) + payload_len);
    __CPROVER_assume(hdr != NULL);
    __CPROVER_assume(__CPROVER_rw_ok(hdr, sizeof(coap_hdr_t) + (opt_len) + payload_len));

    //Set a token length of 0 to make it easier to model
    uint8_t token_len = 0xf0;

    hdr -> ver_t_tkl = token_len;
    
    //The length stored in each option is used to try and read values, I'm going to set the delta to 1 and the length to 0 for everything
    //Because the actual values for each option don't matter for this function (I think)
    // for(int i = 0; i < opt_len; i++) {
    //     *(uint8_t*)(hdr + sizeof(coap_hdr_t) + i) == 0x10;
    // }

    pkt -> hdr = hdr;

    uint8_t *payload = (uint8_t*) ((uint8_t*) hdr + sizeof(coap_hdr_t) + (opt_len));

    pkt->payload = payload;
    pkt->payload_len = payload_len;

    return pkt;
}

void harness(void)
{

    coap_pkt_t *pkt = alloc_coap_pkt_t();

    coap_pkt_t *client_pkt = alloc_coap_pkt_t();

    client_ep_t cep; //No pointers in this so I'm not going to alloc it

    uri_parser_result_t* urip = malloc(sizeof(uri_parser_result_t));
    __CPROVER_assume(urip != NULL);
    //I'm allocing this because the path var which I need to make sure is defined is constant

    uint8_t path_len;
    __CPROVER_assume(path_len <= 20);
    char* path = malloc(path_len);
    __CPROVER_assume(path != NULL);

    if(path_len != 0) {
        __CPROVER_assume(path[path_len - 1] == '\0');
    }

    uint8_t query_len;
    __CPROVER_assume(query_len <= 20);
    char* query = malloc(query_len);
    __CPROVER_assume(query != NULL);


    if(query_len != 0) {
        __CPROVER_assume(query[query_len - 1] == '\0');
    }

    urip -> path = path;
    urip -> path_len = path_len;
    urip -> query = query;
    urip -> query_len = query_len;
    

    /* Insert argument declarations */
    _gcoap_forward_proxy_copy_options(pkt, client_pkt, &cep, urip);
}
