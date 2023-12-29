#include "LinkList.h"
#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(
    PRemoveDuplicatesFromSortedList, 83, DIFFI_EASY, TOPIC_ALGORITHMS,
    "Remove Duplicates from Sorted List",
    "Given the head of a sorted linked list, delete all duplicates such that "
    "each element appears only once. Return the linked list sorted as well.",
    {"Link List"});

class SRemoveDuplicatesFromSortedList : public ISolution {
 public:
  size_t problemId() const override { return 83; }
  string name() const override {
    return "Solution for Remove Duplicates from Sorted List";
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelperLinkList(
        {{1, 1, 2}, {1, 1, 2, 3, 3}}, {{1, 2}, {1, 2, 3}},
        [this](auto head) { return this->deleteDuplicates(head); });
  };
  int benchmark() const override { return 0; }

 private:
  ListNode* deleteDuplicates(ListNode* head) const {}
};
