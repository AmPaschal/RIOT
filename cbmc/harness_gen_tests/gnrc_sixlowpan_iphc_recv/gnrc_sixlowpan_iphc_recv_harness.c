#include <stdlib.h>
#include <stdint.h>

#include "net/gnrc/pkt.h"
#include "net/gnrc/sixlowpan/frag/rb.h"
#include <sys/types.h>

#include "net/gnrc/sixlowpan/ctx.h"
#include "net/gnrc/sixlowpan/frag/vrb.h"

/* Forward declaration of the function under test */
extern void gnrc_sixlowpan_iphc_recv(gnrc_pktsnip_t *sixlo, void *rbuf_ptr, unsigned page);

gnrc_sixlowpan_ctx_t *gnrc_sixlowpan_ctx_lookup_id(uint8_t id) {
    gnrc_sixlowpan_ctx_t* context = malloc(sizeof(gnrc_sixlowpan_ctx_t));
    return context;
}

gnrc_pktsnip_t *gnrc_pktbuf_add(gnrc_pktsnip_t *next, const void *data, size_t size,
                                gnrc_nettype_t type) {
    gnrc_pktsnip_t* new_pkt = malloc(sizeof(gnrc_pktsnip_t));
    __CPROVER_assume(new_pkt != NULL);
    return new_pkt;
}

// gnrc_pktsnip_t *gnrc_pktsnip_search_type(gnrc_pktsnip_t *pkt,
//                                          gnrc_nettype_t type) {
//     gnrc_pktsnip_t* new_pkt = malloc(sizeof(gnrc_pktsnip_t));
//     __CPROVER_assume(new_pkt != NULL);
//     // pkt -> next = NULL;

//     size_t size;

//     //This part of the buffer can be read as quite a few different things
//     //sixlowpan_sfr_rfrag_t I think is the biggest of the possible options

//     __CPROVER_assume(size <= 100 && size >= sizeof(gnrc_netif_hdr_t));

//     uint8_t* data = malloc(size);
//     __CPROVER_assume(data != NULL);
    
//     new_pkt -> data = data;
//     new_pkt -> size = size;
//     new_pkt -> next = NULL;

//     return new_pkt;
// }

// gnrc_netif_t *gnrc_netif_get_by_pid(kernel_pid_t pid) {
//     gnrc_netif_t *new_netif = malloc(sizeof(gnrc_netif_t));

//     //Addresses Potential Vulnerability B in gnrc_sixlowpan_iphc_recv
//     __CPROVER_assume(new_netif != NULL);

//     return new_netif;
// }

// bool _is_rfrag(gnrc_pktsnip_t *sixlo)
// {
//     bool rand;
//     return rand;
// }

// gnrc_pktsnip_t *_encode_frag_for_forwarding(gnrc_pktsnip_t *decoded_pkt,
//                                                    gnrc_sixlowpan_frag_vrb_t *vrbe) {
//     gnrc_pktsnip_t* new_pkt = malloc(sizeof(gnrc_pktsnip_t));
//     if(new_pkt == NULL) {
//         return new_pkt;
//     }

//     size_t size;

//     //Assume no size constraints
//     __CPROVER_assume(size <= 100);

//     uint8_t* data = malloc(size);
//     __CPROVER_assume(data != NULL);
    
//     new_pkt -> data = data;
//     new_pkt -> size = size;
//     new_pkt -> next = NULL;

//     return new_pkt;
// }


// void gnrc_pktbuf_release_error(gnrc_pktsnip_t *pkt, uint32_t err)
// {
//     return;
// }

// gnrc_sixlowpan_frag_vrb_t *gnrc_sixlowpan_frag_vrb_from_route(
//             const gnrc_sixlowpan_frag_rb_base_t *base,
//             gnrc_netif_t *netif, const gnrc_pktsnip_t *hdr)
// {
//     gnrc_sixlowpan_frag_vrb_t* new_vrb = malloc(sizeof(gnrc_sixlowpan_frag_vrb_t));
//     return new_vrb;
// }


void harness() {
    /* Parameter 1: gnrc_pktsnip_t *sixlo */
    gnrc_pktsnip_t *sixlo = (gnrc_pktsnip_t *)malloc(sizeof(gnrc_pktsnip_t));
    __CPROVER_assume(sixlo != NULL);

    /* Prepare sixlo->data and sixlo->size as the function reads these */
    size_t sixlo_data_len;
    sixlo->data = malloc(sizeof(uint8_t) * sixlo_data_len);
    sixlo->size = sixlo_data_len;

    /* Initialize remaining fields conservatively */
    sixlo->next = NULL;

    /* Parameter 2: void *rbuf_ptr (may be NULL or point to gnrc_sixlowpan_frag_rb_t) */
    uint8_t rbuf_size;
    void *rbuf_ptr = malloc(rbuf_size);
    
    /* Parameter 3: unsigned page */
    unsigned page;

    /* Call the function under test */
    gnrc_sixlowpan_iphc_recv(sixlo, rbuf_ptr, page);
}
