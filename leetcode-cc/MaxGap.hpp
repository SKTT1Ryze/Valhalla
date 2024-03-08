#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(
    PMaxGap, 164, DIFFI_MEDIUM, TOPIC_ALGORITHMS, "Maximum Gap",
    "Given an integer array nums, return the maximum difference between two "
    "successive elements in its sorted form. If the array contains less than "
    "two elements, return 0.",
    {""});

class SMaxGap : public ISolution {
 public:
  size_t problemId() const override { return 164; }
  string name() const override {
    return ("Solution for " + string("Maximum Gap"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelper<vector<int>, int>(
        {{3, 6, 9, 1}, {10}}, {3, 0},
        [this](auto input) { return this->maximumGap(input); });
  };
  int benchmark() const override { return 0; }

 private:
  int maximumGap(vector<int>& nums) const {}
};
