
#include "test.h"

START_TEST(test1_from_int_to_decimal) {
  int src = 1337;
  s21_decimal e = {{1337, 0}};
  s21_decimal r;
  ck_assert_int_eq(s21_from_int_to_decimal(src, &r), 0);
  fail_if(memcmp(&e, &r, DSIZE));
}
END_TEST

START_TEST(test2_from_int_to_decimal) {
  int src = 430;
  s21_decimal e = {{430, 0}};
  s21_decimal r;
  ck_assert_int_eq(s21_from_int_to_decimal(src, &r), 0);
  fail_if(memcmp(&e, &r, DSIZE));
}
END_TEST

START_TEST(test3_from_int_to_decimal) {
  int src = 0xAB0BA;
  s21_decimal e = {{0xAB0BA, 0}};
  s21_decimal r;
  ck_assert_int_eq(s21_from_int_to_decimal(src, &r), 0);
  fail_if(memcmp(&e, &r, DSIZE));
}
END_TEST

START_TEST(test4_from_int_to_decimal) {
  int src = -1337;
  s21_decimal e = {{1337, 0}};
  e.bits8[15] = 0x80;
  s21_decimal r;
  ck_assert_int_eq(s21_from_int_to_decimal(src, &r), 0);
  fail_if(memcmp(&e, &r, DSIZE));
}
END_TEST

START_TEST(test5_from_int_to_decimal) {
  int src = INT32_MAX;
  s21_decimal e = {{INT32_MAX, 0}};
  s21_decimal r;
  ck_assert_int_eq(s21_from_int_to_decimal(src, &r), 0);
  fail_if(memcmp(&e, &r, DSIZE));
}
END_TEST

START_TEST(test6_from_int_to_decimal) {
  int src = INT32_MIN;
  s21_decimal e = {{0x80000000, 0}};
  e.bits8[15] = 0x80;
  s21_decimal r;
  ck_assert_int_eq(s21_from_int_to_decimal(src, &r), 0);
  fail_if(memcmp(&e, &r, DSIZE));
}
END_TEST

START_TEST(test7_from_int_to_decimal) {
  int src = 0;
  s21_decimal e = S21_DECIMAL_ZERO;
  s21_decimal r;
  ck_assert_int_eq(s21_from_int_to_decimal(src, &r), 0);
  fail_if(memcmp(&e, &r, DSIZE));
}
END_TEST

Suite *s21_test_from_int_to_decimal(void) {
  Suite *s = suite_create("\033[45m-=s21_from_int_to_decimal=-\033[0m");
  TCase *tc = tcase_create("from_int_to_decimal_rc");

  tcase_add_test(tc, test1_from_int_to_decimal);
  tcase_add_test(tc, test2_from_int_to_decimal);
  tcase_add_test(tc, test3_from_int_to_decimal);
  tcase_add_test(tc, test4_from_int_to_decimal);
  tcase_add_test(tc, test5_from_int_to_decimal);
  tcase_add_test(tc, test6_from_int_to_decimal);
  tcase_add_test(tc, test7_from_int_to_decimal);

  suite_add_tcase(s, tc);
  return s;
}