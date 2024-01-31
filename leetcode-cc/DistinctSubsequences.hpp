#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(PDistinctSubsequences, 115, DIFFI_HARD,
                        TOPIC_ALGORITHMS, "Distinct Subsequences",
                        "Given two strings s and t, return the number of "
                        "distinct subsequences of s which equals t.",
                        {"DP"});

class SDistinctSubsequences : public ISolution {
 public:
  size_t problemId() const override { return 115; }
  string name() const override {
    return ("Solution for " + string("Distinct Subsequences"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelper<pair<string, string>, int>(
        {{"rabbbit", "rabbit"}, {"babgbag", "bag"}}, {3, 5},
        [this](auto input) {
          return this->numDistinct(input.first, input.second);
        });
  };
  int benchmark() const override { return 0; }

 private:
  int numDistinct(string s, string t) const {
    int m = s.length();
    int n = t.length();
    vector<vector<unsigned long long>> dp(m + 1,
                                          vector<unsigned long long>(n + 1, 0));

    dp[0][0] = 1;

    for (int i = 1; i <= m; i++) dp[i][0] = 1;

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (s[i] == t[j]) {
          dp[i + 1][j + 1] = dp[i][j + 1] + dp[i][j];
        } else {
          dp[i + 1][j + 1] = dp[i][j + 1];
        }
      }
    }

    return dp[m][n];
  }
};
