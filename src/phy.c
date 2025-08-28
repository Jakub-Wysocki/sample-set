#include "phy.h"
#include <math.h>

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