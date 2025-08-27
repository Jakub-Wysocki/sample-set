#include "dsp.h"
#include "fixed_point.h"
#include <stdint.h>
#include <stddef.h>
#include <string.h>

void fir_init(fir_t *fir, const int16_t *coef)
{
    memset(fir->state, 0, FIR_TAPS * sizeof(int16_t));
    memcpy(fir->coef, coef, FIR_TAPS * sizeof(int16_t));
}

int fir_step(fir_t *fir, int16_t new_sample, int16_t *result)
{
    if (!(fir && result))
        return 1;

    *result = 0;

    for (int i = FIR_TAPS - 1; i > 0; i--)
    {
        fir->state[i] = fir->state[i - 1];
    }
    fir->state[0] = new_sample;

    for (int i = 0; i < FIR_TAPS; i++)
    {
        *result = add_q15(*result, mul_q15(fir->state[i], fir->coef[i]));
    }

    return 0;
}
