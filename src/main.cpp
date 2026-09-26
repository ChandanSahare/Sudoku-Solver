#include <iostream>
#include <vector>
#include <string>
#include<chrono>

#include "SudokuSolver.h"

using namespace std;

bool isValidRow(const string& row) {
    if (row.length() != 9) return false;
    for (char c : row) {
        if (c != '.' && (c < '1' || c > '9')) return false;
    }
    return true;
}

vector<vector<char>> inputBoard() {
    vector<vector<char>> board(9, vector<char>(9));
    cout << "Enter Sudoku row by row." << endl 
         << "Use '.' for empty cells." << endl
         << endl ;
    
    for (int i=0;i<9;i++) {
        while(true) {
            string row ;
            cout << "Row " << i+1 << ": " ;
            cin >> row ;
            if(isValidRow(row)) {
                for(int j=0;j<9;j++) {
                    board[i][j] = row[j];
                }
                break;
            }

            cout << "Invalid input! " 
                 << "Enter exactly 9 characters using 1-9 or '.'." << endl ;
        }
    }
    return board ;
}

void printBoard(const vector<vector<char>>& board) {
    for(int i=0;i<9;i++) {
        if(i % 3 == 0) cout << "+------+------+------+" << endl;
        for(int j=0;j<9;j++) {
            if(j % 3 == 0) cout << "|";
            cout << board[i][j] << " ";
        }
        cout << "|"<< endl;
    }
    cout << "+------+------+------+" << endl;
}

vector<vector<char>> getEasyBoard() {

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

vector<vector<char>> getMediumBoard() {

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

vector<vector<char>> getHardBoard() {

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

void solveAndDisplay(vector<vector<char>>& board) {

    SudokuSolver solver;

    cout << "\nOriginal Sudoku:" << endl;
    printBoard(board);

    if (!solver.isValidBoard(board)) {
        cout << "\nInvalid Sudoku!" << endl;
        return;
    }

    auto start = chrono::high_resolution_clock::now();

    bool solved = solver.solve(board);

    auto end = chrono::high_resolution_clock::now();

    auto duration =
        chrono::duration_cast<chrono::microseconds>(
            end - start
        ).count();

    double timeInMilliseconds = duration / 1000.0;

    if (solved) {

        cout << "\nSolved Sudoku:" << endl;
        printBoard(board);

        cout << "\n================================" << endl;
        cout << "       SOLVING STATISTICS" << endl;
        cout << "================================" << endl;

        cout << "Recursive calls : "
             << solver.getRecursiveCalls() << endl;

        cout << "Numbers tried   : "
             << solver.getNumbersTried() << endl;

        cout << "Backtracks      : "
             << solver.getBacktracks() << endl;

        cout << "Solving time    : "
             << duration << " microseconds"
             << " (" << timeInMilliseconds << " ms)"
             << endl;

        cout << "================================" << endl;

    } else {

        cout << "\nNo solution exists." << endl;
    }
}

vector<vector<char>> chooseSampleBoard() {

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

int main() {

    while (true) {

        cout << "\n========================================" << endl;
        cout << "           SUDOKU SOLVER" << endl;
        cout << "========================================" << endl;

        cout << "\n1. Enter Sudoku manually" << endl;
        cout << "2. Use sample Sudoku" << endl;
        cout << "3. Exit" << endl;

        cout << "\nEnter choice: ";

        int choice;
        cin >> choice;

        if (choice == 1) {
            vector<vector<char>> board = inputBoard();
            solveAndDisplay(board);
        }
        else if (choice == 2) {
            vector<vector<char>> board = chooseSampleBoard();
            if(!board.empty()) {
                solveAndDisplay(board);
            }
        }
        else if (choice == 3) {
            cout << "\nThank you for using Sudoku Solver!" << endl;
            break;
        }
        else {
            cout << "\nInvalid choice. Please choose 1, 2, or 3."
                 << endl;
        }
    }
    return 0;
}