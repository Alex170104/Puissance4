//
// Created by alexd on 18/10/2024.
//

#include "JEU.h"
#include "Pion.h"
#include <iostream>

using namespace std;

bool JEU::alignement(const Board& board) {
    for (int i = 0; i < board.getCols(); ++i) {
        for (int j = 0; i < board.getRows(); ++i) {
            if (board.getGrid()[i][j] != 0) {
                JEU::checkAround(board, i, j, );
            }
        }
    }
}