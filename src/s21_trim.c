#include "s21_string.h"

void *s21_trim(const char *src, const char *trim_chars) {
  int error = 0;
  char *result = S21_NULL;
  s21_size_t len_trim_chars;

  if (trim_chars == S21_NULL) {
    len_trim_chars = 0;
  } else {
    len_trim_chars = s21_strlen(trim_chars);
  }

  char *buffer_trim_chars = malloc((len_trim_chars + 7) * sizeof(char));
  if (buffer_trim_chars == S21_NULL) {
    error = 1;
  }

  if (!error) {
    if (len_trim_chars == 0) {
      s21_memcpy(buffer_trim_chars, " \t\n\r\f\v", 7);
      buffer_trim_chars[6] = '\0';
    } else {
      s21_memcpy(buffer_trim_chars, trim_chars, len_trim_chars);
      buffer_trim_chars[len_trim_chars] = '\0';
    }
  }

  if (src != S21_NULL && !error) {
    s21_size_t len_src = s21_strlen(src);
    result = malloc((len_src + 1) * sizeof(char));

    if (result == S21_NULL) {
      error = 1;
    }
    if (!error) {
      if (len_src == 0) {
        result[0] = '\0';
      }
      if (len_src > 0) {
        s21_size_t start = 0;
        s21_size_t end = len_src - 1;

        while (start < len_src &&
               s21_strchr(buffer_trim_chars, src[start]) != S21_NULL) {
          start++;
        }

        while (end > start &&
               s21_strchr(buffer_trim_chars, src[end]) != S21_NULL) {
          end--;
        }

        if (start <= end) {
          s21_memcpy(result, src + start, end - start + 1);
          result[end - start + 1] = '\0';
        } else {
          result[0] = '\0';
        }
      }
    }
  }

  if (buffer_trim_chars) {
    free(buffer_trim_chars);
  }

  if (error) {
    if (result) {
      free(result);
    }
    result = S21_NULL;
  }

  return result;
}