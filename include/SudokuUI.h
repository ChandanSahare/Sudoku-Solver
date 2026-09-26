#ifndef SUDOKU_UI_H
#define SUDOKU_UI_H

#include <vector>
#include <string>

using namespace std;

class SudokuUI {

public:

    void run();

private:

    int chooseVisualizationMode();
    vector<vector<char>> inputBoard();
    vector<vector<char>> chooseSampleBoard();
    vector<vector<char>> getEasyBoard();
    vector<vector<char>> getMediumBoard();
    vector<vector<char>> getHardBoard();

    void printBoard(
        const vector<vector<char>>& board
    );

    void solveAndDisplay(
        vector<vector<char>>& board,
        bool visualize = false
    );

    bool isValidRow(
        const string& row
    );
};

#endif