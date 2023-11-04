#include <tuple>

#include "LinkList.h"
#include "problem.h"
#include "solution.h"

using namespace std;

class PRemoveNthNode : public IProblem {
  size_t id() const override { return 19; }
  int difficulty() const override { return DIFFI_MEDIUM; }
  int topic() const override { return TOPIC_ALGORITHMS; }
  string title() const override { return "Remove Nth Node From End of List"; }
  string description() const override { return ""; }
  vector<string> labels() const override { return {"Link List"}; }
};

class SRemoveNthNode : public ISolution {
 public:
  size_t problemId() const override { return 19; }
  string name() const override {
    return "Solution for Remove Nth Node From End of List";
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    auto testCases = {
        make_tuple<vector<int>, int, vector<int>>({1, 2, 3, 4, 5}, 2,
                                                  {1, 2, 3, 5}),
        make_tuple<vector<int>, int, vector<int>>({1}, 1, {}),
        make_tuple<vector<int>, int, vector<int>>({1, 2}, 1, {1}),
    };

    for (const auto& [list, n, expect] : testCases) {
      auto head = vectorToLinkList(list);
      auto output = this->removeNthFromEnd(head, n);

      if (!output->compVector(expect)) return 1;
    }

    return 0;
  }
  int benchmark() const override { return 0; }

 private:
  ListNode* removeNthFromEnd(ListNode* head, int n) const { return head; }
};
