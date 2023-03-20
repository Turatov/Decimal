
#include "test.h"

START_TEST(test1_negate) {
  s21_decimal x = {{92986, 0x804000000000000}};
  s21_decimal t = x;
  t.bits8[15] = x.bits8[15] ^ 0x80;
  ck_assert_int_eq(s21_negate(x, &t), 0);
  fail_if(x.bits8[15] == t.bits8[15]);
}
END_TEST

START_TEST(test2_negate) {
  s21_decimal x = {{92986, 0x4000000000000}};
  s21_decimal t = x;
  t.bits8[15] = x.bits8[15] ^ 0x80;
  ck_assert_int_eq(s21_negate(x, &t), 0);
  fail_if(x.bits8[15] == t.bits8[15]);
}
END_TEST

START_TEST(test3_negate) {
  s21_decimal x = S21_DECIMAL_PI;
  s21_decimal t = x;
  t.bits8[15] = x.bits8[15] ^ 0x80;
  ck_assert_int_eq(s21_negate(x, &t), 0);
  fail_if(x.bits8[15] == t.bits8[15]);
}
END_TEST

START_TEST(test4_negate) {
  s21_decimal x = S21_DECIMAL_E;
  s21_decimal t = x;
  t.bits8[15] = x.bits8[15] ^ 0x80;
  ck_assert_int_eq(s21_negate(x, &t), 0);
  fail_if(x.bits8[15] == t.bits8[15]);
}
END_TEST

START_TEST(test5_negate) {
  s21_decimal x = S21_DECIMAL_MAX;
  s21_decimal t = x;
  t.bits8[15] = x.bits8[15] ^ 0x80;
  ck_assert_int_eq(s21_negate(x, &t), 0);
  fail_if(x.bits8[15] == t.bits8[15]);
}
END_TEST

START_TEST(test6_negate) {
  s21_decimal x = S21_DECIMAL_MIN;
  s21_decimal t = x;
  t.bits8[15] = x.bits8[15] ^ 0x80;
  ck_assert_int_eq(s21_negate(x, &t), 0);
  fail_if(x.bits8[15] == t.bits8[15]);
}
END_TEST

START_TEST(test7_negate) {
  s21_decimal x = S21_DECIMAL_INF;
  s21_decimal t = x;
  t.bits8[15] = x.bits8[15] ^ 0x80;
  ck_assert_int_eq(s21_negate(x, &t), 0);
  fail_if(x.bits8[15] == t.bits8[15]);
}
END_TEST

START_TEST(test8_negate) {
  s21_decimal x = S21_DECIMAL_ONE;
  s21_decimal t = x;
  t.bits8[15] = x.bits8[15] ^ 0x80;
  ck_assert_int_eq(s21_negate(x, &t), 0);
  fail_if(x.bits8[15] == t.bits8[15]);
}
END_TEST

Suite *s21_test_negate(void) {
  Suite *s = suite_create("\033[45m-=s21_negate=-\033[0m");
  TCase *tc = tcase_create("negate_rc");

  tcase_add_test(tc, test1_negate);
  tcase_add_test(tc, test2_negate);
  tcase_add_test(tc, test3_negate);
  tcase_add_test(tc, test4_negate);
  tcase_add_test(tc, test5_negate);
  tcase_add_test(tc, test6_negate);
  tcase_add_test(tc, test7_negate);
  tcase_add_test(tc, test8_negate);

  suite_add_tcase(s, tc);
  return s;
}