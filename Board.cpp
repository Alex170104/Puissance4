// Board.cpp


#include "Board.h"
#include <iostream>

using namespace std;

Board::Board(int rows, int cols) : rows(rows), cols(cols), grid(rows, vector<char>(cols, ' ')) {}

void Board::display() const {
    for (const auto& row : grid) {
        for (char cell : row) {
            cout << "|" << cell;
        }
        cout << "|\n";
    }
    for (int i = 0; i < cols; ++i) {
        cout << " " << i;
    }
    cout << "\n";
}