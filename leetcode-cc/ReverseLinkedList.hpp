#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(PReverseLinkedList, 206, DIFFI_EASY, TOPIC_ALGORITHMS,
                        "Reverse Linked List",
                        "Given the head of a singly linked list, reverse the "
                        "list, and return the reversed list.",
                        {"Linked List"});

class SReverseLinkedList : public ISolution {
 public:
  size_t problemId() const override { return 206; }
  string name() const override {
    return ("Solution for " + string("Reverse Linked List"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelperLinkList(
        {{1, 2, 3, 4, 5}, {1, 2}, {}}, {{5, 4, 3, 2, 1}, {2, 1}, {}},
        [this](auto head) { return this->reverseList(head); });
  };
  int benchmark() const override { return 0; }

 private:
  ListNode* reverseList(ListNode* head) const {
    auto newHead = new ListNode();
    newHead->next = head;
    auto p = head;
    ListNode* prev = nullptr;

    while (p && p->next) {
      newHead->next = p->next;
      p->next = prev;
      prev = p;
      p = newHead->next;
    }

    if (p) p->next = prev;

    return newHead->next;
  }
};
