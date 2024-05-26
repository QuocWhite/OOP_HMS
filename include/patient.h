#ifndef PATIENT
#define PATIENT
using namespace std;

#include "./user.h"

class appointment;
class patient : public user
{
private:
    int height; //in cms;
    int weight; //in pounds;
    bool hospitalized;
    bool alive;
    friend class appointment;

public:
    patient();
    void fillMap();
    void saveMap();
    void adduser();
    void printDetails();
    void printDetailsFromHistory(string extraDetails = "");
    void getDetails(int rec = 0);
    void getDetailsFromHistory();
    void hospitalize();
    void reportADeath();
    void removeuser();
};
#endif 