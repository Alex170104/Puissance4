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
    for (int j = 0; j < getRows(); ++j) {
        if (grid[j][i] == 0) {
            caseEmpty = make_tuple(i, j);
        }
    }
    return caseEmpty;
}

void Board::putPion(int i, int j, int player) {
    grid[j][i] = player;
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

bool Board::checkAround(int i, int j, int player) {
    const int directions[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {1, 1}, {-1, 1}, {1, -1}};
    for (auto& dir : directions) {
        int count = 1;
        int new_i = i + dir[0];
        int new_j = j + dir[1];
        while (new_i >= 0 && new_i < getRows() && new_j >= 0 && new_j < getCols() && grid[new_i][new_j] == player) {
            ++count;
            if (count == 4) {
                return true;
            }
            new_i += dir[0];
            new_j += dir[1];
        }
    }
    return false;
}

bool Board::win(int player) {
    for (int i = 0; i < getRows(); ++i) {
        for (int j = 0; j < getCols(); ++j) {
            if (grid[i][j] == player) {
                if (checkAround(i, j, player)) {
                    cout << "Victoire" << endl;
                    return true;
                }
            }
        }
    }
    cout << "Pas de victoire" << endl;
    return false;
}