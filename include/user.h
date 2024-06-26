#ifndef USER
#define USER
using namespace std;
#include <string>

#include "./address.h"

class user //abstract class
{
protected:
    int id;
    string firstName, lastName;
    char gender;
    int16_t age;
    string mobNumber;
    address add;
    string cat;
    int category;
    //category: 1:doctor; 2:patient; 3:nurse; 4:driver;

public:
    user();
    void getCurrentTime();
    virtual void fillMap() = 0;
    virtual void saveMap() = 0;
    virtual void adduser(int minAge, int maxAge);
    virtual void printDetails();
    virtual void printDetailsFromHistory();
    virtual void getDetails(int rec = 0) = 0;
    virtual void getDetailsFromHistory() = 0;
    virtual void removeuser() = 0;
};
#endif 
