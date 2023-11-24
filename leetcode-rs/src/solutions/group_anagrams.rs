use super::{test_helper, Solution};

pub struct SolutionImpl;

crate::derive_solution!(
    SolutionImpl,
    49,
    "Group Anagrams",
    [
        vec!["eat", "tea", "tan", "ate", "nat", "bat"],
        vec![""],
        vec!["a"]
    ],
    [
        vec![
            vec!["bat".into()],
            vec!["nat".into(), "tan".into()],
            vec!["ate".into(), "eat".into(), "tea".into()]
        ],
        vec![vec!["".into()]],
        vec![vec!["a".into()]]
    ],
    |strs| {
        let strs = strs.into_iter().map(std::convert::Into::into).collect();
        let mut output = Self::group_anagrams(strs);
        output.sort();
        output
    }
);

impl SolutionImpl {
    pub fn group_anagrams(strs: Vec<String>) -> Vec<Vec<String>> {
        todo!()
    }
}
