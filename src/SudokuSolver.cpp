#include "SudokuSolver.h"
#include <iostream>
#include <limits>
#include <windows.h>

void setConsoleColor(int color) {

    SetConsoleTextAttribute(
        GetStdHandle(STD_OUTPUT_HANDLE),
        color
    );
}

SudokuSolver::SudokuSolver() : recursiveCalls(0), numbersTried(0), backtracks(0), visualizationEnabled(false) {}

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

void printVisualizationBoard(
    const vector<vector<char>>& board
) {

    cout << "\n+------+------+------+" << endl;

    for (int row = 0; row < 9; row++) {

        for (int col = 0; col < 9; col++) {

            if (col % 3 == 0) {
                cout << "| ";
            }

            cout << board[row][col] << " ";

        }

        cout << "|" << endl;

        if ((row + 1) % 3 == 0) {
            cout << "+------+------+------+" << endl;
        }
    }
}

void waitForNextStep() {

    cout << "\nPress ENTER to continue...";

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
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

            if (visualizationEnabled) {

                setConsoleColor(10);

                cout << "Trying " << digit
                     << " at row " << bestRow + 1
                     << ", column " << bestCol + 1
                     << endl;

                setConsoleColor(7);
            }


            board[bestRow][bestCol] = digit;

            if(visualizationEnabled) {
                printVisualizationBoard(board) ;
                waitForNextStep() ;
            }
            if(helper(board)) return true ;
            board[bestRow][bestCol] = '.';

            backtracks++;

            if (visualizationEnabled) {

                setConsoleColor(12);

                cout << "Backtracking from row "
                     << bestRow + 1
                     << ", column "
                     << bestCol + 1
                     << endl;

                setConsoleColor(7);
            }

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

void SudokuSolver::setVisualization(bool enable) {
    visualizationEnabled = enable;
}