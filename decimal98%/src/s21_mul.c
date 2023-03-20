#include <stdio.h>
#include <string.h>

#include "s21_dbinary.h"
#include "s21_decimal.h"

// void output193(uint8_t *target) {
//   for (uint8_t i = 0; i < 193; i++)
//     printf("%d", (target[i / 8] & (1 << (i % 8))) >> i % 8);
//   printf("\n");
// }
void s21_rshift193(uint8_t *target) {
  uint32_t buff;
  target[0] >>= 1;
  for (int i = 1; i < 25; i++) {
    buff = target[i] & 1;
    target[i] >>= 1;
    target[i - 1] = (target[i - 1] & 0x7F) | (buff << 7);
  }
}
void s21_lshift193(uint8_t *target) {
  uint32_t buff;
  target[24] <<= 1;
  for (int i = 23; i >= 0; i--) {
    buff = target[i] & (1 << 7);
    target[i] <<= 1;
    target[i + 1] = (target[i + 1] & -2) | (buff >> 7);
  }
}
int8_t s21_cmp193(uint8_t *a, uint8_t *b) {
  int i = 24;
  for (; i > 0 && a[i] == b[i]; i--) {
  }
  return (a[i] > b[i]) - (a[i] < b[i]);
}

void s21_set(uint8_t *dst, s21_decimal src) {
  for (uint8_t i = 0; i < 12; i++) dst[i] = src.bits8[i];
}

void s21_add193(uint8_t *first, uint8_t *second) {
  uint8_t result[25];
  for (uint8_t i = 0, carry = 0; i < 25; i++) {
    result[i] = first[i] + second[i] + carry;
    carry = (second[i] > UINT8_MAX - carry) ||
            (first[i] > UINT8_MAX - second[i] - carry);
  }
  memcpy(second, result, 25);
  second[24] &= 1;
}
void s21_sub193(uint8_t *first, uint8_t *second) {
  uint8_t tmp[25];
  for (int i = 0; i < 25; i++) tmp[i] = ~second[i];
  uint8_t one[25] = {0};
  one[0] = 1;
  s21_add193(one, tmp);
  s21_add193(tmp, first);
}
void s21_mul193(uint8_t *first, uint8_t *second) {
  uint8_t res[25] = {0};
  for (uint8_t i = 0; i < 193; i++, s21_lshift193(first))
    if (second[i / 8] & (1 << i % 8)) s21_add193(first, res);
  memcpy(first, res, 25);
}
void s21_round193(uint8_t *target, uint8_t *div, uint8_t *rem) {
  uint8_t one[25] = {0};
  one[0] = 1;
  if ((s21_cmp193(rem, div) == 0 && (div[0] & 1)) || s21_cmp193(rem, div) == 1)
    s21_add193(one, target);
}
void s21_div193(uint8_t *n, uint8_t *d) {
  uint8_t r[25] = {0}, q[25] = {0};
  for (int i = 192; i >= 0; i--) {
    s21_lshift193(r);
    r[0] |= (n[i / 8] & (1 << (i % 8))) >> i % 8;
    if (s21_cmp193(r, d) != -1) {
      s21_sub193(r, d);
      q[i / 8] |= 1 << (i % 8);
    }
  }
  s21_lshift193(r);
  s21_round193(q, d, r);
  memcpy(n, q, 25);
}
uint8_t s21_is193(uint8_t *bits) {
  for (int i = 12; i < 25; i++)
    if (bits[i]) return 1;
  return 0;
}

s21_decimal s21_todecimal193(uint8_t *bits, int8_t power) {
  s21_decimal result = S21_DECIMAL_ZERO;
  uint8_t ten193[25] = {0};
  ten193[0] = 10;
  while (s21_is193(bits)) {
    s21_div193(bits, ten193);
    power--;
  }
  if (power > 28)
    return S21_DECIMAL_EPS;
  else if (power < 0)
    return S21_DECIMAL_INF;
  for (uint8_t i = 0; i < 12; i++) result.bits8[i] = bits[i];
  result.bits8[14] = power;
  return result;
}

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  uint8_t v1[25] = {0}, v2[25] = {0};
  s21_set(v1, value_1);
  s21_set(v2, value_2);
  s21_mul193(v1, v2);
  *result = s21_todecimal193(v1, value_1.bits8[14] + value_2.bits8[14]);
  result->bits8[15] = value_1.bits8[15] ^ value_2.bits8[15];
  if (result->bits8[14] == 0xFF)
    return (result->bits8[15]) ? 2 : 1;
  else if (result->bits8[14] == 0xFE)
    return 2;
  *result = s21_normalize(*result);
  return 0;
}
