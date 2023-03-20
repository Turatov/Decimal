#include "../s21_dbinary.h"
#include "test.h"

START_TEST(test1_add) {
  s21_decimal n = {{48, 0}};
  s21_decimal d = {{6, 0}};
  s21_decimal r = {{54, 0}};
  s21_decimal q;
  ck_assert_int_eq(s21_add(n, d, &q), 0);  // 48+6 = 54
  fail_if(memcmp(&q, &r, DSIZE));
}
END_TEST

START_TEST(test2_add) {
  s21_decimal n = {{6, 0}};
  s21_decimal d = {{48, 0}};
  s21_decimal r = {{54, 0}};
  s21_decimal q;
  ck_assert_int_eq(s21_add(n, d, &q), 0);  // 6+48 = 54
  fail_if(memcmp(&q, &r, DSIZE));
}
END_TEST

START_TEST(test3_add) {
  s21_decimal n = {{48, 0}};
  s21_decimal d = {{6, 0}};
  n.bits8[15] = 0x80;
  s21_decimal r = {{42, 0}};
  r.bits8[15] = 0x80;
  s21_decimal q;
  ck_assert_int_eq(s21_add(n, d, &q), 0);  // -48+6 = 42
  fail_if(memcmp(&q, &r, DSIZE));
}
END_TEST

START_TEST(test4_add) {
  s21_decimal n = {{233, 0x1000000000000}};
  s21_decimal d = {{92985, 0x4000000000000}};
  s21_decimal r = {{325985, 0x4000000000000}};
  s21_decimal q;
  ck_assert_int_eq(s21_add(n, d, &q), 0);  // 23.3+9.2985 = 32.5985
  fail_if(memcmp(&q, &r, DSIZE));
}
END_TEST

START_TEST(test5_add) {
  s21_decimal n = S21_DECIMAL_PI;
  s21_decimal d = {{2, 0}};
  s21_decimal r = {{0x875e3d4761b65f28, 0x1C0000a62241f2}};
  s21_decimal q;
  ck_assert_int_eq(s21_add(n, d, &q), 0);  // pi+2
  fail_if(memcmp(&q, &r, DSIZE));
}
END_TEST

START_TEST(test6_add) {
  s21_decimal n = {{1, 0x1000000000000}};
  s21_decimal d = {{3, 0}};
  s21_decimal r = {{31, 0x1000000000000}};
  s21_decimal q;
  ck_assert_int_eq(s21_add(n, d, &q), 0);  // 0.1+3
  fail_if(memcmp(&q, &r, DSIZE));
}
END_TEST

START_TEST(test7_add) {
  s21_decimal n = {{25, 0x1000000000000}};
  s21_decimal d = {{25, 0x1000000000000}};
  s21_decimal r = {{5, 0}};
  s21_decimal q;
  ck_assert_int_eq(s21_add(n, d, &q), 0);  // 2.5+2.5
  fail_if(memcmp(&q, &r, DSIZE));
}
END_TEST

START_TEST(test8_add) {
  s21_decimal n = {{233, 0x01000000000000}};
  s21_decimal d = {{92985, 0x8004000000000000}};
  s21_decimal r = {{140015, 0x4000000000000}};
  s21_decimal q;
  ck_assert_int_eq(s21_add(n, d, &q), 0);  // 23.3+-9.2985 = 14.0015
  fail_if(memcmp(&q, &r, DSIZE));
}
END_TEST

START_TEST(test9_add) {
  s21_decimal n = {{0x50A00E51E3936EB0, 0x8010000000000057}};
  s21_decimal d = {{0x29636EC4111B3, 0x9000000000000}};
  s21_decimal r = {{0x654b8234df9c4cd0, 0x10000000000133}};
  s21_decimal q;
  // -161067.6393676912160432 (+ 10^-16) + 728112.589509043 (+ 10^-9)
  // 567044.9501413517839568 × (10^-16)
  ck_assert_int_eq(s21_add(n, d, &q), 0);
  fail_if(memcmp(&q, &r, DSIZE));
}
END_TEST

