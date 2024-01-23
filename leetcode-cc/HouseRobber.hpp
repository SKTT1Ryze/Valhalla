#include <algorithm>

#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(PHouseRobber, 198, DIFFI_MEDIUM, TOPIC_ALGORITHMS,
                        "House Robber", "", {""});

class SHouseRobber : public ISolution {
 public:
  size_t problemId() const override { return 198; }
  string name() const override {
    return ("Solution for " + string("House Robber"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelper<vector<int>, int>(
        {{1, 2, 3, 1}, {2, 7, 9, 3, 1}}, {4, 12},
        [this](auto input) { return this->rob(input); });
  };
  int benchmark() const override { return 0; }

 private:
  int rob(vector<int>& nums) const {
    int n = nums.size();
    if (n == 1) return nums[0];
    if (n == 2) return max(nums[0], nums[1]);

    vector<int> dp(n, 0);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    for (int i = 2; i < n; i++) dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);

    return dp[n - 1];
  }
};
