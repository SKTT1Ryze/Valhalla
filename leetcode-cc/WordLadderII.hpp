#include <tuple>

#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(PWordLadderII, 126, DIFFI_HARD, TOPIC_ALGORITHMS,
                        "Word Ladder II", "", {"BFS"});

class SWordLadderII : public ISolution {
 public:
  size_t problemId() const override { return 126; }
  string name() const override {
    return ("Solution for " + string("Word Ladder II"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelper<tuple<string, string, vector<string>>,
                      vector<vector<string>>>(
        {make_tuple("hit", "cog",
                    vector<string>({"hot", "dot", "dog", "lot", "log", "cog"})),
         make_tuple("hit", "hit",
                    vector<string>({"hot", "dot", "dog", "lot", "log"}))},
        {{{"hit", "hot", "dot", "dog", "cog"},
          {"hit", "hot", "lot", "log", "cog"}},
         {}},
        [this](auto input) {
          return this->findLadders(get<0>(input), get<1>(input), get<2>(input));
        });
  };
  int benchmark() const override { return 0; }

 private:
  vector<vector<string>> findLadders(string beginWord, string endWord,
                                     vector<string>& wordList) const {}
};
