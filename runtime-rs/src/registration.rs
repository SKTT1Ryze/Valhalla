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

    Ok(())
}
