pub mod add_two_numbers;
pub mod container_with_most_water;
pub mod longest_palindromic_substring;
pub mod longest_substring;
pub mod median_of_two_sorted_arrays;
pub mod palindrome_number;
pub mod regular_expression_matching;
pub mod reverse_integer;
pub mod string_to_integer;
pub mod swap_nodes_in_pairs;
pub mod two_sum;
pub mod zigzag_conversion;

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

#[macro_export]
macro_rules! derive_problem {
    ($struct:ident, $id:expr, $difficulty:expr, $topic:expr, $title:expr, $desc:expr, $( $label:expr ), *) => {
        impl Problem for $struct {
            fn id(&self) -> usize {
                $id
            }
            fn difficulty(&self) -> Difficulty {
                $difficulty
            }
            fn topic(&self) -> Topic {
                $topic
            }
            fn title(&self) -> String {
                $title.into()
            }
            fn description(&self) -> String {
                $desc.into()
            }
            fn labels(&self) -> Vec<String> {
                [$( $label, )*].into()
            }
        }
    };
}
