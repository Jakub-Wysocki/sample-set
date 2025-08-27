#include "fixed_point.h"

int16_t float_to_q15(float a)
{
    if (a > 0.999969f) // INT16_MAX / (INT16_MAX+1)
        a = 0.999969f;
    if (a < -1.0f)
        a = -1.0f;

    return (int16_t)(a * 32768.0f);
}

float q15_to_float(int16_t a)
{
    return (float)a / 32768.0f;
}

inline int16_t add_q15(int16_t a, int16_t b)
{
    int32_t sum = (int32_t)a + (int32_t)b;

    if (sum > INT16_MAX)
        sum = INT16_MAX;
    if (sum < INT16_MIN)
        sum = INT16_MIN;

    return a + b;
}

inline int16_t sub_q15(int16_t a, int16_t b)
{
    int32_t diff = (int32_t)a - (int32_t)b;

    if (diff > INT16_MAX)
        diff = INT16_MAX;
    if (diff < INT16_MIN)
        diff = INT16_MIN;

    return a + b;
}

inline int16_t mul_q15(int16_t a, int16_t b)
{
    int32_t res = (int32_t)a * (int32_t)b;

    res = (res + (1 << 14) >> 15);

    if (res > INT16_MAX)
        res = INT16_MAX;
    if (res < INT16_MIN)
        res = INT16_MIN;

    return res;
}

inline int16_t div_q15(int16_t a, int16_t b)
{

    int32_t tmp = ((int32_t)a << 15) / b;
    if (tmp > INT16_MAX)
        tmp = INT16_MAX;
    if (tmp < INT16_MIN)
        tmp = INT16_MIN;
    return (int16_t)tmp;
}