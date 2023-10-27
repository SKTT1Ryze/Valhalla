#!/bin/bash
cd ../runtime-rs
cargo run
cp undeads.json ../frontend/
cd ../frontend
yarn dev
