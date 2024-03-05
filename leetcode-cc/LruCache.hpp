#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(PLRUCache, 146, DIFFI_MEDIUM, TOPIC_ALGORITHMS,
                        "LRU Cache",
                        "Design a data structure that follows the constraints "
                        "of a Least Recently Used (LRU) cache.",
                        {"LRU"});

class SLRUCache : public ISolution {
 public:
  size_t problemId() const override { return 146; }
  string name() const override {
    return ("Solution for " + string("LRU Cache"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override { return 0; };
  int benchmark() const override { return 0; }
};

class LRUCache {
 public:
  LRUCache(int capacity) {}

  int get(int key) {}

  void put(int key, int value) {}
};
