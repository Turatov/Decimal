#include "s21_dbinary.h"
#include "s21_decimal.h"

int s21_is_less(s21_decimal a, s21_decimal b) {
  if (a.bits8[15] != b.bits8[15]) return a.bits8[15] > b.bits8[15] ? 1 : 0;
  s21_eqscale(&a, &b);
  if (s21_bincmp(a, b) > 0 && a.bits8[15])
    return 1;
  else if (s21_bincmp(a, b) < 0 && !a.bits8[15])
    return 1;
  return 0;
}
