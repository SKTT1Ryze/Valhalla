#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(
    PDeleteNodeInLinkedList, 237, DIFFI_MEDIUM, TOPIC_ALGORITHMS,
    "Delete Node In Linked List",
    "There is a singly-linked list head and we want to delete a node node in "
    "it. You are given the node to be deleted node. You will not be given "
    "access to the first node of head.",
    {"Linked List"});

class SDeleteNodeInLinkedList : public ISolution {
 public:
  size_t problemId() const override { return 237; }
  string name() const override {
    return ("Solution for " + string("Delete Node In Linked List"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override { return 0; };
  int benchmark() const override { return 0; }

 private:
  void deleteNode(ListNode* node) const {
    if (node != nullptr) {
      if (node->next) {
        node->val = node->next->val;

        if (node->next->next) {
          deleteNode(node->next);
        } else {
          node->next = nullptr;
        }
      }
    }
  }
};
