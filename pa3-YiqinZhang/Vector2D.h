//
// Created by Garfield on 2019-11-05.
//

#ifndef PA33_VECTOR2D_H
#define PA33_VECTOR2D_H
#include <iostream>
using namespace std;

class Vector2D
{
public:
    double x;
    double y;
    Vector2D();
    Vector2D(double in_x, double in_y);
};

Vector2D operator* (Vector2D v1, double d);

Vector2D operator/ (Vector2D v1, double d);

ostream & operator<< (ostream & os, Vector2D v1);

#endif //PA33_VECTOR2D_H
