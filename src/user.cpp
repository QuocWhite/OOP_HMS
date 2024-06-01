using namespace std;
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <limits> 

#include "./../include/global.h"
#include "./../include/user.h"



user::user()
{
    id = -1;
}
void user::adduser(int minAge, int maxAge)
{
    //getting basic details of the user from the user side;
    cout << "\nEnter First name:\n";
    getline(cin >> ws, firstName);
    cout << "\nLast name:\n";
    getline(cin, lastName);
    // Age Validation
// Function to validate user's agewhile (age <= 0)
    cout << "\nEnter age: \n";
    cin >> age;
    while (cin.fail() || age < 0 || age > maxAge || age < minAge){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Was that supposed to make any kind of sense?\nEnter again!\n", cin >> age;
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
    cout << "Address            : ";
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