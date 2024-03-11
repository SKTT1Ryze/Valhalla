#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(
    PExcelSheetColTitle, 168, DIFFI_EASY, TOPIC_ALGORITHMS,
    "Excel Sheet Column Title",
    "Given an integer columnNumber, return its corresponding column title as "
    "it appears in an Excel sheet.",
    {"Math"});

class SExcelSheetColTitle : public ISolution {
 public:
  size_t problemId() const override { return 168; }
  string name() const override {
    return ("Solution for " + string("Excel Sheet Column Title"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelper<int, string>(
        {1, 28, 701}, {"A", "AB", "ZY"},
        [this](auto input) { return this->convertToTitle(input); });
  };
  int benchmark() const override { return 0; }

 private:
  string convertToTitle(int columnNumber) const {
    string res = "";

    while (columnNumber) {
      columnNumber--;
      int mod = columnNumber % 26;
      res = char('A' + mod) + res;
      columnNumber /= 26;
    }

    return res;
  }
};
