#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(PRotateArray, 189, DIFFI_MEDIUM, TOPIC_ALGORITHMS,
                        "Rotate Array",
                        "Given an integer array nums, rotate the array to the "
                        "right by k steps, where k is non-negative.",
                        {"Array"});

class SRotateArray : public ISolution {
 public:
  size_t problemId() const override { return 189; }
  string name() const override {
    return ("Solution for " + string("Rotate Array"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    this->rotate(nums, k);
    if (nums == vector({5, 6, 7, 1, 2, 3, 4})) {
      return 0;
    } else {
      return 1;
    }
  };
  int benchmark() const override { return 0; }

 private:
  void rotate(vector<int>& nums, int k) const {
    
  }
};
