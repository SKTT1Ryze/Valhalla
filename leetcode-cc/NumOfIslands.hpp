#include <unordered_set>
#include <utility>

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
         },
         {
             {'1', '1', '0', '0', '0'},
             {'1', '1', '0', '0', '0'},
             {'0', '0', '1', '0', '0'},
             {'0', '0', '0', '1', '1'},
         }},
        {1, 3}, [this](auto input) { return this->numIslands(input); });
  };
  int benchmark() const override { return 0; }

 private:
  int numIslands(vector<vector<char>>& grid) const {
    int m = grid.size();
    int n = grid[0].size();

    pair<int, int> p = {0, 0};

    while (p.first < m && p.second < n) {
      if (grid[p.first][p.second] == '1') break;
      p = nextPair(p, m, n);
    }

    int res = 0;
    unordered_set<pair<int, int>, pair_hash> set = {};

    while (p.first < m && p.second < n) {
      if (!set.contains(p) && grid[p.first][p.second] == '1') {
        dfs(grid, p.first, p.second, set);
        res++;
      }
      p = nextPair(p, m, n);
    }

    return res;
  }

  static void dfs(vector<vector<char>>& grid, int row, int col,
                  unordered_set<pair<int, int>, pair_hash>& set) {
    if (!set.contains({row, col}) && grid[row][col] == '1') {
      set.insert({row, col});
      if (row > 0) dfs(grid, row - 1, col, set);
      if (row < grid.size() - 1) dfs(grid, row + 1, col, set);
      if (col > 0) dfs(grid, row, col - 1, set);
      if (col < grid[0].size() - 1) dfs(grid, row, col + 1, set);
    }
  }

  static pair<int, int> nextPair(pair<int, int> p, int m, int n) {
    return (p.second == n - 1) ? make_pair(p.first + 1, 0)
                               : make_pair(p.first, p.second + 1);
  }
};
