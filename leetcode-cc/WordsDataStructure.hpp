#include <unordered_map>

#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(
    PWordsDataStructure, 211, DIFFI_MEDIUM, TOPIC_ALGORITHMS,
    "Design Add and Search Words Data Structure",
    "Design a data structure that supports adding new words and finding if a "
    "string matches any previously added string.",
    {"Trie"});

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
  struct TrieNode {
    char ch;
    unordered_map<char, TrieNode*> nexts;
    bool existEnd;

    TrieNode() : ch(' '), nexts({}), existEnd(false) {}
    TrieNode(char ch) : ch(ch), nexts({}), existEnd(false) {}
  };

  class WordDictionary {
   public:
    WordDictionary() { root = new TrieNode(); }

    void addWord(string word) {
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

    bool search(string word) { return this->searchHelper(word, 0, root); }

   private:
    bool searchHelper(string& word, int start, TrieNode* p) {
      if (start == word.size()) return p->existEnd;
      char curr = word[start];
      if (curr == '.') {
        for (const auto& [ch, next] : p->nexts) {
          if (this->searchHelper(word, start + 1, next)) return true;
        }
        return false;
      } else if (p->nexts.contains(curr)) {
        return this->searchHelper(word, start + 1, p->nexts[curr]);
      } else {
        return false;
      }
    }

    TrieNode* root;
  };
};
