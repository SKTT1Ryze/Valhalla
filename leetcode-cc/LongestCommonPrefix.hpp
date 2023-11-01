#include "problem.h"
#include "solution.h"

class PLongestCommonPrefix : public IProblem {
  std::size_t id() const override { return 14; }
  int difficulty() const override { return DIFFI_EASY; }
  int topic() const override { return TOPIC_ALGORITHMS; }
  std::string title() const override { return "Longest Common Prefix"; }
  std::string description() const override { return ""; }
  std::vector<std::string> labels() const override { return {"String", "DP"}; }
};

class SLonestCommonPrefix : public ISolution {
 public:
  std::size_t problemId() const override { return 14; }
  std::string name() const override {
    return "Solution for Longest Common Prefix";
  }
  std::string location() const override { return __FILE_NAME__; }
  int test() const override {
    auto testCases = {std::make_pair<std::vector<std::string>, std::string>(
                          {"flower", "flow", "flight"}, "fl"),
                      std::make_pair<std::vector<std::string>, std::string>(
                          {"dog", "racecar", "car"}, "")};

    for (const auto& [strs, expect] : testCases) {
      auto output = this->longestCommonPrefix(strs);

      if (output != expect) {
        return 1;
      }
    }

    return 0;
  }
  int benchmark() const override { return 0; }

 private:
  std::string longestCommonPrefix(const std::vector<std::string>& strs) const {
    return "";
  }
};
