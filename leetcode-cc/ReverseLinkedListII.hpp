#include <tuple>

#include "LinkList.h"
#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

#define ID 92
#define NAME "Reverse Linked List II"

IMPLEMENT_PROBLEM_CLASS(PReverseLinkedListII, ID, DIFFI_MEDIUM,
                        TOPIC_ALGORITHMS, NAME, "", {"Linked List"});

class SReverseLinkedListII : public ISolution {
 public:
  size_t problemId() const override { return ID; }
  string name() const override { return ("Solution for " + string(NAME)); }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    auto testCases = {make_tuple(vector<int>({1, 2, 3, 4, 5}), 2, 4,
                                 vector<int>({1, 4, 3, 2, 5}))};

    for (const auto& [v, left, right, expect] : testCases) {
      auto head = vectorToLinkList(v);
      auto output = this->reverseBetween(head, left, right);

      if (!output->compVector(expect)) return 1;
    }

    return 0;
  };
  int benchmark() const override { return 0; }

 private:
  ListNode* reverseBetween(ListNode* head, int left, int right) const {}
};
