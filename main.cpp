#include <iostream>
#include "Board.h"
#include "raylib.h"

int main() {



    int choose;
    int player = 1;
    bool gameWon = false;
    int gameMode;
    cout << "GAME MODE : 1 or 2" << endl;
    cin >> gameMode;
    Board board;

    int cellSize = 100;

    InitWindow(board.getCols() * cellSize +100, board.getRows() * cellSize +100, "Raylib Example");
    SetTargetFPS(60);



    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        for (int i = 0; i < board.getRows(); i++) {
            for (int j = 0; j < board.getCols(); j++) {
                Color cellColor = BLACK;
                DrawRectangle(j * cellSize+50, i * cellSize+50, cellSize, cellSize, cellColor);
                DrawRectangleLines(j * cellSize +50, i * cellSize +50, cellSize, cellSize, GRAY);
                if (board.getGrid(i, j) == 1) {
                    DrawCircle(j * cellSize +50 + cellSize / 2, i * cellSize +50 + cellSize / 2, cellSize / 2 - 10, RED);
                } else if (board.getGrid(i, j) == 2) {
                    DrawCircle(j * cellSize +50 + cellSize / 2, i * cellSize +50 + cellSize / 2, cellSize / 2 - 10, BLUE);
                }
            }
        }

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            Vector2 mousePosition = GetMousePosition();
            cout << "Mouse clicked at: (" << mousePosition.x << ", " << mousePosition.y << ")" << endl;
            int col = (mousePosition.x - 50) / cellSize;
            int row = (mousePosition.y - 50) / cellSize;
            cout << "Mouse clicked at: (" << row << ", " << col << ")" << endl;
            auto [newCol, newRow] = board.checkGravity(col);
            board.putPion(newCol, newRow, player);
            gameWon = board.win(player);
            if (gameWon) {
                cout << "Player " << player << " wins!" << endl;
            } else {
                player = (player == 1) ? 2 : 1;
            }
        }

        EndDrawing();
    }

    CloseWindow();




//    board.display();
//    if (gameMode == 1) {
//        while (!gameWon) {
//            choose = board.chooseCol();
//            auto [row, col] = board.checkGravity(choose);
//            board.putPion(row, col, player);
//            board.display();
//            gameWon = board.win(player);
//            if (gameWon) {
//                cout << "Player " << player << " wins!" << endl;
//            } else {
//                player = (player == 1) ? 2 : 1;
//            }
//        }
//    }
//    else if (gameMode == 2) {
//        while (!gameWon) {
//            if (player == 1) {
//                choose = board.chooseCol();
//            } else{
//                choose = board.chooseColBot();
//                cout << "le BOT choose column " << choose << endl;
//            }
//            auto [row, col] = board.checkGravity(choose);
//            board.putPion(row, col, player);
//            board.display();
//            gameWon = board.win(player);
//            if (gameWon) {
//                cout << "Player " << player << " wins!" << endl;
//            } else {
//                player = (player == 1) ? 2 : 1;
//            }
//        }
//    }

    return 0;
}

