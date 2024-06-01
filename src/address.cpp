using namespace std;
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

#include "./../include/global.h"
#include "./../include/address.h"

address::address()
{
    district = "";
    street = "";
    city = "";
    country = "";
}
void address::takeInput()
{
    cout << "\nAddress information: \t";
    cout << "\nYour street:\n";
    getline(cin >> ws, street);
    cout << "\nYour district:\n";
    getline(cin, district);
    cout << "\nCity:\n";
    getline(cin >> ws, city);
    cout << "\nCountry:\n";
    getline(cin >> ws, country);
    return;
}
void address::print()
{
    cout << street << district <<  city << country << "\n";
    return;
}
string address::addToStr()
{
    stringstream s;
    s << street << " " << district << " " << city << " " << country;
    string add;
    getline(s, add);
    for (auto &i : add)
        if (i == ',')
            i = '^';
    return add;
}
void address::strToAdd(string str)
{
    stringstream s(str);
    
    getline(s, street);
    for (auto &i : street)
        if (i == '^')
            i = ',';

    getline(s, district);
    for (auto &i : district)
        if (i == '^')
            i = ',';

    getline(s, city);
    getline(s, country);
    return;
}