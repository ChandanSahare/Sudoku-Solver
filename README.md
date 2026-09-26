Sudoku Solver

A C++ Sudoku solver that uses backtracking with the Minimum Remaining Values (MRV) heuristic to efficiently solve Sudoku puzzles.

Features

Solve Sudoku puzzles manually entered by the user

Easy, Medium, and Hard sample puzzles

Sudoku board validation

Backtracking algorithm

MRV-based cell selection

Recursive-call statistics

Numbers-tried statistics

Backtracking statistics

Solving-time measurement

Automatic solving visualization

Step-by-step solving visualization

Colored console output

Console board refresh during visualization

Project Structure
Sudoku-Solver/
│
├── include/
│   ├── SudokuSolver.h
│   └── SudokuUI.h
│
├── src/
│   ├── SudokuSolver.cpp
│   ├── SudokuUI.cpp
│   └── main.cpp
│
├── .gitignore
└── README.md

Algorithm

The solver uses recursive backtracking.

For each empty cell, the program:

Finds an empty cell with the fewest possible candidates.

Tries valid digits from 1 to 9.

Recursively continues solving.

If a choice leads to a dead end, the solver removes the choice.

It then tries another candidate.

The process continues until the Sudoku is solved or no solution exists.

The MRV heuristic helps reduce the search space by selecting the most constrained empty cell first.

Visualization Modes

The program provides two visualization modes.

Automatic

The solver automatically displays each step with a short delay.

Step-by-step

The solver pauses after each move and waits for the user to press Enter.

Backtracking is displayed separately so the solving process can be followed in the terminal.

Building

This project uses a C++ compiler such as MinGW g++.

From the project directory:

g++ src\main.cpp src\SudokuSolver.cpp src\SudokuUI.cpp -Iinclude -o sudoku

Running

Run the compiled program:

sudoku.exe


The main menu provides:

1. Enter Sudoku manually
2. Use sample Sudoku
3. Watch solver step-by-step
4. Exit

Sudoku Input

When entering a Sudoku manually:

Use digits 1 through 9 for filled cells.

Use . for empty cells.

Enter exactly 9 characters for each row.

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

Statistics

After solving, the program displays:

Recursive calls

Numbers tried

Backtracks

Solving time

Example:

================================
       SOLVING STATISTICS
================================
Recursive calls : ...
Numbers tried   : ...
Backtracks      : ...
Solving time    : ... microseconds (... ms)
================================

Technologies

C++

Standard Library

Recursive Backtracking

MRV Heuristic

Windows Console API for colored output

Author

Chandan Sahare