#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(PReorderList, 143, DIFFI_MEDIUM, TOPIC_ALGORITHMS,
                        "Reorder List", "Reorder the linked list",
                        {"Linked List"});

class SReorderList : public ISolution {
 public:
  size_t problemId() const override { return 143; }
  string name() const override {
    return ("Solution for " + string("Reorder List"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    auto head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    this->reorderList(head);
    return 0;
  };
  int benchmark() const override { return 0; }

 private:
  void reorderList(ListNode *head) const {
    if (!head || !head->next) return;

    auto slow = head, fast = head;
    while (fast->next && fast->next->next) {
      slow = slow->next;
      fast = fast->next->next;
    }

    ListNode *prev = nullptr, *curr = slow->next, *temp;
    slow->next = nullptr;
    while (curr) {
      temp = curr->next;
      curr->next = prev;
      prev = curr;
      curr = temp;
    }

    auto first = head, second = prev;
    while (second) {
      auto nextFirst = first->next;
      auto nextSecond = second->next;
      first->next = second;
      second->next = nextFirst;
      first = nextFirst;
      second = nextSecond;
    }
  }
};
