
#include "test.h"

START_TEST(test1_from_decimal_to_float) {
  s21_decimal t = S21_DECIMAL_ONE;
  float n, r = 1;
  ck_assert_int_eq(s21_from_decimal_to_float(t, &n), 0);
  ck_assert_float_eq_tol(n, r, 1e-6);
}
END_TEST

START_TEST(test2_from_decimal_to_float) {
  s21_decimal t = {{0x80000000, 0x8000000000000000}};
  float n, r = -2147483647.;
  ck_assert_int_eq(s21_from_decimal_to_float(t, &n), 0);
  ck_assert_float_eq_tol(n, r, 1e-6);
}
END_TEST

START_TEST(test3_from_decimal_to_float) {
  s21_decimal t = S21_DECIMAL_TEN;
  float n, r = 10.;
  ck_assert_int_eq(s21_from_decimal_to_float(t, &n), 0);
  ck_assert_float_eq_tol(n, r, 1e-6);
}
END_TEST

START_TEST(test4_from_decimal_to_float) {
  s21_decimal t = S21_DECIMAL_TEN;
  float n, r = 10.;
  ck_assert_int_eq(s21_from_decimal_to_float(t, &n), 0);
  ck_assert_float_eq_tol(n, r, 1e-6);
}
END_TEST

START_TEST(test5_from_decimal_to_float) {
  s21_decimal t = {{1337, 0x2000000000000}};
  float n, r = 13.37;
  ck_assert_int_eq(s21_from_decimal_to_float(t, &n), 0);
  ck_assert_float_eq_tol(n, r, 1e-6);
}
END_TEST

START_TEST(test6_from_decimal_to_float) {
  s21_decimal t = {{1237846, 0x4000000000000}};
  float n, r = 123.7846;
  ck_assert_int_eq(s21_from_decimal_to_float(t, &n), 0);
  ck_assert_float_eq_tol(n, r, 1e-6);
}
END_TEST

START_TEST(test7_from_decimal_to_float) {
  s21_decimal t = {{1237846, 0x8006000000000000}};
  float n, r = -1.237846;
  ck_assert_int_eq(s21_from_decimal_to_float(t, &n), 0);
  ck_assert_float_eq_tol(n, r, 1e-6);
}
END_TEST

START_TEST(test8_from_decimal_to_float) {
  s21_decimal t = {{42.0, 0x8000000000000000}};
  float n, r = -42.0;
  ck_assert_int_eq(s21_from_decimal_to_float(t, &n), 0);
  ck_assert_float_eq_tol(n, r, 1e-6);
}
END_TEST

START_TEST(test9_from_decimal_to_float) {
  s21_decimal t = S21_DECIMAL_PI;
  float n, r = 3.1415926535897932384626433832;
  ck_assert_int_eq(s21_from_decimal_to_float(t, &n), 0);
  ck_assert_float_eq_tol(n, r, 1e-6);
}
END_TEST

START_TEST(test10_from_decimal_to_float) {
  s21_decimal t = S21_DECIMAL_E;
  t.bits8[15] = 0x80;
  float n, r = -2.7182818284590452353602874713;
  ck_assert_int_eq(s21_from_decimal_to_float(t, &n), 0);
  ck_assert_float_eq_tol(n, r, 1e-6);
}
END_TEST

START_TEST(test11_from_decimal_to_float) {
  s21_decimal t = {{0x354580144d555555, 0x1c00000113ba14}};
  float n, r = 0.0333333333333333333333333333;
  ck_assert_int_eq(s21_from_decimal_to_float(t, &n), 0);
  ck_assert_float_eq_tol(n, r, 1e-6);
}
END_TEST

START_TEST(test12_from_decimal_to_float) {
  s21_decimal t = {{0x2547e8e3782ad6b7, 0x801c000050f7549c}};
  float n, r = -2.5057805022315427219443996343;
  ck_assert_int_eq(s21_from_decimal_to_float(t, &n), 0);
  ck_assert_float_eq_tol(n, r, 1e-6);
}
END_TEST

START_TEST(test13_from_decimal_to_float) {
  s21_decimal t = {{92985, 0x4000000000000}};
  ;
  float n, r = 9.2985;
  ck_assert_int_eq(s21_from_decimal_to_float(t, &n), 0);
  ck_assert_float_eq_tol(n, r, 1e-6);
}
END_TEST

Suite *s21_test_from_decimal_to_float(void) {
  Suite *s = suite_create("\033[45m-=s21_from_decimal_to_float=-\033[0m");
  TCase *tc = tcase_create("from_decimal_to_float_rc");

  tcase_add_test(tc, test1_from_decimal_to_float);
  tcase_add_test(tc, test2_from_decimal_to_float);
  tcase_add_test(tc, test3_from_decimal_to_float);
  tcase_add_test(tc, test4_from_decimal_to_float);
  tcase_add_test(tc, test5_from_decimal_to_float);
  tcase_add_test(tc, test6_from_decimal_to_float);
  tcase_add_test(tc, test7_from_decimal_to_float);
  tcase_add_test(tc, test8_from_decimal_to_float);
  tcase_add_test(tc, test9_from_decimal_to_float);
  tcase_add_test(tc, test10_from_decimal_to_float);
  tcase_add_test(tc, test11_from_decimal_to_float);
  tcase_add_test(tc, test12_from_decimal_to_float);
  tcase_add_test(tc, test13_from_decimal_to_float);

  suite_add_tcase(s, tc);
  return s;
}