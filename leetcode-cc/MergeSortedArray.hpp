#include <tuple>

#include "problem.h"
#include "solution.h"
#include "util.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(
    PMergeSortedArray, 88, DIFFI_EASY, TOPIC_ALGORITHMS, "Merge Sorted Array",
    "Merge nums1 and nums2 into a single array sorted in non-decreasing order.",
    {"Array"});

class SMergeSortedArray : public ISolution {
 public:
  size_t problemId() const override { return 88; }
  string name() const override { return "Solution for Merge Sorted Array"; }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    vector<tuple<vector<int>, int, vector<int>, int, vector<int>>> testCases = {
        make_tuple(vector<int>({1, 2, 3, 0, 0, 0}), 3, vector<int>({2, 5, 6}),
                   3, vector<int>({1, 2, 2, 3, 5, 6})),
        make_tuple(vector<int>({1}), 1, vector<int>({}), 0, vector<int>({1}))};

    for (auto& [nums1, m, nums2, n, expect] : testCases) {
      this->merge(nums1, m, nums2, n);
      if (!compareVectors(nums1, expect)) {
        return 1;
      }
    }
    return 0;
  }
  int benchmark() const override { return 0; }

 private:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) const {}
};
