#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(
    PConvertSortedArrayToBST, 108, DIFFI_EASY, TOPIC_ALGORITHMS,
    "Convert Sorted Array to Binary Search Tree",
    "Given an integer array nums where the elements are sorted in ascending "
    "order, convert it to a height-balanced binary search tree",
    {"Binary Tree"});

class SConvertSortedArrayToBST : public ISolution {
 public:
  size_t problemId() const override { return 108; }
  string name() const override {
    return ("Solution for " +
            string("Convert Sorted Array to Binary Search Tree"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelperBinaryTreeV3<vector<int>>(
        {{-10, -3, 0, 5, 9}, {1, 3}}, {"[0,-3,9,-10,null,5]", "[3,1]"},
        [this](auto nums) { return this->sortedArrayToBST(nums); });
  };
  int benchmark() const override { return 0; }

 private:
  TreeNode* sortedArrayToBST(vector<int>& nums) const {
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
