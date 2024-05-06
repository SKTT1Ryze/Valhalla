#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(
    PProductOfArrayExceptSelf, 238, DIFFI_MEDIUM, TOPIC_ALGORITHMS,
    "Product of Array Except Self",
    "Given an integer array nums, return an array answer such that answer[i] "
    "is equal to the product of all the elements of nums except nums[i].",
    {"Array"});

class SProductOfArrayExceptSelf : public ISolution {
 public:
  size_t problemId() const override { return 238; }
  string name() const override {
    return ("Solution for " + string("Product of Array Expect Self"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelper<vector<int>, vector<int>>(
        {{1, 2, 3, 4}, {-1, 1, 0, -3, 3}}, {{24, 12, 8, 6}, {0, 0, 9, 0, 0}},
        [this](auto input) { return this->productExceptSelf(input); });
  };
  int benchmark() const override { return 0; }

 private:
  vector<int> productExceptSelf(vector<int>& nums) const {}
};
