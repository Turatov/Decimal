#include "test.h"

START_TEST(test1_div) {
  s21_decimal n = {{48, 0}};
  s21_decimal d = {{6, 0}};
  s21_decimal r = {{8, 0}};
  s21_decimal q;
  ck_assert_int_eq(s21_div(n, d, &q), 0);  // 48/6 = 8
  fail_if(memcmp(&q, &r, DSIZE));
}
END_TEST

START_TEST(test2_div) {
  s21_decimal n = {{90, 0}};
  s21_decimal d = {{9, 0}};
  s21_decimal r = {{10, 0}};
  s21_decimal q;
  ck_assert_int_eq(s21_div(n, d, &q), 0);  // 90/9 = 10
  fail_if(memcmp(&q, &r, DSIZE));
}
END_TEST

START_TEST(test3_div) {
  s21_decimal n = {{1024, 0}};
  s21_decimal d = {{4, 0}};
  s21_decimal r = {{256, 0}};
  s21_decimal q;
  ck_assert_int_eq(s21_div(n, d, &q), 0);  // 1024/4 = 256
  fail_if(memcmp(&q, &r, DSIZE));
}
END_TEST

START_TEST(test4_div) {
  s21_decimal n = {{233, 0x1000000000000}};
  s21_decimal d = {{92985, 0x4000000000000}};
  s21_decimal r = {{0x2547e8e3782ad6b7, 0x1c000050f7549c}};
  s21_decimal q;
  // 23.3/9.2985
  // 2.5057805022315427219443996343 * (10^-28)
  ck_assert_int_eq(s21_div(n, d, &q), 0);
  fail_if(memcmp(&q, &r, DSIZE));
}
END_TEST

START_TEST(test5_div) {
  s21_decimal n = S21_DECIMAL_PI;
  s21_decimal d = {{2, 0}};
  s21_decimal r = {{0x058a1c42a0db2f94, 0x1C000032c1529b}};
  s21_decimal q;
  // pi/2
  // 1.5707963267948966192313216916 (* 10^-28)
  ck_assert_int_eq(s21_div(n, d, &q), 0);
  fail_if(memcmp(&q, &r, DSIZE));
}
END_TEST

START_TEST(test6_div) {
  s21_decimal n = {{1, 0x1000000000000}};
  s21_decimal d = {{3, 0}};
  s21_decimal r = {{0x354580144d555555, 0x1c00000113ba14}};
  s21_decimal q;
  // 0.1/3
  // 0.0333333333333333333333333333 (* 10^-28)
  ck_assert_int_eq(s21_div(n, d, &q), 0);
  fail_if(memcmp(&q, &r, DSIZE));
}
END_TEST

START_TEST(test7_div) {
  s21_decimal n = {{1, 0x1000000000000}};
  s21_decimal d = {{7, 0x2000000000000}};
  s21_decimal r = {{0x3434ded3cdb6db6e, 0x1c00002e28ddab}};
  s21_decimal q;
  // 0.1/0.07
  // 1.4285714285714285714285714286 (* 10^-28)
  ck_assert_int_eq(s21_div(n, d, &q), 0);
  fail_if(memcmp(&q, &r, DSIZE));
}
END_TEST

START_TEST(test8_div) {
  s21_decimal n = {{233, 0x8001000000000000}};
  s21_decimal d = {{92985, 0x4000000000000}};
  s21_decimal r = {{0x2547e8e3782ad6b7, 0x801c000050f7549c}};
  s21_decimal q;
  // -23.3/9.2985
  // -2.5057805022315427219443996343 * (10^-28)
  ck_assert_int_eq(s21_div(n, d, &q), 0);
  fail_if(memcmp(&q, &r, DSIZE));
}
END_TEST

START_TEST(test9_div) {
  s21_decimal n = {{0x50A00E51E3936EB0, 0x8010000000000057}};
  s21_decimal d = {{0x29636EC4111B3, 0x9000000000000}};
  s21_decimal r = {{0x3ad0e045f01c3b27, 0x801c00000725d3c9}};
  s21_decimal q;
  // -161067.6393676912160432 (* 10^-16) / 728112.589509043 (* 10^-9)
  // -0.2212125455436734911638944551 * (10^-28)
  ck_assert_int_eq(s21_div(n, d, &q), 0);
  fail_if(memcmp(&q, &r, DSIZE));
}
END_TEST

START_TEST(test10_div) {
  s21_decimal n = S21_DECIMAL_PI;
  s21_decimal d = S21_DECIMAL_E;
  s21_decimal r = {{0xb8dc96a4aec266f9, 0x1c00002557f3db}};
  s21_decimal q;
  // pi/e
  // 1.1557273497909217179100931833 (* 10^-28)
  ck_assert_int_eq(s21_div(n, d, &q), 0);
  fail_if(memcmp(&q, &r, DSIZE));
}
END_TEST

START_TEST(test11_div) {
  s21_decimal n = S21_DECIMAL_MAX;
  s21_decimal d = S21_DECIMAL_ONE;
  s21_decimal r = S21_DECIMAL_MAX;
  s21_decimal q;
  ck_assert_int_eq(s21_div(n, d, &q), 0);  // MAX/1
  fail_if(memcmp(&q, &r, DSIZE));
}
END_TEST

