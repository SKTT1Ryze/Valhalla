#include <algorithm>
#include <climits>
#include <stack>

#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(PMinStack, 155, DIFFI_MEDIUM, TOPIC_ALGORITHMS,
                        "Min Stack",
                        "Design a stack that supports push, pop, top, and "
                        "retrieving the minimum element in constant time.",
                        {"Stack"});

class SMinStack : public ISolution {
 public:
  size_t problemId() const override { return 155; }
  string name() const override {
    return ("Solution for " + string("Min Stack"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override { return 0; };
  int benchmark() const override { return 0; }

 private:
  class MinStack {
   public:
    MinStack() {
      s = {};
      s.push({0, INT_MAX});
    }

    void push(int val) {
      int preMin = this->s.top().second;
      auto element = make_pair(val, min(val, preMin));
      this->s.push(element);
    }

    void pop() { this->s.pop(); }

    int top() { return this->s.top().first; }

    int getMin() { return this->s.top().second; }

   private:
    stack<pair<int, int>> s;
  };
};
