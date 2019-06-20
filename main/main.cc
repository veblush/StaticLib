#define ICEBERG_FUNCTION_PREFIX a_
#include "../lib/iceberg.h"
#undef  ICEBERG_FUNCTION_PREFIX

#define ICEBERG_FUNCTION_PREFIX b_
#include "../lib/iceberg.h"
#undef ICEBERG_FUNCTION_PREFIX

#include <iostream>
#include <vector>

int main() {
  std::vector<int> a = {{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }};
  std::vector<int> b = {{ 5, 4, 1, 4, 3, 4, 2, 1, 1, 2 }};

  std::cout << "a_sum : " << a_ice_sum(a.size(), &a[0]) << std::endl;
  std::cout << "a_unique : " << a_ice_unique_count(b.size(), &b[0]) << std::endl;
  a_ice_print("a_main");

  std::cout << "b_sum : " << b_ice_sum(a.size(), &a[0]) << std::endl;
  std::cout << "b_unique : " << b_ice_unique_count(b.size(), &b[0]) << std::endl;
  b_ice_print("b_main");

  return 0;
}