// Board.h

#ifndef PUISSANCE4_BOARD_H
#define PUISSANCE4_BOARD_H

#include <vector>
using namespace std;

class Board {
public:
    explicit Board(int rows = 6, int cols = 7);
    void display() const;
    [[nodiscard]] int getRows() const { return rows; }
    [[nodiscard]] int getCols() const { return cols; }
    [[nodiscard]] vector<vector<int>>& getGrid() { return grid; }
    void setCell(int x, int y, int value);

private:
    int rows;
    int cols;
    vector<vector<int>> grid;
};

#endif //PUISSANCE4_BOARD_H