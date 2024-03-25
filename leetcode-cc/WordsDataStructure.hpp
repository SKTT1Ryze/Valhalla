#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(
    PWordsDataStructure, 211, DIFFI_MEDIUM, TOPIC_ALGORITHMS,
    "Design Add and Search Words Data Structure",
    "Design a data structure that supports adding new words and finding if a "
    "string matches any previously added string.",
    {""});

class SWordsDataStructure : public ISolution {
 public:
  size_t problemId() const override { return 211; }
  string name() const override {
    return ("Solution for " +
            string("Design Add and Search Words Data Structure"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override { return 0; };
  int benchmark() const override { return 0; }

 private:
  class WordDictionary {
   public:
    WordDictionary() {}

    void addWord(string word) {}

    bool search(string word) {}
  };
};
