#ifndef SRC_TESTS_TEST_H
#define SRC_TESTS_TEST_H

#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../s21_decimal.h"

#define DSIZE sizeof(s21_decimal)

//  Arithmetic operators
Suite *s21_test_add(void);
Suite *s21_test_sub(void);
Suite *s21_test_mul(void);
Suite *s21_test_div(void);
Suite *s21_test_mod(void);

//  Comparison operators
Suite *s21_test_is_less(void);
Suite *s21_test_is_less_or_equal(void);
Suite *s21_test_is_greater(void);
Suite *s21_test_is_greater_or_equal(void);
Suite *s21_test_is_equal(void);
Suite *s21_test_is_not_equal(void);

//  Converters
Suite *s21_test_from_int_to_decimal(void);
Suite *s21_test_from_float_to_decimal(void);
Suite *s21_test_from_decimal_to_int(void);
Suite *s21_test_from_decimal_to_float(void);

// Another functions
Suite *s21_test_floor(void);
Suite *s21_test_round(void);
Suite *s21_test_truncate(void);
Suite *s21_test_negate(void);

Suite *s21_test_dbinary(void);

#endif  // SRC_TESTS_TEST_H