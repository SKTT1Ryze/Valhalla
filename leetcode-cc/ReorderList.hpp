#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(PReorderList, 143, DIFFI_MEDIUM, TOPIC_ALGORITHMS,
                        "Reorder List", "Reorder the linked list",
                        {"Linked List"});

class SReorderList : public ISolution {
 public:
  size_t problemId() const override { return 143; }
  string name() const override {
    return ("Solution for " + string("Reorder List"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override { return 0; };
  int benchmark() const override { return 0; }

 private:
  void reorderList(ListNode* head) const {}
};
