#include "test.h"

START_TEST(test_s21_insert_1) {
  char *test01 = s21_insert("Hello", "Man", 2);
  ck_assert_pstr_eq(test01, "HeManllo");
  if (test01) free(test01);
}
END_TEST

START_TEST(test_s21_insert_2) {
  char *test02 = s21_insert("Hello\n\0", "Man\n\0", 1);
  ck_assert_pstr_eq(test02, "HMan\nello\n\0");
  if (test02) free(test02);
}
END_TEST

START_TEST(test_s21_insert_3) {
  char *test03 = s21_insert("a\0", "man\0", 1);
  ck_assert_pstr_eq(test03, "aman");
  if (test03) free(test03);
}
END_TEST

START_TEST(test_s21_insert_4) {
  char *test04 = s21_insert(" s\0", " s\0", 1);
  ck_assert_pstr_eq(test04, "  ss");
  if (test04) free(test04);
}
END_TEST

START_TEST(test_s21_insert_5) {
  char *test05 = s21_insert("\n\0", "\n\0", 1);
  ck_assert_pstr_eq(test05, "\n\n");
  if (test05) free(test05);
}
END_TEST

Suite *suite_create_insert(void) {
  Suite *suite;
  TCase *tcase_insert;

  suite = suite_create("part 5: insert");
  tcase_insert = tcase_create("insert");

  tcase_add_test(tcase_insert, test_s21_insert_1);
  tcase_add_test(tcase_insert, test_s21_insert_2);
  tcase_add_test(tcase_insert, test_s21_insert_3);
  tcase_add_test(tcase_insert, test_s21_insert_4);
  tcase_add_test(tcase_insert, test_s21_insert_5);
  suite_add_tcase(suite, tcase_insert);

  return suite;
}

int test_insert() {
  int no_failed = 0;
  Suite *suite = suite_create_insert();
  SRunner *suite_runner = srunner_create(suite);

  srunner_set_fork_status(suite_runner, CK_NOFORK);
  srunner_run_all(suite_runner, CK_NORMAL);
  no_failed = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);

  return no_failed;
}
