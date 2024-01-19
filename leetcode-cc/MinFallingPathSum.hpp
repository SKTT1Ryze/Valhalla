#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(PMinFallingPathSum, 931, DIFFI_MEDIUM, TOPIC_ALGORITHMS,
                        "Minimum Falling Path Sum", "931", {"Matrix"});

class SMinFallingPathSum : public ISolution {
 public:
  size_t problemId() const override { return 931; }
  string name() const override {
    return ("Solution for " + string("Minimum Falling Path Sum"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelper<vector<vector<int>>, int>(
        {{{2, 1, 3}, {6, 5, 4}, {7, 8, 9}}, {{-19, 57}, {-40, -5}}}, {13, -59},
        [this](auto input) { return this->minFallingPathSum(input); });
  };
  int benchmark() const override { return 0; }

 private:
  int minFallingPathSum(vector<vector<int>>& matrix) const {}
};
