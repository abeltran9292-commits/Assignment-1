# Assignment-1
C++17 program that solves the Two Sum problem using brute-force and hash-table methods and compares their time and space complexity.
# 2Sum and Complexity

This C++17 program solves the Two Sum problem using two methods.

## Methods

- Brute force checks every possible pair.
- The hash method uses an unordered map to find the pair faster.

## Testing

Both methods were tested with the required vector and four additional cases:

- Positive numbers
- Duplicate numbers
- A negative number
- Zeroes

Each test prints the indices, values, and whether the answer is valid.

## Complexity

The brute-force method has O(n²) time complexity because it uses two loops. It uses O(1) extra space.

The hash method has O(n) expected time complexity because it checks the vector once. It uses O(n) extra space for the unordered map.

The hash method is faster for large vectors because it avoids checking every possible pair.

## Run the Program

Compile with C++17:

g++ -std=c++17 main.cpp -o main

Run:

./main
