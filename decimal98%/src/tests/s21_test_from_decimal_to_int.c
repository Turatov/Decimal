#include "test.h"

START_TEST(test1_from_decimal_to_int) {
  s21_decimal t = S21_DECIMAL_ONE;
  int n, r = 1;
  ck_assert_int_eq(s21_from_decimal_to_int(t, &n), 0);
  ck_assert_int_eq(n, r);
}
END_TEST

START_TEST(test2_from_decimal_to_int) {
  s21_decimal t = {{0x80000000, 0x8000000000000000}};
  int n, r = INT32_MIN;
  ck_assert_int_eq(s21_from_decimal_to_int(t, &n), 0);
  ck_assert_int_eq(n, r);
}
END_TEST

START_TEST(test3_from_decimal_to_int) {
  s21_decimal t = S21_DECIMAL_TEN;
  int n, r = 10;
  ck_assert_int_eq(s21_from_decimal_to_int(t, &n), 0);
  ck_assert_int_eq(n, r);
}
END_TEST

START_TEST(test4_from_decimal_to_int) {
  s21_decimal t = S21_DECIMAL_TEN;
  int n, r = 10;
  ck_assert_int_eq(s21_from_decimal_to_int(t, &n), 0);
  ck_assert_int_eq(n, r);
}
END_TEST

START_TEST(test5_from_decimal_to_int) {
  s21_decimal t = {{1337, 0}};
  int n, r = 1337;
  ck_assert_int_eq(s21_from_decimal_to_int(t, &n), 0);
  ck_assert_int_eq(n, r);
}
END_TEST

START_TEST(test6_from_decimal_to_int) {
  s21_decimal t = {{1237846, 0}};
  int n, r = 1237846;
  ck_assert_int_eq(s21_from_decimal_to_int(t, &n), 0);
  ck_assert_int_eq(n, r);
}
END_TEST

START_TEST(test7_from_decimal_to_int) {
  s21_decimal t = {{1237846, 0x8000000000000000}};
  int n, r = -1237846;
  ck_assert_int_eq(s21_from_decimal_to_int(t, &n), 0);
  ck_assert_int_eq(n, r);
}
END_TEST

START_TEST(test8_from_decimal_to_int) {
  s21_decimal t = {{420, 0x8000000000000000}};
  int n, r = -420;
  ck_assert_int_eq(s21_from_decimal_to_int(t, &n), 0);
  ck_assert_int_eq(n, r);
}
END_TEST

START_TEST(test9_from_decimal_to_int) {
  s21_decimal t = S21_DECIMAL_PI;
  int n, r = 3;
  ck_assert_int_eq(s21_from_decimal_to_int(t, &n), 0);
  ck_assert_int_eq(n, r);
}
END_TEST

START_TEST(test10_from_decimal_to_int) {
  s21_decimal t = S21_DECIMAL_E;
  t.bits8[15] = 0x80;
  int n, r = -2;
  r = -2;
  ck_assert_int_eq(s21_from_decimal_to_int(t, &n), 0);
  ck_assert_int_eq(n, r);
}
END_TEST

START_TEST(test11_from_decimal_to_int) {
  s21_decimal t = {{0x80000000, 0}};
  int n;
  ck_assert_int_eq(s21_from_decimal_to_int(t, &n), 1);
}
END_TEST

START_TEST(test12_from_decimal_to_int) {
  s21_decimal t = {{-1, 0}};
  int n;
  ck_assert_int_eq(s21_from_decimal_to_int(t, &n), 1);
}
END_TEST

START_TEST(test13_from_decimal_to_int) {
  s21_decimal t = S21_DECIMAL_MAX;
  int n;
  ck_assert_int_eq(s21_from_decimal_to_int(t, &n), 1);
}
END_TEST

Suite *s21_test_from_decimal_to_int(void) {
  Suite *s = suite_create("\033[45m-=s21_from_decimal_to_int=-\033[0m");
  TCase *tc = tcase_create("from_decimal_to_int_rc");

  tcase_add_test(tc, test1_from_decimal_to_int);
  tcase_add_test(tc, test2_from_decimal_to_int);
  tcase_add_test(tc, test3_from_decimal_to_int);
  tcase_add_test(tc, test4_from_decimal_to_int);
  tcase_add_test(tc, test5_from_decimal_to_int);
  tcase_add_test(tc, test6_from_decimal_to_int);
  tcase_add_test(tc, test7_from_decimal_to_int);
  tcase_add_test(tc, test8_from_decimal_to_int);
  tcase_add_test(tc, test9_from_decimal_to_int);
  tcase_add_test(tc, test10_from_decimal_to_int);
  tcase_add_test(tc, test11_from_decimal_to_int);
  tcase_add_test(tc, test12_from_decimal_to_int);
  tcase_add_test(tc, test13_from_decimal_to_int);

  suite_add_tcase(s, tc);
  return s;
}