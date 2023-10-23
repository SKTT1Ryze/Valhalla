use super::{Difficulty, Problem, Topic};

pub struct ProblemImpl;

impl Problem for ProblemImpl {
    fn id(&self) -> usize {
        6
    }
    fn difficulty(&self) -> Difficulty {
        Difficulty::Medium
    }
    fn topic(&self) -> Topic {
        Topic::Algorithms
    }
    fn title(&self) -> String {
        "Zigzag Conversion".into()
    }
    fn description(&self) -> String {
        "".into()
    }
    fn labels(&self) -> Vec<String> {
        ["String".into()].into()
    }
}
