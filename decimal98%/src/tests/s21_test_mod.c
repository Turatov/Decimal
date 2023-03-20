
#include "test.h"

START_TEST(test1_mod) {
  s21_decimal n = {{48, 0}};
  s21_decimal d = {{6, 0}};
  s21_decimal r = {{0, 0}};
  s21_decimal q;
  ck_assert_int_eq(s21_mod(n, d, &q), 0);  // 48%6 = 0
  fail_if(memcmp(&q, &r, DSIZE));
}
END_TEST

START_TEST(test2_mod) {
  s21_decimal n = {{90, 0}};
  s21_decimal d = {{9, 0}};
  s21_decimal r = {{0, 0}};
  s21_decimal q;
  ck_assert_int_eq(s21_mod(n, d, &q), 0);  // 90%9 = 0
  fail_if(memcmp(&q, &r, DSIZE));
}
END_TEST

START_TEST(test3_mod) {
  s21_decimal n = {{1024, 0}};
  s21_decimal d = {{4, 0}};
  s21_decimal r = {{0, 0}};
  s21_decimal q;
  ck_assert_int_eq(s21_mod(n, d, &q), 0);  // 1024%4 = 0
  fail_if(memcmp(&q, &r, DSIZE));
}
END_TEST

START_TEST(test4_mod) {
  s21_decimal n = {{233, 0x1000000000000}};
  s21_decimal d = {{92985, 0x4000000000000}};
  s21_decimal r = {{4703, 0x3000000000000}};
  s21_decimal q;
  ck_assert_int_eq(s21_mod(n, d, &q), 0);  // 23.3%9.2985 = 4.703
  fail_if(memcmp(&q, &r, DSIZE));
}
END_TEST

START_TEST(test5_mod) {
  s21_decimal n = S21_DECIMAL_PI;
  s21_decimal d = {{2, 0}};
  s21_decimal r = {{0x8eca33c321b65f28, 0x1C000024e30879}};
  s21_decimal q;
  ck_assert_int_eq(s21_mod(n, d, &q),
                   0);  // pi%2 = 1.1415926535897932384626433832 (* 10^-28)
  fail_if(memcmp(&q, &r, DSIZE));
}
END_TEST

START_TEST(test6_mod) {
  s21_decimal n = {{1, 0x1000000000000}};
  s21_decimal d = {{3, 0}};
  s21_decimal r = {{1, 0x1000000000000}};
  s21_decimal q;
  ck_assert_int_eq(s21_mod(n, d, &q), 0);  // 0.1%3 = 0.1
  fail_if(memcmp(&q, &r, DSIZE));
}
END_TEST

START_TEST(test7_mod) {
  s21_decimal n = {{1, 0x1000000000000}};
  s21_decimal d = {{7, 0x2000000000000}};
  s21_decimal r = {{3, 0x2000000000000}};
  s21_decimal q;
  ck_assert_int_eq(s21_mod(n, d, &q), 0);  // 0.1%0.07 = 0.03
  fail_if(memcmp(&q, &r, DSIZE));
}
END_TEST

START_TEST(test8_mod) {
  s21_decimal n = {{233, 0x8001000000000000}};
  s21_decimal d = {{92985, 0x4000000000000}};
  s21_decimal r = {{4703, 0x8003000000000000}};
  s21_decimal q;
  ck_assert_int_eq(s21_mod(n, d, &q), 0);  // -23.3%9.2985 = -4.703
  fail_if(memcmp(&q, &r, DSIZE));
}
END_TEST

START_TEST(test9_mod) {
  s21_decimal n = {{0x50A00E51E3936EB0, 0x10000000000057}};
  s21_decimal d = {{0x29636EC4111B3, 0x8009000000000000}};
  s21_decimal r = {{0x50A00E51E3936EB0, 0x10000000000057}};
  s21_decimal q;
  // 161067.6393676912160432 (* 10^-16) % -728112.589509043 (* 10^-9)
  // 161067.6393676912160432 * (10^-16)
  ck_assert_int_eq(s21_mod(n, d, &q), 0);
  fail_if(memcmp(&q, &r, DSIZE));
}
END_TEST

