#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(PReverseBits, 190, DIFFI_EASY, TOPIC_ALGORITHMS,
                        "Reverse Bits",
                        "Reverse bits of a given 32 bits unsigned integer.",
                        {""});

class SReverseBits : public ISolution {
 public:
  size_t problemId() const override { return 190; }
  string name() const override {
    return ("Solution for " + string("Reverse Bits"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelper<uint32_t, uint32_t>(
        {0b00000010100101000001111010011100,
         0b11111111111111111111111111111101},
        {0b00111001011110000010100101000000,
         0b10111111111111111111111111111111},
        [this](auto input) { return this->reverseBits(input); });
  };
  int benchmark() const override { return 0; }

 private:
  uint32_t reverseBits(uint32_t n) const {}
};
