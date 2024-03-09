#include <unordered_map>

#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(PTwoSumIIInputArraySorted, 167, DIFFI_MEDIUM,
                        TOPIC_ALGORITHMS, "Two Sum II - Input Array Is Sorted",
                        "", {"Hash Table"});

class STwoSumIIInputArraySorted : public ISolution {
 public:
  size_t problemId() const override { return 167; }
  string name() const override {
    return ("Solution for " + string("Two Sum II - Input Array is Sorted"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelper<pair<vector<int>, int>, vector<int>>(
        {{{2, 7, 11, 15}, 9}, {{2, 3, 4}, 6}, {{-1, 0}, -1}},
        {{1, 2}, {1, 3}, {1, 2}},
        [this](auto input) { return this->twoSum(input.first, input.second); });
  };
  int benchmark() const override { return 0; }

 private:
  vector<int> twoSum(vector<int>& numbers, int target) const {
    unordered_map<int, int> map = {};

    for (int i = 0; i < numbers.size(); i++) {
      int current = numbers[i];
      int left = target - current;
      if (map.contains(left)) {
        return {map[left] + 1, i + 1};
      } else {
        map.insert({current, i});
      }
    }

    return {};
  }
};
