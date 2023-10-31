#include "registration.h"

#include "../leetcode-cc/IntegerToRoman.hpp"
#include "../leetcode-cc/RomanToInteger.hpp"

const int registerAll(std::shared_ptr<Container> handle) {
  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PIntToRoman>(); });
  handle->registerSolution(
      []() -> ArcSolution { return std::make_shared<SIntToRoman>(); });

  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PRomanToInt>(); });
  handle->registerSolution(
      []() -> ArcSolution { return std::make_shared<SRomanToInt>(); });

  return 0;
}
