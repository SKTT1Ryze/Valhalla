use anyhow::Result;

mod two_sum;

pub trait Solution {
    fn problem_id(&self) -> usize;
    fn name(&self) -> String;
    fn test(&self) -> Result<()>;
    fn benchmark(&self) -> Result<usize>;
}
