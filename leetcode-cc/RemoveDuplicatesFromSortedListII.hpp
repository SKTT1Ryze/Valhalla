#include "LinkList.h"
#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(
    PRemoveDuplicatesFromSortedListII, 82, DIFFI_MEDIUM, TOPIC_ALGORITHMS,
    "Remove Duplicates from Sorted List II",
    "Given the head of a sorted linked list, delete all nodes that have "
    "duplicate numbers, leaving only distinct numbers from the original list. "
    "Return the linked list sorted as well.",
    {"Link List"});

class SRemoveDuplicatesFromSortedListII : public ISolution {
 public:
  size_t problemId() const override { return 82; }
  string name() const override {
    return "Solution for Remove Duplicates from Sorted List II";
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelperLinkList(
        {{1, 2, 3, 3, 4, 4, 5}, {1, 1, 1, 2, 3}}, {{1, 2, 5}, {2, 3}},
        [this](auto head) { return this->deleteDuplicates(head); });
  };
  int benchmark() const override { return 0; }

 private:
  ListNode* deleteDuplicates(ListNode* head) const {
    auto newHead = new ListNode;
    newHead->next = head;
    auto p1 = newHead;

    while (p1) {
      if (p1->next && p1->next->next) {
        if (p1->next->val == p1->next->next->val) {
          auto p2 = p1->next->next->next;
          while (p2) {
            if (p2->val != p1->next->val) {
              break;
            }
            p2 = p2->next;
          }

          p1->next = p2;
          continue;
        }
      }

      p1 = p1->next;
    }

    return newHead->next;
  }
};
