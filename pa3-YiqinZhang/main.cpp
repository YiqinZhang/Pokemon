#include <iostream>
#include "Point2D.h"
#include "Vector2D.h"
#include <cmath>
#include "GameObject.h"
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
    GameObject g1('a');
    GameObject g2(p1, 123,'a');
    g1.ShowStatus();
    g2.ShowStatus();
return 0;
}