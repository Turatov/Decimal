
#include "test.h"

START_TEST(test1_round) {
  s21_decimal x = {{92986, 0x4000000000000}};
  s21_decimal t = {{9, 0}};
  ck_assert_int_eq(s21_round(x, &x), 0);
  fail_if(memcmp(&x, &t, DSIZE));
}
END_TEST

START_TEST(test2_round) {
  s21_decimal x = {{100000000, 0x3000000000000}};
  s21_decimal t = {{100000, 0}};
  ck_assert_int_eq(s21_round(x, &x), 0);
  fail_if(memcmp(&x, &t, DSIZE));
}
END_TEST

START_TEST(test3_round) {
  s21_decimal x = {{0xB14388541B65F28, 0x1C00006582A536}};
  s21_decimal t = {{3, 0}};
  ck_assert_int_eq(s21_round(x, &x), 0);  // pi(zdec)
  fail_if(memcmp(&x, &t, DSIZE));
}
END_TEST

START_TEST(test4_round) {
  s21_decimal x = {{0xEBECDE35857AED59, 0x1C000057D519AB}};
  s21_decimal t = {{3, 0}};
  ck_assert_int_eq(s21_round(x, &x), 0);  // e
  fail_if(memcmp(&x, &t, DSIZE));
}
END_TEST

START_TEST(test5_round) {
  s21_decimal x = {{92986, 0x8003000000000000}};
  s21_decimal t = {{93, 0x8000000000000000}};
  ck_assert_int_eq(s21_round(x, &x), 0);
  fail_if(memcmp(&x, &t, DSIZE));
}
END_TEST

START_TEST(test6_round) {
  s21_decimal x = {{10000000, 0x8003000000000000}};
  s21_decimal t = {{10000, 0x8000000000000000}};
  ck_assert_int_eq(s21_round(x, &x), 0);
  fail_if(memcmp(&x, &t, DSIZE));
}
END_TEST

START_TEST(test7_round) {
  s21_decimal x = {{0xB14388541B65F28, 0x801C00006582A536}};
  s21_decimal t = {{3, 0x8000000000000000}};
  ck_assert_int_eq(s21_round(x, &x), 0);  // pi(zdec)
  fail_if(memcmp(&x, &t, DSIZE));
}
END_TEST

START_TEST(test8_round) {
  s21_decimal x = {{0xEBECDE35857AED59, 0x801C000057D519AB}};
  s21_decimal t = {{3, 0x8000000000000000}};
  ck_assert_int_eq(s21_round(x, &x), 0);  // e
  fail_if(memcmp(&x, &t, DSIZE));
}
END_TEST

Suite *s21_test_round(void) {
  Suite *s = suite_create("\033[45m-=s21_round=-\033[0m");
  TCase *tc = tcase_create("round_rc");

  tcase_add_test(tc, test1_round);
  tcase_add_test(tc, test2_round);
  tcase_add_test(tc, test3_round);
  tcase_add_test(tc, test4_round);
  tcase_add_test(tc, test5_round);
  tcase_add_test(tc, test6_round);
  tcase_add_test(tc, test7_round);
  tcase_add_test(tc, test8_round);

  suite_add_tcase(s, tc);
  return s;
}