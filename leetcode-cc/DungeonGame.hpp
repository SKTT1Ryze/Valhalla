#include <algorithm>
#include <cmath>

#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(PDungeonGame, 174, DIFFI_HARD, TOPIC_ALGORITHMS,
                        "Dungeon Game",
                        "Return the knight's minimum initial health so that he "
                        "can rescue the princess.",
                        {"DP"});

class SDungeonGame : public ISolution {
 public:
  size_t problemId() const override { return 174; }
  string name() const override {
    return ("Solution for " + string("Dungeon Game"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelper<vector<vector<int>>, int>(
        {{{-2, -3, 3}, {-5, -10, 1}, {10, 30, -5}}, {{0}}}, {7, 1},
        [this](auto input) { return this->calculateMinimumHP(input); });
  };
  int benchmark() const override { return 0; }

 private:
  int calculateMinimumHP(vector<vector<int>>& dungeon) const {
    int m = dungeon.size();
    int n = dungeon[0].size();

    vector<vector<int>> dp(m, vector(n, 0));

    dp[m - 1][n - 1] = max(1, 1 - dungeon[m - 1][n - 1]);

    for (int i = n - 2; i >= 0; i--)
      dp[m - 1][i] = max(1, dp[m - 1][i + 1] - dungeon[m - 1][i]);

    for (int i = m - 2; i >= 0; i--)
      dp[i][n - 1] = max(1, dp[i + 1][n - 1] - dungeon[i][n - 1]);

    for (int i = m - 2; i >= 0; i--) {
      for (int j = n - 2; j >= 0; j--) {
        int down = max(1, dp[i + 1][j] - dungeon[i][j]);
        int right = max(1, dp[i][j + 1] - dungeon[i][j]);
        dp[i][j] = min(down, right);
      }
    }

    return dp[0][0];
  }
};
