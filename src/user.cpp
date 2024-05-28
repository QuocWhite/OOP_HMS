
using namespace std;
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <limits> // for std::numeric_limits

#include "./../include/global.h"
#include "./../include/user.h"

void ageValidation()
{
    int number;

    while (true) {
        std::cout << "Please enter a valid age (1 - 100): ";
        std::cin >> number;

        // Check if the input is valid
        if (std::cin.fail() || number <= 0) {
            // Clear the error state
            std::cin.clear();
            
            // Ignore the rest of the invalid input
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            
            // Inform the user about the invalid input
            std::cout << "Invalid input. Please enter a valid age." << std::endl;
        } else {
            // Valid input, break the loop
            break;
        }
    }
    return;

}

user::user()
{
    id = -1;
}
void user::adduser(int16_t minAge, int16_t maxAge)
{
    //getting basic details of the user from the user side;
    cout << "\nEnter First name:\n";
    getline(cin >> ws, firstName);
    cout << "\nLast name:\n";
    getline(cin, lastName);
    a:
    // Age Validation
    ageValidation(); // Function to validate user's age 

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