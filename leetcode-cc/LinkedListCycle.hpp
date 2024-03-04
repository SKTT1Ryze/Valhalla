#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(PLinkedListCycle, 141, DIFFI_EASY, TOPIC_ALGORITHMS,
                        "Linked List Cycle",
                        "Given head, the head of a linked list, determine if "
                        "the linked list has a cycle in it.",
                        {"Linked List"});

class SLinkedListCycle : public ISolution {
 public:
  size_t problemId() const override { return 141; }
  string name() const override {
    return ("Solution for " + string("Linked List Cycle"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    auto head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = head;

    auto result = this->hasCycle(head);
    return result ? 0 : 1;
  };
  int benchmark() const override { return 0; }

 private:
  bool hasCycle(ListNode *head) const {
    if (head == nullptr) return false;
    auto fast = head->next;
    auto slow = head;

    while (fast && slow) {
      if (fast == slow) return true;

      slow = slow->next;
      fast = fast->next;
      if (fast) fast = fast->next;
    }

    return false;
  }
};
