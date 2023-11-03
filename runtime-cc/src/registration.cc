#include "registration.h"

#include "../leetcode-cc/IntegerToRoman.hpp"
#include "../leetcode-cc/LetterCombsOfAPhoneNum.hpp"
#include "../leetcode-cc/LongestCommonPrefix.hpp"
#include "../leetcode-cc/RomanToInteger.hpp"
#include "../leetcode-cc/ThreeSum.hpp"
#include "../leetcode-cc/ThreeSumClosest.hpp"

const int registerAll(std::shared_ptr<Container> handle) {
  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PIntToRoman>(); });
  handle->registerSolution(
      []() -> ArcSolution { return std::make_shared<SIntToRoman>(); });

  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PRomanToInt>(); });
  handle->registerSolution(
      []() -> ArcSolution { return std::make_shared<SRomanToInt>(); });

  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PLongestCommonPrefix>(); });
  handle->registerSolution(
      []() -> ArcSolution { return std::make_shared<SLonestCommonPrefix>(); });

  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PThreeSum>(); });
  handle->registerSolution(
      []() -> ArcSolution { return std::make_shared<SThreeSum>(); });

  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PThreeSumClosest>(); });
  handle->registerSolution(
      []() -> ArcSolution { return std::make_shared<SThreeSumClosest>(); });

  handle->registerProblem([]() -> ArcProblem {
    return std::make_shared<PLetterCombsOfAPhoneNum>();
  });
  handle->registerSolution([]() -> ArcSolution {
    return std::make_shared<SLetterCombsOfAPhoneNum>();
  });

  return 0;
}
