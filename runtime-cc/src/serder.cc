#include "serder.h"
using namespace nlohmann;

std::string diffi2string(int difficulty);
std::string topic2string(int topic);

Undead::Undead(const std::shared_ptr<IProblem> &prob) {
  this->id = prob->id();
  this->difficulty = diffi2string(prob->difficulty());
  this->topic = topic2string(prob->topic());
  this->title = prob->title();
  this->description = prob->description();
  this->labels = prob->labels();
  this->solutions = {};
}

json Undead::serialization() {
  return {{"id", this->id},
          {"difficulty", this->difficulty},
          {"topic", this->topic},
          {"title", this->title},
          {"description", this->description},
          {"labels", this->labels},
          {"solutions", this->solutions}};
}

std::string diffi2string(int difficulty) {
  switch (difficulty) {
    case DIFFI_EASY:
      return "Easy";
    case DIFFI_MEDIUM:
      return "Medium";
    case DIFFI_HARD:
      return "Hard";
    default:
      return "Unknown";
  }
}

std::string topic2string(int topic) {
  switch (topic) {
    case TOPIC_ALGORITHMS:
      return "Algorithms";
    case TOPIC_DATABASE:
      return "DataBase";
    default:
      return "Unknown";
  }
}
