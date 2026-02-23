#include "Car.h"
#include <iostream>
#include <string>
using namespace std;

// Default constructor
Car::Car() 
{
    identification = 0;
    type = "No Type";
    isAvailable = true;
}

// Parameter constructor
Car::Car(int id, string t, bool ia) 
{
    identification = id;
    type = t;
    isAvailable = ia;
}
// Copy constructor
Car::Car(const Car &other)
{
    identification = other.identification;
    type = other.type;
    isAvailable = other.isAvailable;
}
// Destructor
Car::~Car(){}

// Setters
void Car::setIdentification(int id) {
    identification = id;
}
void Car::setType(string t) {
    type = t;
}
void Car::setIsAvailable(bool ia) {
    isAvailable = ia;
}

// Getters
int Car::getIdentification() const {
    return identification;
}
string Car::getType() const {
    return type;
}
bool Car::getIsAvailable() const {
    return isAvailable;
}

//Implementing the StandardCar class
StandardCar::StandardCar(int id){
    identification = id;
    type = "Standard Car";
    isAvailable = true;
}

// now for luxury cars
LuxuryCar::LuxuryCar(int id){
    identification = id;
    type = "Luxury Car";
    isAvailable = true;
}
//Functions
void StandardCar::print() const {
    cout << "Standard car ID: " << identification << endl; 
    cout <<"Availability: " << (isAvailable ? "Available" : "Not available") << endl;
}

void LuxuryCar::print()const{
    cout << "Luxury car ID: " << identification<< endl;  
    cout << "Availability: " << (isAvailable ? "Available" : "Not available") << endl;
}
