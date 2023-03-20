
#include "test.h"

START_TEST(test1_mul) {
  s21_decimal n = {{48, 0}};
  s21_decimal d = {{6, 0}};
  s21_decimal r = {{288, 0}};
  s21_decimal q;
  ck_assert_int_eq(s21_mul(n, d, &q), 0);  // 48*6 = 288
  fail_if(memcmp(&q, &r, DSIZE));
}
END_TEST

START_TEST(test2_mul) {
  s21_decimal n = {{90, 0}};
  s21_decimal d = {{9, 0}};
  s21_decimal r = {{810, 0}};
  s21_decimal q;
  ck_assert_int_eq(s21_mul(n, d, &q), 0);  // 90*9 = 810
  fail_if(memcmp(&q, &r, DSIZE));
}
END_TEST

START_TEST(test3_mul) {
  s21_decimal n = {{1024, 0}};
  s21_decimal d = {{4, 0}};
  s21_decimal r = {{4096, 0}};
  s21_decimal q;
  ck_assert_int_eq(s21_mul(n, d, &q), 0);  // 1024*4 = 4096
  fail_if(memcmp(&q, &r, DSIZE));
}
END_TEST

START_TEST(test4_mul) {
  s21_decimal n = {{233, 0x1000000000000}};
  s21_decimal d = {{92985, 0x4000000000000}};
  s21_decimal r = {{21665505, 0x5000000000000}};
  s21_decimal q;
  ck_assert_int_eq(s21_mul(n, d, &q), 0);  // 23.3*9.2985 = 216.65505
  fail_if(memcmp(&q, &r, DSIZE));
}
END_TEST

START_TEST(test5_mul) {
  s21_decimal n = S21_DECIMAL_PI;
  s21_decimal d = {{2, 0}};
  s21_decimal r = {{0x1628710A836CBE50, 0x1C0000CB054A6C}};
  s21_decimal q;
  ck_assert_int_eq(s21_mul(n, d, &q), 0);  // pi*2
  fail_if(memcmp(&q, &r, DSIZE));
}
END_TEST

START_TEST(test6_mul) {
  s21_decimal n = {{1, 0x1000000000000}};
  s21_decimal d = {{3, 0}};
  s21_decimal r = {{3, 0x1000000000000}};
  s21_decimal q;
  ck_assert_int_eq(s21_mul(n, d, &q), 0);  // 0.1*3
  fail_if(memcmp(&q, &r, DSIZE));
}
END_TEST

START_TEST(test7_mul) {
  s21_decimal n = {{1, 0x1000000000000}};
  s21_decimal d = {{7, 0x2000000000000}};
  s21_decimal r = {{7, 0x3000000000000}};
  s21_decimal q;
  ck_assert_int_eq(s21_mul(n, d, &q), 0);  // 0.180.07
  fail_if(memcmp(&q, &r, DSIZE));
}
END_TEST

START_TEST(test8_mul) {
  s21_decimal n = {{233, 0x8001000000000000}};
  s21_decimal d = {{92985, 0x4000000000000}};
  s21_decimal r = {{21665505, 0x8005000000000000}};
  s21_decimal q;
  ck_assert_int_eq(s21_mul(n, d, &q), 0);  // -23.3*9.2985 = -216.65505
  fail_if(memcmp(&q, &r, DSIZE));
}
END_TEST

START_TEST(test9_mul) {
  s21_decimal n = {{0x50A00E51E3936EB0, 0x8010000000000057}};
  s21_decimal d = {{0x29636EC4111B3, 0x9000000000000}};
  s21_decimal r = {{0x1DB36FEA14760271, 0x8011000025e4caaf}};

  // -161067.6393676912160432 (* 10^-16) * 728112.589509043 (* 10^-9)
  // 117275375986.11832861242032753 × (10^-17)
  s21_decimal q;
  ck_assert_int_eq(s21_mul(n, d, &q), 0);
  fail_if(memcmp(&q, &r, DSIZE));
}
END_TEST

START_TEST(test10_mul) {
  s21_decimal n = S21_DECIMAL_PI;
  s21_decimal d = S21_DECIMAL_E;
  s21_decimal r = {{0xD565250617D37395, 0x1B00001B97E70F}};
  s21_decimal q;
  // pi*e
  // 8.539734222673567065463550869 (* 10^-27)
  ck_assert_int_eq(s21_mul(n, d, &q), 0);
  fail_if(memcmp(&q, &r, DSIZE));
}
END_TEST

