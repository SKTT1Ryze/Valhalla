#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(PKthLargestElement, 215, DIFFI_MEDIUM, TOPIC_ALGORITHMS,
                        "Kth Largest Element in an Array",
                        "Given an integer array nums and an integer k, return "
                        "the kth largest element in the array.",
                        {"Heap"});

class SKthLargestElement : public ISolution {
 public:
  size_t problemId() const override { return 215; }
  string name() const override {
    return ("Solution for " + string("Kth Largest Element in an Array"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelper<pair<vector<int>, int>, int>(
        {{{3, 2, 1, 5, 6, 4}, 2}, {{3, 2, 3, 1, 2, 4, 5, 5, 6}, 4}}, {5, 4},
        [this](auto input) {
          return this->findKthLargest(input.first, input.second);
        });
  };
  int benchmark() const override { return 0; }

 private:
  int findKthLargest(vector<int>& nums, int k) const {}
};
