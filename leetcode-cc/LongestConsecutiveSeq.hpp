#include <algorithm>

#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(PLongestConsecutiveSeq, 128, DIFFI_MEDIUM,
                        TOPIC_ALGORITHMS, "Longest Consecutive Sequence",
                        "Given an unsorted array of integers nums, return the "
                        "length of the longest consecutive elements sequence.",
                        {"Two Pointer"});

class SLongestConsecutiveSeq : public ISolution {
 public:
  size_t problemId() const override { return 128; }
  string name() const override {
    return ("Solution for " + string("Longest Consecutive Sequence"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelper<vector<int>, int>(
        {{100, 4, 200, 1, 3, 2}, {0, 3, 7, 2, 5, 8, 4, 6, 0, 1}, {1, 2, 0, 1}},
        {4, 9, 3},
        [this](auto input) { return this->longestConsecutive(input); });
  };
  int benchmark() const override { return 0; }

 private:
  int longestConsecutive(vector<int>& nums) const {
    int n = nums.size();
    if (n == 0 || n == 1) return n;

    int ans = 0;
    sort(nums.begin(), nums.end());

    int start = 0;
    while (start < n - 1) {
      int end = start + 1;
      int len = 1;
      while (end < n) {
        if (nums[end] - nums[start] == len) {
          len++;
          end++;
        } else if (nums[end] == nums[end - 1]) {
          end++;
        } else {
          break;
        }
      }

      ans = max(ans, len);
      start = end;
    }

    return ans;
  }
};
