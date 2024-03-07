#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(PFindMinInRotatedSortedArray, 153, DIFFI_MEDIUM,
                        TOPIC_ALGORITHMS,
                        "Find Minimum in Rotated Sorted Array",
                        "Given the sorted rotated array nums of unique "
                        "elements, return the minimum element of this array.",
                        {""});

class SFindMinInRotatedSortedArray : public ISolution {
 public:
  size_t problemId() const override { return 153; }
  string name() const override {
    return ("Solution for " + string("Find Minimum in Rotated Sorted Array"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelper<vector<int>, int>(
        {{3, 4, 5, 1, 2}, {4, 5, 6, 7, 0, 1, 2}, {11, 13, 15, 17}}, {1, 0, 11},
        [this](auto input) { return this->findMin(input); });
  };
  int benchmark() const override { return 0; }

 private:
  int findMin(vector<int>& nums) const {}
};
