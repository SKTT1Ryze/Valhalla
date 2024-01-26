#include <unordered_set>
#include <utility>

#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(POutOfBoundaryPaths, 576, DIFFI_MEDIUM,
                        TOPIC_ALGORITHMS, "Out of Boundary Paths", "", {""});

class SOutOfBoundaryPaths : public ISolution {
 public:
  size_t problemId() const override { return 576; }
  string name() const override {
    return ("Solution for " + string("Out of Boundary Paths"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    int m = 2;
    int n = 2;
    int maxMove = 2;
    int startRow = 0;
    int startColumn = 0;

    auto output = this->findPaths(m, n, maxMove, startRow, startColumn);

    if (output != 6) return 1;
    return 0;
  };
  int benchmark() const override { return 0; }

 private:
  int findPaths(int m, int n, int maxMove, int startRow,
                int startColumn) const {
    const int MOD = 1e9 + 7;
    vector<vector<vector<int>>> dp(maxMove + 1,
                                   vector<vector<int>>(m, vector<int>(n, 0)));

    // Initialize base case: starting position
    dp[0][startRow][startColumn] = 1;

    int count = 0;
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    // Iterate over each move
    for (int move = 1; move <= maxMove; move++) {
      for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
          for (const auto& dir : directions) {
            int newRow = i + dir[0];
            int newCol = j + dir[1];

            // Check if the new position is within the boundary
            if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n) {
              // Accumulate the number of paths to the current position
              dp[move][i][j] =
                  (dp[move][i][j] + dp[move - 1][newRow][newCol]) % MOD;
            } else {
              // If the new position is outside the boundary, increment the
              // count
              count = (count + dp[move - 1][i][j]) % MOD;
            }
          }
        }
      }
    }

    return count;
  }
};
