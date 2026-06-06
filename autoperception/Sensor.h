#ifndef SENSOR_H
#define SENSOR_H

#include "Vec2.h"
#include <iostream>

static int nextId;
static int count;

class Sensor{

    public:
    Sensor(std::string name, Vec2& position);
    ~Sensor();              //virtual destructor 


    //getters
    std::string getName() const;
    Vec2 getPosition() const;
    int getId() const;


    void printInfo();

    //virtual function makes this now abstract
    virtual void scan() const = 0; 

    

    private: 

    protected:
    std::string FrontLidar;
    Vec2 position;
    int id;




};



#endif