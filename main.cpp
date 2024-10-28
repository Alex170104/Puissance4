#include <iostream>
#include "Board.h"
#include "JEU.h"

//void testCheckAround() {
//    Board board;
//    // Initialiser le plateau avec des pions pour le test
//    board.getGrid()[0][0] = 1;
//    board.getGrid()[1][1] = 1;
//    board.getGrid()[2][2] = 1;
//    board.getGrid()[3][3] = 1; // Quatrième pion pour tester l'alignement
//
//    JEU jeu;
//    jeu.checkAround(board, 0, 0); // Devrait détecter un alignement et afficher un message
//}

//int main() {
//    testCheckAround();
//    return 0;
//}


int main() {
    Board board;
    board.display();
    auto [row, col] = JEU::checkGravity(board, 3);
    cout << "Empty cell at: (" << row << ", " << col << ")" << endl;
    JEU::putPion(board, row, col);
    board.display();
    return 0;
}