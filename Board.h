// Board.h

#ifndef PUISSANCE4_BOARD_H
#define PUISSANCE4_BOARD_H

#include <vector>
using namespace std;

class Board {
public:
    explicit Board(int rows = 7, int cols = 7);
    int getRows() const { return rows; }
    int getCols() const { return rows; }
    void display() const;
    void putPion(int i, int j);
    void checkAround(int i, int j);
    int chooseCol(void) const;
    tuple<int, int> checkGravity(int i);
    void win();

private:
    int rows;
    int cols;
    vector<vector<int>> grid;


};

#endif //PUISSANCE4_BOARD_H