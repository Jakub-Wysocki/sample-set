#ifndef __FIXED_POINT_H__
#define __FIXED_POINT_H__

#include <stdint.h>

/// @brief convert float to Q15 format
/// @param a float to be converted
/// @return value of input in Q15 format
int16_t float_to_q15(float a);

/// @brief convert Q15 to float
/// @param a value to be converted
/// @return converted value
float q15_to_float(int16_t a);

/// @brief Add values
/// @param a number to be added
/// @param b number to be added
/// @return result of addition
int16_t add_q15(int16_t a, int16_t b);

/// @brief Subtract values
/// @param a Value to be subtracted
/// @param b Value to be subtracted
/// @return result of subtraction
int16_t sub_q15(int16_t a, int16_t b);

/// @brief Multiply values
/// @param a value to be multiplied
/// @param b value to be multiplied
/// @return result of multiplication
int16_t mul_q15(int16_t a, int16_t b);

/// @brief Divide values a/b
/// @param a Value to be divided
/// @param b Value that divide
/// @return result of division
int16_t div_q15(int16_t a, int16_t b);

#endif