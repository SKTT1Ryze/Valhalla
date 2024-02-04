#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(
    PTriangle, 120, DIFFI_MEDIUM, TOPIC_ALGORITHMS, "Triangle",
    "Given a triangle array, return the minimum path sum from top to bottom.",
    {"Triangle"});

class STriangle : public ISolution {
 public:
  size_t problemId() const override { return 120; }
  string name() const override {
    return ("Solution for " + string("Triangle"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelper<vector<vector<int>>, int>(
        {{{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}}, {{-10}}}, {11, -10},
        [this](auto input) { return this->minimumTotal(input); });
  };
  int benchmark() const override { return 0; }

 private:
  int minimumTotal(vector<vector<int>>& triangle) const {
    
  }
};
