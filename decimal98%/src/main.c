#include <stdio.h>

#include "s21_decimal.h"
int main(int argc, char const *argv[]) {
  // s21_decimal n = {{48, 0}};
  // s21_decimal d = {{6, 0}};
  // s21_decimal r = {{54, 0}};
  // s21_decimal q;
  // s21_add(n, d, &q);  // 48+6 = 54
  // int res;
  // s21_from_decimal_to_int(q, &res);
  // printf("%d", res);

  double a = -321;
  s21_decimal b = {0};
  s21_from_int_to_decimal(a, &b);
  int res = 0;
  s21_from_decimal_to_int(b, &res);
  printf("%d", res);
  return 0;
}
