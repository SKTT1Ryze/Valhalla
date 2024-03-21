#include <algorithm>

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
    return testHelper<int, int>({10, 0, 1}, {4, 0, 0}, [this](auto input) {
      return this->countPrimes(input);
    });
  };
  int benchmark() const override { return 0; }

 private:
  int countPrimes(int n) const {
    if (n < 2) return 0;
    vector<bool> v(n, true);
    v[0] = false;
    v[1] = false;

    for (int i = 2; i * i < n; i++) {
      if (v[i]) {
        for (int j = i * i; j < n; j += i) {
          v[j] = false;
        }
      }
    }

    return count_if(v.begin(), v.end(), [](bool e) { return e; });
  }
};
