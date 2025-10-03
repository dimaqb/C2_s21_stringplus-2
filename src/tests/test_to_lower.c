#include "test.h"

START_TEST(test_s21_to_lower_1) {
  char *res = s21_to_lower("AbCdEfG");
  ck_assert_pstr_eq(res, "abcdefg");
  if (res) free(res);
}
END_TEST

START_TEST(test_s21_to_lower_2) {
  char *res = s21_to_lower("Testing code\n\0");
  ck_assert_pstr_eq(res, "testing code\n\0");
  if (res) free(res);
}
END_TEST

START_TEST(test_s21_to_lower_3) {
  char *res = s21_to_lower("a\n\0");
  ck_assert_pstr_eq(res, "a\n\0");
  if (res) free(res);
}
END_TEST

START_TEST(test_s21_to_lower_4) {
  char *res = s21_to_lower(" \n\0");
  ck_assert_pstr_eq(res, " \n\0");
  if (res) free(res);
}
END_TEST

START_TEST(test_s21_to_lower_5) {
  char *res = s21_to_lower("\0");
  ck_assert_pstr_eq(res, "\0");
  if (res) free(res);
}
END_TEST

Suite *suite_create_to_lower(void) {
  Suite *suite;
  TCase *tcase_to_lower;

  suite = suite_create("part 5: to lower");
  tcase_to_lower = tcase_create("to_lower");

  tcase_add_test(tcase_to_lower, test_s21_to_lower_1);
  tcase_add_test(tcase_to_lower, test_s21_to_lower_2);
  tcase_add_test(tcase_to_lower, test_s21_to_lower_3);
  tcase_add_test(tcase_to_lower, test_s21_to_lower_4);
  tcase_add_test(tcase_to_lower, test_s21_to_lower_5);
  suite_add_tcase(suite, tcase_to_lower);

  return suite;
}

int test_to_lower() {
  int no_failed = 0;
  Suite *suite = suite_create_to_lower();
  SRunner *suite_runner = srunner_create(suite);

  srunner_set_fork_status(suite_runner, CK_NOFORK);
  srunner_run_all(suite_runner, CK_NORMAL);
  no_failed = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);

  return no_failed;
}
