#include "s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  const unsigned char *str1_p = str1, *str2_p = str2;
  int result = 0;
  for (s21_size_t i = 0; i < n; i++) {
    if (*str1_p != *str2_p) {
      result = *str1_p - *str2_p;
      break;
    }
    str1_p++;
    str2_p++;
  }
  return result;
}
