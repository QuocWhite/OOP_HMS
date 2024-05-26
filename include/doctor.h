#ifndef DOCTOR
#define DOCTOR
using namespace std;
#include <string>

#include "./user.h"

class appointment;
class doctor : public user
{
private:
    string type;
    int appointmentsBooked;
    friend class appointment;

public:
    doctor();
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