START_TEST(test10_mod) {
  s21_decimal n = S21_DECIMAL_PI;
  s21_decimal d = S21_DECIMAL_E;
  s21_decimal r = {{0x1f275a4fbc3b71cf, 0x1c00000dad8b8a}};
  s21_decimal q;
  // pi%e
  // 0.4233108251307480031023559119 (* 10^-28)
  ck_assert_int_eq(s21_mod(n, d, &q), 0);
  fail_if(memcmp(&q, &r, DSIZE));
}
END_TEST

START_TEST(test11_mod) {
  s21_decimal n = S21_DECIMAL_MAX;
  s21_decimal d = S21_DECIMAL_ONE;
  s21_decimal r = S21_DECIMAL_ZERO;
  s21_decimal q;
  ck_assert_int_eq(s21_mod(n, d, &q), 0);  // MAX%1 = 0
  fail_if(memcmp(&q, &r, DSIZE));
}
END_TEST

START_TEST(test12_mod) {
  s21_decimal n = S21_DECIMAL_PI;
  s21_decimal d = S21_DECIMAL_ONE;
  s21_decimal r = {{0x50a5316211b65f28, 0x1c000004933a1b}};
  s21_decimal q;
  // pi%1 = 0.1415926535897932384626433832 (* 10^-28)
  ck_assert_int_eq(s21_mod(n, d, &q), 0);
  fail_if(memcmp(&q, &r, DSIZE));
}
END_TEST

START_TEST(test13_mod) {
  s21_decimal n = S21_DECIMAL_MAX;
  s21_decimal d = {{2, 0}};
  s21_decimal r = S21_DECIMAL_ONE;
  s21_decimal q;
  ck_assert_int_eq(s21_mod(n, d, &q), 0);  // MAX%2
  fail_if(memcmp(&q, &r, DSIZE));
}
END_TEST

START_TEST(test14_mod) {
  s21_decimal n = S21_DECIMAL_MIN;
  s21_decimal d = {{2, 0}};
  s21_decimal r = S21_DECIMAL_ONE;
  s21_decimal q;
  ck_assert_int_eq(s21_mod(n, d, &q), 0);  // MIN%2
  fail_if(memcmp(&q, &r, DSIZE));
}
END_TEST

START_TEST(test15_mod) {
  s21_decimal n = {{0xb30310a770000000, 0xe22ea493}};
  s21_decimal d = {{1, 0x3000000000000}};
  s21_decimal r = S21_DECIMAL_ZERO;
  s21_decimal q;
  // 70000000000000000000000000000 % 0.001 = 0
  ck_assert_int_eq(s21_mod(n, d, &q), 0);
  fail_if(memcmp(&q, &r, DSIZE));
}
END_TEST

START_TEST(test16_mod) {
  s21_decimal n = {{0x1C1EBCD1D2D77, 0x8000000000000000}};
  ;
  s21_decimal d = {{0x265678CD26C4, 0x8000000000000000}};
  s21_decimal r = {{0x1c349c4c830b, 0x8000000000000000}};
  s21_decimal q;
  // -494693479427447%-42152835753668
  // -31012286137099
  ck_assert_int_eq(s21_mod(n, d, &q), 0);
  fail_if(memcmp(&q, &r, DSIZE));
}
END_TEST

Suite *s21_test_mod(void) {
  Suite *s = suite_create("\033[45m-=s21_mod=-\033[0m");
  TCase *tc = tcase_create("mod_rc");

  tcase_add_test(tc, test1_mod);
  tcase_add_test(tc, test2_mod);
  tcase_add_test(tc, test3_mod);
  tcase_add_test(tc, test4_mod);
  tcase_add_test(tc, test5_mod);
  tcase_add_test(tc, test6_mod);
  tcase_add_test(tc, test7_mod);
  tcase_add_test(tc, test8_mod);
  tcase_add_test(tc, test9_mod);
  tcase_add_test(tc, test10_mod);
  tcase_add_test(tc, test11_mod);
  tcase_add_test(tc, test12_mod);
  tcase_add_test(tc, test13_mod);
  tcase_add_test(tc, test14_mod);
  tcase_add_test(tc, test15_mod);
  tcase_add_test(tc, test16_mod);

  suite_add_tcase(s, tc);
  return s;
}