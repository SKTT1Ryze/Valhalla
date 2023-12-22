use super::{test_helper, Solution};

pub struct SolutionImpl;

crate::derive_solution!(
    SolutionImpl,
    60,
    "Permutation Sequence",
    [(3, 3), (4, 9), (3, 1)],
    ["213".into(), "2314".into(), "123".into()],
    |(n, k)| Self::get_permutation(n, k)
);

impl SolutionImpl {
    pub fn get_permutation(n: i32, k: i32) -> String {
        let mut init = vec![];
        for i in 1..=n {
            init.push(i);
        }
        for _ in 0..k - 1 {
            Self::next_permutation(&mut init);
        }
        init.into_iter()
            .map(|x| x.to_string())
            .collect::<Vec<_>>()
            .join("")
    }

    fn next_permutation(nums: &mut [i32]) {
        let mut breakpt = -1;
        for i in (0..nums.len() - 1).rev() {
            if nums[i] < nums[i + 1] {
                breakpt = i as i32;
                break;
            }
        }
        if breakpt == -1 {
            nums.reverse();
        } else {
            let breakpt = breakpt as usize;
            for i in ((breakpt + 1)..nums.len()).rev() {
                if nums[i] > nums[breakpt] {
                    nums.swap(i, breakpt);
                    break;
                }
            }

            nums[breakpt + 1..].reverse();
        }
    }
}
