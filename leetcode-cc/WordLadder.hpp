#include <tuple>

#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(PWordLadder, 127, DIFFI_HARD, TOPIC_ALGORITHMS,
                        "Word Ladder", "", {""});

class SWordLadder : public ISolution {
 public:
  size_t problemId() const override { return 127; }
  string name() const override {
    return ("Solution for " + string("Word Ladder"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelper<tuple<string, string, vector<string>>, int>(
        {make_tuple("hit", "cog",
                    vector<string>({"hot", "dot", "dog", "lot", "log", "cog"})),
         make_tuple("hit", "cog",
                    vector<string>({"hot", "dot", "dog", "lot", "log"}))},
        {5, 0}, [this](auto input) {
          return this->ladderLength(get<0>(input), get<1>(input),
                                    get<2>(input));
        });
  };
  int benchmark() const override { return 0; }

 private:
  int ladderLength(string beginWord, string endWord,
                   vector<string>& wordList) const {}
};
