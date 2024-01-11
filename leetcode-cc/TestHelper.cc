#include "TestHelper.h"

int testHelperLinkList(std::vector<std::vector<int>> Inputs,
                       std::vector<std::vector<int>> Expects,
                       std::function<ListNode*(ListNode*)> function) {
  int n = std::min(Inputs.size(), Expects.size());
  for (int i = 0; i < n; i++) {
    auto head = vectorToLinkList(Inputs[i]);
    auto output = function(head);
    if (!output->compVector(Expects[i])) return 1;
    freeLinkList(output);
  }

  return 0;
}

int testHelperBinaryTree(std::vector<std::string> Inputs,
                         std::vector<std::string> Expects,
                         std::function<void(TreeNode*)> function) {
  int n = std::min(Inputs.size(), Expects.size());
  for (int i = 0; i < n; i++) {
    auto root = buildTree(Inputs[i]);
    function(root);
    auto expect = buildTree(Expects[i]);

    if (!isSameTree(root, expect)) return 1;
  }
  return 0;
}
