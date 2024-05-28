
using namespace std;
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

#include "./../include/global.h"
#include "./../include/user.h"

user::user()
{
    id = -1;
}
void user::adduser(int16_t minAge, int16_t maxAge)
{
    //getting basic details of the user from the user side;
    cout << "\nFirst name:\n";
    getline(cin >> ws, firstName);
    cout << "\nLast name:\n";
    getline(cin, lastName);
    a:
    cout << "\nEnter age: (0 - 100) \n";
    cin >> age;
    if (age < 0 || age != int(age)){
        cout << "Was that supposed to make any kind of sense?\nEnter again!\n";
        goto a;
    }
        
    if (category != 2)
    {
        if (age < minAge)
            return void(cout << "Sorry, user should be at least " << minAge << " years old to be registered as a " << cat << ".\n");
        else if (age > maxAge)
            return void(cout << "Sorry, we can't register a user older than " << maxAge << " years as a " << cat << ".\n");
    }

    cout << "\nGender (M = Male || F = Female): \n";
    cin >> gender;
    while (gender != 'M' && gender != 'F'){
        cout << "Gender must be M or F\n", cin >> gender;
    }
    cout << "\nEnter mobile number (with country code): \n";
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