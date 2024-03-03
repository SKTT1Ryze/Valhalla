#include "problem.h"
#include "solution.h"
#include "unordered_map"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(PCopyListWithRandPointer, 138, DIFFI_MEDIUM,
                        TOPIC_ALGORITHMS, "Copy List With Rand Pointer", "",
                        {""});

class RandNode {
 public:
  int val;
  RandNode* next;
  RandNode* random;

  RandNode(int _val) {
    val = _val;
    next = NULL;
    random = NULL;
  }
};

class SCopyListWithRandPointer : public ISolution {
 public:
  size_t problemId() const override { return 138; }
  string name() const override {
    return ("Solution for " + string("Copy List With Rand Pointer"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override { return 0; };
  int benchmark() const override { return 0; }

 private:
  RandNode* copyRandomList(RandNode* head) {
    auto newHead = new RandNode(0);
    auto p1 = head;
    auto p2 = newHead;
    unordered_map<RandNode*, RandNode*> map = {};

    while (p1) {
      auto node = new RandNode(p1->val);
      p2->next = node;
      p2 = p2->next;
      map.insert({p1, p2});
      p1 = p1->next;
    }

    p1 = head;
    p2 = newHead->next;

    while (p1) {
      auto rand = map[p1->random];
      p2->random = rand;

      p1 = p1->next;
      p2 = p2->next;
    }

    return newHead->next;
  }
};
