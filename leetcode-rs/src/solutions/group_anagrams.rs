use std::collections::HashMap;

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
            vec!["nat".into(), "tan".into(),],
            vec!["ate".into(), "eat".into(), "tea".into(),],
        ],
        vec![vec!["".into()]],
        vec![vec!["a".into()]]
    ],
    |strs| {
        let strs = strs.into_iter().map(std::convert::Into::into).collect();
        let mut output = Self::group_anagrams(strs);
        output.sort_by_key(|a| a.len());
        for v in &mut output {
            v.sort();
        }
        output
    }
);

impl SolutionImpl {
    pub fn group_anagrams(strs: Vec<String>) -> Vec<Vec<String>> {
        let mut hash: HashMap<String, Vec<String>> = HashMap::new();

        for s in strs {
            let mut chars: Vec<_> = s.chars().collect();
            chars.sort();
            let s_sorted: String = chars.into_iter().collect();

            hash.entry(s_sorted).or_default().push(s);
        }

        hash.into_values().collect()
    }
}
