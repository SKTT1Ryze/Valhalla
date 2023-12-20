use super::{test_helper, Solution};

pub struct SolutionImpl;

crate::derive_solution!(
    SolutionImpl,
    71,
    "Simplify Path",
    ["/home/", "/../", "/home//foo/"],
    ["/home".into(), "/".into(), "/home/foo".into()],
    |path| Self::simplify_path(path.into())
);

impl SolutionImpl {
    pub fn simplify_path(path: String) -> String {
        todo!()
    }
}
