#include "problem.h"
#include "solution.h"

class PThreeSum : public IProblem {
  std::size_t id() const override { return 15; }
  int difficulty() const override { return DIFFI_MEDIUM; }
  int topic() const override { return TOPIC_ALGORITHMS; }
  std::string title() const override { return "3Sum"; }
  std::string description() const override { return ""; }
  std::vector<std::string> labels() const override { return {"Array", "DP"}; }
};

class SThreeSum : public ISolution {
 public:
  std::size_t problemId() const override { return 15; }
  std::string name() const override { return "Solution for 3Sum"; }
  std::string location() const override { return __FILE_NAME__; }
  int test() const override { return 0; }
  int benchmark() const override { return 0; }
};
