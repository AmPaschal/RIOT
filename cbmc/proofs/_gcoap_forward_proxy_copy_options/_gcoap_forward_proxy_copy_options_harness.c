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
#include <sys/include/net/nanocoap.h>
#include <sys/include/uri_parser.h>

static coap_pkt_t* alloc_coap_pkt_t()
{
    coap_pkt_t *pkt = malloc(sizeof(coap_pkt_t));
    __CPROVER_assume(pkt != NULL);

    uint16_t payload_len;
    __CPROVER_assume(payload_len <= 100);

    uint8_t *payload = malloc(payload_len);
    __CPROVER_assume(payload != NULL);

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
    //I'm allocing this because the path var which I need to make sure is defined is constant

    uint8_t path_len;
    __CPROVER_assume(path_len <= 20);
    char* path = malloc(path_len);
    urip -> path = path;
    urip -> path_len = path_len;
    

    /* Insert argument declarations */
    _gcoap_forward_proxy_copy_options(pkt, client_pkt, &cep, urip);
}
