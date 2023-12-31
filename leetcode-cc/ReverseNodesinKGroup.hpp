#include <tuple>

#include "LinkList.h"
#include "problem.h"
#include "solution.h"

using namespace std;

class PReverseNodesInKGroup : public IProblem {
  size_t id() const override { return 25; }
  int difficulty() const override { return DIFFI_HARD; }
  int topic() const override { return TOPIC_ALGORITHMS; }
  string title() const override { return "Reverse Nodes in k-Group"; }
  string description() const override { return ""; }
  vector<string> labels() const override { return {"Link List"}; }
};

class SReverseNodesInKGroup : public ISolution {
 public:
  size_t problemId() const override { return 25; }
  string name() const override {
    return "Solution for Reverse Nodes in k-Group";
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    auto testCases = {
        make_tuple<vector<int>, int, vector<int>>({1, 2, 3, 4, 5}, 2,
                                                  {2, 1, 4, 3, 5}),
        make_tuple<vector<int>, int, vector<int>>({1, 2, 3, 4, 5}, 3,
                                                  {3, 2, 1, 4, 5}),
    };

    for (const auto& [list, k, expect] : testCases) {
      auto head = vectorToLinkList(list);
      auto output = this->reverseKGroup(head, k);

      if (!output->compVector(expect)) return 1;

      freeLinkList(output);
    }

    return 0;
  }
  int benchmark() const override { return 0; }

 private:
  ListNode* reverseKGroup(ListNode* head, int k) const {
    auto res = new ListNode();
    auto p1 = res;

    while (head != nullptr) {
      bool longEnough = true;
      auto p = head;
      for (int i = 0; i < k; i++) {
        if (p == nullptr) {
          longEnough = false;
          break;
        }
        p = p->next;
      }

      if (longEnough) {
        auto tail = head;
        ListNode* p2 = nullptr;

        for (int i = 0; i < k; i++) {
          if (head != nullptr) {
            auto temp = head->next;
            head->next = p2;
            p2 = head;
            head = temp;
          } else {
            break;
          }
        }

        p1->next = p2;
        p1 = tail;
      } else {
        p1->next = head;
        break;
      }
    }

    return res->next;
  }
};
