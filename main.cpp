#include <iostream>
#include "Board.h"
#include "JEU.h"

int main() {
    Board board;
    board.display();
    JEU::alignement(board);
    return 0;
}