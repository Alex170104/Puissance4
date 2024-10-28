#include <iostream>
#include "Board.h"

int main() {
    int choose;
    int player = 1;
    bool gameWon = false;
    int gameMode;
    cout << "GAME MODE : 1 or 2" << endl;
    cin >> gameMode;
    Board board;
    board.display();
    if (gameMode == 1) {
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
    }
    else if (gameMode == 2) {
        while (!gameWon) {
            if (player == 1) {
                choose = board.chooseCol();
            } else{
                choose = board.chooseColBot();
                cout << "le BOT choose column " << choose << endl;
            }
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
    }

    return 0;
}