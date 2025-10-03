#include "s21_string.h"

s21_size_t s21_strnlen(const char *str, s21_size_t n) {
  const char *first_null = s21_memchr(str, '\0', n);
  return first_null ? (s21_size_t)(first_null - str) : n;
}