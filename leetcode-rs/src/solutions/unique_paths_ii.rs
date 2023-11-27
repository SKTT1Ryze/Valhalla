use super::{test_helper, Solution};

pub struct SolutionImpl;

crate::derive_solution!(
    SolutionImpl,
    63,
    "Unique Paths II",
    [
        vec![vec![0, 0, 0], vec![0, 1, 0], vec![0, 0, 0]],
        vec![vec![0, 1], vec![0, 0]]
    ],
    [2, 1],
    Self::unique_paths_with_obstacles
);

impl SolutionImpl {
    pub fn unique_paths_with_obstacles(obstacle_grid: Vec<Vec<i32>>) -> i32 {
        todo!()
    }
}
