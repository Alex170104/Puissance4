#include <iostream>
#include "Board.h"

int main() {
    Board board;
    board.display();
    int choose = board.chooseCol();
    auto [row, col] = board.checkGravity(choose);
    cout << "Empty cell at: (" << row << ", " << col << ")" << endl;
    board.putPion(row, col);
    board.display();
    board.win();
    return 0;
}