#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(
    PTheSkylineProblem, 218, DIFFI_HARD, TOPIC_ALGORITHMS,
    "The Skyline Problem",
    "A city's skyline is the outer contour of the silhouette formed by all the "
    "buildings in that city when viewed from a distance. Given the locations "
    "and heights of all the buildings, return the skyline formed by these "
    "buildings collectively.",
    {""});

class STheSkylineProblem : public ISolution {
 public:
  size_t problemId() const override { return 218; }
  string name() const override {
    return ("Solution for " + string("The Skyline Problem"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelper<vector<vector<int>>, vector<vector<int>>>(
        {{{0, 2, 3}, {2, 5, 3}},
         {{2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8}}},
        {{{0, 3}, {5, 0}},
         {{2, 10}, {3, 15}, {7, 12}, {12, 0}, {15, 10}, {20, 8}, {24, 0}}},
        [this](auto input) { return this->getSkyline(input); });
  };
  int benchmark() const override { return 0; }

 private:
  vector<vector<int>> getSkyline(vector<vector<int>>& buildings) const {}
};
