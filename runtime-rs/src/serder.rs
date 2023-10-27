use std::sync::Arc;

use leetcode_rs::problems::Problem;
use serde::{Deserialize, Serialize};

#[derive(Serialize, Deserialize, Default)]
pub struct Undead {
    id: usize,
    difficulty: String,
    topic: String,
    title: String,
    description: String,
    labels: Vec<String>,
    pub solutions: Vec<String>,
}

impl From<Arc<dyn Problem>> for Undead {
    fn from(value: Arc<dyn Problem>) -> Self {
        Self {
            id: value.id(),
            difficulty: value.difficulty().into(),
            topic: value.topic().into(),
            title: value.title(),
            description: value.description(),
            labels: value.labels(),
            ..Default::default()
        }
    }
}
