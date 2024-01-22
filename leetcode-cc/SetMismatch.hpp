#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(PSetMisMatch, 645, DIFFI_EASY, TOPIC_ALGORITHMS,
                        "Set Mismatch", "", {""});

class SSetMisMatch : public ISolution {
 public:
  size_t problemId() const override { return 645; }
  string name() const override {
    return ("Solution for " + string("Set Mismatch"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelper<vector<int>, vector<int>>(
        {{1, 2, 2, 4}, {1, 1}}, {{2, 3}, {1, 2}},
        [this](auto input) { return this->findErrorNums(input); });
  };
  int benchmark() const override { return 0; }

 private:
  vector<int> findErrorNums(vector<int>& nums) const {}
};
