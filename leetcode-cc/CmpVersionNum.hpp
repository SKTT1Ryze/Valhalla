#include <algorithm>
#include <queue>
#include <string>

#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(
    PCmpVersionNum, 165, DIFFI_MEDIUM, TOPIC_ALGORITHMS,
    "Compare Version Number",
    "Given two version numbers, version1 and version2, compare them.", {""});

class SCmpVersionNum : public ISolution {
 public:
  size_t problemId() const override { return 165; }
  string name() const override {
    return ("Solution for " + string("Compare Version Number"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelper<pair<string, string>, int>(
        {{"1.01", "1.001"},
         {"1.0", "1.0.0"},
         {"0.1", "1.1"},
         {"7.5.2.4", "7.5.3"}},
        {0, 0, -1, -1}, [this](auto input) {
          return this->compareVersion(input.first, input.second);
        });
  };
  int benchmark() const override { return 0; }

 private:
  int compareVersion(string version1, string version2) const {
    auto q1 = parseVersoin(version1);
    auto q2 = parseVersoin(version2);

    while (!q1.empty() && !q2.empty()) {
      auto e1 = q1.front();
      auto e2 = q2.front();

      if (e1 != e2) {
        return e1 > e2 ? 1 : -1;
      } else {
        q1.pop();
        q2.pop();
      }
    }

    return checkNonZero(q1) ? 1 : checkNonZero(q2) ? -1 : 0;
  }

  static queue<int> parseVersoin(const string& version) {
    queue<int> q = {};
    string s = "";

    for (const auto& ch : version) {
      if (ch == '.') {
        q.push(stoi(s));
        s = "";
      } else {
        s.push_back(ch);
      }
    }

    if (s != "") q.push(stoi(s));

    return q;
  }

  static bool checkNonZero(queue<int>& q) {
    while (!q.empty()) {
      if (q.front() != 0) return true;
      q.pop();
    }
    return false;
  }
};
