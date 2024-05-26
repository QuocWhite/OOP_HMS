#ifndef NURSE
#define NURSE
using namespace std;
#include <string>

#include "./user.h"

class nurse : public user
{
private:
    string type;

public:
    nurse();
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