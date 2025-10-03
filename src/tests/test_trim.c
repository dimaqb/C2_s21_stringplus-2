#include "test.h"

START_TEST(test_s21_trim_1) {
  char *test01 = s21_trim("-=Hello=-", "-");
  ck_assert_pstr_eq(test01, "=Hello=\0");
  if (test01) free(test01);
}
END_TEST

START_TEST(test_s21_trim_2) {
  char *test02 = s21_trim("-Hello\n\0", "-");
  ck_assert_pstr_eq(test02, "Hello\n");
  if (test02) free(test02);
}
END_TEST

START_TEST(test_s21_trim_3) {
  char *test03 = s21_trim("aa", "a");
  ck_assert_pstr_eq(test03, "");
  if (test03) free(test03);
}
END_TEST

START_TEST(test_s21_trim_4) {
  char *test04 = s21_trim(" \n ", "\n");
  ck_assert_pstr_eq(test04, " \n ");
  if (test04) free(test04);
}
END_TEST

START_TEST(test_s21_trim_5) {
  char *res = s21_trim("testc", "c");
  ck_assert_str_eq(res, "test");
  if (res) free(res);
}
END_TEST

START_TEST(test_s21_trim_6) {
  char *res = s21_trim(S21_NULL, "c");
  ck_assert_ptr_eq(res, S21_NULL);
  if (res) free(res);
}
END_TEST

START_TEST(test_s21_trim_7) {
  char *res = s21_trim("  test ", S21_NULL);
  ck_assert_str_eq(res, "test");
  if (res) free(res);
}
END_TEST

START_TEST(test_s21_trim_8) {
  char *res = s21_trim(S21_NULL, S21_NULL);
  ck_assert_ptr_eq(res, S21_NULL);
  if (res) free(res);
}
END_TEST

Suite *suite_create_trim(void) {
  Suite *suite;
  TCase *tcase_trim;

  suite = suite_create("part 5: trim");

  tcase_trim = tcase_create("trim");
  tcase_add_test(tcase_trim, test_s21_trim_1);
  tcase_add_test(tcase_trim, test_s21_trim_2);
  tcase_add_test(tcase_trim, test_s21_trim_3);
  tcase_add_test(tcase_trim, test_s21_trim_4);
  tcase_add_test(tcase_trim, test_s21_trim_5);
  tcase_add_test(tcase_trim, test_s21_trim_6);
  tcase_add_test(tcase_trim, test_s21_trim_7);
  tcase_add_test(tcase_trim, test_s21_trim_8);
  suite_add_tcase(suite, tcase_trim);

  return suite;
}

int test_trim() {
  int no_failed = 0;
  Suite *suite = suite_create_trim();
  SRunner *suite_runner = srunner_create(suite);

  srunner_set_fork_status(suite_runner, CK_NOFORK);
  srunner_run_all(suite_runner, CK_NORMAL);
  no_failed = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);

  return no_failed;
}
