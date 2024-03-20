#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(
    PHappyNumber, 202, DIFFI_EASY, TOPIC_ALGORITHMS, "Harry Number",
    "Write an algorithm to determine if a number n is happy.", {"Math"});

class SHappyNumber : public ISolution {
 public:
  size_t problemId() const override { return 202; }
  string name() const override {
    return ("Solution for " + string("Happy Number"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelper<int, bool>({19, 2}, {true, false}, [this](auto input) {
      return this->isHappy(input);
    });
  };
  int benchmark() const override { return 0; }

 private:
  bool isHappy(int n) const {}
};
