#include "LinkList.h"

ListNode* vectorToLinkList(const std::vector<int>& v) {
  if (v.empty()) {
    return nullptr;
  }
  ListNode* head = new ListNode(v[0]);
  ListNode* p = head;

  for (int i = 1; i < v.size(); i++) {
    p->next = new ListNode(v[i]);
    p = p->next;
  }

  return head;
}

void freeLinkList(ListNode* head) {
  while (head != nullptr) {
    ListNode* temp = head;
    head = head->next;
    delete temp;
  }
}
