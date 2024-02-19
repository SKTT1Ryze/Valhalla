#include <algorithm>
#include <climits>

#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(
    PPalindromePartitioningII, 132, DIFFI_HARD, TOPIC_ALGORITHMS,
    "Palindrome Partitioning II",
    "Given a string s, partition s such that every substring of the partition "
    "is a palindrome. Return the minimum cuts needed for a palindrome "
    "partitioning of s.",
    {"DP"});

class SPalindromePartitioningII : public ISolution {
 public:
  size_t problemId() const override { return 132; }
  string name() const override {
    return ("Solution for " + string("Palindrome Partitioning II"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelper<string, int>(
        {"aab", "a", "ab"}, {1, 0, 1},
        [this](auto input) { return this->minCut(input); });
  };
  int benchmark() const override { return 0; }

 private:
  int minCut(string s) const {
    int n = s.size();
    vector<int> dp(n + 1, 0);
    vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));

    // Initialize dp
    for (int i = 0; i <= n; i++) {
      dp[i] = n - i - 1;
    }

    // Pre-calculate isPalindrome
    for (int i = n - 1; i >= 0; i--) {
      for (int j = i; j < n; j++) {
        if (s[i] == s[j] && (j - i < 2 || isPalindrome[i + 1][j - 1])) {
          isPalindrome[i][j] = true;
        }
      }
    }

    // DP
    for (int i = n - 1; i >= 0; i--) {
      for (int j = i; j < n; j++) {
        if (isPalindrome[i][j]) {
          dp[i] = min(dp[i], dp[j + 1] + 1);
        }
      }
    }

    return dp[0];
  }
};
