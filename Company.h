#ifndef COMPANY_H
#define COMPANY_H
#include "Car.h"

#include <iostream>
#include <string>
using namespace std;

class Company 
{

    private:
    Car* inventory[1000];
    int count;

    public:
    //Constructors
    Company();

    //Copy constructor
    Company (const Company &other);

    //Destructor
    ~Company();

    //Getters
    int getCount()const;

    //Functions
    void addCar(Car* c);
    void removeCar(int id);
    void findCar(int id);
    Car* getCar(int id) const;
    void displayCar()const;

};

#endif