pub mod add_two_numbers;
pub mod longest_substring;
pub mod two_sum;

#[allow(dead_code)]
pub enum Difficulty {
    Easy,
    Medium,
    Hard,
}

impl Into<String> for Difficulty {
    fn into(self) -> String {
        match self {
            Self::Easy => "easy".into(),
            Self::Medium => "Medium".into(),
            Self::Hard => "Hard".into(),
        }
    }
}

#[allow(dead_code)]
pub enum Topic {
    Algorithms,
    DataBase,
}

impl Into<String> for Topic {
    fn into(self) -> String {
        match self {
            Self::DataBase => "DataBase".into(),
            Self::Algorithms => "Algorithms".into(),
        }
    }
}

pub trait Problem: Send + Sync {
    fn id(&self) -> usize;
    fn difficulty(&self) -> Difficulty;
    fn topic(&self) -> Topic;
    fn title(&self) -> String;
    fn description(&self) -> String;
    fn labels(&self) -> Vec<String>;
}
