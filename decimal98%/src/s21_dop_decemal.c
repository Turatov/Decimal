#include "s21_dbinary.h"
#include "s21_decimal.h"

void s21_set_to_inf(s21_decimal value_1, s21_decimal value_2,
                    s21_decimal *inf) {
  if (s21_iszero(value_1) && s21_iszero(value_2))
    *inf = S21_DECIMAL_NAN;
  else
    *inf = S21_DECIMAL_INF;
  inf->bits8[15] = value_2.bits8[15] ^ value_1.bits8[15];
}

s21_decimal s21_round_even(s21_decimal n, s21_decimal div, s21_decimal rem) {
  rem = s21_lshift(rem, 1);
  if ((s21_bincmp(rem, div) == 0 && (n.bits8[0] & 1)) ||
      s21_bincmp(rem, div) == 1)
    n = s21_binadd(n, S21_DECIMAL_ONE);
  return n;
}

uint8_t s21_is_full(s21_decimal target) {
  s21_decimal tenth_limit = (s21_decimal){{0x9999999999999999, 0x19999999}};
  if (s21_bincmp(tenth_limit, target) > 0 && (char)target.bits8[14] < 28)
    return 0;
  return 1;
}