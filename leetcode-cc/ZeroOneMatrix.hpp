#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(
    PZeroOneMatrix, 542, DIFFI_MEDIUM, TOPIC_ALGORITHMS, "01 Matrix",
    "Given an m x n binary matrix mat, return the distance of the nearest 0 "
    "for each cell. The distance between two adjacent cells is 1.",
    {"BFS"});

class SZeroOneMatrix : public ISolution {
 public:
  size_t problemId() const override { return 542; }
  string name() const override {
    return ("Solution for " + string("01 Matrix"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelper<vector<vector<int>>, vector<vector<int>>>(
        {{{0, 0, 0}, {0, 1, 0}, {0, 0, 0}}, {{0, 0, 0}, {0, 1, 0}, {1, 1, 1}}},
        {
            {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}},
            {{0, 0, 0}, {0, 1, 0}, {1, 2, 1}},

        },
        [this](auto input) { return this->updateMatrix(input); });
  };
  int benchmark() const override { return 0; }

 private:
  vector<vector<int>> updateMatrix(vector<vector<int>>& mat) const {}
};
