#include "Rental.h"
#include <iostream>
using namespace std;

Rental::Rental() {
    car = nullptr;
    rentalDate = "";
    returnDate = "";
    numDays = 0;
}

Rental::Rental(Car* c, const string& rDate, int days) {
    car = c;
    rentalDate = rDate;
    returnDate = "";
    numDays = days;
}

Rental::Rental(const Rental& other) {
    car = other.car;
    rentalDate = other.rentalDate;
    returnDate = other.returnDate;
    numDays = other.numDays;
}

// Rental does not own the Car pointer — do not delete it here
Rental::~Rental() {
}

Car* Rental::getCar() const {
    return car;
}

string Rental::getRentalDate() const {
    return rentalDate;
}

string Rental::getReturnDate() const {
    return returnDate;
}

int Rental::getNumDays() const {
    return numDays;
}

bool Rental::isReturned() const {
    return !returnDate.empty();
}

void Rental::returnCar(const string& retDate) {
    returnDate = retDate;
    if (car) car->setIsAvailable(true);
}

double Rental::getCost() const {
    if (!car) return 0.0;
    return car->calculateRentalCost(numDays);
}

void Rental::print() const {
    cout << "  Rental Details:" << endl;
    cout << "Car ID: " << (car ? to_string(car->getIdentification()) : "N/A") << endl;
    cout << "Car Type: " << (car ? car->getType() : "N/A") << endl;
    cout << "Rental Date: " << rentalDate << endl;
    cout << "Num Days: " << numDays << endl;
    cout << "Return Date: " << (returnDate.empty() ? "Not yet returned" : returnDate) << endl;
    cout << "Total Cost: $" << getCost() << endl;
}
