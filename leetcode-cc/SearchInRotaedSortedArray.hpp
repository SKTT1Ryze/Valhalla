#include <tuple>

#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(PSearchInRotatedSortedArray, 33, DIFFI_MEDIUM,
                        TOPIC_ALGORITHMS, "Search In Rotated Sorted Array", "",
                        {"Array"});

class SSearchInRotatedSortedArray : public ISolution {
 public:
  size_t problemId() const override { return 33; }
  string name() const override {
    return "Solution for Search In Rotated Sorted Array";
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelper<tuple<vector<int>, int>, int>(
        {{{4, 5, 6, 7, 0, 1, 2}, 0}}, {4}, [this](auto input) {
          return this->search(get<0>(input), get<1>(input));
        });
  };
  int benchmark() const override { return 0; }

 private:
  int search(const vector<int>& nums, int target) const {
    int m = 0;
    int n = nums.size() - 1;

    while (m <= n) {
      int k = (m + n) / 2;

      if (nums[k] == target) return k;

      if (nums[m] <= nums[k]) {
        // m..k is sorted
        if (nums[m] <= target && target < nums[k]) {
          n = k - 1;
        } else {
          m = k + 1;
        }
      } else {
        // k..n is sorted
        if (nums[k] < target && target <= nums[n]) {
          m = k + 1;
        } else {
          n = k - 1;
        }
      }
    }

    return -1;
  }
};
