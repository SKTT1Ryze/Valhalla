#include <utility>

#include "LinkList.h"
#include "problem.h"
#include "solution.h"

using namespace std;

class PMergeKSortedLists : public IProblem {
  size_t id() const override { return 23; }
  int difficulty() const override { return DIFFI_HARD; }
  int topic() const override { return TOPIC_ALGORITHMS; }
  string title() const override { return "Merge K Sorted Lists"; }
  string description() const override { return ""; }
  vector<string> labels() const override { return {"Link List"}; }
};

class SMergeKSortedLists : public ISolution {
 public:
  size_t problemId() const override { return 23; }
  string name() const override { return "Solution for Merge K Sorted Lists"; }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    auto testCases = {
        make_pair<vector<vector<int>>, vector<int>>(
            {{1, 4, 5}, {1, 3, 4}, {2, 6}}, {1, 1, 2, 3, 4, 4, 5, 6}),
        make_pair<vector<vector<int>>, vector<int>>({{}}, {}),
        make_pair<vector<vector<int>>, vector<int>>({}, {}),
    };

    for (const auto& [lists, expect] : testCases) {
      vector<ListNode*> v = {};
      for (const auto& list : lists) {
        v.push_back(vectorToLinkList(list));
      }

      auto output = this->mergeKLists(v);

      if (!output->compVector(expect)) return 1;

      freeLinkList(output);
    }
    return 0;
  }
  int benchmark() const override { return 0; }

 private:
  ListNode* mergeKLists(vector<ListNode*>& lists) const {}
};
