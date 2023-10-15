use super::Solution;

pub struct MedianOfTwoSortedArrays;

impl Solution for MedianOfTwoSortedArrays {
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

impl MedianOfTwoSortedArrays {
    pub fn find_median_sorted_arrays(nums1: Vec<i32>, nums2: Vec<i32>) -> f64 {
        todo!()
    }
}
