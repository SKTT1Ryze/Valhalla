#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

class Node {
 public:
  int val;
  Node* left;
  Node* right;
  Node* next;

  Node() : val(0), left(NULL), right(NULL), next(NULL) {}

  Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

  Node(int _val, Node* _left, Node* _right, Node* _next)
      : val(_val), left(_left), right(_right), next(_next) {}
};

IMPLEMENT_PROBLEM_CLASS(
    PPopulateNextRightPointers, 116, DIFFI_MEDIUM, TOPIC_ALGORITHMS,
    "Populating Next Right Pointers in Each Node",
    "Populate each next pointer to point to its next right node. If there is "
    "no next right node, the next pointer should be set to NULL.",
    {"Binary Tree"});

class SPopulateNextRightPointers : public ISolution {
 public:
  size_t problemId() const override { return 116; }
  string name() const override {
    return ("Solution for " +
            string("Populating Next Right Pointers in Each Node"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override { return 0; };
  int benchmark() const override { return 0; }

 private:
  Node* connect(Node* root) const {}
};
