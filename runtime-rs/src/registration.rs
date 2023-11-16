use super::container::ContainerHandle;

use leetcode_rs::{problems, solutions};

pub fn register_all(handle: ContainerHandle) -> anyhow::Result<()> {
    handle.register_problem(|_| problems::two_sum::ProblemImpl)?;
    handle.register_solution(|_| solutions::two_sum::SolutionImpl)?;

    handle.register_problem(|_| problems::add_two_numbers::ProblemImpl)?;
    handle.register_solution(|_| solutions::add_two_numbers::SolutionImpl)?;

    handle.register_problem(|_| problems::longest_substring::ProblemImpl)?;
    handle.register_solution(|_| solutions::longest_substring::SolutionImpl)?;
    handle.register_solution(|_| solutions::longest_substring::SolutionImplHashMap)?;

    handle.register_problem(|_| problems::median_of_two_sorted_arrays::ProblemImpl)?;
    handle.register_solution(|_| solutions::median_of_two_sorted_arrays::SolutionImpl)?;

    handle.register_problem(|_| problems::longest_palindromic_substring::ProblemImpl)?;
    handle.register_solution(|_| solutions::longest_palindromic_substring::SolutionImpl)?;
    handle.register_solution(|_| solutions::longest_palindromic_substring::SolutionImplDP)?;

    handle.register_problem(|_| problems::zigzag_conversion::ProblemImpl)?;
    handle.register_solution(|_| solutions::zigzag_conversion::SolutionImpl)?;

    handle.register_problem(|_| problems::reverse_integer::ProblemImpl)?;
    handle.register_solution(|_| solutions::reverse_integer::SolutionImpl)?;

    handle.register_problem(|_| problems::string_to_integer::ProblemImpl)?;
    handle.register_solution(|_| solutions::string_to_integer::SolutionImpl)?;

    handle.register_problem(|_| problems::palindrome_number::ProblemImpl)?;
    handle.register_solution(|_| solutions::palindrome_number::SolutionImpl)?;

    handle.register_problem(|_| problems::regular_expression_matching::ProblemImpl)?;
    handle.register_solution(|_| solutions::regular_expression_matching::SolutionImpl)?;

    handle.register_problem(|_| problems::container_with_most_water::ProblemImpl)?;
    handle.register_solution(|_| solutions::container_with_most_water::SolutionImpl)?;

    handle.register_problem(|_| problems::swap_nodes_in_pairs::ProblemImpl)?;
    handle.register_solution(|_| solutions::swap_nodes_in_pairs::SolutionImpl)?;

    handle.register_problem(|_| problems::remove_duplicates_from_sorted_array::ProblemImpl)?;
    handle.register_solution(|_| solutions::remove_duplicates_from_sorted_array::SolutionImpl)?;

    handle.register_problem(|_| problems::find_first_occurrence::ProblemImpl)?;
    handle.register_solution(|_| solutions::find_first_occurrence::SolutionImpl)?;

    handle.register_problem(|_| problems::substring_with_concatenation::ProblemImpl)?;
    handle.register_solution(|_| solutions::substring_with_concatenation::SolutionImpl)?;

    handle.register_problem(|_| problems::longest_valid_parentheses::ProblemImpl)?;
    handle.register_solution(|_| solutions::longest_valid_parentheses::SolutionImpl)?;

    handle.register_problem(|_| problems::find_first_last_in_sorted_array::ProblemImpl)?;
    handle.register_solution(|_| solutions::find_first_last_in_sorted_array::SolutionImpl)?;

    handle.register_problem(|_| problems::search_insert_position::ProblemImpl)?;
    handle.register_solution(|_| solutions::search_insert_position::SolutionImpl)?;

    Ok(())
}
