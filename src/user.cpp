
using namespace std;
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <limits> // for std::numeric_limits

#include "./../include/global.h"
#include "./../include/user.h"



user::user()
{
    id = -1;
}
void user::adduser(int16_t minAge, int16_t maxAge)
{
    cout << "\nEnter First name:\n";
    getline(cin >> ws, firstName);
    cout << "\nLast name:\n";
    getline(cin, lastName);
    cout << "\nEnter age: \n";
    cin >> age;
    while ( age < 0){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Was that supposed to make any kind of sense?\nEnter again!\n", cin >> age;
    }
    while(age > minAge && age < maxAge){
        if (age < minAge){
            cout << "Sorry, person should be at least " << minAge 
            << " years old to be registered as a " << cat << ".\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nEnter again!\n", cin >> age;
        }
        else if (age > maxAge){
            cout << "Sorry, we can't register a person older than " << maxAge << " years as a " << cat << ".\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Was that supposed to make any kind of sense?\nEnter again!\n", cin >> age;
        }
    }
    cout << "\nGender (M = Male || F = Female): \n";
    cin >> gender;
    while (gender != 'M' && gender != 'F' && gender != 'm' && gender != 'f'){
        cout << "Gender must be M or F\n", cin >> gender;
    }
    cout << "\nEnter mobile number: \n";
    getline(cin >> ws, mobNumber);
    add.takeInput();
    return;
}

void user::printDetails()
{
    if (id == -1)
        return;
    cout << "\nDetails:\n";
    cout << "ID                 : " << id << "\n";
    cout << "Full Name          : " << firstName << " " << lastName << "\n";
    cout << "Gender             : " << gender << "\n";
    cout << "Age                : " << age << "\n";
    cout << "Mobile             : " << mobNumber << "\n";
    cout << "Address            : \n";
    add.print();
    return;
}
void user::printDetailsFromHistory()
{
    if (id == -1)
        return;
    cout << "\nHistory Details :\n";
    cout << "Full Name       : " << firstName << " " << lastName << "\n";
    cout << "Gender          : " << gender << "\n";
    cout << "Age             : " << age << "\n";
    cout << "Mobile          : " << mobNumber << "\n";
    cout << "Address         : ";
    add.print();
    return;
}