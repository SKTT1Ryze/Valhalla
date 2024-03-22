#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(
    PImplTriePrefixTree, 208, DIFFI_MEDIUM, TOPIC_ALGORITHMS,
    "Implement Trie (Prefix Tree)",
    "A trie (pronounced as try) or prefix tree is a tree data structure used "
    "to efficiently store and retrieve keys in a dataset of strings. There are "
    "various applications of this data structure, such as autocomplete and "
    "spellchecker.",
    {""});

class SImplTriePrefixTree : public ISolution {
 public:
  size_t problemId() const override { return 208; }
  string name() const override {
    return ("Solution for " + string("Implement Trie (Prefix Tree)"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override { return 0; };
  int benchmark() const override { return 0; }

 private:
  class Trie {
   public:
    Trie() {}

    void insert(string word) {}

    bool search(string word) {}

    bool startsWith(string prefix) {}
  };
};