START_TEST(test10_add) {
  s21_decimal n = S21_DECIMAL_PI;
  s21_decimal d = S21_DECIMAL_E;
  s21_decimal r = {{0xf70116bac7314c81, 0x1c0000bd57bee1}};
  s21_decimal q;
  // pi+e
  // 5.8598744820488384738229308545 (+ 10^-28)
  ck_assert_int_eq(s21_add(n, d, &q), 0);
  fail_if(memcmp(&q, &r, DSIZE));
}
END_TEST

START_TEST(test11_add) {
  s21_decimal n = S21_DECIMAL_MAX;
  s21_decimal d = S21_DECIMAL_ONE;
  s21_decimal q;
  ck_assert_int_eq(s21_add(n, d, &q), 1);  // MAX+1
}
END_TEST

START_TEST(test12_add) {
  s21_decimal n = S21_DECIMAL_MIN;
  s21_decimal d = S21_DECIMAL_ONE;
  d.bits8[15] = 0x80;
  s21_decimal q;
  ck_assert_int_eq(s21_add(n, d, &q), 2);  // MIN+-1
}
END_TEST

START_TEST(test13_add) {
  s21_decimal n = S21_DECIMAL_MIN;
  s21_decimal d = {{2, 0}};
  s21_decimal r = {{0xfffffffffffffffd, 0x80000000ffffffff}};
  s21_decimal q;
  s21_add(n, d, &q);
  ck_assert_int_eq(s21_add(n, d, &q), 0);  // MIN+2
  fail_if(memcmp(&q, &r, DSIZE));
}
END_TEST

START_TEST(test14_add) {
  s21_decimal n = S21_DECIMAL_MIN;
  s21_decimal d = {{2, 0x8000000000000000}};
  s21_decimal q;
  ck_assert_int_eq(s21_add(n, d, &q), 2);  // MIN+-2
}
END_TEST

START_TEST(test15_add) {
  s21_decimal n = S21_DECIMAL_MAX;
  s21_decimal d = {{1, 0x1000000000000}};
  s21_decimal r = S21_DECIMAL_MAX;
  s21_decimal q;
  ck_assert_int_eq(s21_add(n, d, &q), 0);  // MAX+0.1
  fail_if(memcmp(&q, &r, DSIZE));
}
END_TEST

START_TEST(test16_add) {
  s21_decimal n = S21_DECIMAL_MAX;
  s21_decimal d = {{1, 0x801000000000000}};
  s21_decimal r = S21_DECIMAL_MAX;
  s21_decimal q;
  ck_assert_int_eq(s21_add(n, d, &q), 0);  // MAX+-0.1
  fail_if(memcmp(&q, &r, DSIZE));
}
END_TEST

START_TEST(test17_add) {
  s21_decimal n = {{0x1C1EBCD1D2D77, 0}};
  ;
  s21_decimal d = {{0x265678CD26C4, 0}};
  s21_decimal r = {{0x1e84245ea543b, 0}};
  n.bits8[15] = 0x80;
  d.bits8[15] = 0x80;
  r.bits8[15] = 0x80;
  s21_decimal q;
  // -494693479427447+-42152835753668
  // -536846315181115
  ck_assert_int_eq(s21_add(n, d, &q), 0);
  fail_if(memcmp(&q, &r, DSIZE));
}
END_TEST

Suite *s21_test_add(void) {
  Suite *s = suite_create("\033[45m-=s21_add=-\033[0m");
  TCase *tc = tcase_create("add_rc");

  tcase_add_test(tc, test1_add);
  tcase_add_test(tc, test2_add);
  tcase_add_test(tc, test3_add);
  tcase_add_test(tc, test4_add);
  tcase_add_test(tc, test5_add);
  tcase_add_test(tc, test6_add);
  tcase_add_test(tc, test7_add);
  tcase_add_test(tc, test8_add);
  tcase_add_test(tc, test9_add);
  tcase_add_test(tc, test10_add);
  tcase_add_test(tc, test11_add);
  tcase_add_test(tc, test12_add);
  tcase_add_test(tc, test13_add);
  tcase_add_test(tc, test14_add);
  tcase_add_test(tc, test15_add);
  tcase_add_test(tc, test16_add);
  tcase_add_test(tc, test17_add);

  suite_add_tcase(s, tc);
  return s;
}