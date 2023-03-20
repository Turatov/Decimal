#include "s21_dbinary.h"
#include "s21_decimal.h"

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  s21_set_to_inf(value_1, value_2, result);
  if (s21_iszero(value_2)) return 3;

  s21_decimal r = s21_binmod(value_1, value_2),
              q = s21_bindiv(value_1, value_2);

  q.bits8[14] = value_1.bits8[14] - value_2.bits8[14];

  while (!s21_iszero(r)) {
    while (s21_bincmp(r, value_2) < 0 && !s21_is_full(q)) {
      s21_decimal tenth_limit = (s21_decimal){{0x9999999999999999, 0x19999999}};
      if (s21_bincmp(tenth_limit, r) != 1)
        value_2 = s21_bindiv(value_2, S21_DECIMAL_TEN);
      else
        r = s21_binadd(s21_lshift(r, 1), s21_lshift(r, 3));
      q = s21_binadd(s21_lshift(q, 1), s21_lshift(q, 3));
      q.bits8[14]++;
    }
    q = s21_binadd(q, s21_bindiv(r, value_2));
    r = s21_binmod(r, value_2);
    if (s21_is_full(q)) break;
  }
  if (!s21_iszero(r)) q = s21_round_even(q, value_2, r);
  result = s21_bincpy(result, &q);
  result->bits8[14] = q.bits8[14];
  result->bits8[15] = value_2.bits8[15] ^ value_1.bits8[15];
  if (result->bits8[14] > 28) return (result->bits8[15]) ? 2 : 1;
  *result = s21_normalize(*result);
  return 0;
}