START_TEST(test11_mul) {
  s21_decimal n = S21_DECIMAL_MAX;
  s21_decimal d = S21_DECIMAL_ONE;
  s21_decimal r = S21_DECIMAL_MAX;
  s21_decimal q;
  ck_assert_int_eq(s21_mul(n, d, &q), 0);  // MAX*1
  fail_if(memcmp(&q, &r, DSIZE));
}
END_TEST

START_TEST(test12_mul) {
  s21_decimal n = S21_DECIMAL_PI;
  s21_decimal d = S21_DECIMAL_ONE;
  s21_decimal r = S21_DECIMAL_PI;
  s21_decimal q;
  ck_assert_int_eq(s21_mul(n, d, &q), 0);  // pi*1
  fail_if(memcmp(&q, &r, DSIZE));
}
END_TEST

START_TEST(test13_mul) {
  s21_decimal n = S21_DECIMAL_MAX;
  s21_decimal d = {{2, 0}};
  s21_decimal q;
  ck_assert_int_eq(s21_mul(n, d, &q), 1);  // MAX*2
}
END_TEST

START_TEST(test14_mul) {
  s21_decimal n = S21_DECIMAL_MIN;
  s21_decimal d = {{2, 0}};
  s21_decimal q;
  ck_assert_int_eq(s21_mul(n, d, &q), 2);  // MIN*2
}
END_TEST

START_TEST(test15_mul) {
  s21_decimal n = S21_DECIMAL_MAX;
  s21_decimal d = {{2, 0x8000000000000000}};
  s21_decimal q;
  ck_assert_int_eq(s21_mul(n, d, &q), 2);  // MAX*-2
}
END_TEST

START_TEST(test16_mul) {
  s21_decimal n = S21_DECIMAL_MIN;
  s21_decimal d = {{2, 0x8000000000000000}};
  s21_decimal q;
  ck_assert_int_eq(s21_mul(n, d, &q), 1);  // MIN*-2
}
END_TEST

START_TEST(test17_mul) {
  s21_decimal n = S21_DECIMAL_MAX;
  s21_decimal d = {{1, 0x1000000000000}};
  s21_decimal r = {{-1, 0x10000FFFFFFFF}};
  s21_decimal q;
  ck_assert_int_eq(s21_mul(n, d, &q), 0);  // MAX*0.1
  fail_if(memcmp(&q, &r, DSIZE));
}
END_TEST

START_TEST(test18_mul) {
  s21_decimal n = S21_DECIMAL_MAX;
  s21_decimal d = {{1, 0x801000000000000}};
  s21_decimal r = {{-1, 0x8010000FFFFFFFF}};
  s21_decimal q;
  ck_assert_int_eq(s21_mul(n, d, &q), 0);  // MAX*-0.1
  fail_if(memcmp(&q, &r, DSIZE));
}
END_TEST

START_TEST(test19_mul) {
  s21_decimal n = {{0x1C1EBCD1D2D77, 0x800000000000000}};
  ;
  s21_decimal d = {{0x265678CD26C4, 0x800000000000000}};
  s21_decimal r = {{0x52A756A28F61791C, 0x4360F9F8}};
  // -494693479427447*-42152835753668
  // 20852732986715713115370125596
  s21_decimal q;
  ck_assert_int_eq(s21_mul(n, d, &q), 0);
  fail_if(memcmp(&q, &r, DSIZE));
}
END_TEST

START_TEST(test20_mul) {
  s21_decimal n = {{0, 0x80000000}};
  s21_decimal d = {{2, 0}};
  s21_decimal q;
  // 39614081257132168796771975168*2
  ck_assert_int_eq(s21_mul(n, d, &q), 1);
}
END_TEST

Suite *s21_test_mul(void) {
  Suite *s = suite_create("\033[45m-=s21_mul=-\033[0m");
  TCase *tc = tcase_create("mul_rc");

  tcase_add_test(tc, test1_mul);
  tcase_add_test(tc, test2_mul);
  tcase_add_test(tc, test3_mul);
  tcase_add_test(tc, test4_mul);
  tcase_add_test(tc, test5_mul);
  tcase_add_test(tc, test6_mul);
  tcase_add_test(tc, test7_mul);
  tcase_add_test(tc, test8_mul);
  tcase_add_test(tc, test9_mul);
  tcase_add_test(tc, test10_mul);
  tcase_add_test(tc, test11_mul);
  tcase_add_test(tc, test12_mul);
  tcase_add_test(tc, test13_mul);
  tcase_add_test(tc, test14_mul);
  tcase_add_test(tc, test15_mul);
  tcase_add_test(tc, test16_mul);
  tcase_add_test(tc, test17_mul);
  tcase_add_test(tc, test18_mul);
  tcase_add_test(tc, test19_mul);
  tcase_add_test(tc, test20_mul);

  suite_add_tcase(s, tc);
  return s;
}