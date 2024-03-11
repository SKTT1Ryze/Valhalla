#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(
    PExcelSheetColNum, 171, DIFFI_EASY, TOPIC_ALGORITHMS,
    "Excel Sheet Column Number",
    "Given a string columnTitle that represents the column title as appears in "
    "an Excel sheet, return its corresponding column number.",
    {"Math"});

class SExcelSheetColNum : public ISolution {
 public:
  size_t problemId() const override { return 171; }
  string name() const override {
    return ("Solution for " + string("Excel Sheet Column NUmber"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelper<string, int>(
        {"A", "AB", "ZY"}, {1, 28, 701},
        [this](auto input) { return this->titleToNumber(input); });
  };
  int benchmark() const override { return 0; }

 private:
  int titleToNumber(string columnTitle) const {}
};
