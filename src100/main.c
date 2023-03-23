#include "s21_decimal.h"

int main() {
  s21_decimal val1 = {5000000};
  s21_decimal val2 = {3333333};
  s21_decimal res;

  s21_sub(val1, val2, &res);
  // s21_add(val1, val2, &res);
  int a;
  s21_from_decimal_to_int(res, &a);
  printf("%d", a);
  // GetBit(val1, a);
}
