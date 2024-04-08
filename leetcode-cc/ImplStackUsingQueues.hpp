#include <queue>

#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(
    PImplStackUsingQueues, 225, DIFFI_EASY, TOPIC_ALGORITHMS,
    "Implement Stack using Queues",
    "Implement a last-in-first-out (LIFO) stack using only two queues. The "
    "implemented stack should support all the functions of a normal stack "
    "(push, top, pop, and empty).",
    {"Stack"});

class SImplStackUsingQueues : public ISolution {
 public:
  size_t problemId() const override { return 225; }
  string name() const override {
    return ("Solution for " + string("Implement Stack Using Queues"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override { return 0; };
  int benchmark() const override { return 0; }

 private:
  class MyStack {
    queue<int> q1;
    queue<int> q2;

   public:
    MyStack() : q1(), q2() {}

    void push(int x) {
      q2.push(x);
      while (!q1.empty()) {
        q2.push(q1.front());
        q1.pop();
      }
      swap(q1, q2);
    }

    int pop() {
      if (q1.empty()) {
        return -1;
      } else {
        auto ans = q1.front();
        q1.pop();
        return ans;
      }
    }

    int top() { return q1.empty() ? -1 : q1.front(); }

    bool empty() { return q1.empty(); }
  };
};
