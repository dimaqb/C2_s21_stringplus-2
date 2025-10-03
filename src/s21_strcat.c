#include "s21_string.h"

char *s21_strcat(char *dest, const char *src) {
  s21_size_t len = s21_strlen(dest);
  for (s21_size_t i = 0; src[i] != '\0'; i++) {
    dest[len + i] = src[i];
  }
  dest[len + s21_strlen(src)] = '\0';
  return dest;
}
