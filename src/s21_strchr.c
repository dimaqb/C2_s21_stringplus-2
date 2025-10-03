#include "s21_string.h"

char *s21_strchr(const char *dest, int target) {
  char *result = S21_NULL;
  while (*dest != target && *dest != '\0') {
    dest++;
  }
  if (*dest == target) {
    result = (char *)dest;
  }
  return result;
}
