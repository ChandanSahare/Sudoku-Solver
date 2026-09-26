#include "SudokuUI.h"
#include "SudokuSolver.h"

#include <iostream>
#include <chrono>
#include <limits>

using namespace std;


bool SudokuUI::isValidRow(const string& row) {
    
    if (row.length() != 9) {
        return false;
    }
    
    for (char c : row) {
        
        if (c != '.' && (c < '1' || c > '9')) {
            return false;
        }
    }
    
    return true;
}

void SudokuUI::printBoard(
    const vector<vector<char>>& board
) {
    
    for (int i = 0; i < 9; i++) {
        
        if (i % 3 == 0) {
            cout << "+------+------+------+" << endl;
        }
        
        for (int j = 0; j < 9; j++) {
            
            if (j % 3 == 0) {
                cout << "|";
            }
            
            cout << board[i][j] << " ";
        }
        
        cout << "|" << endl;
    }
    
    cout << "+------+------+------+" << endl;
}

int SudokuUI::chooseVisualizationMode() {

    while (true) {

        cout << "\nChoose visualization mode:" << endl;
        cout << "1. Step-by-step" << endl;
        cout << "2. Automatic" << endl;
        cout << "3. Back" << endl;

        cout << "\nEnter choice: ";

        int choice;
        cin >> choice;

        if (choice >= 1 && choice <= 3) {
            return choice;
        }

        cout << "\nInvalid choice. Try again." << endl;
    }
}

vector<vector<char>> SudokuUI::inputBoard() {

    vector<vector<char>> board(
        9,
        vector<char>(9)
    );

    cout << "Enter Sudoku row by row." << endl
         << "Use '.' for empty cells." << endl
         << endl;

    for (int i = 0; i < 9; i++) {

        while (true) {

            string row;

            cout << "Row " << i + 1 << ": ";

            cin >> row;

            if (isValidRow(row)) {

                for (int j = 0; j < 9; j++) {
                    board[i][j] = row[j];
                }

                break;
            }

            cout << "Invalid input! "
                 << "Enter exactly 9 characters using 1-9 or '.'."
                 << endl;
        }
    }

    return board;
}

