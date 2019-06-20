#include "iceberg.h"

#include <vector>
#include <algorithm>
#include <set>
#include <iostream>

int ICEBERG_FUNCTION(ice_sum)(size_t count, int vals[]) {
  std::vector<int> tmp(vals, vals + count);
  int sum = 0;
  std::for_each(tmp.begin(), tmp.end(), [&sum](const int& n) {
    sum += n;
  });
  return sum;
}

int ICEBERG_FUNCTION(ice_unique_count)(size_t count, int vals[]) {
  std::set<int> tmp(vals, vals + count);
  return (int)tmp.size();
}

void ICEBERG_FUNCTION(ice_print)(const char* str) {
  std::cout << "ice_print(" << str << ")" << std::endl;
}
