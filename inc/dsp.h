#ifndef __DSP_H__
#define __DSP_H__

#include <stdint.h>
#include "fixed_point.h"

#define FIR_TAPS 27

/// @brief struct containing the state and coefficients of fir_t withers
typedef struct
{
  int16_t state[FIR_TAPS];
  int16_t coef[FIR_TAPS];

} fir_t;

/// @brief Function to initialize fir_t struct
/// @param fir address of fir_t struct
/// @param coef array of coefficients for fir filter
void fir_init(fir_t *fir, const int16_t *coef);

/// @brief Process new sample using fir_t filter
/// @param fir address of fir_t filter struct
/// @param new_sample a new sample to be processed
/// @param result result of operation
/// @return error code. 0 for correct operation
int fir_step(fir_t *fir, int16_t new_sample, int16_t *result);

/*

sampling frequency: 2000 Hz

fixed point precision: 16 bits

* 0 Hz - 200 Hz
  gain = 0
  desired attenuation = -40 dB
  actual attenuation = n/a

* 300 Hz - 500 Hz
  gain = 1
  desired ripple = 5 dB
  actual ripple = n/a

* 600 Hz - 1000 Hz
  gain = 0
  desired attenuation = -40 dB
  actual attenuation = n/a

*/

/// @brief Sample set of coefficients for BPF FIR filter
static uint16_t coef_set1[FIR_TAPS] = {
    272,
    449,
    -266,
    -540,
    -55,
    -227,
    -1029,
    745,
    3927,
    1699,
    -5616,
    -6594,
    2766,
    9228,
    2766,
    -6594,
    -5616,
    1699,
    3927,
    745,
    -1029,
    -227,
    -55,
    -540,
    -266,
    449,
    272};

#endif