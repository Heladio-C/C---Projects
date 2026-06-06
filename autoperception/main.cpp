#include "Vec2.h"
#include <iostream>
using namespace std;

int main(){
    Vec2 origin;

    Vec2 point1(3.0,4.0);

    cout << "Point P = ";
    point1.print();
    cout << endl;

    cout << "Magnitdue of p = " << point1.magnitude() << endl;
    cout << "Distance from origin to point 1: " << origin.distanceTo(point1) << endl;


    return 0;
}