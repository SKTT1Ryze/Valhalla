#include <climits>

#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(
    PBestTimeToBuySellStockIII, 123, DIFFI_HARD, TOPIC_ALGORITHMS,
    "Best Time to Buy and Sell Stock III",
    "You are given an array prices where prices[i] is the price of a given "
    "stock on the ith day. Find the maximum profit you can achieve. You may "
    "complete at most two transactions.",
    {"DP"});

class SBestTimeToBuySellStockIII : public ISolution {
 public:
  size_t problemId() const override { return 123; }
  string name() const override {
    return ("Solution for " + string("Best Time to Buy and Sell Stock III"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelper<vector<int>, int>(
        {{3, 3, 5, 0, 0, 3, 1, 4}, {1, 2, 3, 4, 5}, {7, 6, 4, 3, 1}}, {6, 4, 0},
        [this](auto input) { return this->maxProfit(input); });
  };
  int benchmark() const override { return 0; }

 private:
  int maxProfit(vector<int>& prices) const {
    if (prices.empty()) return 0;

    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(5, 0));

    // Initialize base cases
    dp[0][1] = -prices[0];
    dp[0][3] = -prices[0];

    for (int i = 1; i < n; ++i) {
      // Transition for the first transaction
      dp[i][1] = max(dp[i - 1][1], -prices[i]);
      dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + prices[i]);
      // Transition for the second transaction
      dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] - prices[i]);
      dp[i][4] = max(dp[i - 1][4], dp[i - 1][3] + prices[i]);
    }

    // The answer is the maximum profit after the last day with at most 2
    // transactions
    return max(0, max(dp[n - 1][2], dp[n - 1][4]));
  }
};
