#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(PPerfectSquares, 279, DIFFI_MEDIUM, TOPIC_ALGORITHMS,
                        "Perfect Squares",
                        "Given an integer n, return the least number of "
                        "perfect square numbers that sum to n.",
                        {"Math"});

class SPerfectSquares : public ISolution {
 public:
  size_t problemId() const override { return 279; }
  string name() const override {
    return ("Solution for " + string("Perfect Squares"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelper<int, int>({12, 13}, {3, 2}, [this](auto input) {
      return this->numSquares(input);
    });
  };
  int benchmark() const override { return 0; }

 private:
  int numSquares(int n) const {}
};
