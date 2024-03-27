#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(PWordSearchII, 212, DIFFI_HARD, TOPIC_ALGORITHMS,
                        "Word Search II",
                        "Given an m x n board of characters and a list of "
                        "strings words, return all words on the board.",
                        {""});

class SWordSearchII : public ISolution {
 public:
  size_t problemId() const override { return 212; }
  string name() const override {
    return ("Solution for " + string("Word Search II"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelper<pair<vector<vector<char>>, vector<string>>,
                      vector<string>>(
        {
            {{{'o', 'a', 'a', 'n'},
              {'e', 't', 'a', 'e'},
              {'i', 'h', 'k', 'r'},
              {'i', 'f', 'l', 'v'}},
             {"oath", "pea", "eat", "rain"}},

        },
        {{"eat", "oath"}}, [this](auto input) {
          return this->findWords(input.first, input.second);
        });
  };
  int benchmark() const override { return 0; }

 private:
  vector<string> findWords(vector<vector<char>>& board,
                           vector<string>& words) const {}
};
