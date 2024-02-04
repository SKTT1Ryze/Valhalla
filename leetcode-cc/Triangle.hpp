#include <algorithm>

#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(
    PTriangle, 120, DIFFI_MEDIUM, TOPIC_ALGORITHMS, "Triangle",
    "Given a triangle array, return the minimum path sum from top to bottom.",
    {"Triangle"});

class STriangle : public ISolution {
 public:
  size_t problemId() const override { return 120; }
  string name() const override {
    return ("Solution for " + string("Triangle"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelper<vector<vector<int>>, int>(
        {{{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}}, {{-10}}}, {11, -10},
        [this](auto input) { return this->minimumTotal(input); });
  };
  int benchmark() const override { return 0; }

 private:
  int minimumTotal(vector<vector<int>>& triangle) const {
    int n = triangle.size();
    vector<vector<int>> dp(n, vector(n, 0));

    dp[0][0] = triangle[0][0];

    for (int i = 1; i < n; i++) {
      for (int j = 0; j <= i; j++) {
        if (j == 0) {
          dp[i][j] = dp[i - 1][0] + triangle[i][j];
        } else if (j == i) {
          dp[j][j] = dp[i - 1][j - 1] + triangle[i][j];
        } else {
          dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
        }
      }
    }

    auto ans = min_element(dp[n - 1].begin(), dp[n - 1].end());

    return *ans;
  }
};
