#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(
    PSurroundedRegions, 130, DIFFI_MEDIUM, TOPIC_ALGORITHMS,
    "Surrounded Regions",
    "Given an m x n matrix board containing 'X' and 'O', capture all regions "
    "that are 4-directionally surrounded by 'X'.",
    {"Matrix"});

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
  void solve(vector<vector<char>>& board) const {}
};
