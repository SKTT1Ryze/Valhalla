use anyhow::Result;

pub mod add_two_numbers;
pub mod two_sum;

pub trait Solution: Send + Sync {
    fn problem_id(&self) -> usize;
    fn name(&self) -> String;
    fn test(&self) -> Result<()>;
    fn benchmark(&self) -> Result<usize>;
}
