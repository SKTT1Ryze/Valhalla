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
        {}, {}, [this](auto head) { return this->insertionSortList(head); });
  };
  int benchmark() const override { return 0; }

 private:
  ListNode* insertionSortList(ListNode* head) const {}
};
