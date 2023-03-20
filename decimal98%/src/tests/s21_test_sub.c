#include "test.h"

START_TEST(test1_sub) {
  s21_decimal n = {{48, 0}};
  s21_decimal d = {{6, 0}};
  s21_decimal r = {{42, 0}};
  s21_decimal q;
  ck_assert_int_eq(s21_sub(n, d, &q), 0);  // 48-6 = 42
  fail_if(memcmp(&q, &r, DSIZE));
}
END_TEST

START_TEST(test2_sub) {
  s21_decimal n = {{6, 0}};
  s21_decimal d = {{48, 0}};
  s21_decimal r = {{42, 0}};
  r.bits8[15] = 0x80;
  s21_decimal q;
  ck_assert_int_eq(s21_sub(n, d, &q), 0);  // 6-48 = -42
  fail_if(memcmp(&q, &r, DSIZE));
}
END_TEST

START_TEST(test3_sub) {
  s21_decimal n = {{48, 0}};
  s21_decimal d = {{6, 0}};
  n.bits8[15] = 0x80;
  s21_decimal r = {{54, 0}};
  r.bits8[15] = 0x80;
  s21_decimal q;
  ck_assert_int_eq(s21_sub(n, d, &q), 0);  // -48-6 = -54
  fail_if(memcmp(&q, &r, DSIZE));
}
END_TEST

START_TEST(test4_sub) {
  s21_decimal n = {{233, 0x1000000000000}};
  s21_decimal d = {{92985, 0x4000000000000}};
  s21_decimal r = {{140015, 0x4000000000000}};
  s21_decimal q;
  ck_assert_int_eq(s21_sub(n, d, &q), 0);  // 23.3-9.2985 = 14.0015
  fail_if(memcmp(&q, &r, DSIZE));
}
END_TEST

START_TEST(test5_sub) {
  s21_decimal n = S21_DECIMAL_PI;
  s21_decimal d = {{2, 0}};
  s21_decimal r = {{0x8eca33c321b65f28, 0x1C000024e30879}};
  s21_decimal q;
  ck_assert_int_eq(s21_sub(n, d, &q), 0);  // pi-2
  fail_if(memcmp(&q, &r, DSIZE));
}
END_TEST

START_TEST(test6_sub) {
  s21_decimal n = {{1, 0x1000000000000}};
  s21_decimal d = {{3, 0}};
  s21_decimal r = {{29, 0x8001000000000000}};
  s21_decimal q;
  ck_assert_int_eq(s21_sub(n, d, &q), 0);  // 0.1-3
  fail_if(memcmp(&q, &r, DSIZE));
}
END_TEST

START_TEST(test7_sub) {
  s21_decimal n = {{25, 0x1000000000000}};
  s21_decimal d = {{25, 0x1000000000000}};
  s21_decimal r = S21_DECIMAL_ZERO;
  s21_decimal q;
  ck_assert_int_eq(s21_sub(n, d, &q), 0);  // 2.5-2.5
  fail_if(memcmp(&q, &r, DSIZE));
}
END_TEST

START_TEST(test8_sub) {
  s21_decimal n = {{233, 0x01000000000000}};
  s21_decimal d = {{92985, 0x8004000000000000}};
  s21_decimal r = {{325985, 0x4000000000000}};
  s21_decimal q;
  ck_assert_int_eq(s21_sub(n, d, &q), 0);  // 23.3--9.2985 = 32.5985
  fail_if(memcmp(&q, &r, DSIZE));
}
END_TEST

START_TEST(test9_sub) {
  s21_decimal n = {{0x50A00E51E3936EB0, 0x8010000000000057}};
  s21_decimal d = {{0x29636EC4111B3, 0x9000000000000}};
  s21_decimal r = {{0x068b9ed8a6c32a30, 0x80100000000001e2}};
  s21_decimal q;
  // -161067.6393676912160432 (+ 10^-16) - 728112.589509043 (+ 10^-9)
  // -889180.2288767342160432 × (10^-16)
  ck_assert_int_eq(s21_sub(n, d, &q), 0);
  fail_if(memcmp(&q, &r, DSIZE));
}
END_TEST

