#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(
    PMaximalRectangle, 85, DIFFI_HARD, TOPIC_ALGORITHMS, "Maximal Rectangle",
    "Given a rows x cols binary matrix filled with 0's and 1's, find the "
    "largest rectangle containing only 1's and return its area.",
    {"DP"});

class SMaximalRectangle : public ISolution {
 public:
  size_t problemId() const override { return 85; }
  string name() const override { return "Solution for Maximal Rectangle"; }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelper<vector<vector<char>>, int>(
        {{{'1', '0', '1', '0', '0'},
          {'1', '0', '1', '1', '1'},
          {'1', '1', '1', '1', '1'},
          {'1', '0', '0', '1', '0'}},
         {{'0'}}},
        {6, 0}, [this](auto input) { return this->maximalRectangle(input); });
  };
  int benchmark() const override { return 0; }

 private:
  int maximalRectangle(vector<vector<char>>& matrix) const {}
};
