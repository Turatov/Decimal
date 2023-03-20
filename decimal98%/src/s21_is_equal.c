#include "s21_dbinary.h"
#include "s21_decimal.h"

int s21_is_equal(s21_decimal a, s21_decimal b) {
  a = s21_normalize(a);
  b = s21_normalize(b);
  if ((s21_iszero(a) && s21_iszero(b)) ||
      (!s21_bincmp(a, b) && a.bits8[15] == b.bits8[15] &&
       a.bits8[14] == b.bits8[14]))
    return 1;
  return 0;
}
