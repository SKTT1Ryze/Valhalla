#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(
    PBestTimeToBuySellStockIV, 188, DIFFI_HARD, TOPIC_ALGORITHMS,
    "Best Time To Buy and Sell Stock IV",
    "You are given an integer array prices where prices[i] is the price of a "
    "given stock on the ith day, and an integer k.Find the maximum profit you "
    "can achieve. You may complete at most k transactions: i.e. you may buy at "
    "most k times and sell at most k times.",
    {"DP"});

class SBestTimeToBuySellStockIV : public ISolution {
 public:
  size_t problemId() const override { return 188; }
  string name() const override {
    return ("Solution for " + string("Best Time To Buy and Sell Stock IV"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelper<pair<int, vector<int>>, int>(
        {{2, {2, 4, 1}}, {2, {3, 2, 6, 5, 0, 3}}}, {2, 7}, [this](auto input) {
          return this->maxProfit(input.first, input.second);
        });
  };
  int benchmark() const override { return 0; }

 private:
  int maxProfit(int k, vector<int>& prices) const {
    int n = prices.size();
    vector<int> dp(k * 2 + 1, 0);

    for (int i = 0; i < dp.size(); i++) {
      dp[i] = i % 2 == 0 ? 0 : INT_MIN;
    }

    for (int i = 0; i < n; i++) {
      for (int j = 1; j < dp.size(); j++) {
        if (j % 2 == 0) {
          dp[j] = max(dp[j], dp[j - 1] + prices[i]);
        } else {
          dp[j] = max(dp[j], dp[j - 1] - prices[i]);
        }
      }
    }

    return dp[k * 2];
  }
};
