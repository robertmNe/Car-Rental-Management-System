#include "Company.h"
#include "Customer.h"
#include <iostream>
using namespace std;

int main()
{
   
    // creating our company and adding 6 cars to our fleet 
    
    Company* company = new Company();

    company->addCar(new StandardCar(101));
    company->addCar(new StandardCar(102));
    company->addCar(new StandardCar(103));
    company->addCar(new LuxuryCar(501));
    company->addCar(new LuxuryCar(502));
    company->addCar(new LuxuryCar(503));

    // lists our fleet 
    cout << "xxx Initial Inventory xxx" << endl;
    cout << "\n";
    company->displayCar();

    
    // creating 3 regular customers and 2 corporate accts 
   
    Customer* michael = new RegularCustomer(1, "Michael Saylor",  "67 KFC St", "514-111-2222");
    Customer* tyler = new RegularCustomer(2, "Tyler Page", "4 Ridgewood Ave", "514-333-4444");
    Customer* daniel = new RegularCustomer(3, "Daniel Roberts", "420 Woodland Rd", "514-555-6666");
    Customer* palantir = new CorporateCustomer(4, "Palantir", "17 Cupertino Ave", "514-777-8888", "Palantir Inc");
    Customer* nvidia = new CorporateCustomer(5, "Nvidia", "200 AI Blvd", "514-999-0000", "Nvidia");

    
    // here we r getting some customers 
    
    cout << endl << "xxx Renting Cars xxx" << endl;
    cout << "\n";

    cout << "Attempting to rent Car 101 to Michael..." << endl;
    if (michael->rentCar(company->getCar(101), "2026-02-22", 5))
        cout << "Rental successful." << endl;
    else
        cout << "Rental failed: Car is not available." << endl;

    cout << "Attempting to rent Car 102 to Tyler..." << endl;
    if (tyler->rentCar(company->getCar(102), "2026-02-22", 3))
        cout << "Rental successful." << endl;
    else
        cout << "Rental failed: Car is not available." << endl;

    cout << "Attempting to rent Car 103 to Daniel..." << endl;
    if (daniel->rentCar(company->getCar(103), "2026-02-22", 7))
        cout << "Rental successful." << endl;
    else
        cout << "Rental failed: Car is not available." << endl;

    cout << "Attempting to rent Car 501 to Palantir..." << endl;
    if (palantir->rentCar(company->getCar(501), "2026-02-22", 4))
        cout << "Rental successful." << endl;
    else
        cout << "Rental failed: Car is not available." << endl;

    cout << "Attempting to rent Car 502 to Nvidia..." << endl;
    if (nvidia->rentCar(company->getCar(502), "2026-02-22", 6))
        cout << "Rental successful." << endl;
    else
        cout << "Rental failed: Car is not available." << endl;

    cout << "Attempting to rent Car 101 to Tyler (Already taken)..." << endl;
    if (tyler->rentCar(company->getCar(101), "2026-02-22", 2))
        cout << "Rental successful." << endl;
    else
        cout << "Rental failed as expected: Car is not available." << endl;

    
    // get info on our clients 
    
    cout << endl << "xxx Customer accounts xxx" << endl;
    cout << "\n";

    cout << "xxx Michael's account xxx" << endl;
    michael->print();
    michael->printRentals();

    cout << "xxx Tyler's account xxx" << endl;
    tyler->print();
    tyler->printRentals();

    cout << "xxx Daniel's account xxx" << endl;
    daniel->print();
    daniel->printRentals();

    cout << "xxx Palantir's account xxx" << endl;
    palantir->print();
    palantir->printRentals();

    cout << "xxx Nvidia's account xxx" << endl;
    nvidia->print();
    nvidia->printRentals();

    
    // customers returning some cars 
    
    cout << endl << "xxx Returning cars xxx" << endl;
    cout << "\n";

    cout << "Michael is returning car 101..." << endl;
    if (michael->returnCar(101, "2026-02-27"))
        cout << "Car 101 is now available." << endl;

    cout << "Palantir is returning car 501..." << endl;
    if (palantir->returnCar(501, "2026-02-26"))
        cout << "Car 501 is now available." << endl;

    cout << "Tyler tries to return car 101 (not his)..." << endl;
    if (!tyler->returnCar(101, "2026-02-26"))
        cout << "Return failed as expected: rental not found." << endl;

    
    // find a car in our fleet 
    
    cout << endl << "Searching for car 503 in company records:" << endl;
    company->findCar(503);

    
    // how to remove a car from our fleet 
    
    cout << "Removing car 103 from company inventory..." << endl;
    company->removeCar(103);

    // 
    // final list of cars, whether rented out or not. 
    // 
    cout << endl << "Final inventory list:" << endl;
    cout << "\n";
    company->displayCar();

    
    // wiping everything 
    
    delete michael;
    delete tyler;
    delete daniel;
    delete palantir;
    delete nvidia;
    delete company;

    return 0;
}
