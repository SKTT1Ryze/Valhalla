#include <algorithm>
#include <vector>

#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(
    PMyCalendarII, 731, DIFFI_MEDIUM, TOPIC_ALGORITHMS, "My Calendar II",
    "You are implementing a program to use as your calendar. We can add a new "
    "event if adding the event will not cause a triple booking.",
    {"Math"});

class SMyCalendarII : public ISolution {
 public:
  size_t problemId() const override { return 731; }
  string name() const override {
    return ("Solution for " + string("My Calendar II"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override { return 0; };
  int benchmark() const override { return 0; }

  class MyCalendarTwo {
   public:
    MyCalendarTwo() {}

    bool book(int start, int end) {
      for (const auto &[s, e] : doubled) {
        if (start < e && s < end) return false;
      }

      for (const auto &[s, e] : single) {
        if (start < e && s < end) {
          doubled.emplace_back(std::max(s, start), std::min(e, end));
        }
      }

      single.emplace_back(start, end);
      return true;
    }

   private:
    vector<pair<int, int>> single;
    vector<pair<int, int>> doubled;
  };
};
