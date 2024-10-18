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
    bool etat;
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
    void setCoordonne(int x, int y) {
    coordonne =make_tuple(x, y);
}
    int getX() {
        return get<0>(coordonne);
    }
    int getY() {
        return get<1>(coordonne);
    }

    void setX(int x) {
        get<0>(coordonne) = x;
    }
    void setY(int y) {
        get<1>(coordonne) = y;
    }
    bool getEtat() {
        return etat;
    }
    bool setEtat(bool nouvelEtat) {
        etat=nouvelEtat;
    }


};



#endif //PION_H
