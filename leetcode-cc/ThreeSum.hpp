#include <algorithm>
#include <utility>

#include "problem.h"
#include "solution.h"

using namespace std;

class PThreeSum : public IProblem {
  size_t id() const override { return 15; }
  int difficulty() const override { return DIFFI_MEDIUM; }
  int topic() const override { return TOPIC_ALGORITHMS; }
  string title() const override { return "3Sum"; }
  string description() const override { return ""; }
  vector<string> labels() const override { return {"Array", "DP"}; }
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
                          this->compareVectors)) {
        return 1;
      }
    }

    return 0;
  }
  int benchmark() const override { return 0; }

 private:
  vector<vector<int>> threeSum(const vector<int>& nums) const {}
  static bool compareVectors(const vector<int>& v1, const vector<int>& v2) {
    if (v1.size() != v2.size()) {
      return false;
    }

    vector<int> sortedV1 = v1;
    vector<int> sortedV2 = v2;
    sort(sortedV1.begin(), sortedV1.end());
    sort(sortedV2.begin(), sortedV2.end());

    return sortedV1 == sortedV2;
  }
};
