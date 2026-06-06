#include "Sensor.h"
#include <iostream>

using namespace std;

Sensor::Sensor(const std::string& name, const Vec2& position) : name(name), position(position), id(++nextId){
    count++;
}
