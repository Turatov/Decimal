
#include "test.h"

START_TEST(test1_from_float_to_decimal) {
  float src = 13.37;
  s21_decimal e = {{1337, 0x2000000000000}};
  s21_decimal r;
  ck_assert_int_eq(s21_from_float_to_decimal(src, &r), 0);
  fail_if(memcmp(&e, &r, DSIZE));
}
END_TEST

START_TEST(test2_from_float_to_decimal) {
  float src = 133.7;
  s21_decimal e = {{1337, 0x1000000000000}};
  s21_decimal r;
  ck_assert_int_eq(s21_from_float_to_decimal(src, &r), 0);
  fail_if(memcmp(&e, &r, DSIZE));
}
END_TEST

START_TEST(test3_from_float_to_decimal) {
  float src = -13.37;
  s21_decimal e = {{1337, 0x8002000000000000}};
  s21_decimal r;
  ck_assert_int_eq(s21_from_float_to_decimal(src, &r), 0);
  fail_if(memcmp(&e, &r, DSIZE));
}
END_TEST

START_TEST(test4_from_float_to_decimal) {
  float src = 4;
  s21_decimal e = {{4, 0}};
  s21_decimal r;
  ck_assert_int_eq(s21_from_float_to_decimal(src, &r), 0);
  fail_if(memcmp(&e, &r, DSIZE));
}
END_TEST

START_TEST(test5_from_float_to_decimal) {
  float src = 3.141592;
  s21_decimal e = {{3141592, 0x6000000000000}};
  s21_decimal r;
  ck_assert_int_eq(s21_from_float_to_decimal(src, &r), 0);
  fail_if(memcmp(&e, &r, DSIZE));
}
END_TEST

START_TEST(test6_from_float_to_decimal) {
  float src = FLT_MAX;
  s21_decimal r;
  ck_assert_int_eq(s21_from_float_to_decimal(src, &r), 1);
}
END_TEST

START_TEST(test7_from_float_to_decimal) {
  float src = -2.1474836E+09;
  s21_decimal e = {{2147483648, 0x8000000000000000}};
  s21_decimal r;
  ck_assert_int_eq(s21_from_float_to_decimal(src, &r), 0);
  fail_if(memcmp(&e, &r, DSIZE));
}
END_TEST

START_TEST(test8_from_float_to_decimal) {
  float src = -128.023;
  s21_decimal e = {{128023, 0x8003000000000000}};
  s21_decimal r;
  ck_assert_int_eq(s21_from_float_to_decimal(src, &r), 0);
  fail_if(memcmp(&e, &r, DSIZE));
}
END_TEST

START_TEST(test9_from_float_to_decimal) {
  float src = 1.337;
  s21_decimal e = {{1337, 0x3000000000000}};
  s21_decimal r;
  ck_assert_int_eq(s21_from_float_to_decimal(src, &r), 0);
  fail_if(memcmp(&e, &r, DSIZE));
}
END_TEST

START_TEST(test10_from_float_to_decimal) {
  float src = 1.02E+09;
  s21_decimal e = {{1020000000, 0}};
  s21_decimal r;
  ck_assert_int_eq(s21_from_float_to_decimal(src, &r), 0);
  fail_if(memcmp(&e, &r, DSIZE));
}
END_TEST

START_TEST(test11_from_float_to_decimal) {
  float src = -333.2222;
  s21_decimal e = {{3332222, 0x8004000000000000}};
  s21_decimal r;
  ck_assert_int_eq(s21_from_float_to_decimal(src, &r), 0);
  fail_if(memcmp(&e, &r, DSIZE));
}
END_TEST

START_TEST(test12_from_float_to_decimal) {
  float src = 127.1234;
  s21_decimal e = {{1271234, 0x04000000000000}};
  s21_decimal r;
  ck_assert_int_eq(s21_from_float_to_decimal(src, &r), 0);
  fail_if(memcmp(&e, &r, DSIZE));
}
END_TEST

START_TEST(test13_from_float_to_decimal) {
  float src = 0.03;
  s21_decimal e = {{3, 0x02000000000000}};
  s21_decimal r;
  ck_assert_int_eq(s21_from_float_to_decimal(src, &r), 0);
  fail_if(memcmp(&e, &r, DSIZE));
}
END_TEST

Suite *s21_test_from_float_to_decimal(void) {
  Suite *s = suite_create("\033[45m-=s21_from_float_to_decimal=-\033[0m");
  TCase *tc = tcase_create("from_float_to_decimal_rc");

  tcase_add_test(tc, test1_from_float_to_decimal);
  tcase_add_test(tc, test2_from_float_to_decimal);
  tcase_add_test(tc, test3_from_float_to_decimal);
  tcase_add_test(tc, test4_from_float_to_decimal);
  tcase_add_test(tc, test5_from_float_to_decimal);
  tcase_add_test(tc, test6_from_float_to_decimal);
  tcase_add_test(tc, test7_from_float_to_decimal);
  tcase_add_test(tc, test8_from_float_to_decimal);
  tcase_add_test(tc, test9_from_float_to_decimal);
  tcase_add_test(tc, test10_from_float_to_decimal);
  tcase_add_test(tc, test11_from_float_to_decimal);
  tcase_add_test(tc, test12_from_float_to_decimal);
  tcase_add_test(tc, test13_from_float_to_decimal);

  suite_add_tcase(s, tc);
  return s;
}