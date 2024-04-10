#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(PContainsDuplicateIII, 220, DIFFI_HARD,
                        TOPIC_ALGORITHMS, "Contains Duplicate III", "", {""});

class SContainsDuplicateIII : public ISolution {
 public:
  size_t problemId() const override { return 220; }
  string name() const override {
    return ("Solution for " + string("Contains Duplicate III"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelper<tuple<vector<int>, int, int>, bool>(
        {{{1, 2, 3, 1}, 3, 0}, {{1, 5, 9, 1, 5, 9}, 2, 3}}, {true, false},
        [this](auto input) {
          return this->containsNearbyAlmostDuplicate(
              get<0>(input), get<1>(input), get<2>(input));
        });
  };
  int benchmark() const override { return 0; }

 private:
  bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff,
                                     int valueDiff) const {}
};
