#include <cstddef>
#include <string>
#include <vector>

#define DIFFI_EASY 1
#define DIFFI_MEDIUM 2
#define DIFFI_HARD 3

#define TOPIC_ALGORITHMS 1
#define TOPIC_DATABASE 2

class Problem {
 public:
  virtual std::size_t id() const = 0;
  virtual int difficulty() const = 0;
  virtual int topic() const = 0;
  virtual std::string title() const = 0;
  virtual std::string description() const = 0;
  virtual std::vector<std::string> labels() const = 0;
};
