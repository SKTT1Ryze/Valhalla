#pragma once

#include <vector>
using namespace std;

#include <algorithm>

template <typename T>
bool compareVectors(const vector<T>& v1, const vector<T>& v2) {
  if (v1.size() != v2.size()) {
    return false;
  }

  vector<T> sortedV1 = v1;
  vector<T> sortedV2 = v2;
  sort(sortedV1.begin(), sortedV1.end());
  sort(sortedV2.begin(), sortedV2.end());

  return sortedV1 == sortedV2;
}
