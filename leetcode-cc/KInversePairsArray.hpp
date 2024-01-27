#include <utility>

#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(PKInversePairsArray, 629, DIFFI_HARD, TOPIC_ALGORITHMS,
                        "K Inverse Pairs Array", "", {""});

class SKInversePairsArray : public ISolution {
 public:
  size_t problemId() const override { return 629; }
  string name() const override {
    return ("Solution for " + string("K Inverse Pairs Array"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelper<pair<int, int>, int>(
        {{3, 0}, {3, 1}}, {1, 2}, [this](auto input) {
          return this->kInversePairs(get<0>(input), get<1>(input));
        });
  };
  int benchmark() const override { return 0; }

 private:
  int kInversePairs(int n, int k) const {}
};
