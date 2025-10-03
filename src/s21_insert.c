#include "s21_string.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  int error = 0;
  char *result = S21_NULL;

  if (str == S21_NULL || src == S21_NULL) {
    error = 1;
  }
  if (!error) {
    s21_size_t len_src = s21_strlen(src);
    s21_size_t len_str = s21_strlen(str);
    if (start_index <= len_src) {
      result = malloc((len_str + len_src + 1) * sizeof(char));
      if (result == S21_NULL) {
        error = 1;
      }
      if (!error) {
        s21_memcpy(result, src, start_index);
        s21_memcpy(result + start_index, str, len_str);
        s21_memcpy(result + start_index + len_str, src + start_index,
                   len_src - start_index + 1);

        result[len_str + len_src] = '\0';
      }
    }
  }
  return (void *)result;
}