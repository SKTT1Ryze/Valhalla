#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(PUqBinarySearchTrees, 96, DIFFI_MEDIUM,
                        TOPIC_ALGORITHMS, "Unique Binary Search Trees",
                        "Given an integer n, return the number of structurally "
                        "unique BST's (binary search trees) which has exactly "
                        "n nodes of unique values from 1 to n.",
                        {"DP"});

class SUqBinarySearchTrees : public ISolution {
 public:
  size_t problemId() const override { return 96; }
  string name() const override {
    return ("Solution for " + string("Unique Binary Search Trees"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelper<int, int>(
        {3, 1}, {5, 1}, [this](auto input) { return this->numTrees(input); });
  };
  int benchmark() const override { return 0; }

 private:
  int numTrees(int n) const {
    vector<int> dp(n + 1, 0);

    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
      for (int j = 1; j <= i; j++) {
        dp[i] += dp[j - 1] * dp[i - j];
      }
    }

    return dp[n];
  }
};
