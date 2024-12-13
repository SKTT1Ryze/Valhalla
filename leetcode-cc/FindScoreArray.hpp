#include <climits>

#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(
    PFindScoreArray, 2593, DIFFI_MEDIUM, TOPIC_ALGORITHMS,
    "Find Score of an Array After Marking All Elements",
    "Return the score you get after applying the above algorithm.", {"Map"});

class SFindScoreArray : public ISolution {
 public:
  size_t problemId() const override { return 2593; }
  string name() const override {
    return ("Solution for " +
            string("Find Score of an Array After Marking All Elements"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    vector<int> nums = {2, 1, 3, 4, 5, 2};
    auto score = this->findScore(nums);

    return (1 - (score == 7));
  };
  int benchmark() const override { return 0; }

  long long findScore(vector<int> &nums) const {
    auto length = nums.size();
    vector<bool> marked(length);
    long long score = 0;

    vector<pair<int, int>> sorted;
    for (int i = 0; i < length; i++) sorted.push_back({nums[i], i});

    std::sort(sorted.begin(), sorted.end());

    for (int i = 0; i < length; i++) {
      int num = sorted[i].first;
      int idx = sorted[i].second;

      if (!marked[idx]) {
        score += num;

        marked[idx] = true;
        if (idx - 1 >= 0) marked[idx - 1] = true;
        if (idx + 1 < length) marked[idx + 1] = true;
      }
    }

    return score;
  }
};
