#include <unordered_map>

#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(PTupleWithSameProduct, 1726, DIFFI_MEDIUM,
                        TOPIC_ALGORITHMS, "Tuple with Same Product", "", {""});

class STupleWithSameProduct : public ISolution {
 public:
  size_t problemId() const override { return 1726; }
  string name() const override {
    return ("Solution for " + string("Tuple with Same Product"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override { return 0; };
  int benchmark() const override { return 0; }

 private:
  int tupleSameProduct(vector<int> &nums) {
    unordered_map<int, int> memo = {};
    int n = nums.size();
    int ans = 0;

    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        int product = nums[i] * nums[j];

        ans += memo[product] * 8;

        memo[product]++;
      }
    }

    return ans;
  }
};
