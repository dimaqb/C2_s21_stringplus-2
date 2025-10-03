#include "test.h"

START_TEST(test_s21_to_upper_1) {
  char *res = s21_to_upper("AbCdEfG");
  ck_assert_pstr_eq(res, "ABCDEFG");
  if (res) free(res);
}
END_TEST

START_TEST(test_s21_to_upper_2) {
  char *res = s21_to_upper("Testing code\n\0");
  ck_assert_pstr_eq(res, "TESTING CODE\n\0");
  if (res) free(res);
}
END_TEST

START_TEST(test_s21_to_upper_3) {
  char *res = s21_to_upper("a\n\0");
  ck_assert_pstr_eq(res, "A\n\0");
  if (res) free(res);
}
END_TEST

START_TEST(test_s21_to_upper_4) {
  char *res = s21_to_upper(" \n\0");
  ck_assert_pstr_eq(res, " \n\0");
  if (res) free(res);
}
END_TEST

START_TEST(test_s21_to_upper_5) {
  char *res = s21_to_upper("\0");
  ck_assert_pstr_eq(res, "\0");
  if (res) free(res);
}
END_TEST

Suite *suite_create_to_upper(void) {
  Suite *suite;
  TCase *tcase_to_upper;

  suite = suite_create("part 5: to_upper");
  tcase_to_upper = tcase_create("to_upper");

  tcase_add_test(tcase_to_upper, test_s21_to_upper_1);
  tcase_add_test(tcase_to_upper, test_s21_to_upper_2);
  tcase_add_test(tcase_to_upper, test_s21_to_upper_3);
  tcase_add_test(tcase_to_upper, test_s21_to_upper_4);
  tcase_add_test(tcase_to_upper, test_s21_to_upper_5);
  suite_add_tcase(suite, tcase_to_upper);

  return suite;
}

int test_to_upper() {
  int no_failed = 0;
  Suite *suite = suite_create_to_upper();
  SRunner *suite_runner = srunner_create(suite);

  srunner_set_fork_status(suite_runner, CK_NOFORK);
  srunner_run_all(suite_runner, CK_NORMAL);
  no_failed = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);

  return no_failed;
}
