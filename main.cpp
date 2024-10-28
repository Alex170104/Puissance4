#include <iostream>
#include "Board.h"

int main() {
    Board board;
    board.display();
    auto [row, col] = board.checkGravity(3);
    cout << "Empty cell at: (" << row << ", " << col << ")" << endl;
    board.putPion(row, col);
    board.display();
    board.win();
    return 0;
}