#include <iostream>
#include "Point2D.h"
#include "Vector2D.h"
#include <cmath>
#include "GameObject.h"
using namespace std;

int main() {
    Point2D p1(3,5);
    Point2D p2(1,2);
    cout<< p1 << endl;
    cout<< p2 << endl;
    Vector2D v1(10,15);
    Vector2D v2(15,20);
    cout << v1 << endl;
    cout << v2 << endl;
    cout << v1/5 << endl;
    cout << v2*2 << endl;
return 0;
}