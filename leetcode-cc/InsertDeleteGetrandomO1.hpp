#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(PInsertDeleteGetrandO1, 380, DIFFI_MEDIUM,
                        TOPIC_ALGORITHMS, "Insert Delete GetRandom O(1)", "",
                        {""});

class SInsertDeleteGetrandO1 : public ISolution {
 public:
  size_t problemId() const override { return 380; }
  string name() const override {
    return ("Solution for " + string("Insert Delete GetRandom O(1)"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override { return 0; };
  int benchmark() const override { return 0; }
};

class RandomizedSet {
 public:
  RandomizedSet() {}

  bool insert(int val) {}

  bool remove(int val) {}

  int getRandom() {}
};
