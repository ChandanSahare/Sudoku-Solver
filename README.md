Sudoku Solver

A C++ Sudoku Solver that uses Backtracking with the Minimum Remaining Values (MRV) heuristic to efficiently solve Sudoku puzzles.

Features

Solve standard 9×9 Sudoku puzzles

Manual Sudoku input

Built-in Easy, Medium, and Hard puzzles

Sudoku board validation

Detects duplicate numbers in rows, columns, and 3×3 boxes

Backtracking algorithm

Minimum Remaining Values (MRV) heuristic

Recursive call statistics

Number-of-attempts statistics

Backtracking statistics

Solving-time measurement

Interactive command-line menu

Project Structure
Sudoku-Solver/
│
├── include/
│   └── SudokuSolver.h
│
├── src/
│   ├── main.cpp
│   └── SudokuSolver.cpp
│
├── README.md
└── .gitignore

How It Works

The solver uses recursive backtracking.

At every step, it:

Finds an empty cell.

Determines which digits can legally be placed there.

Selects the empty cell with the fewest possible digits using the MRV heuristic.

Tries each valid digit.

Recursively continues solving.

If a choice leads to an invalid state, the algorithm backtracks and tries another digit.

Minimum Remaining Values (MRV)

Instead of always selecting the first empty cell, the solver searches for the empty cell with the smallest number of possible values.

For example:

Cell A → 1, 4, 7       → 3 possibilities
Cell B → 2, 8          → 2 possibilities
Cell C → 6             → 1 possibility


The solver chooses Cell C first.

This reduces unnecessary search and can significantly improve performance on difficult Sudoku puzzles.

Example
========================================
           SUDOKU SOLVER
========================================

1. Enter Sudoku manually
2. Use sample Sudoku
3. Exit

Enter choice: 2

Choose difficulty:

1. Easy
2. Medium
3. Hard
4. Back


After solving, the program displays the solved board and statistics such as:

================================
       SOLVING STATISTICS
================================
Recursive calls : ...
Numbers tried   : ...
Backtracks      : ...
Solving time    : ... microseconds
================================

Input Format

Use . for an empty cell.

Example:

53..7....
6..195...
.98....6.
8...6...3
4..8.3..1
7...2...6
.6....28.
...419..5
....8..79


Each row must contain exactly 9 characters using:

1–9 for filled cells

. for empty cells

Compilation

From the project root:

g++ src/main.cpp src/SudokuSolver.cpp -Iinclude -o sudoku

Run

On Windows:

.\sudoku.exe

Technologies

C++

STL vector

Recursion

Backtracking

Constraint checking

MRV heuristic

<chrono> for performance measurement

Learning Objectives

This project demonstrates:

Object-oriented C++ programming

Recursion

Backtracking

Constraint satisfaction

Algorithm optimization

Header/source file separation

Basic performance analysis

Command-line application design

C++ project organization

Future Improvements

Possible future improvements include:

Random Sudoku puzzle generation

Graphical user interface

Hint system

Step-by-step solving visualization

Multiple solving algorithms

Unit tests

Performance comparison between different solving strategies

Difficulty estimation based on solving complexity

License

This project is available for educational and personal use.