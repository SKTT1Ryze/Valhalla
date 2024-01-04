#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(PScrambleString, 87, DIFFI_HARD, TOPIC_ALGORITHMS,
                        "Scramble String", "", {"String"});

class SScrambleString : public ISolution {
 public:
  size_t problemId() const override { return 87; }
  string name() const override { return "Scramble String"; }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelper<tuple<string, string>, bool>(
        {{"great", "rgeat"}, {"abcde", "caebd"}, {"a", "a"}},
        {true, false, true}, [this](auto input) {
          return this->isScramble(get<0>(input), get<1>(input));
        });
  };
  int benchmark() const override { return 0; }

 private:
  bool isScramble(string s1, string s2) const {
    int n = s1.length();
    if (n != s2.length()) {
      return false;
    }

    vector<vector<vector<bool>>> dp(
        n, vector<vector<bool>>(n, vector<bool>(n + 1, false)));

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (s1[i] == s2[j]) {
          dp[i][j][1] = true;
        }
      }
    }

    for (int len = 2; len <= n; len++) {
      for (int i = 0; i <= n - len; i++) {
        for (int j = 0; j <= n - len; j++) {
          for (int k = 1; k < len; k++) {
            // swap
            if ((dp[i][j][k] && dp[i + k][j + k][len - k]) ||
                // do not swap
                (dp[i][j + len - k][k] && dp[i + k][j][len - k])) {
              dp[i][j][len] = true;
              break;
            }
          }
        }
      }
    }

    return dp[0][0][n];
  }
};
