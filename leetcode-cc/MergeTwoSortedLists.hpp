#include <tuple>

#include "LinkList.h"
#include "problem.h"
#include "solution.h"

using namespace std;

class PMergeTwoSortedLists : public IProblem {
  size_t id() const override { return 21; }
  int difficulty() const override { return DIFFI_EASY; }
  int topic() const override { return TOPIC_ALGORITHMS; }
  string title() const override { return "Merge Two Sorted Lists"; }
  string description() const override { return ""; }
  vector<string> labels() const override { return {"Link List"}; }
};

class SMergeTwoSortedLists : public ISolution {
 public:
  size_t problemId() const override { return 21; }
  string name() const override { return "Solution for Merge Two Sorted Lists"; }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    auto testCases = {
        make_tuple<vector<int>, vector<int>, vector<int>>({1, 2, 4}, {1, 3, 4},
                                                          {1, 1, 2, 3, 4, 4}),
        make_tuple<vector<int>, vector<int>, vector<int>>({}, {}, {}),
        make_tuple<vector<int>, vector<int>, vector<int>>({}, {0}, {0}),
    };

    for (const auto& [l1, l2, expect] : testCases) {
      auto list1 = vectorToLinkList(l1);
      auto list2 = vectorToLinkList(l2);

      auto output = this->mergeTwoLists(list1, list2);

      if (!output->compVector(expect)) return 1;

      freeLinkList(output);
    }

    return 0;
  }
  int benchmark() const override { return 0; }

 private:
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) const {}
};
