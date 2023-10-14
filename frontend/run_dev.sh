#!/bin/bash
cd ../runtime
cargo run
cp undeads.json ../frontend/
cd ../frontend
yarn dev
