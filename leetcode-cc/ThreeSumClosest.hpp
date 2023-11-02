#include <tuple>

#include "problem.h"
#include "solution.h"

using namespace std;

class PThreeSumClosest : public IProblem {
  size_t id() const override { return 16; }
  int difficulty() const override { return DIFFI_MEDIUM; }
  int topic() const override { return TOPIC_ALGORITHMS; }
  string title() const override { return "3Sum Closest"; }
  string description() const override { return ""; }
  vector<string> labels() const override { return {"Array", "Math"}; }
};

class SThreeSumClosest : public ISolution {
 public:
  size_t problemId() const override { return 16; }
  string name() const override { return "Solution for 3Sum Closest"; }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    auto testCases = {
        make_tuple<vector<int>, int, int>({-1, 2, 1, -4}, 1, 2),
        make_tuple<vector<int>, int, int>({0, 0, 0}, 1, 0),
    };

    for (const auto& [nums, target, expect] : testCases) {
      auto output = this->threeSumClosest(nums, target);

      if (output != expect) return 1;
    }

    return 0;
  }
  int benchmark() const override { return 0; }

 private:
  int threeSumClosest(const vector<int>& nums, int target) const { return 0; }
};
