#include "Company.h"
#include <iostream>
#include <string>
using namespace std;

//Constructor
Company::Company() 
{
    count = 0;

    for (int i = 0; i < 1000; i++){
        inventory [i] = nullptr;            //Initializing all of the slots in the inventory array
    }
}

// Copy constructor (create new objects)
Company::Company(const Company &other)
{
    count = other.count;
    for (int i = 0; i < count; i++){
        if (other.inventory[i] -> getType() == "Standard Car"){
            inventory[i] = new StandardCar(other.inventory[i]-> getIdentification());
        }else{
            inventory[i] = new LuxuryCar(other.inventory[i]-> getIdentification());
        }

        inventory[i]->setIsAvailable(other.inventory[i]->getIsAvailable());
    }
}

// Destructor
Company::~Company(){
    for(int i=0; i<count;i++){
        delete inventory[i];
        inventory[i] = nullptr;
    }
}

// Getters
int Company::getCount() const {
    return count;
}

//Functions
void Company::addCar(Car* c){
    if(count < 1000){
        inventory[count] = c;
        count++;
    } else {
        cout << "Car inventory is currently full" << endl;
    }
}

void Company::removeCar(int id){
    for (int i = 0; i < count; i++){
        if (inventory[i] -> getIdentification() == id){
            delete inventory[i];

            // To update the array and fill the gap we need to shift the array components
            for (int j = i; j < count-1; j++){
                inventory[j] = inventory[j+1];
            }
            //Empty out the slot where car was deleted
            inventory[count -1] = nullptr;
            count --;

            cout << "The car with the following ID was removed: " << id << endl;
            return;
        }
    }
    cout << "Cannot remove the following car: "<< id << endl;
}

void Company::findCar(int id){
    bool carFound = false;
    for (int i = 0; i < count; i++){
        if (inventory[i] -> getIdentification() == id){
            cout << "Car was found";
            inventory[i] -> print();
            carFound = true;
        }
    }
    if (carFound == false){
        cout << "The car with the following ID was not found: " << id <<endl;
    }
}

void Company::displayCar()const{
    cout << "----- CoenCars slection of cars -----" << endl;
    for (int i = 0; i < count; i++){
        inventory[i] -> print();
    } 
}
