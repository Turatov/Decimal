#include "test.h"

START_TEST(test1_is_greater) {
  s21_decimal n = {{48, 0}};
  s21_decimal d = {{48, 0}};
  ck_assert_int_eq(s21_is_greater(n, d), 0);
}
END_TEST

START_TEST(test2_is_greater) {
  s21_decimal n = {{48, 0}};
  s21_decimal d = {{48, 0}};
  n.bits8[15] = 0x80;
  d.bits8[15] = 0x80;
  ck_assert_int_eq(s21_is_greater(n, d), 0);
}
END_TEST

START_TEST(test3_is_greater) {
  s21_decimal n = {{48, 0}};
  s21_decimal d = {{48, 0}};
  n.bits8[15] = 0;
  d.bits8[15] = 0x80;
  ck_assert_int_eq(s21_is_greater(n, d), 1);
}
END_TEST

START_TEST(test4_is_greater) {
  s21_decimal n = {{48, 0}};
  s21_decimal d = {{48, 0}};
  n.bits8[15] = 0x80;
  d.bits8[15] = 0;
  ck_assert_int_eq(s21_is_greater(n, d), 0);
}
END_TEST

START_TEST(test5_is_greater) {
  s21_decimal n = {{-1, 0}};
  s21_decimal d = {{-1, 0}};
  ck_assert_int_eq(s21_is_greater(n, d), 0);
}
END_TEST

START_TEST(test6_is_greater) {
  s21_decimal n = {{-1, 0}};
  s21_decimal d = {{-1, 0}};
  n.bits8[15] = 0x80;
  d.bits8[15] = 0x80;
  ck_assert_int_eq(s21_is_greater(n, d), 0);
}
END_TEST

START_TEST(test7_is_greater) {
  s21_decimal n = {{-1, 0}};
  s21_decimal d = {{-1, 0}};
  n.bits8[15] = 0;
  d.bits8[15] = 0x80;
  ck_assert_int_eq(s21_is_greater(n, d), 1);
}
END_TEST

START_TEST(test8_is_greater) {
  s21_decimal n = {{-1, 0}};
  s21_decimal d = {{-1, 0}};
  n.bits8[15] = 0x80;
  d.bits8[15] = 0;
  ck_assert_int_eq(s21_is_greater(n, d), 0);
}
END_TEST

START_TEST(test9_is_greater) {
  s21_decimal n = {{-1, 0}};
  s21_decimal d = {{-1, 0}};
  n = S21_DECIMAL_PI;
  d = S21_DECIMAL_E;
  n.bits8[14] = 0;
  d.bits8[14] = 0;
  ck_assert_int_eq(s21_is_greater(n, d), 1);
}
END_TEST

START_TEST(test10_is_greater) {
  s21_decimal n = {{-1, 0}};
  s21_decimal d = {{-1, 0}};
  n.bits8[15] = 0x80;
  d.bits8[15] = 0x80;
  ck_assert_int_eq(s21_is_greater(n, d), 0);
}
END_TEST

START_TEST(test11_is_greater) {
  s21_decimal n = {{-1, 0}};
  s21_decimal d = {{-1, 0}};
  n.bits8[15] = 0;
  d.bits8[15] = 0x80;
  ck_assert_int_eq(s21_is_greater(n, d), 1);
}
END_TEST

START_TEST(test12_is_greater) {
  s21_decimal n = {{-1, 0}};
  s21_decimal d = {{-1, 0}};
  n.bits8[15] = 0x80;
  d.bits8[15] = 0;
  ck_assert_int_eq(s21_is_greater(n, d), 0);
}
END_TEST

START_TEST(test13_is_greater) {
  s21_decimal n = {{-1, 0}};
  s21_decimal d = {{-1, 0}};
  n = S21_DECIMAL_PI;
  d = S21_DECIMAL_E;
  ck_assert_int_eq(s21_is_greater(n, d), 1);
}
END_TEST

START_TEST(test14_is_greater) {
  s21_decimal n = {{-1, 0}};
  s21_decimal d = {{-1, 0}};
  n.bits8[15] = 0x80;
  d.bits8[15] = 0x80;
  ck_assert_int_eq(s21_is_greater(n, d), 0);
}
END_TEST

START_TEST(test15_is_greater) {
  s21_decimal n = {{-1, 0}};
  s21_decimal d = {{-1, 0}};
  n.bits8[15] = 0;
  d.bits8[15] = 0x80;
  ck_assert_int_eq(s21_is_greater(n, d), 1);
}
END_TEST

START_TEST(test16_is_greater) {
  s21_decimal n = {{-1, 0}};
  s21_decimal d = {{-1, 0}};
  n.bits8[15] = 0x80;
  d.bits8[15] = 0;
  ck_assert_int_eq(s21_is_greater(n, d), 0);
}
END_TEST

START_TEST(test17_is_greater) {
  s21_decimal n = {{127543, 0}};
  n.bits8[14] = 5;  // 1.27543
  s21_decimal d = {{48567, 0}};
  d.bits8[14] = 2;  // 485.67
  ck_assert_int_eq(s21_is_greater(n, d), 0);
}
END_TEST

START_TEST(test18_is_greater) {
  s21_decimal n = {{127543, 0}};
  n.bits8[14] = 5;  // 1.27543
  s21_decimal d = {{48567, 0}};
  n.bits8[15] = 0x80;
  d.bits8[15] = 0x80;
  ck_assert_int_eq(s21_is_greater(n, d), 1);
}
END_TEST

START_TEST(test19_is_greater) {
  s21_decimal n = {{127543, 0}};
  n.bits8[14] = 5;  // 1.27543
  s21_decimal d = {{48567, 0}};
  n.bits8[15] = 0;
  d.bits8[15] = 0x80;
  ck_assert_int_eq(s21_is_greater(n, d), 1);
}
END_TEST

START_TEST(test20_is_greater) {
  s21_decimal n = {{127543, 0}};
  n.bits8[14] = 5;  // 1.27543
  s21_decimal d = {{48567, 0}};
  n.bits8[15] = 0x80;
  d.bits8[15] = 0;
  ck_assert_int_eq(s21_is_greater(n, d), 0);
}
END_TEST
Suite *s21_test_is_greater(void) {
  Suite *s = suite_create("\033[45m-=s21_is_greater=-\033[0m");
  TCase *tc = tcase_create("is_greater_rc");

  tcase_add_test(tc, test1_is_greater);
  tcase_add_test(tc, test2_is_greater);
  tcase_add_test(tc, test3_is_greater);
  tcase_add_test(tc, test4_is_greater);
  tcase_add_test(tc, test5_is_greater);
  tcase_add_test(tc, test6_is_greater);
  tcase_add_test(tc, test7_is_greater);
  tcase_add_test(tc, test8_is_greater);
  tcase_add_test(tc, test9_is_greater);
  tcase_add_test(tc, test10_is_greater);
  tcase_add_test(tc, test11_is_greater);
  tcase_add_test(tc, test12_is_greater);
  tcase_add_test(tc, test13_is_greater);
  tcase_add_test(tc, test14_is_greater);
  tcase_add_test(tc, test15_is_greater);
  tcase_add_test(tc, test16_is_greater);
  tcase_add_test(tc, test17_is_greater);
  tcase_add_test(tc, test18_is_greater);
  tcase_add_test(tc, test19_is_greater);
  tcase_add_test(tc, test20_is_greater);

  suite_add_tcase(s, tc);
  return s;
}