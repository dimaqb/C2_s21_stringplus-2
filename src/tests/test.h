#ifndef SRC_TEST_H
#define SRC_TEST_H

#include <check.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../s21_string.h"

#define BUFF_SIZE 4096

int test_sprintf();
int test_sscanf();
int test_regular();
int test_csharp();
int test_to_upper();
int test_to_lower();
int test_insert();
int test_trim();
int test_strcmp();
int test_strnlen();

#endif  // SRC_TEST_H
