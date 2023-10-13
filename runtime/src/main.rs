use simple_logger::SimpleLogger;
use std::{
    fs::File,
    io::Write,
    sync::{Arc, Mutex},
};

mod container;
mod registration;
mod serder;

const JSON_OUTPUT: &str = "undeads.json";

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
    let mut undeads: Vec<serder::Undead> = Vec::new();
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
            // serde as json
            undeads.push(problem.into());
        }
    }

    let json = serde_json::to_string(&undeads)?;

    log::info!("Writing {JSON_OUTPUT} ...");
    let mut f = File::create(JSON_OUTPUT)?;
    f.write_all(json.as_bytes())?;
    log::info!("Write {JSON_OUTPUT} succeed!");

    Ok(())
}
