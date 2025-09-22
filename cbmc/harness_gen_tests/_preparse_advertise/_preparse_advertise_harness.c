#include <stdint.h>
#include <stdlib.h>

/* If the build system does not provide a prototype through headers, keep this extern. */
extern int _preparse_advertise(uint8_t *adv, size_t len, uint8_t **buf);

void harness(void)
{
    /* Declare function parameters exactly as in the signature */
    uint8_t *adv;
    size_t len;
    uint8_t **buf;

    /* Constrain len to avoid under-sized packet access in the function. */
    /* If desired, include net/dhcpv6.h and use:
       __CPROVER_assume(len >= sizeof(dhcpv6_msg_t) + sizeof(dhcpv6_opt_t));
    */
    __CPROVER_assume(len > 0);

    /* Allocate adv with size `len` and assume non-NULL */
    adv = (uint8_t *)malloc(sizeof(uint8_t) * len);
    __CPROVER_assume(adv != NULL);

    /* Prepare a buffer pointer to receive best_adv if the function sets it */
    uint8_t *tmp_buf = NULL;
    buf = &tmp_buf; /* Non-NULL to exercise the assignment path; function also handles NULL */

    /* Call the function under test */
    (void)_preparse_advertise(adv, len, buf);
}
