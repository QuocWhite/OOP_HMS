#ifndef ADDRESS
#define ADDRESS
using namespace std;
#include <string>

class address
{
private:
    string district;
    string street;
    string city;
    string country;

public:
    address();
    void takeInput();
    void print();
    string addToStr();
    void strToAdd(string str);

};
#endif 