vector<vector<char>> SudokuUI::getEasyBoard() {

    return {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
}

vector<vector<char>> SudokuUI::getMediumBoard() {

    return {
        {'.','.','9','7','4','8','.','.','.'},
        {'7','.','.','.','.','.','.','.','.'},
        {'.','2','.','1','.','9','.','.','.'},
        {'.','.','7','.','2','.','5','.','.'},
        {'.','8','6','.','3','.','1','7','.'},
        {'.','.','2','.','7','.','8','.','.'},
        {'.','.','.','6','.','2','.','1','.'},
        {'.','.','.','.','.','.','.','5','.'},
        {'.','.','.','.','8','7','2','.','.'}
    };
}

vector<vector<char>> SudokuUI::getHardBoard() {

    return {
        {'.','.','.','.','.','7','.','.','9'},
        {'.','.','9','.','.','.','3','.','.'},
        {'.','.','2','.','.','.','.','8','.'},
        {'.','.','.','.','1','5','.','.','.'},
        {'.','3','.','.','.','.','.','4','.'},
        {'.','.','.','6','.','.','.','.','.'},
        {'.','5','.','.','.','.','7','.','.'},
        {'.','.','7','.','.','.','2','.','.'},
        {'4','.','.','5','.','.','.','.','.'}
    };
}

vector<vector<char>> SudokuUI::chooseSampleBoard() {

    while (true) {

        cout << "\nChoose difficulty:" << endl;
        cout << "1. Easy" << endl;
        cout << "2. Medium" << endl;
        cout << "3. Hard" << endl;
        cout << "4. Back" << endl;

        cout << "\nEnter choice: ";

        int choice;
        cin >> choice;

        if (choice == 1) {
            return getEasyBoard();
        }

        if (choice == 2) {
            return getMediumBoard();
        }

        if (choice == 3) {
            return getHardBoard();
        }

        if (choice == 4) {
            return {};
        }

        cout << "\nInvalid choice. Try again." << endl;
    }
}
bool chooseVisualizationMode() {

    while (true) {

        cout << "\nChoose visualization mode:" << endl;
        cout << "1. Step-by-step" << endl;
        cout << "2. Automatic" << endl;
        cout << "3. Back" << endl;

        cout << "\nEnter choice: ";

        int choice;
        cin >> choice;

        if (choice == 1) {
            return true;
        }

        if (choice == 2) {
            return false;
        }

        if (choice == 3) {
            return false;
        }

        cout << "\nInvalid choice. Try again." << endl;
    }
}

void SudokuUI::solveAndDisplay(
    vector<vector<char>>& board,
    bool visualize
) {

SudokuSolver solver;
solver.setVisualization(visualize);

if (visualize) {
    int mode = chooseVisualizationMode();
    if (mode == 3) {
        return;
    }
    solver.setStepByStep(mode == 1);
}
    cout << "\nOriginal Sudoku:" << endl;
    printBoard(board);

    if (!solver.isValidBoard(board)) {
        cout << "\nInvalid Sudoku!" << endl;
        return;
    }

    auto start =
        chrono::high_resolution_clock::now();

    bool solved = solver.solve(board);

    auto end =
        chrono::high_resolution_clock::now();

    auto duration =
        chrono::duration_cast<chrono::microseconds>(
            end - start
        ).count();

    double timeInMilliseconds =
        duration / 1000.0;

    if (solved) {

        cout << "\nSolved Sudoku:" << endl;

        printBoard(board);

        if (visualize) {

            cout << "\n========================================"
                 << endl;

            cout << "          SOLVING COMPLETE"
                 << endl;

            cout << "========================================"
                 << endl;
        }

        cout << "\n================================"
             << endl;

        cout << "       SOLVING STATISTICS"
             << endl;

        cout << "================================"
             << endl;

        cout << "Recursive calls : "
             << solver.getRecursiveCalls()
             << endl;

        cout << "Numbers tried   : "
             << solver.getNumbersTried()
             << endl;

        cout << "Backtracks      : "
             << solver.getBacktracks()
             << endl;

        cout << "Solving time    : "
             << duration
             << " microseconds"
             << " (" << timeInMilliseconds
             << " ms)"
             << endl;

        cout << "================================"
             << endl;

        if (visualize) {

            cout << "\nPress ENTER to return to the menu...";

            cin.ignore(
                numeric_limits<streamsize>::max(),
                '\n'
            );

            cin.get();
        }

    } else {

        cout << "\nNo solution exists."
             << endl;
    }
}
void SudokuUI::run() {

    while (true) {

        cout << "\n========================================" << endl;
        cout << "           SUDOKU SOLVER" << endl;
        cout << "========================================" << endl;

        cout << "\n1. Enter Sudoku manually" << endl
             << "2. Use sample Sudoku" << endl
             << "3. Watch solver step-by-step" << endl
             << "4. Exit" << endl
             << "\nEnter choice: ";

        int choice;
        cin >> choice;

        if (choice == 1) {

            vector<vector<char>> board = inputBoard();

            solveAndDisplay(board, false);
        }

        else if (choice == 2) {

            vector<vector<char>> board =
                chooseSampleBoard();

            if (!board.empty()) {

                solveAndDisplay(board, false);
            }
        }

        else if (choice == 3) {

            vector<vector<char>> board =
                chooseSampleBoard();

            if (!board.empty()) {

                solveAndDisplay(board, true);
            }
        }

        else if (choice == 4) {

            cout << "\nThank you for using Sudoku Solver!"
                 << endl;

            break;
        }

        else {

            cout << "\nInvalid choice. "
                 << "Please choose 1, 2, 3, or 4."
                 << endl;
        }
    }
}