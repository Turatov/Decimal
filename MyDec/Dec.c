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

int decTOint(int low[]) {
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

int main(int argc, char const *argv[]) {
  int num = 2147483647;
  //   int low[32];
  s21_decimal mytwo;
  int *ptr = &mytwo.bits[0];
  ptr = malloc(sizeof(int) * 32);
  pre lol = {0};
  int i = 1;
  intTOdec(num, mytwo, lol, ptr);
  while (i < 32) {
    printf("%d", ptr[i]);
    i++;
  }
  decTOint(ptr);
  free(ptr);
}
