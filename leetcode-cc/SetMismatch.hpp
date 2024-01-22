#include <algorithm>
#include <unordered_set>

#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(PSetMisMatch, 645, DIFFI_EASY, TOPIC_ALGORITHMS,
                        "Set Mismatch", "", {"Math"});

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
  vector<int> findErrorNums(vector<int>& nums) const {
    int dup = -1, missing = -1;

    for (int i = 1; i <= nums.size(); i++) {
      int count = 0;
      for (int j = 0; j < nums.size(); j++) {
        if (nums[j] == i) {
          count++;
        }
      }
      if (count == 2) {
        dup = i;
      } else if (count == 0) {
        missing = i;
      }
    }

    return {dup, missing};
  }
};
