// Board.h

#ifndef PUISSANCE4_BOARD_H
#define PUISSANCE4_BOARD_H

#include <vector>
using namespace std;

class Board {
public:
    Board(int rows = 6, int cols = 7);
    void display() const;

private:
    int rows;
    int cols;
    vector<vector<char>> grid;
};

#endif //PUISSANCE4_BOARD_H