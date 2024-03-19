#include <unordered_set>

#include "PairHash.h"
#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(
    PNumOfIslands, 200, DIFFI_MEDIUM, TOPIC_ALGORITHMS, "Number of Islands",
    "Given an m x n 2D binary grid grid which represents a map of '1's (land) "
    "and '0's (water), return the number of islands.",
    {"Matrix"});

class SNumOfIslands : public ISolution {
 public:
  size_t problemId() const override { return 200; }
  string name() const override {
    return ("Solution for " + string("Number of Islands"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelper<vector<vector<char>>, int>(
        {{
            {'1', '1', '1', '1', '0'},
            {'1', '1', '0', '1', '0'},
            {'1', '1', '0', '0', '0'},
            {'0', '0', '0', '0', '0'},
        }},
        {1}, [this](auto input) { return this->numIslands(input); });
  };
  int benchmark() const override { return 0; }

 private:
  int numIslands(vector<vector<char>>& grid) const {
    int m = grid.size();
    int n = grid[0].size();
  }

  static void dfs(vector<vector<char>>& grid, int row, int col,
                  unordered_set<pair<int, int>, pair_hash>) {}
};
