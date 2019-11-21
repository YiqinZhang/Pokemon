//
// Created by Garfield on 2019-11-08.
//

#include <iostream>
#include "PokemonGym.h"
#include "PokemonCenter.h"
#include "Building.h"
#include "Point2D.h"

using namespace std;

int main() {
    Point2D p1(3.14,7.07);
    Point2D p2(5,7);
    cout<< p1 << endl;
    cout<< p2 << endl;
    Vector2D v1(10,15);
    Vector2D v2(15,20);
    cout << v1 << endl;
    cout << v2 << endl;
    cout << p1 + v1 << endl;
    cout << p1 - p2 << endl;
    cout << v1/5 << endl;
    cout << v2*2 << endl;
    GameObject g1('Z');
    GameObject g2(p1, 123,'Z');
    g1.ShowStatus();
    g2.ShowStatus();

    Building b1;
    b1.ShowStatus();

    Building b2('z',222,p1);
    b2.ShowStatus();

    PokemonCenter Center1;
    PokemonCenter Center2(2,2,2,p2);
    Center1.ShowStatus();
    Center2.ShowStatus();

    PokemonGym Gym1;
    Gym1.ShowStatus();
    PokemonGym Gym2(3,3,3,3,3,p1);
    Gym2.TrainPokemon(3);
    Gym2.ShowStatus();
    return 0;
}