#include <unordered_map>

#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(
    PMajorityElement, 169, DIFFI_EASY, TOPIC_ALGORITHMS, "Majority Element",
    "Given an array nums of size n, return the majority element. The majority "
    "element is the element that appears more than ⌊n / 2⌋ times. You may "
    "assume that the majority element always exists in the array.",
    {"Hash Table"});

class SMajorityElement : public ISolution {
 public:
  size_t problemId() const override { return 169; }
  string name() const override {
    return ("Solution for " + string("Majority Element"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelper<vector<int>, int>(
        {{3, 2, 3}, {2, 2, 1, 1, 1, 2, 2}}, {3, 2},
        [this](auto input) { return this->majorityElement(input); });
  };
  int benchmark() const override { return 0; }

 private:
  int majorityElement(vector<int>& nums) const {
    unordered_map<int, int> map = {};

    for (const auto& num : nums) {
      map[num]++;
    }

    int res = 0;
    int majority = INT_MIN;
    for (const auto& [k, v] : map) {
      if (v > majority) {
        res = k;
        majority = v;
      }
    }

    return res;
  }
};
