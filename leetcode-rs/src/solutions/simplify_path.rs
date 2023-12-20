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
        let mut res = Vec::<&str>::new();
        let idents: Vec<&str> = path.split('/').collect();

        println!("{idents:?}");

        for ident in idents {
            match ident {
                "/" | "." | "" => {
                    // do nothing
                }
                ".." => {
                    res.pop();
                }
                _ => {
                    res.push(ident);
                }
            }
        }

        format!("/{}", res.join("/"))
    }
}
