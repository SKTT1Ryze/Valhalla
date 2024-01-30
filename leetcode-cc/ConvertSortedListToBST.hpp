#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(
    PConvertSortedListToBST, 109, DIFFI_MEDIUM, TOPIC_ALGORITHMS,
    "Convert Sorted List to Binary Search Tree",
    "Given the head of a singly linked list where elements are sorted in "
    "ascending order, convert it to a height-balanced binary search tree.",
    {"Binary Tree"});

class SConvertSortedListToBST : public ISolution {
 public:
  size_t problemId() const override { return 109; }
  string name() const override {
    return ("Solution for " +
            string("Convert Sorted List to Binary Search Tree"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    auto head = vectorToLinkList({-10, -3, 0, 5, 9});
    auto root = this->sortedListToBST(head);

    if (!isSameTree(root, buildTree("[0,-3,9,-10,null,5]"))) return 1;

    return 0;
  };
  int benchmark() const override { return 0; }

 private:
  TreeNode* sortedListToBST(ListNode* head) const {
    vector<int> nums = {};
    auto p = head;
    while (p) {
      nums.push_back(p->val);
      p = p->next;
    }

    return this->build(nums, 0, nums.size());
  }

  TreeNode* build(vector<int>& nums, int start, int end) const {
    if (start >= end) return nullptr;
    int i = (start + end) / 2;
    auto root = new TreeNode(nums[i]);

    root->left = this->build(nums, start, i);
    root->right = this->build(nums, i + 1, end);

    return root;
  }
};
