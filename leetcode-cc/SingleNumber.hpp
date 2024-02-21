#include <unordered_set>

#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(
    PSingleNumber, 136, DIFFI_EASY, TOPIC_ALGORITHMS, "Single Number",
    "Given a non-empty array of integers nums, every element appears twice "
    "except for one. Find that single one.",
    {"Hash Table"});

class SSingleNumber : public ISolution {
 public:
  size_t problemId() const override { return 136; }
  string name() const override {
    return ("Solution for " + string("Single Number"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelper<vector<int>, int>(
        {{2, 2, 1}, {4, 1, 2, 1, 2}, {1}}, {1, 4, 1},
        [this](auto input) { return this->singleNumber(input); });
  };
  int benchmark() const override { return 0; }

 private:
  int singleNumber(vector<int>& nums) const {
    unordered_set<int> set = {};

    for (const auto& num : nums) {
      if (set.contains(num)) {
        set.erase(num);
      } else {
        set.insert(num);
      }
    }

    return *set.begin();
  }
};
