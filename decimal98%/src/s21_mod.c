#include "s21_dbinary.h"
#include "s21_decimal.h"

int s21_imod(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  *result = s21_binmod(value_1, value_2);
  result->bits8[15] = value_2.bits8[15];
  return 0;
}

int s21_fmod(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  s21_decimal frac = S21_DECIMAL_ZERO;
  *result = value_1;
  s21_div(value_1, value_2, &frac);
  s21_truncate(frac, &frac);
  if (value_2.bits8[14] != 0xFF && value_1.bits8[14] <= 28) {
    s21_mul(frac, value_2, result);
    s21_sub(value_1, *result, result);
  }
  *result = s21_normalize(*result);
  return 0;
}

int s21_mod(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  if (s21_iszero(value_2)) return 3;
  if (value_1.bits8[14] || value_2.bits8[14])
    return s21_fmod(value_1, value_2, result);
  else
    return s21_imod(value_1, value_2, result);
}
