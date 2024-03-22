#include <unordered_map>

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
    {"Trie"});

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
  struct TrieNode {
    char ch;
    unordered_map<char, TrieNode*> nexts;
    bool existEnd;

    TrieNode() : ch(' '), nexts({}), existEnd(false) {}
    TrieNode(char ch) : ch(ch), nexts({}), existEnd(false) {}
  };

  class Trie {
   public:
    Trie() { root = new TrieNode(); }

    void insert(string word) {
      auto p = root;

      for (const auto& ch : word) {
        if (!p->nexts.contains(ch)) {
          auto newNode = new TrieNode(ch);
          p->nexts.insert({ch, newNode});
        }
        p = p->nexts[ch];
      }

      p->existEnd = true;
    }

    bool search(string word) {
      auto p = root;

      for (const auto& ch : word) {
        if (p->nexts.contains(ch)) {
          p = p->nexts[ch];
        } else {
          return false;
        }
      }

      return p->existEnd;
    }

    bool startsWith(string prefix) {
      auto p = root;

      for (const auto& ch : prefix) {
        if (p->nexts.contains(ch)) {
          p = p->nexts[ch];
        } else {
          return false;
        }
      }

      return true;
    }

   private:
    TrieNode* root;
  };
};
