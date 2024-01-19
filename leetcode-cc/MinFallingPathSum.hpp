#include <__algorithm/ranges_min_element.h>

#include <algorithm>

#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(PMinFallingPathSum, 931, DIFFI_MEDIUM, TOPIC_ALGORITHMS,
                        "Minimum Falling Path Sum",
                        "Given an n x n array of integers matrix, return the "
                        "minimum sum of any falling path through matrix.",
                        {"DP"});

class SMinFallingPathSum : public ISolution {
 public:
  size_t problemId() const override { return 931; }
  string name() const override {
    return ("Solution for " + string("Minimum Falling Path Sum"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelper<vector<vector<int>>, int>(
        {{{2, 1, 3}, {6, 5, 4}, {7, 8, 9}}, {{-19, 57}, {-40, -5}}}, {13, -59},
        [this](auto input) { return this->minFallingPathSum(input); });
  };
  int benchmark() const override { return 0; }

 private:
  int minFallingPathSum(vector<vector<int>>& matrix) const {
    int n = matrix.size();
    vector<vector<int>> dp(n, vector(n, 0));

    for (int i = 0; i < n; i++) {
      dp[0][i] = matrix[0][i];
    }

    for (int i = 1; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (j == 0) {
          dp[i][j] = min(dp[i - 1][j], dp[i - 1][j + 1]) + matrix[i][j];
        } else if (j == n - 1) {
          dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1]) + matrix[i][j];
        } else {
          dp[i][j] =
              min(dp[i - 1][j], min(dp[i - 1][j + 1], dp[i - 1][j - 1])) +
              matrix[i][j];
        }
      }
    }

    return *min_element(dp[n - 1].begin(), dp[n - 1].end());
  }
};
