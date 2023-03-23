#include <stdio.h>

#include "s21_decimal.h"

void print_bit(unsigned int aBute, char dec[]) {
  unsigned int mask = 1;
  for (int i = 31; i >= 1; --i) {
    printf("%c", (mask << i & aBute) ? '1' : '0');
    if (i == 1) printf("%c", (mask & aBute) ? '1' : '0');
  }
  printf(" %s\n", dec);
}

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  print_bit(src, "src");
  dst->bits64[0] = dst->bits64[1] = 0;
  print_bit(dst->bits64[0], "dst->bits64[0]");
  if (src < 0) dst->bits8[15] = 0x80;
  print_bit(dst->bits8[15], "dst->bits8[15]");
  unsigned int ecode = (src < 0) ? ~src + 1 : src;
  print_bit(ecode, "ecode");
  dst->bits32[0] = ecode;
  print_bit(dst->bits32[0], "dst->bits32[0]");
  return 0;
}
