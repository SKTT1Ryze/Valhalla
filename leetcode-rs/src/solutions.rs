#![allow(clippy::needless_range_loop)]

use super::{btree::TreeNode, list::ListNode};
use crate::{btree::TreeNodeHandle, list::assert_eq_list};
use anyhow::Result;
use std::{cell::RefCell, fmt::Debug, rc::Rc};

pub mod add_binary;
pub mod add_two_numbers;
pub mod basic_calculator;
pub mod basic_calculator_ii;
pub mod best_time_to_buy_and_sell_stock;
pub mod best_time_to_buy_and_sell_stock_ii;
pub mod candy;
pub mod climbing_stairs;
pub mod combination_sum;
pub mod combination_sum2;
pub mod combination_sum_iii;
pub mod combinations;
pub mod container_with_most_water;
pub mod contains_duplicate;
pub mod contains_duplicate_ii;
pub mod count_and_say;
pub mod edit_distance;
pub mod find_first_last_in_sorted_array;
pub mod find_first_occurrence;
pub mod first_missing_positive;
pub mod gas_station;
pub mod group_anagrams;
pub mod house_robber_ii;
pub mod insert_interval;
pub mod invert_binary_tree;
pub mod jump_game;
pub mod jump_game_ii;
pub mod kth_smallest_in_bst;
pub mod largest_number;
pub mod length_of_last_word;
pub mod longest_palindromic_substring;
pub mod longest_substring;
pub mod longest_valid_parentheses;
pub mod majority_element_ii;
pub mod maximal_square;
pub mod maximum_subarray;
pub mod median_of_two_sorted_arrays;
pub mod merge_intervals;
pub mod minimum_path_sum;
pub mod minimum_window_substring;
pub mod multiply_strings;
pub mod n_queens;
pub mod n_queens_ii;
pub mod palindrome_linked_list;
pub mod palindrome_number;
pub mod permutation_sequence;
pub mod permutations;
pub mod permutations_ii;
pub mod plus_one;
pub mod pow_x_n;
pub mod power_of_two;
pub mod regular_expression_matching;
pub mod remove_duplicates_from_sorted_array;
pub mod remove_duplicates_from_sorted_array_ii;
pub mod reverse_integer;
pub mod rotate_image;
pub mod rotate_list;
pub mod search_2d_matrix;
pub mod search_in_rotated_sorted_array_ii;
pub mod search_insert_position;
pub mod set_matrix_zeroes;
pub mod simplify_path;
pub mod sort_colors;
pub mod spiral_matrix;
pub mod spiral_matrix_ii;
pub mod sqrtx;
pub mod string_to_integer;
pub mod subsets;
pub mod substring_with_concatenation;
pub mod sudoku_solver;
pub mod summary_ranges;
pub mod swap_nodes_in_pairs;
pub mod text_justification;
pub mod trapping_rain_water;
pub mod two_sum;
pub mod unique_paths;
pub mod unique_paths_ii;
pub mod valid_number;
pub mod valid_sudoku;
pub mod wildcard_matching;
pub mod word_search;
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

/// Template
/// ```no_run
/// use super::{test_helper, Solution};
///
/// pub struct SolutionImpl;
///
/// crate::derive_solution!(
///     SolutionImpl,
///     X,
///     "Name",
///     [],
///     [],
///     f
/// );
///
/// impl SolutionImpl {
///
/// }
/// ```
#[macro_export]
macro_rules! derive_solution {
    ($struct:ident, $id:expr, $name:expr, $testcases:expr, $expects:expr, $test_function:expr) => {
        impl Solution for $struct {
            fn name(&self) -> String {
                format!("Solution for {}", $name)
            }
            fn problem_id(&self) -> usize {
                $id
            }
            fn location(&self) -> String {
                $crate::location!()
            }
            fn test(&self) -> anyhow::Result<()> {
                test_helper($testcases, $expects, $test_function)
            }
        }
    };
}

// TODO: reuse the code
#[macro_export]
macro_rules! derive_inplace_solution {
    ($struct:ident, $id:expr, $name:expr, $testcases:expr, $expects:expr, $test_function:expr) => {
        impl Solution for $struct {
            fn name(&self) -> String {
                format!("Solution for {}", $name)
            }
            fn problem_id(&self) -> usize {
                $id
            }
            fn location(&self) -> String {
                $crate::location!()
            }
            fn test(&self) -> anyhow::Result<()> {
                mut_test_helper($testcases, $expects, $test_function)
            }
        }
    };
}

#[macro_export]
macro_rules! derive_list_solution {
    ($struct:ident, $id:expr, $name:expr, $testcases:expr, $expects:expr, $test_function:expr) => {
        impl Solution for $struct {
            fn name(&self) -> String {
                format!("Solution for {}", $name)
            }
            fn problem_id(&self) -> usize {
                $id
            }
            fn location(&self) -> String {
                $crate::location!()
            }
            fn test(&self) -> anyhow::Result<()> {
                list_test_helper($testcases, $expects, $test_function)
            }
        }
    };
}

#[macro_export]
macro_rules! derive_btree_solution {
    ($struct:ident, $id:expr, $name:expr, $testcases:expr, $expects:expr, $test_function:expr) => {
        impl Solution for $struct {
            fn name(&self) -> String {
                format!("Solution for {}", $name)
            }
            fn problem_id(&self) -> usize {
                $id
            }
            fn location(&self) -> String {
                $crate::location!()
            }
            fn test(&self) -> anyhow::Result<()> {
                btree_test_helper($testcases, $expects, $test_function)
            }
        }
    };
}

pub fn test_helper<T, E, I, X, F>(testcases: I, expects: X, f: F) -> Result<()>
where
    T: Debug + Clone,
    E: Debug + PartialEq,
    I: IntoIterator<Item = T>,
    X: IntoIterator<Item = E>,
    F: Fn(T) -> E,
{
    for (input, expect) in testcases.into_iter().zip(expects) {
        let output = f(input.clone());

        if output != expect {
            anyhow::bail!(
                "test failed for input={input:?}, expect={expect:?}, \
                 output={output:?}"
            )
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
            anyhow::bail!(
                "test failed for input={input:?}, expect={expect:?}, \
                 output={output:?}"
            )
        }
    }

    Ok(())
}

pub fn list_test_helper<T, E, I, X, F>(
    testcases: I,
    expects: X,
    f: F,
) -> Result<()>
where
    T: Debug + Clone,
    E: Debug + Eq,
    I: IntoIterator<Item = T>,
    X: IntoIterator<Item = Vec<E>>,
    F: Fn(T) -> Option<Box<ListNode<E>>>,
{
    for (input, expect) in testcases.into_iter().zip(expects) {
        let output = f(input);
        let expect = ListNode::create_list(expect);

        if !assert_eq_list(&output, &expect) {
            anyhow::bail!("test failed!")
        }
    }

    Ok(())
}

pub fn btree_test_helper<'a, I, E, F>(
    testcases: I,
    expects: E,
    f: F,
) -> Result<()>
where
    I: IntoIterator<Item = &'a str>,
    E: IntoIterator<Item = &'a str>,
    F: Fn(Option<Rc<RefCell<TreeNode>>>) -> Option<Rc<RefCell<TreeNode>>>,
{
    for (input, expect) in testcases.into_iter().zip(expects) {
        let root = TreeNodeHandle::from(input.to_string());
        let expect = TreeNodeHandle::from(expect.to_string());
        let output = TreeNodeHandle {
            inner: f(root.inner),
        };

        if output != expect {
            anyhow::bail!("test failed!")
        }
    }
    Ok(())
}
