//
// Created by Garfield on 2019-11-04.
//
#include <cmath>
#include <iostream>
#include "Vector2D.h"

#ifndef PA33_POINT2D_H
#define PA33_POINT2D_H
using namespace std;

class Vector2D;
class Point2D
{
    public:
    double x,y;
    Point2D ();
    Point2D (double in_x, double in_y);
};

double GetDistanceBetween(Point2D p1, Point2D p2);

ostream & operator<< (ostream & os, Point2D p1);

Point2D operator+ (Point2D p1, Vector2D v1);


#endif //PA33_POINT2D_H
