// Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
// SPDX-License-Identifier: MIT-0

/**
 * @file _parse_advertise.c
 * @brief Implements the proof harness for _parse_advertise function.
 */

#include <stdint.h>
#include <stdlib.h>

uint32_t random_uint32_range(uint32_t a, uint32_t b) {

    // Create unconstrained int

    uint32_t val;

    // Ensure int falls within range

    __CPROVER_assume(a <= val);
    __CPROVER_assume(val < b);

    return val;
}

// int _preparse_advertise(uint8_t *adv, size_t len, uint8_t **buf) {
//     int val;

//     return val;
// }

/**
 * @brief Starting point for formal analysis
 * 
 */
    void harness(void)
{
    // Define unconstrained array length

    size_t len;

    // Constrain size to be something reasonable:

    __CPROVER_assume(len <= 500);

    // Allocate data of length

    uint8_t* data = (uint8_t*)malloc(sizeof(uint8_t) * len);

    __CPROVER_assume(data != NULL);

    _parse_advertise(data, len);
}
