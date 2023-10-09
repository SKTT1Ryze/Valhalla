mod two_sum;

pub enum Difficulty {
    Easy,
    Medium,
    Diffcult,
}

pub enum Topic {
    Algorithms,
    DataBase,
}

pub trait Problem {
    fn id(&self) -> usize;
    fn difficulty(&self) -> Difficulty;
    fn topic(&self) -> Topic;
    fn title(&self) -> String;
    fn description(&self) -> String;
    fn labels(&self) -> Vec<String>;
}
