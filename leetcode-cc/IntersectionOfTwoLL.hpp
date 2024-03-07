#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(
    PIntersectionOfTwoLL, 160, DIFFI_EASY, TOPIC_ALGORITHMS,
    "Intersection of Two Linked Lists",
    "Given the heads of two singly linked-lists headA and headB, return the "
    "node at which the two lists intersect. If the two linked lists have no "
    "intersection at all, return null.",
    {"Linked List"});

class SIntersectionOfTwoLL : public ISolution {
 public:
  size_t problemId() const override { return 160; }
  string name() const override {
    return ("Solution for " + string("Intersection of Two Linked Lists"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override { return 0; };
  int benchmark() const override { return 0; }

 private:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) const {}
};
