//
// Created by Admin on 18/10/2024.
//

#ifndef PION_H
#define PION_H
#include <string>
#include <tuple>

using namespace std;


class pion {
private:
    string couleur ;
    tuple<int,int> coordonne;

public :
    pion (string couleur, int x, int y): couleur("R"),coordonne(make_tuple(x, y)) {}

    string getCouleur() {
        return couleur;
    }
    tuple<int,int> getCoordonne(){
        return coordonne;
    }
    int getX() {
        return get<0>(coordonne);
    }
    int getY() {
        return get<1>(coordonne);
    }
    void setCoordonne(int x, int y) {
        coordonne =make_tuple(x, y);
    }
    void setX(int x) {
        get<0>(coordonne) = x;
    }
    void setY(int y) {
        get<1>(coordonne) = y;
    }


    tuple<int, int> getCoordonne() const {
        return coordonne;
    }

};



#endif //PION_H
