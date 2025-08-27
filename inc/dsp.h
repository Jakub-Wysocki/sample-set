#ifndef __DSP_H__
#define __DSP_H__

#include <stdint.h>
#include "fixed_point.h"

#define FIR_TAPS 27

typedef struct
{
    int16_t state[FIR_TAPS];
    int16_t coef[FIR_TAPS];

} fir_t;

void fir_init(fir_t *fir, const int16_t *coef);
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
  272
};





#endif