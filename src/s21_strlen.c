#include "s21_string.h"

s21_size_t s21_strlen(const char *str) {
  s21_size_t result = 0;
  const char *pointer = str;
  while (*pointer != '\0') {
    pointer++;
  }
  result = (s21_size_t)(pointer - str);
  return result;
}
