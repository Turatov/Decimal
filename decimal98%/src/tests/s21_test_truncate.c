#include "test.h"

START_TEST(test1_truncate) {
  s21_decimal x = {{92986, 0x4000000000000}};
  s21_decimal t = {{9, 0}};
  ck_assert_int_eq(s21_truncate(x, &x), 0);
  fail_if(memcmp(&x, &t, DSIZE));
}
END_TEST

START_TEST(test2_truncate) {
  s21_decimal x = {{100000000, 0x3000000000000}};
  s21_decimal t = {{100000, 0}};
  ck_assert_int_eq(s21_truncate(x, &x), 0);
  fail_if(memcmp(&x, &t, DSIZE));
}
END_TEST

START_TEST(test3_truncate) {
  s21_decimal x = {{0xB14388541B65F28, 0x1C00006582A536}};
  s21_decimal t = {{3, 0}};
  ck_assert_int_eq(s21_truncate(x, &x), 0);  // pi(zdec)
  fail_if(memcmp(&x, &t, DSIZE));
}
END_TEST

START_TEST(test4_truncate) {
  s21_decimal x = {{0xEBECDE35857AED59, 0x1C000057D519AB}};
  s21_decimal t = {{2, 0}};
  ck_assert_int_eq(s21_truncate(x, &x), 0);  // e
  fail_if(memcmp(&x, &t, DSIZE));
}
END_TEST

START_TEST(test5_truncate) {
  s21_decimal x = {{92986, 0x8003000000000000}};
  s21_decimal t = {{92, 0x8000000000000000}};
  ck_assert_int_eq(s21_truncate(x, &x), 0);
  fail_if(memcmp(&x, &t, DSIZE));
}
END_TEST

START_TEST(test6_truncate) {
  s21_decimal x = {{10000000, 0x8003000000000000}};
  s21_decimal t = {{10000, 0x8000000000000000}};
  ck_assert_int_eq(s21_truncate(x, &x), 0);
  fail_if(memcmp(&x, &t, DSIZE));
}
END_TEST

START_TEST(test7_truncate) {
  s21_decimal x = {{0xB14388541B65F28, 0x801C00006582A536}};
  s21_decimal t = {{3, 0x8000000000000000}};
  ck_assert_int_eq(s21_truncate(x, &x), 0);  // pi(zdec)
  fail_if(memcmp(&x, &t, DSIZE));
}
END_TEST

START_TEST(test8_truncate) {
  s21_decimal x = {{0xEBECDE35857AED59, 0x801C000057D519AB}};
  s21_decimal t = {{2, 0x8000000000000000}};
  ck_assert_int_eq(s21_truncate(x, &x), 0);  // e
  fail_if(memcmp(&x, &t, DSIZE));
}
END_TEST

Suite *s21_test_truncate(void) {
  Suite *s = suite_create("\033[45m-=s21_truncate=-\033[0m");
  TCase *tc = tcase_create("truncate_rc");

  tcase_add_test(tc, test1_truncate);
  tcase_add_test(tc, test2_truncate);
  tcase_add_test(tc, test3_truncate);
  tcase_add_test(tc, test4_truncate);
  tcase_add_test(tc, test5_truncate);
  tcase_add_test(tc, test6_truncate);
  tcase_add_test(tc, test7_truncate);
  tcase_add_test(tc, test8_truncate);

  suite_add_tcase(s, tc);
  return s;
}