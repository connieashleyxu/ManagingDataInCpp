#!/bin/bash
# ©2023 Nathan Greenfield

# Pull the graded tests
# wget "https://drive.google.com/file/d/1JIeqBqlv9JINuCuE83lLLyS8M-uyS3qg/view?usp=drive_link" -O hw02.tar.gz
# wget "https://drive.google.com/uc?export=download&id=19U7hrj3waregvjgJY0TjPxKVvP0kU8hE" -O hw02.tar.gz
wget "https://drive.google.com/uc?export=download&id=1JIeqBqlv9JINuCuE83lLLyS8M-uyS3qg" -O hw02.tar.gz
tar xzf hw02.tar.gz

# Cmake into build directory
echo "Compiling..."
mkdir build
cd build
CC=clang CXX=clang++ cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON .. || exit 1
make || exit 1

# Return to root folder (so cwd is correct)
cd ..

# Run graded tests
echo "Running graded tests..."
# timeout 30 build/tests/tests [graded]
timeout 30 build/tests/tests [graded] || exit 1

