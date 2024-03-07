#include <algorithm>

#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(
    PFindMinInRotatedSortedArrayII, 154, DIFFI_HARD, TOPIC_ALGORITHMS,
    "Find Minimum in Rotated Sorted Array II",
    "Given the sorted rotated array nums may contain duplicates,"
    "return the minimum element of this array.",
    {"Array"});

class SFindMinInRotatedSortedArrayII : public ISolution {
 public:
  size_t problemId() const override { return 154; }
  string name() const override {
    return ("Solution for " +
            string("Find Minimum in Rotated Sorted Array II"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelper<vector<int>, int>(
        {{1, 3, 5}, {2, 2, 2, 0, 1}}, {1, 0},
        [this](auto input) { return this->findMin(input); });
  };
  int benchmark() const override { return 0; }

 private:
  int findMin(vector<int>& nums) const {}
};
