//
// Created by alexd on 18/10/2024.
//

#include "JEU.h"
#include "Pion.h"
#include <iostream>
#include "Board.h"

using namespace std;

tuple<int, int> JEU::checkGravity(Board& board, int i) {
    tuple<int, int> caseEmpty;
    for (int j = 0; j < board.getRows(); ++j) {
        if (board.getGrid()[i][j] == 0) {
            caseEmpty = make_tuple(i, j);
        }
    }
    return caseEmpty;
}

void JEU::putPion(Board& board, int i, int j) {
    board.setCell(j, i, 1);
}

