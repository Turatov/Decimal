#include "s21_dbinary.h"
#include "s21_decimal.h"

int s21_is_greater(s21_decimal a, s21_decimal b) {
  return !s21_is_less_or_equal(a, b);
}
