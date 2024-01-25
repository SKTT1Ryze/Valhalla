#include <algorithm>
#include <utility>

#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(
    PLongestCommonSubsequence, 1143, DIFFI_MEDIUM, TOPIC_ALGORITHMS,
    "Longest Common Subsequence",
    "Given two strings text1 and text2, return the length of their longest "
    "common subsequence. If there is no common subsequence, return 0.",
    {"DP"});

class SLongestCommonSubsequence : public ISolution {
 public:
  size_t problemId() const override { return 1143; }
  string name() const override {
    return ("Solution for " + string("Longest Common Subsequence"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelper<pair<string, string>, int>(
        {{"abcde", "ace"}, {"abc", "abc"}, {"abc", "def"}}, {3, 3, 0},
        [this](auto input) {
          return this->longestCommonSubsequence(get<0>(input), get<1>(input));
        });
  };
  int benchmark() const override { return 0; }

 private:
  int longestCommonSubsequence(string text1, string text2) const {
    int m = text1.size();
    int n = text2.size();

    vector<vector<int>> dp(m + 1, vector(n + 1, 0));
    dp[0][0] = 0;

    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        if (text1[i - 1] == text2[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1] + 1;
        } else {
          dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
      }
    }

    return dp[m][n];
  }
};
