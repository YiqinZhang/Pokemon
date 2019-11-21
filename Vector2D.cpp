//
// Created by Garfield on 2019-11-19.
//

#include "Vector2D.h"
#include <iostream>

using namespace std;

Vector2D::Vector2D()
{
    x = 0.0;
    y = 0.0;
}

Vector2D::Vector2D(double in_x, double in_y)
{
    x = in_x;
    y = in_y;
}


Vector2D operator*(Vector2D v1, double d)
{
    Vector2D v2;
    v2.x = v1.x * d;
    v2.y = v1.y * d;
    return v2;
}

Vector2D operator/ (Vector2D v1, double d)
{
    if (d)
    {
        Vector2D v2;
        v2.x = v1.x / d;
        v2.y = v1.y / d;
        return v2;
    }
    else return v1;
}

ostream& operator<< (ostream & os, Vector2D v1)
{
    os <<"<" << v1.x << ","<<v1.y << ">";
    return os;
}