START_TEST(test12_div) {
  s21_decimal n = S21_DECIMAL_ONE;
  s21_decimal d = S21_DECIMAL_PI;
  s21_decimal r = {{0x0fe1d645e0942c04, 0x1c00000a48ff67}};
  s21_decimal q;
  // 1/pi
  // 0.3183098861837906715377675268 (* 10^-28)
  ck_assert_int_eq(s21_div(n, d, &q), 0);
  fail_if(memcmp(&q, &r, DSIZE));
}
END_TEST

START_TEST(test13_div) {
  s21_decimal n = S21_DECIMAL_ONE;
  s21_decimal d = S21_DECIMAL_MAX;
  s21_decimal r = S21_DECIMAL_ZERO;
  s21_decimal q;
  ck_assert_int_eq(s21_div(n, d, &q), 0);  // 1/max
  fail_if(memcmp(&q, &r, DSIZE));
}
END_TEST

START_TEST(test14_div) {
  s21_decimal n = S21_DECIMAL_ONE;
  s21_decimal d = {{8, 0x1000000000000}};
  s21_decimal r = {{125, 0x2000000000000}};
  s21_decimal q;
  ck_assert_int_eq(s21_div(n, d, &q), 0);  // 1/0.8 = 1.25
  fail_if(memcmp(&q, &r, DSIZE));
}
END_TEST

START_TEST(test15_div) {
  s21_decimal n = S21_DECIMAL_MAX;
  s21_decimal d = {{2, 0}};
  s21_decimal r = {{0, 0x80000000}};
  s21_decimal q;
  // MAX/2
  // 39614081257132168796771975168 (* 10^-28)
  ck_assert_int_eq(s21_div(n, d, &q), 0);
  fail_if(memcmp(&q, &r, DSIZE));
}
END_TEST

START_TEST(test16_div) {
  s21_decimal n = S21_DECIMAL_MAX;
  s21_decimal d = {{1, 0x1000000000000}};
  s21_decimal q;
  ck_assert_int_eq(s21_div(n, d, &q), 1);  // MAX/0.1
}
END_TEST

START_TEST(test17_div) {
  s21_decimal n = S21_DECIMAL_MAX;
  s21_decimal d = {{1, 0x801000000000000}};
  s21_decimal q;
  ck_assert_int_eq(s21_div(n, d, &q), 2);  // MAX*-0.1
}
END_TEST

START_TEST(test18_div) {
  s21_decimal n = {{494693479427447, 0x800000000000000}};
  ;
  s21_decimal d = {{42152835753668, 0x800000000000000}};
  s21_decimal r = {{0xe7bd1e5d61dc9b7c, 0x1b000025eb8d5f}};
  s21_decimal q;
  // -494693479427447/-42152835753668
  // 11.735710553812513401037691772 (* 10^-27)
  ck_assert_int_eq(s21_div(n, d, &q), 0);
  fail_if(memcmp(&q, &r, DSIZE));
}
END_TEST

START_TEST(test19_div) {
  s21_decimal n = {{0x50A00E51E3936EB0, 0x8007000000000057}};
  s21_decimal d = {{0x1d955d2f916, 0x1b000000000000}};
  s21_decimal q;
  // -161067639367691.2160432 (* 10^-7) * 0.000000000000002032959420694 (*
  // 10^-27) -79228162514285145572795599123
  ck_assert_int_eq(s21_div(n, d, &q), 2);
}
END_TEST

START_TEST(test20_div) {
  s21_decimal n = {{0x50A00E51E3936EB0, 0x07000000000057}};
  s21_decimal d = {{0x1d9cd088d16, 0x1b000000000000}};
  s21_decimal r = {{0xbf8bf6e8c2a6e02b, 0xffbf9701}};
  s21_decimal q;
  // 161067639367691.2160432 (* 10^-7) * 0.000000000000002034959420694 (*
  // 10^-27) 79150295445577441049890447403
  ck_assert_int_eq(s21_div(n, d, &q), 0);
  fail_if(memcmp(&q, &r, DSIZE));
}
END_TEST

Suite *s21_test_div(void) {
  Suite *s = suite_create("\033[45m-=s21_div=-\033[0m");
  TCase *tc = tcase_create("div_rc");

  tcase_add_test(tc, test1_div);
  tcase_add_test(tc, test2_div);
  tcase_add_test(tc, test3_div);
  tcase_add_test(tc, test4_div);
  tcase_add_test(tc, test5_div);
  tcase_add_test(tc, test6_div);
  tcase_add_test(tc, test7_div);
  tcase_add_test(tc, test8_div);
  tcase_add_test(tc, test9_div);
  tcase_add_test(tc, test10_div);
  tcase_add_test(tc, test11_div);
  tcase_add_test(tc, test12_div);
  tcase_add_test(tc, test13_div);
  tcase_add_test(tc, test14_div);
  tcase_add_test(tc, test15_div);
  tcase_add_test(tc, test16_div);
  tcase_add_test(tc, test17_div);
  tcase_add_test(tc, test18_div);
  tcase_add_test(tc, test19_div);
  tcase_add_test(tc, test20_div);

  suite_add_tcase(s, tc);
  return s;
}