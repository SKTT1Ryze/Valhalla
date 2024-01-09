#include <tuple>

#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(PInterleavingString, 97, DIFFI_MEDIUM, TOPIC_ALGORITHMS,
                        "Interleaving String",
                        "Given strings s1, s2, and s3, find whether s3 is "
                        "formed by an interleaving of s1 and s2.",
                        {"DP / Backtracking"});

class SInterleavingString : public ISolution {
 public:
  size_t problemId() const override { return 97; }
  string name() const override {
    return ("Solution for " + string("Interleaving String"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelper<tuple<string, string, string>, bool>(
        {make_tuple("aabcc", "dbbca", "aadbbcbcac"),
         make_tuple("aabcc", "dbbca", "aadbbbaccc"), make_tuple("", "", "")},
        {true, false, true}, [this](auto input) {
          return this->isInterleaveBacktracking(get<0>(input), get<1>(input),
                                                get<2>(input)) &&
                 this->isInterleaveDP(get<0>(input), get<1>(input),
                                      get<2>(input));
        });
  };
  int benchmark() const override { return 0; }

 private:
  bool isInterleaveBacktracking(string s1, string s2, string s3) const {
    if ((s1.size() + s2.size()) != s3.size()) return false;
    return this->backtracking(0, 0, 0, s1, s2, s3);
  }

  bool backtracking(int m, int n, int i, string& s1, string& s2,
                    string& s3) const {
    if (m == s1.size() && n == s2.size() && i == s3.size()) {
      return true;
    } else {
      if (s1[m] == s2[n] && s1[m] == s3[i]) {
        return this->backtracking(m + 1, n, i + 1, s1, s2, s3) ||
               this->backtracking(m, n + 1, i + 1, s1, s2, s3);
      } else if (s1[m] == s3[i]) {
        return this->backtracking(m + 1, n, i + 1, s1, s2, s3);
      } else if (s2[n] == s3[i]) {
        return this->backtracking(m, n + 1, i + 1, s1, s2, s3);
      } else {
        return false;
      }
    }
  }

  bool isInterleaveDP(string s1, string s2, string s3) const {
    int len1 = s1.length();
    int len2 = s2.length();
    int len3 = s3.length();

    if (len1 + len2 != len3) {
      return false;
    }

    vector<vector<bool>> dp(len1 + 1, vector<bool>(len2 + 1, false));

    dp[0][0] = true;

    for (int i = 1; i <= len1; ++i) {
      dp[i][0] = dp[i - 1][0] && s1[i - 1] == s3[i - 1];
    }

    for (int j = 1; j <= len2; ++j) {
      dp[0][j] = dp[0][j - 1] && s2[j - 1] == s3[j - 1];
    }

    for (int i = 1; i <= len1; ++i) {
      for (int j = 1; j <= len2; ++j) {
        dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) ||
                   (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
      }
    }

    // The final result is stored in the bottom-right cell
    return dp[len1][len2];
  }
};
