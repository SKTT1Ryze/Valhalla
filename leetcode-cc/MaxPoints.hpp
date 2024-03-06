#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(
    PMaxPointsLine, 149, DIFFI_MEDIUM, TOPIC_ALGORITHMS, "Max Points on a Line",
    "Given an array of points where points[i] = [xi, yi] represents a point on "
    "the X-Y plane, return the maximum number of points that lie on the same "
    "straight line.",
    {""});

class SMaxPointsLine : public ISolution {
 public:
  size_t problemId() const override { return 149; }
  string name() const override {
    return ("Solution for " + string("Max Points on a Line"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelper<vector<vector<int>>, int>(
        {{{1, 1}, {2, 2}, {3, 3}},
         {{1, 1}, {3, 2}, {5, 3}, {4, 1}, {2, 3}, {1, 4}}},
        {3, 4}, [this](auto input) { return this->maxPoints(input); });
  };
  int benchmark() const override { return 0; }

 private:
  int maxPoints(vector<vector<int>>& points) const {}
};
