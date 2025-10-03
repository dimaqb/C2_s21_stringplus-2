#include "s21_string.h"

char *s21_strcpy(char *dest, const char *src) {
  char *current = dest;
  while (*src != '\0') {
    *current = *src;
    current++;
    src++;
  }
  *current = '\0';
  return dest;
}
