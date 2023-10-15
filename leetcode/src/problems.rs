pub mod add_two_numbers;
pub mod longest_palindromic_substring;
pub mod longest_substring;
pub mod median_of_two_sorted_arrays;
pub mod two_sum;

#[allow(dead_code)]
pub enum Difficulty {
    Easy,
    Medium,
    Hard,
}

impl From<Difficulty> for String {
    fn from(val: Difficulty) -> Self {
        match val {
            Difficulty::Easy => "Easy".into(),
            Difficulty::Medium => "Medium".into(),
            Difficulty::Hard => "Hard".into(),
        }
    }
}

#[allow(dead_code)]
pub enum Topic {
    Algorithms,
    DataBase,
}

impl From<Topic> for String {
    fn from(val: Topic) -> Self {
        match val {
            Topic::DataBase => "DataBase".into(),
            Topic::Algorithms => "Algorithms".into(),
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
