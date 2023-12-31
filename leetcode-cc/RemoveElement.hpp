#include <algorithm>
#include <tuple>

#include "problem.h"
#include "solution.h"
#include "util.hpp"

using namespace std;

class PRemoveElement : public IProblem {
 public:
  std::size_t id() const override { return 27; }
  int difficulty() const override { return DIFFI_EASY; }
  int topic() const override { return TOPIC_ALGORITHMS; }
  std::string title() const override { return "Remove Element"; }
  std::string description() const override { return ""; }
  std::vector<std::string> labels() const override {
    return {"Array", "In Place"};
  }
};

class SRemoveElement : public ISolution {
 public:
  std::size_t problemId() const override { return 27; }
  std::string name() const override { return "Solution for Remove Element"; }
  std::string location() const override { return __FILE_NAME__; }
  int test() const override {
    vector<tuple<vector<int>, int, vector<int>>> testCases = {
        make_tuple<vector<int>, int, vector<int>>({3, 2, 2, 3}, 3, {2, 2}),
        make_tuple<vector<int>, int, vector<int>>({0, 1, 2, 2, 3, 0, 4, 2}, 2,
                                                  {0, 1, 4, 0, 3}),
    };

    for (auto& [nums, val, expect] : testCases) {
      auto output = this->removeElement(nums, val);
      vector<int> subNums = {};
      for (auto it = nums.begin(); it != nums.begin() + output; ++it)
        subNums.push_back(*it);

      if (output != expect.size() || !compareVectors(subNums, expect)) return 1;
    }
    return 0;
  }
  int benchmark() const override { return 0; }

 private:
  int removeElement(vector<int>& nums, int val) const {
    if (nums.empty()) return 0;
    int head = 0;
    int tail = nums.size() - 1;

    while (head < tail) {
      if (nums[head] == val) {
        while (tail > head && nums[tail] == val) tail--;
        if (head == tail) return head;
        swap(nums[head], nums[tail]);
        tail--;
      }
      if ((tail - head) == 1 && nums[head] == val) break;
      head++;
    }

    return head + (nums[head] != val);
  }
};
