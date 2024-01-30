#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(
    PPathSum, 112, DIFFI_EASY, TOPIC_ALGORITHMS, "Path Sum",
    "Given the root of a binary tree and an integer targetSum, return true if "
    "the tree has a root-to-leaf path such that adding up all the values along "
    "the path equals targetSum.",
    {"Binary Tree"});

class SPathSum : public ISolution {
 public:
  size_t problemId() const override { return 112; }
  string name() const override {
    return ("Solution for " + string("Path Sum"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    auto root = buildTree("[5,4,8,11,null,13,4,7,2,null,null,null,1]");
    int targetSum = 22;

    if (!hasPathSum(root, targetSum)) return 1;

    return 0;
  };
  int benchmark() const override { return 0; }

 private:
  bool hasPathSum(TreeNode* root, int targetSum) const {
    if (root == nullptr) return false;
    return this->walk(root, 0, targetSum);
  }

  bool walk(TreeNode* root, int current, int targetSum) const {
    current += root->val;
    if (root->left == nullptr && root->right == nullptr) {
      return current == targetSum;
    } else if (root->left == nullptr) {
      return this->walk(root->right, current, targetSum);
    } else if (root->right == nullptr) {
      return this->walk(root->left, current, targetSum);
    } else {
      return this->walk(root->left, current, targetSum) ||
             this->walk(root->right, current, targetSum);
    }
  }
};
