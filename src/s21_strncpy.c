#include "s21_string.h"

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  s21_size_t runner = 0;
  for (; runner < n && src[runner] != '\0'; ++runner) {
    dest[runner] = src[runner];
  }
  for (; runner < n; ++runner) {
    dest[runner] = '\0';
  }
  return dest;
}