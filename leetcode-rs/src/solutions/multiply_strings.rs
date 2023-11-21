use super::{test_helper, Solution};

pub struct SolutionImpl;

crate::derive_solution!(
    SolutionImpl,
    43,
    "Multiply Strings",
    [("2", "3"), ("123", "456"), ("123456789", "987654321")],
    ["6".into(), "56088".into(), "121932631112635269".into()],
    |(num1, num2)| Self::multiply(num1.into(), num2.into())
);

impl SolutionImpl {
    pub fn multiply(num1: String, num2: String) -> String {
        let len1 = num1.len();
        let len2 = num2.len();
        let mut result = vec![0; len1 + len2];

        for (i, c1) in num1.chars().rev().enumerate() {
            for (j, c2) in num2.chars().rev().enumerate() {
                let digit1 = c1.to_digit(10).unwrap();
                let digit2 = c2.to_digit(10).unwrap();

                let temp_sum = result[i + j] + digit1 * digit2;
                result[i + j] = temp_sum % 10;
                result[i + j + 1] += temp_sum / 10;
            }
        }

        // Convert result vector to a string
        let mut result_str: String = result
            .into_iter()
            .rev()
            .skip_while(|&x| x == 0)
            .map(|x| std::char::from_digit(x, 10).unwrap())
            .collect();

        // Handle the case where the result is zero
        if result_str.is_empty() {
            result_str.push('0');
        }

        result_str
    }
}
