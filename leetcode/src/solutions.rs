use anyhow::Result;

pub trait Solution {
    fn problem_id(&self) -> usize;
    fn name(&self) -> String;
    fn test(&self) -> Result<()>;
    fn benchmark(&self) -> Result<usize>;
}
