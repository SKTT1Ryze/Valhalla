#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(PSortList, 148, DIFFI_MEDIUM, TOPIC_ALGORITHMS,
                        "Sort List",
                        "Given the head of a linked list, return the list "
                        "after sorting it in ascending order.",
                        {"Linkded List"});

class SSortList : public ISolution {
 public:
  size_t problemId() const override { return 148; }
  string name() const override {
    return ("Solution for " + string("Sort List"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelperLinkList(
        {{4, 2, 1, 3}, {-1, 5, 3, 4, 0}}, {{1, 2, 3, 4}, {-1, 0, 3, 4, 5}},
        [this](auto head) { return this->sortList(head); });
  };
  int benchmark() const override { return 0; }

 private:
  ListNode* sortList(ListNode* head) const {
    if (!head || !head->next) return head;
    auto middle = findMiddle(head);
    auto left = this->sortList(head);
    auto right = this->sortList(middle);
    return merge(left, right);
  }

  static ListNode* findMiddle(ListNode* head) {
    if (!head || !head->next) return head;
    auto slow = head;
    auto fast = head->next;

    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }

    auto middle = slow->next;
    slow->next = nullptr;

    return middle;
  }

  static ListNode* merge(ListNode* l1, ListNode* l2) {
    if (!l1) return l2;
    if (!l2) return l1;

    if (l1->val < l2->val) {
      l1->next = merge(l1->next, l2);
      return l1;
    } else {
      l2->next = merge(l1, l2->next);
      return l2;
    }
  }
};
