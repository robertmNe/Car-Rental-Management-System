#include "Customer.h"
#include <iostream>

Customer::Customer() {
    customerNumber = 0;
    name = "";
    address = "";
    telephone = "";
    rentalCount = 0;
    
    rentals = new Rental*[MAX_RENTALS];
    for (int i = 0; i < MAX_RENTALS; i++) {
        rentals[i] = nullptr;
    }
}

Customer::Customer(int num, const string& n, const string& addr, const string& tel) {
    customerNumber = num;
    name = n;
    address = addr;
    telephone = tel;
    rentalCount = 0;
    
    rentals = new Rental*[MAX_RENTALS];
    for (int i = 0; i < MAX_RENTALS; i++) {
        rentals[i] = nullptr;
    }
}

Customer::Customer(const Customer& other) {
    customerNumber = other.customerNumber;
    name = other.name;
    address = other.address;
    telephone = other.telephone;
    rentalCount = other.rentalCount;
    
    rentals = new Rental*[MAX_RENTALS];
    for (int i = 0; i < MAX_RENTALS; i++) {
        if (other.rentals[i] != nullptr) {
      
            rentals[i] = new Rental(*(other.rentals[i]));
        } else {
            rentals[i] = nullptr;
        }
    }
}

Customer::~Customer() {
    for (int i = 0; i < rentalCount; i++) {
        delete rentals[i];
    }
    delete[] rentals;
}

int Customer::getCustomerNumber() const { return customerNumber; }
string Customer::getName() const { return name; }
string Customer::getAddress() const { return address; }
string Customer::getTelephone() const { return telephone; }
int Customer::getRentalCount() const { return rentalCount; }

bool Customer::rentCar(Car* car, const string& rentalDate, int numDays) {
    if (car != nullptr && car->getIsAvailable() && rentalCount < MAX_RENTALS) {
        rentals[rentalCount] = new Rental(car, rentalDate, numDays);
        rentalCount++;
        car->setIsAvailable(false);
        return true;
    }
    return false;
}

bool Customer::returnCar(int carID, const string& returnDate) {
    for (int i = 0; i < rentalCount; i++) {
        if (rentals[i]->getCar()->getIdentification() == carID && !rentals[i]->isReturned()) {
            rentals[i]->returnCar(returnDate);
            return true;
        }
    }
    return false;
}

void Customer::printRentals() const {
    for (int i = 0; i < rentalCount; i++) {
        rentals[i]->print();
    }
}

void Customer::print() const {
    cout << "Customer #" << customerNumber << ": " << name << " | Address: " << address << " | Tel: " << telephone;
}

string Customer::getCustomerType() const { return "Generic"; }

RegularCustomer::RegularCustomer() : Customer() {}

RegularCustomer::RegularCustomer(int num, const string& name, const string& address, const string& tel) 
    : Customer(num, name, address, tel) {}

RegularCustomer::RegularCustomer(const RegularCustomer& other) : Customer(other) {}

RegularCustomer::~RegularCustomer() {}

void RegularCustomer::print() const {
    cout << "[Regular] ";
    Customer::print();
    cout << endl;
}

string RegularCustomer::getCustomerType() const { return "Regular"; }

CorporateCustomer::CorporateCustomer() : Customer() {
    companyName = "";
}

CorporateCustomer::CorporateCustomer(int num, const string& name, const string& address, const string& tel, const string& cName) 
    : Customer(num, name, address, tel) {
    companyName = cName;
}

CorporateCustomer::CorporateCustomer(const CorporateCustomer& other) : Customer(other) {
    companyName = other.companyName;
}

CorporateCustomer::~CorporateCustomer() {}

string CorporateCustomer::getCompanyName() const { return companyName; }

void CorporateCustomer::print() const {
    cout << "[Corporate: " << companyName << "] ";
    Customer::print();
    cout << endl;
}

string CorporateCustomer::getCustomerType() const { return "Corporate"; }