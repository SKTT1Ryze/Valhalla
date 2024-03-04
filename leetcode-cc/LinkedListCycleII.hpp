
#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(
    PLinkedListCycleII, 142, DIFFI_MEDIUM, TOPIC_ALGORITHMS,
    "Linked List Cycle II",
    "Given the head of a linked list, return the node where the cycle begins. "
    "If there is no cycle, return null.",
    {"Linked List"});

class SLinkedListCycleII : public ISolution {
 public:
  size_t problemId() const override { return 142; }
  string name() const override {
    return ("Solution for " + string("Linked List Cycle II"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override { return 0; };
  int benchmark() const override { return 0; }

 private:
  ListNode *detectCycle(ListNode *head) const {}
};
