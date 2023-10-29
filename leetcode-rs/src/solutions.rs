use anyhow::Result;

pub mod add_two_numbers;
pub mod container_with_most_water;
pub mod longest_palindromic_substring;
pub mod longest_substring;
pub mod median_of_two_sorted_arrays;
pub mod palindrome_number;
pub mod regular_expression_matching;
pub mod reverse_integer;
pub mod string_to_integer;
pub mod two_sum;
pub mod zigzag_conversion;

pub trait Solution: Send + Sync {
    fn problem_id(&self) -> usize;
    fn name(&self) -> String;
    fn location(&self) -> String;
    fn test(&self) -> Result<()>;
    fn benchmark(&self) -> Result<usize>;
}

#[macro_export]
macro_rules! location {
    () => {
        return std::path::Path::new(file!())
            .file_name()
            .unwrap_or_default()
            .to_str()
            .unwrap_or_default()
            .to_string()
    };
}
