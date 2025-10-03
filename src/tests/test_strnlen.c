#include "test.h"

START_TEST(test_s21_strnlen_1) {
  char *string_1 = "AbC";
  int n = 2;
  int actual = s21_strnlen(string_1, n);
  int expected = s21_strnlen(string_1, n);

  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(test_s21_strnlen_2) {
  char *string_1 = "AbC";
  int n = 5;
  int actual = s21_strnlen(string_1, n);
  int expected = s21_strnlen(string_1, n);

  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(test_s21_strnlen_3) {
  char *string_1 = "AbC";
  int n = 0;
  int actual = s21_strnlen(string_1, n);
  int expected = s21_strnlen(string_1, n);

  ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(test_s21_strnlen_4) {
  char *string_1 = "Ab\0C";
  int n = 3;
  int actual = s21_strnlen(string_1, n);
  int expected = s21_strnlen(string_1, n);

  ck_assert_int_eq(actual, expected);
}
END_TEST

Suite *suite_create_strnlen(void) {
  Suite *suite;
  TCase *tcase_strnlen;

  suite = suite_create("part 5: strnlen");
  tcase_strnlen = tcase_create("strnlen");

  tcase_add_test(tcase_strnlen, test_s21_strnlen_1);
  tcase_add_test(tcase_strnlen, test_s21_strnlen_2);
  tcase_add_test(tcase_strnlen, test_s21_strnlen_3);
  tcase_add_test(tcase_strnlen, test_s21_strnlen_4);
  suite_add_tcase(suite, tcase_strnlen);

  return suite;
}

int test_strnlen() {
  int no_failed = 0;
  Suite *suite = suite_create_strnlen();
  SRunner *suite_runner = srunner_create(suite);

  srunner_set_fork_status(suite_runner, CK_NOFORK);
  srunner_run_all(suite_runner, CK_NORMAL);
  no_failed = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);

  return no_failed;
}
