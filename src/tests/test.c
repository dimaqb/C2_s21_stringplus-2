#include "test.h"

int main() {
  int no_failed = 0;

  no_failed |= test_regular();
  no_failed |= test_sprintf();
  no_failed |= test_sscanf();
  no_failed |= test_to_upper();
  no_failed |= test_to_lower();
  no_failed |= test_insert();
  no_failed |= test_trim();
  no_failed |= test_strcmp();
  no_failed |= test_strnlen();

  return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
