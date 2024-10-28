// Board.cpp


#include "Board.h"
#include <iostream>

using namespace std;

Board::Board(int rows, int cols) : rows(rows), cols(cols), grid(rows, vector<int>(cols, 0)) {}

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

tuple<int, int> Board::checkGravity(int i) {
    tuple<int, int> caseEmpty;
    for (int j = 0; j < grid.size(); ++j) {
        if (grid[i][j] == 0) {
            caseEmpty = make_tuple(i, j);
        }
    }
    return caseEmpty;
}

void Board::putPion(int i, int j) {
    grid[j][i] = 1;
}

int Board::chooseCol() const  {
    int col = getCols();
    int num;
    do{
        cout << "Choisissez une colonne: ";
        cin >> num;
    }while(num < 0 || num > col);
    return num;
}

void Board::checkAround(int i, int j) {
    const int directions[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {1, 1}, {-1, 1}, {1, -1}};
    for (auto& dir : directions) {
        int new_i = i + dir[0];
        int new_j = j + dir[1];
        if (new_i >= 0 && new_i < getRows() && new_j >= 0 && new_j < getCols()) {
            cout << "Checking cell: (" << new_i << ", " << new_j << ")" << endl;
            if (grid[new_i][new_j] == 1) {
                cout << "Alignement détecté" << endl;
            } else {
                cout << "Pas d'alignement" << endl;
            }
        }
    }
}

void Board::win() {
    for (int i = 0; i < getRows(); ++i) {
        for (int j = 0; j < getCols(); ++j) {
            if (grid[i][j] == 1) {
                checkAround(i, j);
            }
        }
    }
}