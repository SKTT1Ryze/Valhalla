use super::Solution;

pub struct SolutionImpl;

impl Solution for SolutionImpl {
    fn name(&self) -> String {
        "Solutoin for Median of Two Sorted Arrays".into()
    }
    fn problem_id(&self) -> usize {
        4
    }
    fn location(&self) -> String {
        crate::location!()
    }
    fn test(&self) -> anyhow::Result<()> {
        let testcases = [
            (vec![1, 3], vec![2], 2_f64),
            (vec![1, 2], vec![3, 4], 2.5_f64),
        ];

        for (nums1, nums2, expect) in testcases {
            let output = Self::find_median_sorted_arrays(nums1.clone(), nums2.clone());

            if output != expect {
                anyhow::bail!(
                    "test failed for nums1={nums1:?} and nums2={nums2:?}, expect={expect}, \
                     output={output}"
                );
            }
        }

        Ok(())
    }
    fn benchmark(&self) -> anyhow::Result<usize> {
        anyhow::bail!("TODO");
    }
}

impl SolutionImpl {
    pub fn find_median_sorted_arrays(nums1: Vec<i32>, nums2: Vec<i32>) -> f64 {
        let mut sorted = Vec::new();
        let m = nums1.len();
        let n = nums2.len();
        let mut p1 = 0;
        let mut p2 = 0;

        while p1 < m && p2 < n {
            let num1 = nums1[p1];
            let num2 = nums2[p2];

            if num1 <= num2 {
                sorted.push(num1);
                p1 += 1;
            } else {
                sorted.push(num2);
                p2 += 1;
            }
        }

        sorted.extend(&nums1[p1..]);
        sorted.extend(&nums2[p2..]);

        let len = m + n;
        if len % 2 == 0 {
            (sorted[len / 2 - 1] + sorted[len / 2]) as f64 / 2_f64
        } else {
            sorted[len / 2] as f64
        }
    }
}
