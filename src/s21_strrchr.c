#include "s21_string.h"

char *s21_strrchr(const char *str, int c) {
  const char *result = S21_NULL;
  int is_finished = 0;
  int lenght = s21_strlen(str);

  for (int i = lenght; i >= 0 && !is_finished; i--) {
    if (str[i] == c) {
      result = (str + i);
      is_finished = 1;
    }
  }
  return (char *)result;
}