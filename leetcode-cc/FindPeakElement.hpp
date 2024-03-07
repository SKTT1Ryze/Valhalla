#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(PFindPeakElement, 162, DIFFI_MEDIUM, TOPIC_ALGORITHMS,
                        "Find Peak Element", "", {""});

class SFindPeakElement : public ISolution {
 public:
  size_t problemId() const override { return 162; }
  string name() const override {
    return ("Solution for " + string("Find Peak Element"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelper<vector<int>, int>(
        {{1, 2, 3, 1}, {1, 2, 1, 3, 5, 6, 4}}, {2, 5},
        [this](auto input) { return this->findPeakElement(input); });
  };
  int benchmark() const override { return 0; }

 private:
  int findPeakElement(vector<int>& nums) const {}
};
