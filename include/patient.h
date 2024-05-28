#ifndef PATIENT
#define PATIENT
using namespace std;

#include "./user.h"

class appointment;
class patient : public user
{
private:
    float height; //in M;
    float weight; //in KG;
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