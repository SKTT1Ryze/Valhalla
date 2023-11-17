use std::fmt::Debug;

use anyhow::Result;

pub mod add_two_numbers;
pub mod container_with_most_water;
pub mod find_first_last_in_sorted_array;
pub mod find_first_occurrence;
pub mod longest_palindromic_substring;
pub mod longest_substring;
pub mod longest_valid_parentheses;
pub mod median_of_two_sorted_arrays;
pub mod palindrome_number;
pub mod regular_expression_matching;
pub mod remove_duplicates_from_sorted_array;
pub mod reverse_integer;
pub mod search_insert_position;
pub mod string_to_integer;
pub mod substring_with_concatenation;
pub mod sudoku_solver;
pub mod swap_nodes_in_pairs;
pub mod two_sum;
pub mod valid_sudoku;
pub mod zigzag_conversion;

pub trait Solution: Send + Sync {
    fn problem_id(&self) -> usize;
    fn name(&self) -> String;
    fn location(&self) -> String;
    fn test(&self) -> Result<()>;
    fn benchmark(&self) -> Result<usize> {
        anyhow::bail!("TODO");
    }
}

#[macro_export]
macro_rules! location {
    () => {
        return std::path::Path::new(file!())
            .file_name()
            .unwrap_or_default()
            .to_str()
            .unwrap_or_default()
            .to_string()
    };
}

pub fn test_helper<I, E, T, X, F>(testcases: T, expects: X, f: F) -> Result<()>
where
    I: Debug + Clone,
    E: Debug + PartialEq + Eq,
    T: IntoIterator<Item = I>,
    X: IntoIterator<Item = E>,
    F: Fn(I) -> E,
{
    for (input, expect) in testcases.into_iter().zip(expects) {
        let output = f(input.clone());

        if output != expect {
            anyhow::bail!("test failed for input={input:?}, expect={expect:?}, output={output:?}")
        }
    }

    Ok(())
}

pub fn mut_test_helper<I, T, X, F>(testcases: T, expects: X, f: F) -> Result<()>
where
    I: Debug + Clone + PartialEq + Eq,
    T: IntoIterator<Item = I>,
    X: IntoIterator<Item = I>,
    F: Fn(&mut I),
{
    for (input, expect) in testcases.into_iter().zip(expects) {
        let mut output = input.clone();
        f(&mut output);

        if output != expect {
            anyhow::bail!("test failed for input={input:?}, expect={expect:?}, output={output:?}")
        }
    }

    Ok(())
}
