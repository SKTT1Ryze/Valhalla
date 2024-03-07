#include <algorithm>

#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(PFindPeakElement, 162, DIFFI_MEDIUM, TOPIC_ALGORITHMS,
                        "Find Peak Element", "", {"Array"});

class SFindPeakElement : public ISolution {
 public:
  size_t problemId() const override { return 162; }
  string name() const override {
    return ("Solution for " + string("Find Peak Element"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelper<vector<int>, int>(
        {{1, 2, 3, 1}, {1, 2, 1, 3, 5, 6, 4}}, {2, 1},
        [this](auto input) { return this->findPeakElement(input); });
  };
  int benchmark() const override { return 0; }

 private:
  int findPeakElement(vector<int>& nums) const {
    int n = nums.size();
    if (n == 1) return 0;
    if (n == 2) return nums[0] < nums[1] ? 1 : 0;

    if (nums[0] > nums[1]) {
      return 0;
    }

    int prev = 0;
    int current = 1;
    int next = 2;

    while (next <= n) {
      if (next == n) {
        return nums[prev] < nums[current] ? current : prev;
      } else if (nums[prev] < nums[current] && nums[next] < nums[current]) {
        return current;
      } else {
        prev++;
        current++;
        next++;
      }
    }

    return -1;
  }
};
