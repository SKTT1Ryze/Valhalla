#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(
    PRemoveLinkedListElements, 203, DIFFI_EASY, TOPIC_ALGORITHMS,
    "Remove Linked List Elements",
    "Given the head of a linked list and an integer val, remove all the nodes "
    "of the linked list that has Node.val == val, and return the new head.",
    {"Linked List"});

class SRemoveLinkedListElements : public ISolution {
 public:
  size_t problemId() const override { return 203; }
  string name() const override {
    return ("Solution for " + string("Remove Linked List Elements"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    auto head = vectorToLinkList({1, 2, 6, 3, 4, 5, 6});
    auto output = this->removeElements(head, 6);
    if (output->compVector({1, 2, 3, 4, 5})) {
      return 0;
    } else {
      return 1;
    }
  };
  int benchmark() const override { return 0; }

 private:
  ListNode* removeElements(ListNode* head, int val) const {
    auto newHead = new ListNode();
    newHead->next = head;
    auto prev = newHead;
    auto curr = head;

    while (curr) {
      if (curr->val == val) {
        prev->next = curr->next;
        curr = curr->next;
      } else {
        prev = prev->next;
        curr = curr->next;
      }
    }

    return newHead->next;
  }
};
