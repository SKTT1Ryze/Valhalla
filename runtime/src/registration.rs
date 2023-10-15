use super::container::ContainerHandle;

use leetcode::{problems, solutions};

pub fn register_all(handle: ContainerHandle) -> anyhow::Result<()> {
    handle.register_problem(|_| problems::two_sum::TwoSum)?;
    handle.register_solution(|_| solutions::two_sum::TwoSum)?;

    handle.register_problem(|_| problems::add_two_numbers::AddTwoNumbers)?;
    handle.register_solution(|_| solutions::add_two_numbers::AddTwoNumbers)?;

    handle.register_problem(|_| problems::longest_substring::LongestSubstring)?;
    handle.register_solution(|_| solutions::longest_substring::LongestSubstring)?;
    handle.register_solution(|_| solutions::longest_substring::LongestSubstringHashMap)?;

    handle.register_problem(|_| problems::median_of_two_sorted_arrays::MedianOfTwoSortedArrays)?;
    handle
        .register_solution(|_| solutions::median_of_two_sorted_arrays::MedianOfTwoSortedArrays)?;

    Ok(())
}
