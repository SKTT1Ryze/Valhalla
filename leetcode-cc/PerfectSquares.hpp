#include <queue>
#include <unordered_set>

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
  int numSquares(int n) const {
    queue<pair<int, int>> q = {};
    unordered_set<int> memo = {};

    q.push({0, 0});

    while (!q.empty()) {
      auto [val, step] = q.front();
      q.pop();

      if (val == n) return step;

      memo.insert({val, step});

      for (int i = 1; i * i + val <= n; i++) {
        auto nextVal = val + i * i;
        if (!memo.contains(nextVal)) q.push({nextVal, step + 1});
      }
    }

    return -1;
  }
};
