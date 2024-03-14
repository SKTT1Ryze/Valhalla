#include <queue>
#include <unordered_set>

#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(
    PUglyNumberII, 264, DIFFI_MEDIUM, TOPIC_ALGORITHMS, "Ugly Number II",
    "An ugly number is a positive integer whose prime factors are limited to "
    "2, 3, and 5. Given an integer n, return the nth ugly number.",
    {"Heap"});

class SUglyNumberII : public ISolution {
 public:
  size_t problemId() const override { return 264; }
  string name() const override {
    return ("Solution for " + string("Ugly Number II"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelper<int, int>({10, 1}, {12, 1}, [this](auto input) {
      return this->nthUglyNumber(input);
    });
  };
  int benchmark() const override { return 0; }

 private:
  int nthUglyNumber(int n) const {
    priority_queue<long, vector<long>, greater<long>> minHeap = {};
    unordered_set<long> memo = {};

    minHeap.push(1);
    memo.insert(1);

    long ugly = 0;

    while (n) {
      ugly = minHeap.top();
      minHeap.pop();

      for (const auto& num : {2, 3, 5}) {
        long newUgly = num * ugly;
        if (!memo.contains(newUgly)) {
          memo.insert(newUgly);
          minHeap.push(newUgly);
        }
      }

      n--;
    }

    return ugly;
  }
};
