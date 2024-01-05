#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(PDecodeWays, 91, DIFFI_MEDIUM, TOPIC_ALGORITHMS,
                        "Decode Ways", "", {"DP"});

class SDecodeWays : public ISolution {
 public:
  size_t problemId() const override { return 91; }
  string name() const override { return "Decode Ways"; }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelper<string, int>(
        {"12", "226", "06", "27", "2101"}, {2, 3, 0, 1, 1},
        [this](auto input) { return this->numDecodings(input); });
  };
  int benchmark() const override { return 0; }

 private:
  int numDecodings(string s) const {
    int n = s.size();
    vector<vector<int>> dp = vector(n, vector(n, 0));

    for (int i = 0; i < n; i++) {
      if (s[i] != '0') {
        dp[i][i] = 1;
      }
    }

    for (int i = 0; i < n - 1; i++) {
      if (s[i] != '0') {
        if (s[i + 1] == '0') {
          dp[i][i + 1] = s.substr(i, 2) <= "26" ? 1 : 0;
        } else {
          dp[i][i + 1] = s.substr(i, 2) <= "26" ? 2 : 1;
        }
      }
    }

    for (int len = 3; len <= n; len++) {
      for (int i = 0; i < n - len + 1; i++) {
        int j = i + len - 1;
        if (s[j] == '0') {
          dp[i][j] = dp[i][j - 2] * (s[j - 1] == '1' || s[j - 1] == '2');
        } else if (s.substr(j - 1, 2) <= "26" && s[j - 1] != '0') {
          dp[i][j] = dp[i][j - 1] + dp[i][j - 2];
        } else {
          dp[i][j] = dp[i][j - 1];
        }
      }
    }

    return dp[0][n - 1];
  }
};
