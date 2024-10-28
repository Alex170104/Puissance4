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
    void putPion(int i, int j, int player);
    bool checkAround(int i, int j, int player);
    int chooseCol() const;
    tuple<int, int> checkGravity(int i);
    bool win(int player);

private:
    int rows;
    int cols;
    vector<vector<int>> grid;


};

#endif //PUISSANCE4_BOARD_H