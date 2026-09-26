#ifndef SUDOKUSOLVER_H
#define SUDOKUSOLVER_H

#include <vector>
using namespace std;

class SudokuSolver {
private:

    long long recursiveCalls;
    long long numbersTried;
    long long backtracks;

    bool isSafe(
        vector<vector<char>>& board,
        int row,
        int col,
        char digit
    );

    bool helper(vector<vector<char>>& board);
    bool findBestCell(
        vector<vector<char>>& board,
        int & bestRow,
        int & bestCol
    );

public:
    SudokuSolver();
    bool solve(vector<vector<char>>& board);
    bool isValidBoard(
        const vector<vector<char>>& board
    );

    long long getRecursiveCalls() const;
    long long getNumbersTried() const;
    long long getBacktracks() const;
};
#endif