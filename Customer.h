#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Rental.h"
#include <string>
using namespace std;

const int MAX_RENTALS = 200;

class Customer {

protected:
  int customerNumber;
  string name;
  string address;
  string telephone;

  Rental** rentals;
  int rentalCount;

public:
  Customer();
  Customer(int num, const string& name, const string& address, const string& tel);  
  Customer(const Customer& other);  
  virtual ~Customer();

  int getCustomerNumber() const;
  string getName() const;
  string getAddress() const;
  string getTelephone() const;
  int getRentalCount() const;

  bool rentCar(Car* car, const string& rentalDate, int numDays);

  bool returnCar(int carID, const string& returnDate);

  void printRentals() const; 

  virtual void print() const;

  virtual string getCustomerType() const; 
};

class RegularCustomer : public Customer {

public:
  RegularCustomer();
  RegularCustomer(int num, const string& name, const string& address, const string& tel);
  RegularCustomer(const RegularCustomer& other);
  virtual ~RegularCustomer();

  virtual void print() const override;
  virtual string getCustomerType() const override;
};

class CorporateCustomer : public Customer {

private:
    string companyName;

public:
  CorporateCustomer();
  CorporateCustomer(int num, const string& name, const string& address, const string& tel, const string& companyName);
  CorporateCustomer(const CorporateCustomer& other);
  virtual ~CorporateCustomer();

  string getCompanyName() const;

  virtual void print() const override;
  virtual string getCustomerType() const override;
};

#endif
