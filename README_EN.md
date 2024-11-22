# Matrix Multiplication and Binary Search Challenges in C

## Overview
This repository contains solutions to two problems assigned as part of a biweekly C programming practice test. Each problem is solved using a separate C program. The first program focuses on generating and multiplying matrices, while the second one performs a binary search to find the closest value to a target number in an array.

## Contents
- **`1.c`**: Implements matrix generation, multiplication, and result display. The user inputs two dimensions for matrices, and the program generates two random binary matrices, multiplies them, and outputs the result.
- **`2.c`**: Reads a sorted array of integers from input and finds the value closest to 10,000 using binary search. If there are two values equally close, it selects the larger value.

## Problem Descriptions

### Problem 1: Matrix Multiplication
- **Objective**: Allow the user to input two integers, N and M, representing the dimensions of two matrices. The program generates two matrices filled with random 0s and 1s, multiplies them, and outputs the result.
- **Constraints**:
  - 1 < N, M < 10
  - If N or M is outside this range, print: "Invalid Input: N and M must be between 2 and 9."
  - The program terminates when the input is `0 0`.
  
### Problem 2: Closest Value with Binary Search
- **Objective**: Read a sorted array of integers from the input until End-of-File (EOF). Use binary search to find the value closest to 10,000, and if there are two equally close values, output the larger one.
- **Constraints**:
  - The array's length will not exceed 1024 integers.
  - The program terminates when the user inputs a single `0`, printing "Finish!".
  
## How to Run

1. **Compile the Programs**:
   Use GCC or any C compiler of your choice to compile the programs:
   ```sh
   gcc 1.c -o matrix_multiplication
   gcc 2.c -o closest_value
