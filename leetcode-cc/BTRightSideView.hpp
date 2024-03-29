#include <stack>

#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(PBTRightSideView, 199, DIFFI_MEDIUM, TOPIC_ALGORITHMS,
                        "Binary Tree Right Side View",
                        "Given the root of a binary tree, imagine yourself "
                        "standing on the right side of it, return the values "
                        "of the nodes you can see ordered from top to bottom.",
                        {"Binary Tree"});

class SBTRightSideView : public ISolution {
 public:
  size_t problemId() const override { return 199; }
  string name() const override {
    return ("Solution for " + string("Binary Tree Right Side View"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelperBinaryTreeV2<vector<int>>(
        {"[1,2,3,null,5,null,4]", "[1,null,3]", "[]", "[1,2,3,null,5,6]"},
        {{1, 3, 4}, {1, 3}, {}, {1, 3, 6}},
        [this](auto root) { return this->rightSideView(root); });
  };
  int benchmark() const override { return 0; }

 private:
  vector<int> rightSideView(TreeNode* root) const {
    stack<pair<TreeNode*, int>> s = {};
    int maxLevel = 0;
    int currentLevel = 1;
    auto node = root;
    vector<int> res = {};

    while (node || !s.empty()) {
      if (node) {
        if (currentLevel > maxLevel) {
          res.push_back(node->val);
          maxLevel++;
        }
        s.push({node, currentLevel});
        node = node->right;
        currentLevel++;
      } else {
        auto e = s.top();
        s.pop();
        node = e.first;
        currentLevel = e.second;

        node = node->left;
        currentLevel++;
      }
    }

    return res;
  }
};
