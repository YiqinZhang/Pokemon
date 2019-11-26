//
// Created by Garfield on 2019-11-04.
//
#include "Point2D.h"
#include "Vector2D.h"
#include <iostream>
#include <cmath>
using namespace std;

Point2D::Point2D()
    {
        x=0.0;
        y=0.0;
    }
Point2D::Point2D(double in_x, double in_y)
    {
        x = in_x;
        y = in_y;
    }

double GetDistanceBetween(Point2D p1, Point2D p2)
{
    return sqrt( pow (p1.x - p2.x, 2.0)+ pow (p1.y - p2.y, 2.0) );
}

ostream& operator<< (ostream & os, Point2D p1)
{
    os <<"(" << p1.x <<","<<p1.y << ")";
    return os;
}


Point2D operator+ (Point2D p1, Vector2D v1)
{
    Point2D p2;
    p2.x = p1.x + v1.x;
    p2.y = p1.y + v1.y;
    return p2;
}

Vector2D operator- (Point2D p1, Point2D p2)
{
    Vector2D v1;
    v1.x = p1.x - p2.x;
    v1.y = p1.y - p2.y;

    return v1;
}
