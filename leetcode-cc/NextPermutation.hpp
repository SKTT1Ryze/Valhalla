#include <algorithm>

#include "problem.h"
#include "solution.h"

using namespace std;

class PNextPermutation : public IProblem {
  size_t id() const override { return 31; }
  int difficulty() const override { return DIFFI_MEDIUM; }
  int topic() const override { return TOPIC_ALGORITHMS; }
  string title() const override { return "Next Permutation"; }
  string description() const override { return ""; }
  vector<string> labels() const override { return {"Array"}; }
};

class SNextPermutation : public ISolution {
 public:
  size_t problemId() const override { return 31; }
  string name() const override { return "Solution for Next Permutation"; }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    vector<pair<vector<int>, vector<int>>> testCases = {
        make_pair<vector<int>, vector<int>>({1, 2, 3}, {1, 3, 2}),
        make_pair<vector<int>, vector<int>>({3, 2, 1}, {1, 2, 3}),
        make_pair<vector<int>, vector<int>>({1, 1, 5}, {1, 5, 1}),
        make_pair<vector<int>, vector<int>>({2, 3, 1}, {3, 1, 2}),
    };

    for (auto& [nums, expect] : testCases) {
      this->nextPermutation(nums);

      if (nums != expect) return 1;
    }

    return 0;
  }
  int benchmark() const override { return 0; }

 private:
  void nextPermutation(vector<int>& nums) const {
    if (nums.empty() || nums.size() == 1) return;
    int i = nums.size() - 1;

    while (i > 0) {
      int j = i - 1;
      while (j >= 0) {
        if (nums[i] > nums[j]) {
          int temp = nums.at(i);
          nums.erase(nums.begin() + i);
          nums.insert(nums.begin() + j, temp);
          sort(nums.begin() + j + 1, nums.end());
          return;
        }
        j--;
      }
      i--;
    }

    sort(nums.begin(), nums.end());
  }
};