START_TEST(test10_sub) {
  s21_decimal n = S21_DECIMAL_PI;
  s21_decimal d = S21_DECIMAL_E;
  s21_decimal r = {{0x1f275a4fbc3b71cf, 0x1c00000dad8b8a}};
  s21_decimal q;
  // pi-e
  // 4.233108251307480031023559119 (+ 10^-27)
  ck_assert_int_eq(s21_sub(n, d, &q), 0);
  fail_if(memcmp(&q, &r, DSIZE));
}
END_TEST

START_TEST(test11_sub) {
  s21_decimal n = S21_DECIMAL_MIN;
  s21_decimal d = S21_DECIMAL_ONE;
  s21_decimal q;
  ck_assert_int_eq(s21_sub(n, d, &q), 2);  // MIN-1
}
END_TEST

START_TEST(test12_sub) {
  s21_decimal n = S21_DECIMAL_MAX;
  s21_decimal d = S21_DECIMAL_ONE;
  d.bits8[15] = 0x80;
  s21_decimal q;
  ck_assert_int_eq(s21_sub(n, d, &q), 1);  // MAX--1
}
END_TEST

START_TEST(test13_sub) {
  s21_decimal n = S21_DECIMAL_MIN;
  s21_decimal d = {{2, 0x8000000000000000}};
  s21_decimal r = {{0xfffffffffffffffd, 0x80000000ffffffff}};
  s21_decimal q;
  ck_assert_int_eq(s21_sub(n, d, &q), 0);  // MIN--2
  fail_if(memcmp(&q, &r, DSIZE));
}
END_TEST

START_TEST(test14_sub) {
  s21_decimal n = S21_DECIMAL_MAX;
  s21_decimal d = {{1, 0x1000000000000}};
  s21_decimal r = S21_DECIMAL_MAX;
  s21_decimal q;
  ck_assert_int_eq(s21_sub(n, d, &q), 0);  // MAX-0.1
  fail_if(memcmp(&q, &r, DSIZE));
}
END_TEST

START_TEST(test15_sub) {
  s21_decimal n = S21_DECIMAL_MAX;
  s21_decimal d = {{1, 0x801000000000000}};
  s21_decimal r = S21_DECIMAL_MAX;
  s21_decimal q;
  ck_assert_int_eq(s21_sub(n, d, &q), 0);  // MAX--0.1
  fail_if(memcmp(&q, &r, DSIZE));
}
END_TEST

START_TEST(test16_sub) {
  s21_decimal n = {{0x1C1EBCD1D2D77, 0x8000000000000000}};
  ;
  s21_decimal d = {{0x265678CD26C4, 0x8000000000000000}};
  s21_decimal r = {{0x19b95545006b3, 0x8000000000000000}};
  s21_decimal q;
  // -494693479427447--42152835753668
  // -452540643673779
  ck_assert_int_eq(s21_sub(n, d, &q), 0);
  fail_if(memcmp(&q, &r, DSIZE));
}
END_TEST

Suite *s21_test_sub(void) {
  Suite *s = suite_create("\033[45m-=s21_sub=-\033[0m");
  TCase *tc = tcase_create("sub_rc");

  tcase_add_test(tc, test1_sub);
  tcase_add_test(tc, test2_sub);
  tcase_add_test(tc, test3_sub);
  tcase_add_test(tc, test4_sub);
  tcase_add_test(tc, test5_sub);
  tcase_add_test(tc, test6_sub);
  tcase_add_test(tc, test7_sub);
  tcase_add_test(tc, test8_sub);
  tcase_add_test(tc, test9_sub);
  tcase_add_test(tc, test10_sub);
  tcase_add_test(tc, test11_sub);
  tcase_add_test(tc, test12_sub);
  tcase_add_test(tc, test13_sub);
  tcase_add_test(tc, test14_sub);
  tcase_add_test(tc, test15_sub);
  tcase_add_test(tc, test16_sub);

  suite_add_tcase(s, tc);
  return s;
}