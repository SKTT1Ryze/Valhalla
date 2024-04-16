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

#[allow(dead_code)]
pub enum Difficulty {
    Easy,
    Medium,
    Hard,
}

impl From<Difficulty> for String {
    fn from(val: Difficulty) -> Self {
        match val {
            Difficulty::Easy => "Easy".into(),
            Difficulty::Medium => "Medium".into(),
            Difficulty::Hard => "Hard".into(),
        }
    }
}

#[allow(dead_code)]
pub enum Topic {
    Algorithms,
    DataBase,
}

impl From<Topic> for String {
    fn from(val: Topic) -> Self {
        match val {
            Topic::DataBase => "DataBase".into(),
            Topic::Algorithms => "Algorithms".into(),
        }
    }
}

pub trait Problem: Send + Sync {
    fn id(&self) -> usize;
    fn difficulty(&self) -> Difficulty;
    fn topic(&self) -> Topic;
    fn title(&self) -> String;
    fn description(&self) -> String;
    fn labels(&self) -> Vec<String>;
}

/// Template
/// ```no_run
/// use super::{Difficulty, Problem, Topic};
///
/// pub struct ProblemImpl;
///
/// crate::derive_problem!(
///     ProblemImpl,
///     X,
///     Difficulty::X,
///     Topic::Algorithms,
///     "Name",
///     "Description",
/// );
/// ```
#[macro_export]
macro_rules! derive_problem {
    ($struct:ident, $id:expr, $difficulty:expr, $topic:expr, $title:expr, $desc:expr, $( $label:expr ), *) => {
        impl Problem for $struct {
            fn id(&self) -> usize {
                $id
            }
            fn difficulty(&self) -> Difficulty {
                $difficulty
            }
            fn topic(&self) -> Topic {
                $topic
            }
            fn title(&self) -> String {
                $title.into()
            }
            fn description(&self) -> String {
                $desc.into()
            }
            fn labels(&self) -> Vec<String> {
                [$( $label, )*].into()
            }
        }
    };
}
