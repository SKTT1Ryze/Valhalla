#include "BinaryTree.h"
#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(PSameTree, 100, DIFFI_EASY, TOPIC_ALGORITHMS,
                        "Same Tree",
                        "Given the roots of two binary trees p and q, write a "
                        "function to check if they are the same or not.",
                        {"Binary Tree"});

class SSameTree : public ISolution {
 public:
  size_t problemId() const override { return 100; }
  string name() const override {
    return ("Solution for " + string("Same Tree"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    auto p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);

    auto q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);

    return this->isSameTree(p, q) == true;
  };
  int benchmark() const override { return 0; }

 private:
  bool isSameTree(TreeNode* p, TreeNode* q) const {}
};
