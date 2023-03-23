#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef union {
  uint64_t bits64[2];
  uint32_t bits32[4];  // general
  uint16_t bits16[8];
  uint8_t bits8[16];
  int32_t bits[4];
} s21_decimal;

void print_bit_byte(unsigned char aByte) {
  printf("%c", (0b10000000 & aByte) ? '1' : '0');
  printf("%c", (0b01000000 & aByte) ? '1' : '0');
  printf("%c", (0b00100000 & aByte) ? '1' : '0');
  printf("%c", (0b00010000 & aByte) ? '1' : '0');
  printf("%c", (0b00001000 & aByte) ? '1' : '0');
  printf("%c", (0b00000100 & aByte) ? '1' : '0');
  printf("%c", (0b00000010 & aByte) ? '1' : '0');
  printf("%c", (0b00000001 & aByte) ? '1' : '0');
  printf("\n");
}

void print_bit(unsigned int aBute, char des[]) {
  unsigned int mask = 1;
  for (size_t i = 31; i >= 1; --i) {
    printf("%c", (mask << i & aBute) ? '1' : '0');
    if (i == 1) printf("%c", (mask & aBute) ? '1' : '0');
  }
  printf(" %s\n", des);
}

unsigned set_bit(unsigned aValue, unsigned aNumber) {
  return aValue | (1 << aNumber);
}

unsigned clear_bit(unsigned aValue, unsigned aNumber) {
  return aValue & (~(1 << aNumber));
}

unsigned invert_bit(unsigned aValue, unsigned aNumber) {
  return aValue ^ (1 << aNumber);
}

unsigned test_bit(unsigned aValue, unsigned aNumber) {
  return aValue & (1 << aNumber);
}
// 1101
unsigned n_of_s_bits(unsigned aValue) {
  unsigned res = 0;
  while (aValue) {
    aValue = aValue & (aValue - 1);
    res++;
  }
  return res;
}

void swap_xor(int *a, int *b) {
  *a = *a ^ *b;
  *b = *b ^ *a;
  *a = *a ^ *b;
}

int add(int summand, int addend) {
  /*Перенос.*/
  int carry = 0x00;
  print_bit(summand, "summand");
  print_bit(addend, "addend");
  /*Итерировать до тех пор, пока не закончится перенос на старший разряд.*/
  while (addend != 0x00) {
    /*Выставить флаг под разрядами с установленными битами.*/
    carry = (summand & addend);
    print_bit(carry, "carry");
    /*Снять с первого слагаемого биты, разряд по которым уже учтен.*/
    summand = summand ^ addend;
    print_bit(summand, "summand");
    /*Перенос переводится в старший разряд.*/
    addend = (carry << 1);
    print_bit(addend, "addend");
  }
  return summand;
}

int s21_from_int_to_decimal(long long int src, s21_decimal *dst) {
  print_bit(src, "src");
  dst->bits64[0] = dst->bits64[1] = 0;
  print_bit(dst->bits64[0], "dst->bits64[0]");
  if (src < 0) dst->bits8[15] = 0x80;
  print_bit(dst->bits8[15], "dst->bits8[15]");
  long long int ecode = (src < 0) ? ~src + 1 : src;
  print_bit(ecode, "ecode");
  dst->bits32[0] = ecode;
  print_bit(dst->bits32[0], "dst->bits32[0]");
  return 0;
}

int writeToDec(long double num) {
  char sum[97] = {0};

  s21_decimal a = {0};
  while (1) {
    a.bits32[0] = num;
  }
  print_bit(a.bits32[0], "младший");
  return 0;
}

int main() {
  // unsigned char uc = 0b00111100;

  // int uc = 400000;
  // printf("%d\n", uc);
  // print_bit(uc, "uc");
  // uc = add(uc, 300000);
  // printf("%d\n", uc);
  // printf("%d", n_of_s_bits(uc));
  // print_bit(uc, "uc");

  // writeToDec(7922816251426433759);
  s21_decimal a;
  s21_from_int_to_decimal(7922816251426433759, &a);

  return 0;
}
// 79228162514264337593543950335