#ifndef SRC_S21_DECIMAL_H_
#define SRC_S21_DECIMAL_H_

#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// Десятичная структура
// Поддерживает числа от -79 228 162 514 264 337 593 543 950 335 до
// +79 228 162 514 264 337 593 543 950 335.

// биты[0], биты[1] и биты[2] содержат младшие (LOW), средние (MID) и
// старший (SEN) 32 бита 96-битного целого числа соответственно.
// bits[3] содержит коэффициент масштабирования и знак и состоит из следующего
// части: Биты с 0 по 15, самое младшее слово, не используются и должны быть равны нулю. Биты 16
// до 23 должен содержать показатель степени от 0 до 28, который указывает степень числа 10
// для деления целого числа. Биты с 24 по 30 не используются и должны быть равны нулю. Кусочек
// 31 содержит знак; 0 означает положительный, а 1 означает отрицательный.

#define DEC_MAX 79228162514264337593543950335.0 
#define SIGN_MINUS 0b10000000000000000000000000000000 // это единичка
typedef struct {
  unsigned int bits[4];
} s21_decimal; // 32 * 4 = 128 бит

typedef struct s21_big_decimal {
  int bits[7];
} s21_big_decimal; // 32 * 7 = 224 бита

typedef union {
  unsigned int uint;
  float flot;
} uint_float;

// выходные коды
enum result_codes {
  OK_CODE = 0,
  S21_FALSE = 0,
  INF_OR_TOO_BIG = 1,
  S21_TRUE = 1,
  CONVERTION_ERROR = 1,
  CALCULATION_ERROR = 1,
  MINUS_INF_OR_TOO_SMALL = 2,
  DIV_BY_ZERO = 3
};

// ----------------- Арифметика -----------------
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mod(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

// ----------------- Сравнение -----------------
int s21_is_equal(s21_decimal decimal_one, s21_decimal decimal_two);
int s21_is_not_equal(s21_decimal decimal_one, s21_decimal decimal_two);
int s21_is_less(s21_decimal decimal_one, s21_decimal decimal_two);
int s21_is_less_or_equal(s21_decimal decimal_one, s21_decimal decimal_two);
int s21_is_greater(s21_decimal decimal_one, s21_decimal decimal_two);
int s21_is_greater_or_equal(s21_decimal decimal_one, s21_decimal decimal_two);
int Compare(s21_decimal number_1, s21_decimal number_2);

// ---------------- Преобразователи -------------------
int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);

// ------------- Другие функции ------------------
int s21_floor(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_bank_rounding(s21_decimal value, s21_decimal *result);
void SetScaleSign(s21_decimal *value, int scale, int sign);

// ----------------- Общий -----------------
int GetBit(s21_decimal value, int bit);
int GetSign(s21_decimal value);
int CheckExp(s21_decimal value);
int SetScale(int pow, int sign);
void InitialiseNumber(s21_decimal *value);
s21_decimal InvertSign(s21_decimal value);
void CopySign(s21_decimal value1, s21_decimal *value2);
s21_decimal Module(s21_decimal value);
void ComShift(s21_decimal *value_1, s21_decimal *value_2);
int Mul10(s21_decimal *value);
s21_decimal RoundAftComma(s21_decimal value, int p);
int OccupBitsNum(s21_decimal value);
int ShiftDecimal(s21_decimal *value, int j);
int Div10(s21_decimal value_1, s21_decimal *result);
int IsEven(s21_decimal value);
void TmpUpgrade(s21_decimal *value);

int is_negative(s21_decimal value);
int is_zero(s21_decimal value);
int s21_take_fractional_part(s21_decimal value, s21_decimal *fractional_part);
int s21_ten_pow(int last_32_bits);
int s21_one(s21_decimal *one_value);

// ----------------- Большой децимал -----------------
void GetDigit(s21_big_decimal *value, int j);
void IntDivisionExt(s21_big_decimal *value_1, s21_decimal value_2,
                    s21_big_decimal *mod);
int Div10Ext(s21_big_decimal value_1, s21_big_decimal *result);
int AddAlgo(s21_big_decimal value_1, s21_big_decimal value_2,
            s21_big_decimal *result);
int SubAlgo(s21_big_decimal value_1, s21_big_decimal value_2,
            s21_big_decimal *result);
void MultAlgo(s21_big_decimal value_1, s21_big_decimal value_2,
              s21_big_decimal *result);
void DivAlgo(s21_big_decimal value_1, s21_decimal value_2,
             s21_big_decimal *result);
void ModAlgo(s21_big_decimal *value_1, s21_big_decimal value_2,
             s21_big_decimal *mod);

// ----------------- Общий Расширенный -----------------
s21_big_decimal ExtendDecimal(s21_decimal value);
int ShortenExtDecimal(s21_big_decimal value1, s21_decimal *value2);
int CheckExtPart(s21_big_decimal value);
int MulExtDec10(s21_big_decimal *value);
int GetSignExt(s21_big_decimal value);
int CheckExpExt(s21_big_decimal value);
void InitialiseExtNumber(s21_big_decimal *value);
void ShiftComExt(s21_big_decimal *value_1, s21_big_decimal *value_2);
int Mul10Ext(s21_big_decimal *value);
s21_big_decimal RoundAftCommaExt(s21_big_decimal value, int p);
int OccupBitsNumExt(s21_big_decimal value);
int ShiftBitExt(s21_big_decimal *value, int j);
int GetBitExt(s21_big_decimal value, int bit);
int IsEvenExt(s21_big_decimal value);
void TmpUpgradeExt(s21_big_decimal *value);

//--------- Сравнение большого десятичного числа ------------
int s21_is_equal_big(s21_big_decimal decimal_one, s21_big_decimal decimal_two);
int s21_is_not_equal_big(s21_big_decimal decimal_one,
                         s21_big_decimal decimal_two);
int s21_is_less_big(s21_big_decimal decimal_one, s21_big_decimal decimal_two);
int s21_is_less_or_equal_big(s21_big_decimal decimal_one,
                             s21_big_decimal decimal_two);
int s21_is_greater_big(s21_big_decimal decimal_one,
                       s21_big_decimal decimal_two);
int s21_is_greater_or_equal_big(s21_big_decimal decimal_one,
                                s21_big_decimal decimal_two);

int CompareExt(s21_big_decimal number_1, s21_big_decimal number_2);

//--------- Круглый большой десятичный -----------
int s21_truncate_big(s21_big_decimal value, s21_big_decimal *result);
int s21_banking_round_big(s21_big_decimal value, s21_big_decimal *result);
void SetScaleSignExt(s21_big_decimal *value, int scale, int sign);

#endif  //  SRC_S21_DECIMAL_H_
