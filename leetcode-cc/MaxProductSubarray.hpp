#include <algorithm>

#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(PMaxProductSubarray, 152, DIFFI_MEDIUM,
                        TOPIC_ALGORITHMS, "Maximum Product Subarray",
                        "Given an integer array nums, find a subarray that has "
                        "the largest product, and return the product.",
                        {"DP"});

class SMaxProductSubarray : public ISolution {
 public:
  size_t problemId() const override { return 152; }
  string name() const override {
    return ("Solution for " + string("Maximum Product Subarray"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelper<vector<int>, int>({{2, 3, -2, 4}, {-2, 0, -1}}, {6, 0},
                                        [this](auto input) {
                                          // return this->maxProduct(input);
                                          return this->maxProductV2(input);
                                        });
  };
  int benchmark() const override { return 0; }

 private:
  // work, but time limit
  int maxProduct(vector<int>& nums) const {
    int n = nums.size();
    vector<vector<int>> dp(n, vector(n, 0));
    int res = INT_MIN;

    for (int i = 0; i < n; i++) {
      dp[i][i] = nums[i];
      res = max(res, dp[i][i]);
    }

    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        dp[i][j] = dp[i][j - 1] * nums[j];
        res = max(res, dp[i][j]);
      }
    }

    return res;
  }

  int maxProductV2(vector<int>& nums) const {
    int n = nums.size();
    if (n == 0) return 0;

    int max_product = nums[0];
    int min_product = nums[0];
    int result = nums[0];

    for (int i = 1; i < n; ++i) {
      int temp_max = max_product;
      int temp_min = min_product;
      max_product = max({nums[i], nums[i] * temp_max, nums[i] * temp_min});
      min_product = min({nums[i], nums[i] * temp_max, nums[i] * temp_min});
      result = max(result, max_product);
    }

    return result;
  }
};
