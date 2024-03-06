#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(PMaxProductSubarray, 152, DIFFI_MEDIUM,
                        TOPIC_ALGORITHMS, "Maximum Product Subarray",
                        "Given an integer array nums, find a subarray that has "
                        "the largest product, and return the product.",
                        {""});

class SMaxProductSubarray : public ISolution {
 public:
  size_t problemId() const override { return 152; }
  string name() const override {
    return ("Solution for " + string("Maximum Product Subarray"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelper<vector<int>, int>(
        {{2, 3, -2, 4}, {-2, 0, -1}}, {6, 0},
        [this](auto input) { return this->maxProduct(input); });
  };
  int benchmark() const override { return 0; }

 private:
  int maxProduct(vector<int>& nums) const {}
};
