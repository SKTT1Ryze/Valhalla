use super::{test_helper, Solution};

pub struct SolutionImpl;

crate::derive_solution!(
    SolutionImpl,
    42,
    "Trapping Rain Water",
    [
        vec![0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1],
        vec![4, 2, 0, 3, 2, 5]
    ],
    [6, 9],
    Self::trap
);

impl SolutionImpl {
    pub fn trap(height: Vec<i32>) -> i32 {
        let mut ans = 0;
        let mut i = 0;
        let len = height.len();

        if len < 3 {
            return 0;
        }

        while i < len - 1 {
            if height[i] == 0 {
                i += 1;
                continue;
            }
            let mut j = i + 1;
            let mut target = None;

            while j < len {
                // find the greater one
                if height[i] <= height[j] {
                    target = Some(j);
                    break;
                }

                j += 1;
            }

            if target.is_none() {
                // have no greater one, find the greatest one
                let mut max = 0;

                for (idx, &value) in height[i + 1..].iter().enumerate() {
                    if value > max {
                        max = value;
                        target = Some(i + 1 + idx);
                    }
                }
            }

            if let Some(target) = target {
                let left = height[i];
                let right = height[target];
                ans += (target - i - 1) as i32 * left.min(right);
                if j - i > 1 {
                    ans -= height[i + 1..target].iter().sum::<i32>();
                }

                i = target;
            } else {
                break;
            }
        }

        ans
    }
}
