#include <string>
#include <tuple>

#include "TestHelper.h"
#include "problem.h"
#include "solution.h"
#include "util.hpp"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(PRestoreIPAddresses, 93, DIFFI_MEDIUM, TOPIC_ALGORITHMS,
                        "Restore IP Addresses", "", {"Backtracking"});

class SRestoreIPAddresses : public ISolution {
 public:
  size_t problemId() const override { return 93; }
  string name() const override {
    return ("Solution for " + string("Restore IP Addresses"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    auto testCases = {
        make_tuple("25525511135",
                   vector<string>({"255.255.11.135", "255.255.111.35"})),
        make_tuple("0000", vector<string>({"0.0.0.0"})),
        make_tuple("101023",
                   vector<string>({"1.0.10.23", "1.0.102.3", "10.1.0.23",
                                   "10.10.2.3", "101.0.2.3"})),
    };

    for (const auto& [s, expect] : testCases) {
      auto output = this->restoreIpAddresses(s);

      if (!compareVectors(output, expect)) return 1;
    }

    return 0;
  };
  int benchmark() const override { return 0; }

 private:
  vector<string> restoreIpAddresses(string s) const {
    vector<std::string> result;
    string current;
    this->backtracking(s, 0, 0, current, result);
    return result;
  }

  void backtracking(const string& s, int start, int segment, string& current,
                    vector<string>& result) const {
    if (start == s.size() && segment == 4) {
      result.push_back(current);
      return;
    }

    for (int i = 1; i <= 3; ++i) {
      if (start + i > s.size()) {
        break;
      }

      string str = s.substr(start, i);
      int num = stoi(str);

      if (num >= 0 && num <= 255 && (i == 1 || str[0] != '0')) {
        string temp = current.empty() ? str : current + "." + str;
        this->backtracking(s, start + i, segment + 1, temp, result);
      }
    }
  }
};
