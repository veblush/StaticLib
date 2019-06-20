#include <stddef.h>


#ifndef ICEBERG_FUNCTION_PREFIX
#define ICEBERG_FUNCTION_PREFIX x_
#endif

#define ICEBERG_FUNCTION_CONCAT_IMPL(x, y) x ## y
#define ICEBERG_FUNCTION_CONCAT(x, y) ICEBERG_FUNCTION_CONCAT_IMPL(x, y)
#define ICEBERG_FUNCTION(x) ICEBERG_FUNCTION_CONCAT(ICEBERG_FUNCTION_PREFIX, x)

extern "C" {
  // Returns sum of values
  int ICEBERG_FUNCTION(ice_sum)(size_t count, int vals[]);

  // Returns the count of unique number in values.
  int ICEBERG_FUNCTION(ice_unique_count)(size_t count, int vals[]);

  // Prints a given string.
  void ICEBERG_FUNCTION(ice_print)(const char* str);
}
