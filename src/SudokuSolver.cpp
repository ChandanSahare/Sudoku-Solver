#include "SudokuSolver.h"
#include <iostream>

SudokuSolver::SudokuSolver() : recursiveCalls(0), numbersTried(0), backtracks(0) {}

bool SudokuSolver::findBestCell(
    vector<vector<char>>& board,
    int& bestRow,
    int& bestCol
) {

    int minimumChoices = 10;

    bestRow = -1;
    bestCol = -1;

    for (int row = 0; row < 9; row++) {

        for (int col = 0; col < 9; col++) {

            if (board[row][col] != '.') {
                continue;
            }

            int choices = 0;

            for (char digit = '1'; digit <= '9'; digit++) {

                if (isSafe(board, row, col, digit)) {
                    choices++;
                }
            }

            if (choices < minimumChoices) {

                minimumChoices = choices;

                bestRow = row;
                bestCol = col;
            }

            if (minimumChoices == 1) {
                return true;
            }
        }
    }

    if (bestRow == -1) {
        return false;
    }

    return true;
}

bool SudokuSolver::isValidBoard(
    const vector<vector<char>>& board
) {
    for (int row = 0; row < 9; row++) {

        bool seen[10] = {};

        for (int col = 0; col < 9; col++) {

            char value = board[row][col];

            if (value == '.') {
                continue;
            }

            int number = value - '0';

            if (seen[number]) {
                cout << "Invalid Sudoku!" << endl
                     << "Duplicate '" << value
                     << "' found in row "
                     << row + 1 << "." << endl;

                return false;
            }

            seen[number] = true;
        }
    }

    for (int col = 0; col < 9; col++) {

        bool seen[10] = {};

        for (int row = 0; row < 9; row++) {

            char value = board[row][col];

            if (value == '.') {
                continue;
            }

            int number = value - '0';

            if (seen[number]) {
                cout << "Invalid Sudoku!" << endl
                     << "Duplicate '" << value
                     << "' found in column "
                     << col + 1 << "." << endl;

                return false;
            }

            seen[number] = true;
        }
    }

    for (int startRow = 0; startRow < 9; startRow += 3) {

        for (int startCol = 0; startCol < 9; startCol += 3) {

            bool seen[10] = {};

            for (int row = startRow; row < startRow + 3; row++) {

                for (int col = startCol; col < startCol + 3; col++) {

                    char value = board[row][col];

                    if (value == '.') {
                        continue;
                    }

                    int number = value - '0';

                    if (seen[number]) {

                        cout << "Invalid Sudoku!" << endl;
                        cout << "Duplicate '" << value
                             << "' found in 3x3 box."
                             << endl;

                        return false;
                    }

                    seen[number] = true;
                }
            }
        }
    }

    return true;
}

bool SudokuSolver::isSafe(
    vector<vector<char>>& board,
    int row,
    int col,
    char digit
) {

    for (int j = 0; j < 9; j++) {
        if (board[row][j] == digit) {
            return false;
        }
    }

    for (int i = 0; i < 9; i++) {
        if (board[i][col] == digit) {
            return false;
        }
    }

    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;

    for (int i = startRow; i < startRow + 3; i++) {
        for (int j = startCol; j < startCol + 3; j++) {
            if (board[i][j] == digit) {
                return false;
            }
        }
    }

    return true;
}

bool SudokuSolver::helper(vector<vector<char>>& board) {

    recursiveCalls++;

    int bestRow;
    int bestCol;

    if (!findBestCell(board, bestRow, bestCol)) {

        return true;
    }

    for (char digit = '1'; digit <= '9'; digit++) {

        numbersTried++;

        if (isSafe(board, bestRow, bestCol, digit)) {

            board[bestRow][bestCol] = digit;

            if (helper(board)) {
                return true;
            }

            board[bestRow][bestCol] = '.';

            backtracks++;
        }
    }

    return false;
}

bool SudokuSolver::solve(vector<vector<char>>& board) {
    return helper(board);
}

long long SudokuSolver::getRecursiveCalls() const {
    return recursiveCalls;
}

long long SudokuSolver::getNumbersTried() const {
    return numbersTried;
}

long long SudokuSolver::getBacktracks() const {
    return backtracks;
}