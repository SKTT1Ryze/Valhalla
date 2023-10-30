#include "problem.h"
#include "solution.h"

class PExample : public IProblem {
 public:
  std::size_t id() const override { return 0; }
  int difficulty() const override { return DIFFI_EASY; }
  int topic() const override { return TOPIC_ALGORITHMS; }
  std::string title() const override { return "Example"; }
  std::string description() const override { return "Example for leetcode-cc"; }
  std::vector<std::string> labels() const override {
    return {"Array", "String"};
  }
};

class SExample : public ISolution {
 public:
  std::size_t problemId() const override { return 0; }
  std::string name() const override { return "Solution for Example"; }
  std::string location() const override { return "example.cc"; }
  int test() const override { return 0; }
  int benchmark() const override { return 0; }
};