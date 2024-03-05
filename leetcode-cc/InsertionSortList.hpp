#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(
    PInsertionSortList, 147, DIFFI_MEDIUM, TOPIC_ALGORITHMS,
    "Insertion Sort List",
    "Given the head of a singly linked list, sort the list using insertion "
    "sort, and return the sorted list's head.",
    {"Linked List"});

class SInsertionSortList : public ISolution {
 public:
  size_t problemId() const override { return 147; }
  string name() const override {
    return ("Solution for " + string("Insertion Sort List"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelperLinkList(
        {{4, 2, 1, 3}, {-1, 5, 3, 4, 0}}, {{1, 2, 3, 4}, {-1, 0, 3, 4, 5}},
        [this](auto head) { return this->insertionSortList(head); });
  };
  int benchmark() const override { return 0; }

 private:
  ListNode* insertionSortList(ListNode* head) const {
    auto sortedHead = new ListNode(INT_MIN);
    sortedHead->next = head;
    auto p1 = head->next;
    head->next = nullptr;

    while (p1) {
      auto p2 = sortedHead;

      while (p2 && p2->next) {
        if (p2->val <= p1->val && p2->next->val >= p1->val) {
          break;
        }
        p2 = p2->next;
      }

      auto temp = p1->next;
      p1->next = p2->next;
      p2->next = p1;

      p1 = temp;
    }

    return sortedHead->next;
  }
};
