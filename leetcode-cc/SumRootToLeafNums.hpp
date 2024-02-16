#include <numeric>

#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(PSumRootToLeafNums, 129, DIFFI_MEDIUM, TOPIC_ALGORITHMS,
                        "Sum Root to Leaf Numbers", "", {"Binary Tree"});

class SSumRootToLeafNums : public ISolution {
 public:
  size_t problemId() const override { return 129; }
  string name() const override {
    return ("Solution for " + string("Sum Root to Leaf Numbers"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelperBinaryTreeV2<int>(
        {"[1,2,3]", "[4,9,0,5,1]"}, {25, 1026},
        [this](auto root) { return this->sumNumbers(root); });
  };
  int benchmark() const override { return 0; }

 private:
  int sumNumbers(TreeNode* root) const {
    vector<int> paths = {};

    this->dfs(root, 0, paths);

    return accumulate(paths.begin(), paths.end(), 0);
  }

  void dfs(TreeNode* root, int current, vector<int>& paths) const {
    if (root != nullptr) {
      int path = current * 10 + root->val;

      if (!root->left && !root->right) {
        paths.push_back(path);
      } else {
        this->dfs(root->left, path, paths);
        this->dfs(root->right, path, paths);
      }
    }
  }
};
