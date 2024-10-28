// Board.cpp


#include "Board.h"
#include <iostream>

using namespace std;

Board::Board(int rows, int cols) : rows(rows), cols(cols), grid(rows, vector<int>(cols, 0)) {}
void Board::setCell(int x, int y, int value) {
    if (x >= 0 && x < rows && y >= 0 && y < cols) {
        grid[x][y] = value;
    } else {
        cerr << "Invalid coordinates" << endl;
    }
}


void Board::display() const {
    for (const auto& row : grid) {
        for (int cell : row) {
            cout << "|" << cell; // Print "|" puis l'interieur de la case
        }
        cout << "|\n";
    }
    for (int i = 0; i < cols; ++i) {
        cout << " " << i;
    }
    cout << "\n";
}