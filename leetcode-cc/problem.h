#pragma once

#include <cstddef>
#include <string>
#include <vector>

#define DIFFI_EASY 1
#define DIFFI_MEDIUM 2
#define DIFFI_HARD 3

#define TOPIC_ALGORITHMS 1
#define TOPIC_DATABASE 2

class IProblem {
 public:
  virtual std::size_t id() const = 0;
  virtual int difficulty() const = 0;
  virtual int topic() const = 0;
  virtual std::string title() const = 0;
  virtual std::string description() const = 0;
  virtual std::vector<std::string> labels() const = 0;
  virtual ~IProblem() {}
};

#define IMPLEMENT_PROBLEM_CLASS(ClassName, Id, Difficulty, Topic, Title, \
                                Description, Labels)                     \
  class ClassName : public IProblem {                                    \
   public:                                                               \
    size_t id() const override { return Id; }                            \
    int difficulty() const override { return Difficulty; }               \
    int topic() const override { return Topic; }                         \
    std::string title() const override { return Title; }                 \
    std::string description() const override { return Description; }     \
    std::vector<std::string> labels() const override { return Labels; }  \
  };
