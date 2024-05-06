#include <numeric>

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
  vector<int> productExceptSelf(vector<int>& nums) const {
    int n = nums.size();
    auto zeroCount = count(nums.begin(), nums.end(), 0);
    if (zeroCount > 1) {
      vector<int> ans(n, 0);
      return ans;
    }
    int product = accumulate(nums.begin(), nums.end(), 1, [](int a, int b) {
      if (a != 0 && b != 0) {
        return a * b;
      } else if (a == 0) {
        return b;
      } else {
        return a;
      }
    });
    vector<int> ans(n, 0);
    for (int i = 0; i < n; i++) {
      if (nums[i] == 0) {
        ans[i] = product;
      } else if (zeroCount > 0) {
        ans[i] = 0;
      } else {
        ans[i] = product / nums[i];
      }
    }

    return ans;
  }
};
