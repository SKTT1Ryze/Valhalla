#!/bin/bash
cd ../runtime-rs
cargo run
cp undeads.json ../frontend/undeads_rust.json
cd ../runtime-cc
make && ./build/runtime
cp undeads.json ../frontend/undeads_cpp.json
cd ../frontend
yarn dev
