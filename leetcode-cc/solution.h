#include <cstddef>
#include <string>

#define ERROR_TEST_FAILED 1

class Solution {
 public:
  virtual std::size_t problem_id() const = 0;
  virtual std::string name() const = 0;
  virtual std::string location() const = 0;
  virtual int test() const = 0;
  virtual int benchmark() const = 0;
};
