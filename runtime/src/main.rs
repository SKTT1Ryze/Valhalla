use std::sync::{Arc, Mutex};

use simple_logger::SimpleLogger;

mod container;
mod registration;

fn main() -> anyhow::Result<()> {
    // init logger
    SimpleLogger::new().init()?;

    // create a container which can be shared in multi thread
    let container = Arc::new(Mutex::new(container::Container::default()));
    // create one container handle for registration
    let handle = container::ContainerHandle::new(container.clone());
    // register all problems and solutions
    registration::register_all(handle.clone())?;

    // execute all the testcase in solutions
    let problems = handle.get_problems()?;
    for (id, problem) in problems {
        log::info!(
            "Finding solutions for problem No.{id}, title: {} ...",
            problem.title()
        );

        let solutions = handle.get_solutions_by_id(id)?;
        if solutions.is_empty() {
            log::error!("No solutions found for problem No.{id}.");
            anyhow::bail!("Lack solutions");
        } else {
            log::info!("Found solutions, run testcase...");
            for solution in &solutions {
                // test
                solution.test()?;
                log::info!("Solution {} test passed!", solution.name());
                // TODO: bencmark
            }
        }
    }

    Ok(())
}
