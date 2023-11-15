#include <tuple>

#include "problem.h"
#include "solution.h"

using namespace std;

class PSearchInRotatedSortedArray : public IProblem {
  size_t id() const override { return 33; }
  int difficulty() const override { return DIFFI_MEDIUM; }
  int topic() const override { return TOPIC_ALGORITHMS; }
  string title() const override { return "Search In Rotated Sorted Array"; }
  string description() const override { return ""; }
  vector<string> labels() const override { return {"Array"}; }
};

class SSearchInRotatedSortedArray : public ISolution {
 public:
  size_t problemId() const override { return 33; }
  string name() const override {
    return "Solution Search In Rotated Sorted Array";
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    auto testCases = {
        make_tuple<vector<int>, int, int>({4, 5, 6, 7, 0, 1, 2}, 0, 4)};

    for (const auto& [nums, target, expect] : testCases) {
      auto output = this->search(nums, target);

      if (output != expect) return 1;
    }
    return 0;
  };
  int benchmark() const override { return 0; }

 private:
  int search(const vector<int>& nums, int target) const {}
};
