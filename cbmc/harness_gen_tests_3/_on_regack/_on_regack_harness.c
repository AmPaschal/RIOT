#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <net/asymcute.h>

/* Public function under test in this harness */
extern void _on_regack(asymcute_con_t *con, const uint8_t *data, size_t len);

/* A simple subscription callback stub so that sub->cb(...) is callable */
void harness_sub_cb(const asymcute_sub_t *sub, unsigned evt_type, const void *data, size_t len, void *arg) {
    (void)sub; (void)evt_type; (void)data; (void)len; (void)arg;
}

void harness() {
    /* Existing call to drive _on_regack paths */
    size_t con_len;
    __CPROVER_assume(con_len >= sizeof(asymcute_con_t));
    asymcute_con_t *con = malloc(con_len);

    size_t data_len;
    const uint8_t *data = malloc(data_len);
    size_t len;

    _on_regack(con, data, len);

    /* Case 1: Exercise req->cb dispatch with req->arg == NULL (other timeout paths) */
    size_t req1_len;
    __CPROVER_assume(req1_len >= sizeof(asymcute_req_t));
    asymcute_req_t *req1 = malloc(req1_len);
    if (req1 && req1->cb) {
        (void)req1->cb(con, req1);
    }

    /* Case 2: Exercise req->cb dispatch with a valid subscription in req->arg */
    size_t req2_len;
    __CPROVER_assume(req2_len >= sizeof(asymcute_req_t));
    asymcute_req_t *req2 = malloc(req2_len);
    size_t sub_len;
    __CPROVER_assume(sub_len >= sizeof(asymcute_sub_t));
    asymcute_sub_t *sub2 = malloc(sub_len);
    if (req2) {
        req2->arg = sub2;
        if (req2->cb) {
            (void)req2->cb(con, req2);
        }
    }

    /* Case 3: Drive _disconnect -> _sub_cancel to cover sub->topic = NULL */
    size_t con2_len;
    __CPROVER_assume(con2_len >= sizeof(asymcute_con_t));
    asymcute_con_t *con2 = malloc(con2_len);

    size_t req3_len;
    __CPROVER_assume(req3_len >= sizeof(asymcute_req_t));
    asymcute_req_t *req3 = malloc(req3_len);

    size_t sub3_len;
    __CPROVER_assume(sub3_len >= sizeof(asymcute_sub_t));
    asymcute_sub_t *sub3 = malloc(sub3_len);

    size_t topic_len;
    __CPROVER_assume(topic_len >= sizeof(asymcute_topic_t));
    asymcute_topic_t *topic3 = malloc(topic_len);

    if (con2 && req3 && sub3 && topic3) {
        /* Prepare a connected context with an active subscription */
        con2->state = 2; /* CONNECTED, matches enum in file */
        con2->subscriptions = sub3;
        sub3->next = NULL;
        sub3->topic = topic3;
        sub3->cb = harness_sub_cb;
        /* Call through the timeout callback pointer; CBMC can choose _on_discon_timeout */
        if (req3->cb) {
            (void)req3->cb(con2, req3);
        }
    }
}
