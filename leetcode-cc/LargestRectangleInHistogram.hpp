#include <tuple>

#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(
    PLargestRectangleInHistogram, 84, DIFFI_HARD, TOPIC_ALGORITHMS,
    "Largest Rectangle in Histogram",
    "Given an array of integers heights representing the histogram's bar "
    "height where the width of each bar is 1, return the area of the largest "
    "rectangle in the histogram.",
    {"Array"});

class SLargestRectangleInHistogram : public ISolution {
 public:
  size_t problemId() const override { return 84; }
  string name() const override {
    return "Solution for Largest Rectangle in Histogram";
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelper<vector<int>, int>(
        {{2, 1, 5, 6, 2, 3}, {2, 4}}, {10, 4},
        [this](auto input) { return this->largestRectangleArea(input); });
  };
  int benchmark() const override { return 0; }

 private:
  int largestRectangleArea(vector<int>& heights) const {}
};
