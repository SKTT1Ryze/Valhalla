#include <unordered_map>

#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(PSingleNumberII, 137, DIFFI_MEDIUM, TOPIC_ALGORITHMS,
                        "Single Number II",
                        "Given an integer array nums where every element "
                        "appears three times except for one, which appears "
                        "exactly once. Find the single element and return it.",
                        {"Hash Table"});

class SSingleNumberII : public ISolution {
 public:
  size_t problemId() const override { return 137; }
  string name() const override {
    return ("Solution for " + string("Single Number II"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelper<vector<int>, int>(
        {{2, 2, 3, 2}, {0, 1, 0, 1, 0, 1, 99}}, {3, 99},
        [this](auto input) { return this->singleNumber(input); });
  };
  int benchmark() const override { return 0; }

 private:
  int singleNumber(vector<int>& nums) const {
    unordered_map<int, int> map = {};

    for (const auto& num : nums) {
      map[num]++;
    }

    for (auto it = map.begin(); it != map.end(); it++) {
      if (it->second == 1) return it->first;
    }

    return 0;
  }
};
