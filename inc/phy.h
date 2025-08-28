#ifndef __PHY_H__
#define __PHY_H__

#include <stdint.h>

const float SQRT2_F = 1.41421356f;
const float INV_SQRT2_F = 0.70710678f;

typedef struct
{

    float re;
    float im;

} Complex;

/// @brief The function calculates Signal to Noise Ratio (SNR) of the clean signal and its equivalent with noise
/// @param clean array of clean samples e.g. clean pilot signal
/// @param noisy array of noisy samples e.g. received pilot signal
/// @param size size of the arrays
/// @return snr value of the given signal
float snr(const int16_t *sig, const int16_t *sig_noise, int size);

/// @brief Simple function that generate parity bit of the given data
/// @param data data for which the parity bit check is made
/// @return parity bit
int parity_bit(int32_t data);

/// @brief QPSK modulation of the given data
/// @param data data to be converted to QPSK
/// @param result Array of 8 elements type struct Comples
/// @return error code
int qpsk(int16_t data, Complex *result);

#endif