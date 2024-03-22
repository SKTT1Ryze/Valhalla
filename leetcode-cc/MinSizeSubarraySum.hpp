#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(
    PMinSizeSubarraySum, 209, DIFFI_MEDIUM, TOPIC_ALGORITHMS,
    "Minimum Size Subarray Sum",
    "Given an array of positive integers nums and a positive integer target, "
    "return the minimal length of a subarray whose sum is greater than or "
    "equal to target. If there is no such subarray, return 0 instead.",
    {"Sliding Window"});

class SMinSizeSubarraySum : public ISolution {
 public:
  size_t problemId() const override { return 209; }
  string name() const override {
    return ("Solution for " + string("Minimum Size Subarray Sum"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelper<pair<int, vector<int>>, int>(
        {{7, {2, 3, 1, 2, 4, 3}},
         {4, {1, 4, 4}},
         {11, {1, 1, 1, 1, 1, 1, 1, 1}}},
        {2, 1, 0}, [this](auto input) {
          return this->minSubArrayLen(input.first, input.second);
        });
  };
  int benchmark() const override { return 0; }

 private:
  // Memory Limit Exceeded
  // int minSubArrayLen(int target, vector<int>& nums) const {
  //   int n = nums.size();
  //   vector<vector<int>> dp(n, vector(n, 0));
  //
  //   for (int i = 0; i < n; i++) {
  //     if (nums[i] >= target) {
  //       return 1;
  //     } else {
  //       dp[i][i] = nums[i];
  //     }
  //   }
  //
  //   for (int len = 2; len <= n; len++) {
  //     for (int i = 0; i <= n - len; i++) {
  //       int j = i + len - 1;
  //       dp[i][j] = dp[i][j - 1] + nums[j];
  //
  //       if (dp[i][j] >= target) return len;
  //     }
  //   }
  //
  //   return 0;
  // }

  int minSubArrayLen(int target, vector<int>& nums) const {
    int n = nums.size();
    int left = 0, right = 0;
    int sum = 0;
    int minLen = INT_MAX;

    while (right < n) {
      sum += nums[right];
      while (sum >= target) {
        minLen = min(minLen, right - left + 1);
        sum -= nums[left++];
      }
      right++;
    }

    return minLen == INT_MAX ? 0 : minLen;
  }
};
