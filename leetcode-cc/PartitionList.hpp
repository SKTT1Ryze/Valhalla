#include <tuple>

#include "LinkList.h"
#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(
    PPartitionList, 86, DIFFI_MEDIUM, TOPIC_ALGORITHMS, "Partition List",
    "Given the head of a linked list and a value x, partition it such that all "
    "nodes less than x come before nodes greater than or equal to x.",
    {"Link List"});

class SPartitionList : public ISolution {
 public:
  size_t problemId() const override { return 86; }
  string name() const override { return "Solution for Partition List"; }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    auto testCases = {
        make_tuple(vector({1, 4, 3, 2, 5, 2}), 3, vector({1, 2, 2, 4, 3, 5})),
        make_tuple(vector({2, 1}), 2, vector({1, 2}))};

    for (const auto& [v, x, expect] : testCases) {
      auto head = vectorToLinkList(v);
      auto output = this->partition(head, x);
      if (!output->compVector(expect)) return 1;
    }

    return 0;
  };
  int benchmark() const override { return 0; }

 private:
  ListNode* partition(ListNode* head, int x) const {}
};
