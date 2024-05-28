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
    homecode = "";
    street = "";
    city = "";
    country = "";
}
void address::takeInput()
{
    cout << "\nEnter address:\n";
    cout << "\nYour home code:\n";
    getline(cin >> ws, homecode);
    cout << "\nYour street:\n";
    getline(cin, street);
    cout << "\nCity:\n";
    getline(cin >> ws, city);
    cout << "\nCountry:\n";
    getline(cin >> ws, country);
    return;
}
void address::print()
{
    cout << "Home code          : " << homecode << "\n";
    cout << "Street             : " << street << "\n";
    cout << "City               : " << city << "\n";
    cout << "Country            : " << country << "\n";
    return;
}
string address::addToStr()
{
    stringstream s;
    s << homecode << "`" << street << "`" << city << "`" << country;
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
    
    getline(s, homecode, '`');
    for (auto &i : homecode)
        if (i == '^')
            i = ',';

    getline(s, street, '`');
    for (auto &i : street)
        if (i == '^')
            i = ',';

    getline(s, city, '`');
    getline(s, country, '`');
    return;
}