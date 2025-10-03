#include "s21_string.h"

s21_size_t s21_strspn(const char *str1, const char *str2) {
  char *runner = (char *)str1;
  s21_size_t result = 0;
  while (*runner && s21_strchr(str2, *runner) != S21_NULL) {
    runner++;
    result++;
  }
  return result;
}
