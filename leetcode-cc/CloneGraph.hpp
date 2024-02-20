#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(PCloneGraph, 133, DIFFI_MEDIUM, TOPIC_ALGORITHMS,
                        "Clone Graph",
                        "Given a reference of a node in a connected undirected "
                        "graph. Return a deep copy (clone) of the graph.",
                        {"Graph"});

class GraphNode {
 public:
  int val;
  vector<GraphNode*> neighbors;
  GraphNode() {
    val = 0;
    neighbors = vector<GraphNode*>();
  }
  GraphNode(int _val) {
    val = _val;
    neighbors = vector<GraphNode*>();
  }
  GraphNode(int _val, vector<GraphNode*> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

class SCloneGraph : public ISolution {
 public:
  size_t problemId() const override { return 133; }
  string name() const override {
    return ("Solution for " + string("Clone Graph"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override { return 0; };
  int benchmark() const override { return 0; }

 private:
  GraphNode* cloneGraph(GraphNode* node) const {}
};
