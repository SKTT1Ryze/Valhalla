#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(
    PUniqueNumOfOccurrences, 1207, DIFFI_EASY, TOPIC_ALGORITHMS,
    "Unique Number of Occurrences",
    "Given an array of integers arr, return true if the number of occurrences "
    "of each value in the array is unique or false otherwise.",
    {""});

class SUniqueNumOfOccurrences : public ISolution {
 public:
  size_t problemId() const override { return 1207; }
  string name() const override {
    return ("Solution for " + string("Unique Number of Occurrences"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelper<vector<int>, bool>(
        {{1, 2, 2, 1, 1, 3}, {1, 2}, {-3, 0, 1, -3, 1, 1, 1, -3, 10, 0}},
        {true, false, true},
        [this](auto input) { return this->uniqueOccurrences(input); });
  };
  int benchmark() const override { return 0; }

 private:
  bool uniqueOccurrences(vector<int>& arr) const {}
};
