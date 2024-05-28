#ifndef ADDRESS
#define ADDRESS
using namespace std;
#include <string>

class address
{
private:
    string homecode;
    string street;
    string city;
    string country;

public:
    address();
    void takeInput();
    void print();
    string addToStr();
    void strToAdd(string str);

    address(){};
    address(string homecode, string street, string city, string country){
        this->homecode = homecode;
        this->street = street;
        this->city = city;
        this->country = country;
    }
};
#endif 