#include <iostream>
#include "Board.h"

int main() {
    Board board;
    board.display();
    int choose;
    int player = 1;
    bool gameWon = false;
    while (!gameWon) {
        choose = board.chooseCol();
        auto [row, col] = board.checkGravity(choose);
        board.putPion(row, col, player);
        board.display();
        gameWon = board.win(player);
        if (gameWon) {
            cout << "Player " << player << " wins!" << endl;
        } else {
            player = (player == 1) ? 2 : 1;
        }
    }
    return 0;
}