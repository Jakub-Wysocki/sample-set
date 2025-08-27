#ifndef __FIXED_POINT_H__
#define __FIXED_POINT_H__

#include <stdint.h>

int16_t float_to_q15(float a);
float q15_to_float(int16_t a);

int16_t add_q15(int16_t a, int16_t b);
int16_t sub_q15(int16_t a, int16_t b);
int16_t mul_q15(int16_t a, int16_t b);
int16_t div_q15(int16_t a, int16_t b);

#endif