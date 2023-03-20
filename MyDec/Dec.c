#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int bits[4];
} s21_decimal;

typedef struct {
  int ost;
  int sel;
  int del;
} pre;

int getBit(s21_decimal bit, int i) {
  unsigned int mask = 1u << (i % 32);
  return bit.bits[i / 32] & mask;
}

int intTOdec(int num, s21_decimal mytwo, pre lol, int low[]) {
  int i = 31;
  lol.sel = num;
  while (i > 0) {
    lol.ost = lol.sel % 2;
    lol.sel = lol.sel / 2;
    // lol.sel == 1 ? low[i] = lol.sel :  lol.ost;
    if (lol.sel == 1 && lol.ost == 0) {
      low[i] = lol.ost;
      low[i - 1] = lol.sel;
    } else
      low[i] = lol.ost;
    // printf("%d", low[i]);
    i--;
  }
  printf("\n");

  return 0;
}

int decTOint(char low[]) {
  int i = 31;
  int p = 0;
  int num = 0;
  while (i > 0) {
    if (low[i] == 1) num += pow(2, p);
    i--;
    p++;
  }
  printf("\n%d", num);
  return 0;
}

int floatTOdec(float dec) {
  unsigned int fbits = *((unsigned int *)&dec);
  printf("\n");
  for (unsigned int mask = 0x8000000; mask; mask >>= 1) {
    printf("%d", !!(fbits & mask));
  }
  return 0;
}

int main(int argc, char const *argv[]) {
  int num = 9;
  //   int low[32];
  s21_decimal mytwo, ppp;
  int *ptr = &mytwo.bits[0];
  ptr = malloc(sizeof(char) * 32);
  pre lol = {0};
  int i = 1;
  int inti = 10;
  printf("==%d=1=\n", inti);
  int l = 1 << 3;
  inti = inti | l;
  printf("==%d=2=\n", inti);
  inti = inti >> 3;
  l += 0b1011;
  printf("==%d=3=\n", inti);
  inti += 0b1010;
  ppp.bits[0] = inti;

  printf("====%d====", ppp.bits[0]);

  intTOdec(num, mytwo, lol, ptr);

  while (i < 32) {
    printf("%d", ptr[i]);
    i++;
  }
  char pp[32] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
  decTOint(pp);
  // printf("\n%d", getBit(mytwo, 1));
  floatTOdec(0.5);

  free(ptr);
}
