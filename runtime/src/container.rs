use std::collections::HashMap;
use std::sync::{Arc, Mutex};

use leetcode::problems::Problem;
use leetcode::solutions::Solution;

pub struct Container {
    problems: HashMap<usize, Box<dyn Problem>>,
    solutions: HashMap<usize, Vec<Box<dyn Solution>>>,
}

pub struct ContainerHandle {
    inner: Arc<Mutex<Container>>,
}

impl ContainerHandle {
    pub fn register_problem<T, F>(&self, f: F) -> anyhow::Result<()>
    where
        T: Problem + 'static,
        F: FnOnce(&Self) -> T,
    {
        let item: Box<dyn Problem> = Box::new(f(&self));

        if let Ok(mut guard) = self.inner.lock() {
            guard.problems.insert(item.id(), item);
        } else {
            anyhow::bail!("failed to acquire lock of container.");
        }

        Ok(())
    }

    pub fn register_solution<T, F>(&self, f: F) -> anyhow::Result<()>
    where
        T: Solution + 'static,
        F: FnOnce(&Self) -> T,
    {
        let item: Box<dyn Solution> = Box::new(f(&self));

        if let Ok(mut guard) = self.inner.lock() {
            guard
                .solutions
                .entry(item.problem_id())
                .or_default()
                .push(item);
        } else {
            anyhow::bail!("failed to acquire lock of container.");
        }

        Ok(())
    }
}
