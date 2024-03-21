#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(PCountPrimes, 204, DIFFI_MEDIUM, TOPIC_ALGORITHMS,
                        "Count Primes",
                        "Given an integer n, return the number of prime "
                        "numbers that are strictly less than n.",
                        {"Math"});

class SCountPrimes : public ISolution {
 public:
  size_t problemId() const override { return 204; }
  string name() const override {
    return ("Solution for " + string("Count Primes"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelper<int, int>(
        {}, {}, [this](auto input) { return this->countPrimes(input); });
  };
  int benchmark() const override { return 0; }

 private:
  int countPrimes(int n) const {}
};
