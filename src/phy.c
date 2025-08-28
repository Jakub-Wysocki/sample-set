#include "phy.h"
#include <math.h>
#include <stddef.h>

float snr(const int16_t *clean, const int16_t *noisy, int size)
{
    float sig_power = 0.0f;
    float noise_power = 0.0f;

    for (int i = 0; i < size; i++)
    {
        float s = (float)clean[i];
        float n = (float)(noisy[i] - clean[i]);
        sig_power += s * s;
        noise_power += n * n;
    }

    if (noise_power == 0)
        return INFINITY;

    return 10.0 * log10(sig_power / noise_power);
}

int parity_bit(int32_t data)
{
    int ctr = 0;
    for (int i = 0; i < 32; i++)
    {
        if (((data >> i) & 1) != 0)
            ctr ^= 1;
    }

    return ctr;
}

int qpsk(int16_t data, Complex *result)
{
    for (int i = 0; i < 16; i = i + 2)
    {
        int sym = (data >> i) & 0x3;
        int b0 = sym & 1;
        int b1 = (sym >> 1) & 1;

        // grey mapping with normalization 1/sqrt(2)
        float I = ((b0 ^ b1) ? -INV_SQRT2_F : INV_SQRT2_F);
        float Q = (b1 ? -INV_SQRT2_F : INV_SQRT2_F);

        result[i / 2].re = I;
        result[i / 2].im = Q;
    }

    return 0;
}
