#include <stddef.h>
#include <stdlib.h>
#include <stdint.h>

#include "net/gnrc/nettype.h"        /* gnrc_nettype_t */
#include "net/gnrc/netif.h"          /* gnrc_netif_t, kernel_pid_t */
#include "net/gnrc/netif/hdr.h"      /* gnrc_netif_hdr_t */
#include "net/gnrc/pkt.h"            /* gnrc_pktsnip_t, gnrc_pkt_delete */
#include "net/gnrc/sixlowpan/frag/vrb.h" /* gnrc_sixlowpan_frag_vrb_t, gnrc_sixlowpan_frag_rb_base_t */
#include "net/l2util.h"              /* l2util_addr_to_str */

/* Stubs */

gnrc_pktsnip_t *gnrc_pktbuf_add(gnrc_pktsnip_t *next, const void *data, size_t size, gnrc_nettype_t type) {
    size_t retval_len;
    __CPROVER_assume(retval_len >= sizeof(gnrc_pktsnip_t));
    gnrc_pktsnip_t *retval = (gnrc_pktsnip_t *)malloc(retval_len);
    return retval;
}

gnrc_sixlowpan_frag_vrb_t *gnrc_sixlowpan_frag_vrb_from_route(const gnrc_sixlowpan_frag_rb_base_t *base,
                                                               gnrc_netif_t *netif,
                                                               const gnrc_pktsnip_t *hdr) {
    size_t retval_len;
    __CPROVER_assume(retval_len >= sizeof(gnrc_sixlowpan_frag_vrb_t));
    gnrc_sixlowpan_frag_vrb_t *retval = (gnrc_sixlowpan_frag_vrb_t *)malloc(retval_len);
    return retval;
}

gnrc_pktsnip_t *gnrc_pktbuf_mark(gnrc_pktsnip_t *pkt, size_t size, gnrc_nettype_t type) {
    size_t retval_len;
    __CPROVER_assume(retval_len >= sizeof(gnrc_pktsnip_t));
    gnrc_pktsnip_t *retval = (gnrc_pktsnip_t *)malloc(retval_len);
    return retval;
}

char *l2util_addr_to_str(const uint8_t *addr, size_t addr_len, char *out) {
    size_t retval_len;
    char *retval = (char *)malloc(retval_len);
    return retval;
}

gnrc_sixlowpan_frag_vrb_t *gnrc_sixlowpan_frag_vrb_get(const uint8_t *src, size_t src_len, unsigned src_tag) {
    size_t retval_len;
    __CPROVER_assume(retval_len >= sizeof(gnrc_sixlowpan_frag_vrb_t));
    gnrc_sixlowpan_frag_vrb_t *retval = (gnrc_sixlowpan_frag_vrb_t *)malloc(retval_len);
    return retval;
}

gnrc_netif_t *gnrc_netif_get_by_pid(kernel_pid_t pid) {
    size_t retval_len;
    __CPROVER_assume(retval_len >= sizeof(gnrc_netif_t));
    gnrc_netif_t *retval = (gnrc_netif_t *)malloc(retval_len);
    return retval;
}

gnrc_pktsnip_t *gnrc_pktbuf_remove_snip(gnrc_pktsnip_t *pkt, gnrc_pktsnip_t *snip) {
    size_t retval_len;
    __CPROVER_assume(retval_len >= sizeof(gnrc_pktsnip_t));
    gnrc_pktsnip_t *retval = (gnrc_pktsnip_t *)malloc(retval_len);
    return retval;
}

/* Extern declaration of the target function */
extern int _rbuf_add(gnrc_netif_hdr_t *netif_hdr, gnrc_pktsnip_t *pkt,
                     size_t offset, unsigned page);

void harness() {
    /* gnrc_netif_hdr_t *netif_hdr */
    size_t netif_hdr_len;
    __CPROVER_assume(netif_hdr_len >= sizeof(gnrc_netif_hdr_t));
    gnrc_netif_hdr_t *netif_hdr = (gnrc_netif_hdr_t *)malloc(netif_hdr_len);

    /* gnrc_pktsnip_t *pkt */
    size_t pkt_len;
    __CPROVER_assume(pkt_len >= sizeof(gnrc_pktsnip_t));
    gnrc_pktsnip_t *pkt = (gnrc_pktsnip_t *)malloc(pkt_len);

    /* Ensure pkt->data points to valid memory for safe dereferencing */
    size_t data_len;
    __CPROVER_assume(data_len >= 1);  /* permit reading first byte */
    uint8_t *data = (uint8_t *)malloc(data_len);
    pkt->data = data;

    /* size_t offset */
    size_t offset;

    /* unsigned page */
    unsigned page;

    /* Call the target function */
    (void)_rbuf_add(netif_hdr, pkt, offset, page);

    /* Exercise gnrc_pkt_delete directly to cover its branches */
    {
        /* Case 1: removing head (pkt == snip) */
        gnrc_pktsnip_t node1;
        gnrc_pktsnip_t node2;
        node1.next = &node2;
        node2.next = NULL;
        (void)gnrc_pkt_delete(&node1, &node1);
    }

    {
        /* Case 2: snip == NULL (no-op) */
        gnrc_pktsnip_t node3;
        node3.next = NULL;
        (void)gnrc_pkt_delete(&node3, NULL);
    }

    {
        /* Case 3: remove middle element (i->next == snip) */
        gnrc_pktsnip_t head;
        gnrc_pktsnip_t mid;
        gnrc_pktsnip_t tail;
        head.next = &mid;
        mid.next  = &tail;
        tail.next = NULL;
        (void)gnrc_pkt_delete(&head, &mid);
    }

    {
        /* Case 4: snip not in list (iterate and return pkt) */
        gnrc_pktsnip_t list_a;
        gnrc_pktsnip_t list_b;
        gnrc_pktsnip_t foreign;
        list_a.next = &list_b;
        list_b.next = NULL;
        foreign.next = NULL;
        (void)gnrc_pkt_delete(&list_a, &foreign);
    }
}
