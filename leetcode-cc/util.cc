#include "util.h"

bool compareVectors(const vector<int>& v1, const vector<int>& v2) {
  if (v1.size() != v2.size()) {
    return false;
  }

  vector<int> sortedV1 = v1;
  vector<int> sortedV2 = v2;
  sort(sortedV1.begin(), sortedV1.end());
  sort(sortedV2.begin(), sortedV2.end());

  return sortedV1 == sortedV2;
}
