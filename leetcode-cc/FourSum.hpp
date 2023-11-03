#include <tuple>

#include "problem.h"
#include "solution.h"
#include "util.h"

using namespace std;

class PFourSum : public IProblem {
  size_t id() const override { return 18; }
  int difficulty() const override { return DIFFI_MEDIUM; }
  int topic() const override { return TOPIC_ALGORITHMS; }
  string title() const override { return "4Sum"; }
  string description() const override { return ""; }
  vector<string> labels() const override { return {"Array", "Math"}; }
};

class SFourSum : public ISolution {
 public:
  size_t problemId() const override { return 18; }
  string name() const override { return "Solution for 4Sum"; }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    auto testCases = {
        std::make_tuple<vector<int>, int, vector<vector<int>>>(
            {1, 0, -1, 0, -2, 2}, 0,
            {{-2, -1, 1, 2}, {-2, 0, 0, 2}, {-1, 0, 0, 1}}),
        std::make_tuple<vector<int>, int, vector<vector<int>>>(
            {2, 2, 2, 2, 2}, 8, {{2, 2, 2, 2, 2}}),

    };

    for (const auto& [nums, target, expect] : testCases) {
      auto output = this->fourSum(nums, target);

      if (expect.size() != output.size() ||
          !is_permutation(expect.begin(), expect.end(), output.begin(),
                          compareVectors)) {
        return 1;
      }
    }

    return 0;
  };
  int benchmark() const override { return 0; }

 private:
  vector<vector<int>> fourSum(const vector<int>& nums, int target) const {}
};
