use super::container::ContainerHandle;

use leetcode::{problems, solutions};

pub fn register_all(handle: ContainerHandle) -> anyhow::Result<()> {
    handle.register_problem(|_| problems::two_sum::TwoSum)?;
    handle.register_solution(|_| solutions::two_sum::TwoSum)?;

    Ok(())
}
