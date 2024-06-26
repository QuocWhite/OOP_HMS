#ifndef AMBULANCE
#define AMBULANCE
using namespace std;
#include <string>

#include "./driver.h"
#include "./address.h"

class ambulance
{
private:
    int id;
    string model;
    string manufacturer;
    string Vnumber; // vehicle number
    bool idle; // true if the ambulance free slot otherwise false
    address add;
    driver D;

public:
    ambulance();
    void fillMap();
    void saveMap();
    void addAmbulance();
    void printDetails();
    void printDetailsFromHistory(string extraDetails = "");
    void getDetails(int rec = 0);
    void getDetailsFromHistory();
    void send();
    void reportArrival();
    void removeAmbulance();

};
#endif // !AMBULANCE