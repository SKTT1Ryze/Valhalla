#include "problem.h"
#include "solution.h"

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
  RandNode* copyRandomList(RandNode* head) {}
};
