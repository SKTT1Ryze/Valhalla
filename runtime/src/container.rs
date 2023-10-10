use std::collections::HashMap;
use std::sync::{Arc, Mutex};

use leetcode::problems::Problem;
use leetcode::solutions::Solution;

#[derive(Default)]
pub struct Container {
    problems: HashMap<usize, Arc<dyn Problem>>,
    solutions: HashMap<usize, Vec<Arc<dyn Solution>>>,
}

pub struct ContainerHandle {
    inner: Arc<Mutex<Container>>,
}

impl ContainerHandle {
    pub fn new(container_ref: Arc<Mutex<Container>>) -> Self {
        Self {
            inner: container_ref,
        }
    }

    pub fn register_problem<T, F>(&self, f: F) -> anyhow::Result<()>
    where
        T: Problem + 'static,
        F: FnOnce(&Self) -> T,
    {
        let item: Arc<dyn Problem> = Arc::new(f(self));

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
        let item: Arc<dyn Solution> = Arc::new(f(self));

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

    pub fn get_problems(&self) -> anyhow::Result<HashMap<usize, Arc<dyn Problem>>> {
        Ok(self
            .inner
            .lock()
            .map_err(|_| anyhow::anyhow!("failed to acquire lock of container"))?
            .problems
            .clone())
    }

    pub fn get_solutions_by_id(&self, id: usize) -> anyhow::Result<Vec<Arc<dyn Solution>>> {
        Ok(self
            .inner
            .lock()
            .map_err(|_| anyhow::anyhow!("failed to acquire lock of container"))?
            .solutions
            .get(&id)
            .cloned()
            .unwrap_or_default())
    }
}

impl Clone for ContainerHandle {
    fn clone(&self) -> Self {
        Self {
            inner: self.inner.clone(),
        }
    }
}
