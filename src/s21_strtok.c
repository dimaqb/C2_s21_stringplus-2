#include "s21_string.h"

char* s21_strtok(char* str, const char* delim) {
  static char* buffer;
  int is_finished = 0;

  if (str != S21_NULL) {
    buffer = str;
  }

  buffer += s21_strspn(buffer, delim);

  if (*buffer == '\0') {
    is_finished = 1;
  }

  char* tokenBegin = S21_NULL;
  if (!is_finished) {
    tokenBegin = buffer;
    buffer += s21_strcspn(buffer, delim);
    if (*buffer != '\0') {
      *buffer = '\0';
      buffer++;
    }
  }

  return tokenBegin;
}