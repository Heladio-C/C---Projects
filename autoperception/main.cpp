#include "Sensor.h"
#include "Lidar.h"
#include <iostream>
using namespace std;

int main(){
    
    Lidar frontLidar("Front Lidar" , Vec2(2.5, 0.0), 80);

    frontLidar.printInfo();
    frontLidar.scan();

    cout << "Via base class pointer (polymorphism)" << endl;
    


    return 0;
}