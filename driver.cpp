#include "Company.h"
#include "Customer.h"
#include <iostream>
using namespace std;

// -------------------------------------------------------
// Helper to print section headers
// -------------------------------------------------------
void section(const string& title) 
{
    cout << endl;
    cout << "========================================" << endl;
    cout << "  " << title << endl;
    cout << "========================================" << endl;
}

// -------------------------------------------------------
// Q1: Test Car hierarchy
// -------------------------------------------------------
void testCars() 
{
    section("Q1 - Car Hierarchy");

    // Create cars using dynamic allocation
    Car* c1 = new StandardCar(101);
    Car* c2 = new StandardCar(102);
    Car* c3 = new LuxuryCar(201);
    Car* c4 = new LuxuryCar(202);

    // print() called via base pointer — dynamic binding
    cout << endl << "--- print() via base pointer ---" << endl;
    c1->print();
    cout << endl;
    c3->print();

    // calculateRentalCost via base pointer
    cout << endl << "--- Rental cost for 5 days ---" << endl;
    cout << "Standard car 101: $" << c1->calculateRentalCost(5) << endl;
    cout << "Luxury car 201: $"   << c3->calculateRentalCost(5) << endl;

    // Availability
    cout << endl << "--- Availability ---" << endl;
    cout << "Car 101 available? " << (c1->getIsAvailable() ? "Yes" : "No") << endl;
    c1->setIsAvailable(false);
    cout << "After setIsAvailable(false): " << (c1->getIsAvailable() ? "Yes" : "No") << endl;
    c1->setIsAvailable(true);

    // Copy constructor test
    cout << endl << "--- Copy Constructor ---" << endl;
    StandardCar* original = new StandardCar(103);
    StandardCar* copy     = new StandardCar(*original);
    cout << "Original: "; original->print();
    cout << endl;
    cout << "Copy: ";     copy->print();

    delete c1; delete c2; delete c3; delete c4;
    delete original; delete copy;
}

// -------------------------------------------------------
// Q2: Test Company class
// -------------------------------------------------------
void testCompany() 
{
    section("Q2 - Company Class");

    Company* company = new Company();

    // Add cars
    cout << endl << "--- Adding cars ---" << endl;
    company->addCar(new StandardCar(101));
    company->addCar(new StandardCar(102));
    company->addCar(new LuxuryCar(201));
    company->addCar(new LuxuryCar(202));

    // Display all
    cout << endl << "--- All cars ---" << endl;
    company->displayCar();

    // Find a car
    cout << endl << "--- Find car 201 ---" << endl;
    company->findCar(201);

    // Find non-existent
    cout << endl << "--- Find car 999 ---" << endl;
    company->findCar(999);

    // Remove a car
    cout << endl << "--- Remove car 102 ---" << endl;
    company->removeCar(102);

    cout << endl << "--- Cars after removal ---" << endl;
    company->displayCar();

    cout << "Total cars: " << company->getCount() << endl;

    // Copy constructor test
    cout << endl << "--- Copy Constructor ---" << endl;
    Company* companyCopy = new Company(*company);
    cout << "Copy has " << companyCopy->getCount() << " cars:" << endl;
    companyCopy->displayCar();

    delete companyCopy;
    delete company;
}

// -------------------------------------------------------
// Q3: Test Customer class and rentals
// -------------------------------------------------------
void testCustomers() 
{
    section("Q3 - Customers and Rentals");

    // Create company and add cars
    Company* company = new Company();
    company->addCar(new StandardCar(101));
    company->addCar(new StandardCar(102));
    company->addCar(new LuxuryCar(201));
    company->addCar(new LuxuryCar(202));

    // Get car pointers for renting
    // We use a local array to hold them before company manages them
    Car* car101 = new StandardCar(101);
    Car* car102 = new StandardCar(102);
    Car* car201 = new LuxuryCar(201);
    Car* car202 = new LuxuryCar(202);

    // Create customers using dynamic allocation
    cout << endl << "--- Creating customers ---" << endl;
    Customer* c1 = new RegularCustomer(1, "Palantir Johns", "67 Maple St", "514-111-2222");
    Customer* c2 = new RegularCustomer(2, "Kratos Levine", "275 Berkshire Ave", "514-333-4444");
    Customer* c3 = new CorporateCustomer(3, "Black Rock", "611 Delaware Rd", "450-555-6666", "BlackRock");

    c1->print();
    c2->print();
    c3->print();

    // Rent cars
    section("Renting Cars");

    cout << endl << "--- Alice rents car 101 for 3 days ---" << endl;
    if (c1->rentCar(car101, "2026-02-10", 3)) 
    {
        cout << "Rental successful." << endl;
    }

    cout << endl << "--- Alice tries to rent car 101 again (unavailable) ---" << endl;
    if (!c1->rentCar(car101, "2026-02-10", 1)) 
    {
        cout << "Rental failed - car not available." << endl;
    }

    cout << endl << "--- Bob rents luxury car 201 for 5 days ---" << endl;
    if (c2->rentCar(car201, "2026-02-12", 5)) 
    {
        cout << "Rental successful." << endl;
    }

    cout << endl << "--- Carol rents car 102 and car 202 ---" << endl;
    if (c3->rentCar(car102, "2026-02-15", 7)) 
    {
        cout << "Rental successful." << endl;
    }
    if (c3->rentCar(car202, "2026-02-16", 2)) 
    {
        cout << "Rental successful." << endl;
    }

    // Return cars
    section("Returning Cars");

    cout << endl << "--- Alice returns car 101 ---" << endl;
    if (c1->returnCar(101, "2026-02-13")) 
    {
        cout << "Return successful." << endl;
        cout << "Car 101 available again? " << (car101->getIsAvailable() ? "Yes" : "No") << endl;
    }

    cout << endl << "--- Bob returns car 201 ---" << endl;
    if (c2->returnCar(201, "2026-02-17")) 
    {
        cout << "Return successful." << endl;
    }

    cout << endl << "--- Bob tries to return car 201 again ---" << endl;
    if (!c2->returnCar(201, "2026-02-18")) 
    {
        cout << "Return failed - already returned." << endl;
    }

    // Print rental histories
    section("Rental Histories");

    cout << endl << "--- Alice's rentals ---" << endl;
    c1->printRentals();

    cout << endl << "--- Bob's rentals ---" << endl;
    c2->printRentals();

    cout << endl << "--- Carol's rentals ---" << endl;
    c3->printRentals();

    // Customer type test
    section("Customer Types");
    cout << "c1 type: " << c1->getCustomerType() << endl;
    cout << "c3 type: " << c3->getCustomerType() << endl;

    // Copy constructor test
    section("Copy Constructor - Customer");
    Customer* c1copy = new RegularCustomer(*(RegularCustomer*)c1);
    cout << "Original: "; c1->print();
    cout << "Copy:     "; c1copy->print();

    delete c1; delete c2; delete c3; delete c1copy;
    delete car101; delete car102; delete car201; delete car202;
    delete company;
}

// -------------------------------------------------------
// main
// -------------------------------------------------------
int main() 
{
    cout << "============================================" << endl;
    cout << "coen244 assignment 2" << endl;
    cout << "Car Rental Management System" << endl;
    cout << "============================================" << endl;

    testCars();
    testCompany();
    testCustomers();

    cout << endl;
    cout << "============================================" << endl;
    cout << "  All tests complete.                       " << endl;
    cout << "============================================" << endl;

    return 0;
}
