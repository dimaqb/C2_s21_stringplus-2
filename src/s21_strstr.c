#include "s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  int error = 0;
  char *result = S21_NULL;

  if (haystack == S21_NULL || needle == S21_NULL) {
    error = 1;
  }
  if (!error) {
    s21_size_t len_haystack = s21_strlen(haystack);
    s21_size_t len_needle = s21_strlen(needle);

    if (len_needle == 0) {
      result = (char *)haystack;
    } else {
      for (s21_size_t i = 0; i + len_needle < len_haystack + 1; ++i) {
        if (s21_strncmp(haystack, needle, len_needle) == 0) {
          result = (char *)haystack;
          break;
        }
        haystack++;
      }
    }
  }
  return result;
}