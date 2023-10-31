#include "problem.h"
#include "solution.h"

class PIntToRoman : public IProblem {
 public:
  std::size_t id() const override { return 12; }
  int difficulty() const override { return DIFFI_MEDIUM; }
  int topic() const override { return TOPIC_ALGORITHMS; }
  std::string title() const override { return "Integer to Romain"; }
  std::string description() const override { return ""; }
  std::vector<std::string> labels() const override {
    return {"Hash Map", "Math", "String"};
  }
};

class SIntToRoman : public ISolution {
 public:
  std::size_t problemId() const override { return 12; }
  std::string name() const override { return "Solution for Integer to Romain"; }
  std::string location() const override { return __FILE_NAME__; }
  int test() const override { return 0; }
  int benchmark() const override { return 0; }
};
