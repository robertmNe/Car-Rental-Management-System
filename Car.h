#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <string>
using namespace std;

class Car 
{

    protected:
    int identification;
    string type;
    bool isAvailable;

    public:
    //Constructors
    Car();
    Car (int id, string t, bool ia);
    
    //Copy constructor
    Car (const Car &other);

    //Destructor
    virtual ~Car();

    //Setters and getters
    void setIdentification(int id);
    int getIdentification()const;
    void setType(string t);
    string getType()const;
    void setIsAvailable(bool ia);
    bool getIsAvailable()const;

    virtual void print()const = 0;

};

class StandardCar : public Car
{
    public:
    StandardCar (int id);
    void print() const override;
};

class LuxuryCar : public Car 
{
    public:
    LuxuryCar (int id);
    void print() const override;
};

#endif
