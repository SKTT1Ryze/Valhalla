pub mod add_two_numbers;
pub mod two_sum;

#[allow(dead_code)]
pub enum Difficulty {
    Easy,
    Medium,
    Diffcult,
}

#[allow(dead_code)]
pub enum Topic {
    Algorithms,
    DataBase,
}

pub trait Problem: Send + Sync {
    fn id(&self) -> usize;
    fn difficulty(&self) -> Difficulty;
    fn topic(&self) -> Topic;
    fn title(&self) -> String;
    fn description(&self) -> String;
    fn labels(&self) -> Vec<String>;
}
