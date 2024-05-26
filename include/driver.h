#ifndef DRIVER
#define DRIVER
using namespace std;
#include <string>

#include "./user.h"

class ambulance;
class driver : public user
{
private:
    string licenseNumber;
    bool idle;
    friend class ambulance;

public:
    driver();
    void fillMap();
    void saveMap();
    void adduser();
    void printDetails();
    void printDetailsFromHistory(string extraDetails = "");
    void getDetails(int rec = 0);
    void getDetailsFromHistory();
    void removeuser();
};
#endif