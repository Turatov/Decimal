#include "s21_dbinary.h"
#include "s21_decimal.h"

int s21_floor(s21_decimal value, s21_decimal *result) {
  value = s21_normalize(value);
  int code = s21_truncate(value, result);
  if (!value.bits8[14]) return code;
  if (value.bits8[15]) code = s21_sub(*result, S21_DECIMAL_ONE, result);
  return code;
}
