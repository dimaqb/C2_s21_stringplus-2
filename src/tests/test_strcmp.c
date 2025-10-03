#include "test.h"

START_TEST(test_s21_strcmp_1) {
  char *string_1 = "AbC";
  char *string_2 = "AbC";
  int actual = s21_strcmp(string_1, string_2);
  int expected = s21_strcmp(string_1, string_2);

  ck_assert(!((actual * expected == 0) && (actual - expected != 0)));
  ck_assert_int_ge(expected * actual, 0);
}
END_TEST

START_TEST(test_s21_strcmp_2) {
  char *string_1 = "AbC";
  char *string_2 = "Ab";
  int actual = s21_strcmp(string_1, string_2);
  int expected = s21_strcmp(string_1, string_2);

  ck_assert(!((actual * expected == 0) && (actual - expected != 0)));
  ck_assert_int_ge(expected * actual, 0);
}
END_TEST

START_TEST(test_s21_strcmp_3) {
  char *string_1 = "Ab";
  char *string_2 = "AbC";
  int actual = s21_strcmp(string_1, string_2);
  int expected = s21_strcmp(string_1, string_2);

  ck_assert(!((actual * expected == 0) && (actual - expected != 0)));
  ck_assert_int_ge(expected * actual, 0);
}
END_TEST

Suite *suite_create_strcmp(void) {
  Suite *suite;
  TCase *tcase_strcmp;

  suite = suite_create("part 5: strcmp");
  tcase_strcmp = tcase_create("strcmp");

  tcase_add_test(tcase_strcmp, test_s21_strcmp_1);
  tcase_add_test(tcase_strcmp, test_s21_strcmp_2);
  tcase_add_test(tcase_strcmp, test_s21_strcmp_3);
  suite_add_tcase(suite, tcase_strcmp);

  return suite;
}

int test_strcmp() {
  int no_failed = 0;
  Suite *suite = suite_create_strcmp();
  SRunner *suite_runner = srunner_create(suite);

  srunner_set_fork_status(suite_runner, CK_NOFORK);
  srunner_run_all(suite_runner, CK_NORMAL);
  no_failed = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);

  return no_failed;
}
