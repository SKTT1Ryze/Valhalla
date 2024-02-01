#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(
    PPascalsTriangle, 118, DIFFI_EASY, TOPIC_ALGORITHMS, "Pascal's Triangle",
    "Given an integer numRows, return the first numRows of Pascal's triangle.",
    {"Triangle"});

class SPascalsTriangle : public ISolution {
 public:
  size_t problemId() const override { return 118; }
  string name() const override {
    return ("Solution for " + string("Pascal's Triangle"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelper<int, vector<vector<int>>>(
        {5, 1},
        {{{1}, {1, 1}, {1, 2, 1}, {1, 3, 3, 1}, {1, 4, 6, 4, 1}}, {{1}}},
        [this](auto input) { return this->generate(input); });
  };
  int benchmark() const override { return 0; }

 private:
  vector<vector<int>> generate(int numRows) const {
    vector<vector<int>> res = {{1}};

    for (int i = 1; i < numRows; i++) {
      vector<int> current = {};

      for (int j = 0; j < i - 1; j++)
        current.push_back(res[i - 1][j] + res[i - 1][j + 1]);

      current.push_back(1);
      current.insert(current.begin(), 1);

      res.push_back(current);
    }

    return res;
  }
};
