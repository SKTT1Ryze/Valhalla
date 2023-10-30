#include "../leetcode-cc/problem.h"
#include "../leetcode-cc/solution.h"
#include "json.hpp"

class Undead {
 public:
  Undead(const std::shared_ptr<IProblem> &prob);
  nlohmann::json serialization();

  std::vector<std::string> solutions;

 private:
  std::size_t id;
  std::string difficulty;
  std::string topic;
  std::string title;
  std::string description;
  std::vector<std::string> labels;
};