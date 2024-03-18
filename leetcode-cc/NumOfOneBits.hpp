#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(PNumOfOneBits, 191, DIFFI_EASY, TOPIC_ALGORITHMS,
                        "Number of 1 Bits",
                        "Write a function that takes the binary representation "
                        "of an unsigned integer and returns the number of '1' "
                        "bits it has (also known as the Hamming weight).",
                        {"Bit"});

class SNumOfOneBits : public ISolution {
 public:
  size_t problemId() const override { return 191; }
  string name() const override {
    return ("Solution for " + string("Number of 1 Bits"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelper<uint32_t, int>(
        {0b00000000000000000000000000001011, 0b00000000000000000000000010000000,
         0b11111111111111111111111111111101},
        {3, 1, 31}, [this](auto input) { return this->hammingWeight(input); });
  };
  int benchmark() const override { return 0; }

 private:
  int hammingWeight(uint32_t n) const {}
};
