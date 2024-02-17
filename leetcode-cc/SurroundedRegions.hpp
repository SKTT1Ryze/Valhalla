#include <unordered_set>

#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

struct pair_hash {
  inline size_t operator()(const pair<int, int>& v) const {
    return v.first * 31 + v.second;
  }
};

IMPLEMENT_PROBLEM_CLASS(
    PSurroundedRegions, 130, DIFFI_MEDIUM, TOPIC_ALGORITHMS,
    "Surrounded Regions",
    "Given an m x n matrix board containing 'X' and 'O', capture all regions "
    "that are 4-directionally surrounded by 'X'.",
    {"Matrix / DFS"});

class SSurroundedRegions : public ISolution {
 public:
  size_t problemId() const override { return 130; }
  string name() const override {
    return ("Solution for " + string("Surrounded Regions"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    vector<vector<char>> board = {{'X', 'X', 'X', 'X'},
                                  {'X', 'O', 'O', 'X'},
                                  {'X', 'X', 'O', 'X'},
                                  {'X', 'O', 'X', 'X'}};
    this->solve(board);
    if (board != vector<vector<char>>({{'X', 'X', 'X', 'X'},
                                       {'X', 'X', 'X', 'X'},
                                       {'X', 'X', 'X', 'X'},
                                       {'X', 'O', 'X', 'X'}}))
      return 1;

    return 0;
  };
  int benchmark() const override { return 0; }

 private:
  void solve(vector<vector<char>>& board) const {
    int m = board.size();
    int n = board[0].size();

    unordered_set<pair<int, int>, pair_hash> init = {};
    unordered_set<pair<int, int>, pair_hash> paths = {};

    for (int i = 0; i < m; i++) {
      if (board[i][0] == 'O') init.insert({i, 0});
      if (board[i][n - 1] == 'O') init.insert({i, n - 1});
    }

    for (int i = 0; i < n; i++) {
      if (board[0][i] == 'O') init.insert({0, i});
      if (board[m - 1][i] == 'O') init.insert({m - 1, i});
    }

    for (const auto& [x, y] : init) {
      this->dfs(x, y, m, n, board, paths);
    }

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (board[i][j] == 'O' && !paths.contains({i, j})) board[i][j] = 'X';
      }
    }
  }

  void dfs(int x, int y, int m, int n, vector<vector<char>>& board,
           unordered_set<pair<int, int>, pair_hash>& paths) const {
    if (paths.contains({x, y}) || !this->checkValid(x, y, m, n)) return;

    if (board[x][y] == 'O') paths.insert({x, y});

    if (this->checkValid(x - 1, y, m, n) && board[x - 1][y] == 'O')
      this->dfs(x - 1, y, m, n, board, paths);
    if (this->checkValid(x + 1, y, m, n) && board[x + 1][y] == 'O')
      this->dfs(x + 1, y, m, n, board, paths);
    if (this->checkValid(x, y - 1, m, n) && board[x][y - 1] == 'O')
      this->dfs(x, y - 1, m, n, board, paths);
    if (this->checkValid(x, y + 1, m, n) && board[x][y + 1] == 'O')
      this->dfs(x, y + 1, m, n, board, paths);
  }

  bool checkValid(int x, int y, int m, int n) const {
    return !(x < 0 || x >= m || y < 0 || y >= n);
  }
};
