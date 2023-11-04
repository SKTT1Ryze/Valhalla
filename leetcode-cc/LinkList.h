#pragma once
#include <stdexcept>
#include <vector>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}

  bool compVector(const std::vector<int> &v) {
    auto p = this;

    for (const auto &e : v) {
      if (e != p->val) return false;
      p = p->next;
    }

    return true;
  }
};

ListNode *vectorToLinkList(const std::vector<int> &v);
void freeLinkList(ListNode *head);
