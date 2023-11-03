#include <algorithm>
#include <set>
#include <unordered_set>
#include <utility>

#include "problem.h"
#include "solution.h"
#include "util.h"

using namespace std;

class PThreeSum : public IProblem {
  size_t id() const override { return 15; }
  int difficulty() const override { return DIFFI_MEDIUM; }
  int topic() const override { return TOPIC_ALGORITHMS; }
  string title() const override { return "3Sum"; }
  string description() const override { return ""; }
  vector<string> labels() const override { return {"Array", "Math"}; }
};

class SThreeSum : public ISolution {
 public:
  size_t problemId() const override { return 15; }
  string name() const override { return "Solution for 3Sum"; }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    auto testCases = {
        make_pair<vector<int>, vector<vector<int>>>({-1, 0, 1, 2, -1, -4},
                                                    {{-1, -1, 2}, {-1, 0, 1}}),
        make_pair<vector<int>, vector<vector<int>>>({0, 1, 1}, {}),
        make_pair<vector<int>, vector<vector<int>>>({0, 0, 0}, {{0, 0, 0}})};

    for (const auto& [nums, expect] : testCases) {
      auto output = this->threeSum(nums);

      if (expect.size() != output.size() ||
          !is_permutation(expect.begin(), expect.end(), output.begin(),
                          compareVectors)) {
        return 1;
      }
    }

    return 0;
  }
  int benchmark() const override { return 0; }

 private:
  vector<vector<int>> threeSum(const vector<int>& nums) const {
    // TODO: use the two pointer
    auto len = nums.size();
    if (len < 3) {
      return {};
    }
    unordered_set<int> map = {};
    set<vector<int>> res = {};
    vector<vector<int>> output = {};

    auto sortedNums = nums;
    sort(sortedNums.begin(), sortedNums.end());
    vector<int> prev = {};

    for (int i = 0; i < len - 1; i++) {
      for (int j = i + 1; j < len; j++) {
        auto left = 0 - sortedNums[i] - sortedNums[j];

        if (map.contains(left)) {
          vector<int> v = {sortedNums[i], sortedNums[j], left};

          res.insert(v);
        }
      }
      map.insert(sortedNums[i]);
    }

    for (const auto& v : res) output.push_back(v);

    return output;
  }
};
