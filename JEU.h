//
// Created by alexd on 18/10/2024.
//

#ifndef PUISSANCE4_JEU_H
#define PUISSANCE4_JEU_H

#include "Board.h"

class JEU {
public:
    static tuple<int, int> checkGravity(Board &board, int i);
    static void putPion(Board &board, int i, int j);
};


#endif //PUISSANCE4_JEU_H
