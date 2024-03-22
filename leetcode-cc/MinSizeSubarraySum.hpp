#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(
    PMinSizeSubarraySum, 209, DIFFI_MEDIUM, TOPIC_ALGORITHMS,
    "Minimum Size Subarray Sum",
    "Given an array of positive integers nums and a positive integer target, "
    "return the minimal length of a subarray whose sum is greater than or "
    "equal to target. If there is no such subarray, return 0 instead.",
    {""});

class SMinSizeSubarraySum : public ISolution {
 public:
  size_t problemId() const override { return 209; }
  string name() const override {
    return ("Solution for " + string("Minimum Size Subarray Sum"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelper<pair<int, vector<int>>, int>(
        {{7, {2, 3, 1, 2, 4, 3}},
         {4, {1, 4, 4}},
         {11, {1, 1, 1, 1, 1, 1, 1, 1}}},
        {2, 1, 0}, [this](auto input) {
          return this->minSubArrayLen(input.first, input.second);
        });
  };
  int benchmark() const override { return 0; }

 private:
  int minSubArrayLen(int target, vector<int>& nums) const {}
};
