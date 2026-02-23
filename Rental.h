#ifndef RENTAL_H
#define RENTAL_H

#include "Car.h" 
#include <string>
using namespace std;

class Rental {

  private:
        Car* car;  
        string rentalDate;
        string returnDate;
        int numDays;

  public:
        Rental();
        Rental(Car* c, const string& rDate, int days);
        Rental(const Rental& other);
        ~Rental();

        Car*   getCar()        const;
        string getRentalDate() const;
        string getReturnDate() const;
        int    getNumDays()    const;
        bool   isReturned()    const;

        void returnCar(const string& returnDate);

        double getCost() const;

        void print() const;
};

#endif
