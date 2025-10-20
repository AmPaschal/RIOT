#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <net/asymcute.h>

/* Forward declaration since _on_regack is defined in asymcute.c and not in a header */
extern void _on_regack(asymcute_con_t *con, const uint8_t *data, size_t len);

void harness() {
    /* Parameter: asymcute_con_t *con */
    size_t con_len;
    __CPROVER_assume(con_len >= sizeof(asymcute_con_t));
    asymcute_con_t *con = malloc(con_len);

    /* Parameter: const uint8_t *data */
    size_t data_len;
    const uint8_t *data = malloc(data_len);

    /* Parameter: size_t len */
    size_t len;

    _on_regack(con, data, len);
}
