#ifndef SRC_S21_DECIMAL_H_
#define SRC_S21_DECIMAL_H_
#include <stdio.h>

#include "s21_dconst.h"

//  Arithmetic operators
int s21_add(s21_decimal value_1, s21_decimal value_2,
            s21_decimal *result);  // 1
int s21_sub(s21_decimal value_1, s21_decimal value_2,
            s21_decimal *result);  // 1
int s21_mul(s21_decimal value_1, s21_decimal value_2,
            s21_decimal *result);  // 1
int s21_div(s21_decimal value_1, s21_decimal value_2,
            s21_decimal *result);  // 1
int s21_mod(s21_decimal value_1, s21_decimal value_2,
            s21_decimal *result);  // 1

//  Comparison operators
int s21_is_less(s21_decimal a, s21_decimal b);              //
int s21_is_less_or_equal(s21_decimal a, s21_decimal b);     //
int s21_is_greater(s21_decimal a, s21_decimal b);           //
int s21_is_greater_or_equal(s21_decimal a, s21_decimal b);  //
int s21_is_equal(s21_decimal a, s21_decimal b);             //
int s21_is_not_equal(s21_decimal a, s21_decimal b);         //

//  Converters
int s21_from_int_to_decimal(int src, s21_decimal *dst);      // 1
int s21_from_float_to_decimal(float src, s21_decimal *dst);  // 1
int s21_from_decimal_to_int(s21_decimal src, int *dst);      // 1
int s21_from_decimal_to_float(s21_decimal src, float *dst);  // 1

// Another functions
int s21_floor(s21_decimal value, s21_decimal *result);     // 1
int s21_round(s21_decimal value, s21_decimal *result);     // 1
int s21_truncate(s21_decimal value, s21_decimal *result);  // 1
int s21_negate(s21_decimal value, s21_decimal *result);    // 1

// Decimal Dop
uint8_t s21_is_full(s21_decimal target);
s21_decimal s21_round_even(s21_decimal n, s21_decimal div, s21_decimal rem);
void s21_set_to_inf(s21_decimal value_1, s21_decimal value_2, s21_decimal *inf);

void print_bit(unsigned int aBute, char dec[]);

#endif  //  SRC_S21_DECIMAL_H_
