#include <utility>

#include "TestHelper.h"
#include "problem.h"
#include "solution.h"
#include "util.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(PSubsetsII, 90, DIFFI_MEDIUM, TOPIC_ALGORITHMS,
                        "Subsets II", "", {"Backtracking"});

class SSubsetsII : public ISolution {
 public:
  size_t problemId() const override { return 90; }
  string name() const override { return "Solution for Subsets II"; }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    vector<pair<vector<int>, vector<vector<int>>>> testCases = {
        make_pair(
            vector<int>({1, 2, 2}),
            vector<vector<int>>({{}, {1}, {1, 2}, {1, 2, 2}, {2}, {2, 2}})),
        make_pair(vector<int>({0}), vector<vector<int>>({{}, {0}})),
    };

    for (auto& [nums, expect] : testCases) {
      auto output = this->subsetsWithDup(nums);
      for (int i = 0; i < output.size(); i++) {
        if (!compareVectors(output[i], expect[i])) return 1;
      }
      return 0;
    }
  };
  int benchmark() const override { return 0; }

 private:
  vector<vector<int>> subsetsWithDup(vector<int>& nums) const {}
};
