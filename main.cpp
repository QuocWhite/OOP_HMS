#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <unistd.h> 
#include <ios>    //used to get stream size
#include <limits> //used to get numeric limits
#include <ctime> // used to get the current time and date
#include <cstring>
using namespace std;

#include "./include/global.h"
#include "./include/hospital.h"
#include "./include/address.h"
#include "./include/user.h"
#include "./include/appointment.h"
#include "./include/patient.h"
#include "./include/doctor.h"
#include "./include/nurse.h"
#include "./include/driver.h"
#include "./include/ambulance.h"

void getCurrentTime();
void appointmentsMenu();
void patientsMenu();
void doctorsMenu();
void nursesMenu();
void driversMenu();
void ambulancesMenu();

void getCurrentTime()
{ 
    // Get the current time
    time_t now = time(nullptr);

    // Convert it to local time format
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", localtime(&now));

    // Display the current date and time
    cout << "Today's date and time: " << buffer << endl;

    return;
}

void appointmentsMenu()
{
    a:
    system("clear");
    bool exit = false;
    while (!exit)
    {
        int purpose = 0;
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        getCurrentTime();

        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "\tAPPOINTMENT MENU\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "[1] : Book an appointment\n";
        cout << "[2] : Get appointment details\n";
        cout << "[3] : Show all appointments\n\n";
        cout << "[0] : Back\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
        cout << "Enter your choice: ";
        cin >> purpose;
        while (cin.fail() || purpose < 0){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Your choice should be a number.\nEnter again!\n", cin >> purpose;
        }

        if (purpose == 1)
        {
            system("clear");
            appointment a;
            a.book();
        }
        else if (purpose == 2)
        {
            system("clear");
            appointment a;
            a.getDetails();
            a.printDetails();
        }
        else if (purpose == 3)
        {
            system("clear");
            hospital::printAppointments();
        }
        else if (purpose == 0)
        {
            exit = true;
            break;
        }
        else
        {
            cout << "Invalid choice! Please try again.\n";
            sleep(1);
            cin.clear();
            system("clear");
            goto a;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clearing cin buffer;

        cout << endl;
        cout << "\nPress ENTER to continue...\n";
        cout << endl;

        getchar();
        system("clear");
    }
    return;
}

void patientsMenu()
{
    system("clear");
    b:
    bool exit = false;
    while (!exit)
    {
        int purpose = 0;
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        getCurrentTime(); // Function to get the current time


        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "\tPATIENT MENU\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "[1] : Register a new patient\n";
        cout << "[2] : Get patient details\n";
        cout << "[3] : Hospitalize a registered patient\n";
        cout << "[4] : Report a patient's death\n";
        cout << "[5] : Discharge a patient or their body\n";
        cout << "[6] : Fetch patient details from history\n";
        cout << "[7] : Get details of all registered patients\n\n";
        cout << "[0] : Back\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
        cout << "Enter your choice: ";
        cin >> purpose;
        while (cin.fail() || purpose < 0){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Your choice should be a number.\nEnter again!\n", cin >> purpose;
        }

        if (purpose == 1)
        {
            system("clear");
            patient p;
            p.adduser();
        }
        else if (purpose == 2)
        {
            system("clear");
            patient p;
            p.getDetails(1);
            p.printDetails();
        }
        else if (purpose == 3)
        {
            system("clear");
            patient p;
            p.hospitalize();
        }
        else if (purpose == 4)
        {
            system("clear");
            patient p;
            p.reportADeath();
        }
        else if (purpose == 5)
        {
            system("clear");
            patient p;
            p.removeuser();
        }
        else if (purpose == 6)
        {
            system("clear");
            patient p;
            p.getDetailsFromHistory();
        }
        else if (purpose == 7)
        {
            system("clear");
            hospital::printPatients();
        }
        else if (purpose == 0)
        {
            exit = true;
            break;
        }
        else
        {
            cout << "Invalid choice! Please try again.\n";
            sleep(1);
            cin.clear();
            system("clear");
            goto b;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clearing cin buffer;

        cout << endl;
        cout << "\nPress ENTER to continue...\n";
        cout << endl;

        getchar();
        system("clear");
    }
    return;
}

void doctorsMenu()
{
    c:
    system("clear");
    bool exit = false;
    while (!exit)
    {
        int purpose = 0;
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        getCurrentTime(); // Function to get the current time


        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "\tDOCTOR MENU\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "[1] : Register a new doctor\n";
        cout << "[2] : Get doctor details\n";
        cout << "[3] : Remove a doctor\n";
        cout << "[4] : Fetch doctor details from history\n";
        cout << "[5] : Get details of all registered doctors\n\n";
        cout << "[0] : Back\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
        cout << "Enter your choice: ";
        cin >> purpose;
        while (cin.fail() || purpose < 0){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Your choice should be a number.\nEnter again!\n", cin >> purpose;
        }

        if (purpose == 1)
        {
            system("clear");
            doctor d;
            d.adduser();
        }
        else if (purpose == 2)
        {
            system("clear");
            doctor d;
            d.getDetails(1);
            d.printDetails();
        }
        else if (purpose == 3)
        {
            system("clear");
            doctor d;
            d.removeuser();
        }
        else if (purpose == 4)
        {
            system("clear");
            doctor d;
            d.getDetailsFromHistory();
        }
        else if (purpose == 5)
        {
            system("clear");
            hospital::printDoctors();
        }
        else if (purpose == 0)
        {
            exit = true;
            break;
        }
        else
        {
            cout << "Invalid choice! Please try again.\n";
            sleep(1);
            cin.clear();
            system("clear");
            goto c;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clearing cin buffer;

        cout << endl;
        cout << "\nPress ENTER to continue...\n";
        cout << endl;

        getchar();
        system("clear");
    }
    return;
}

void nursesMenu()
{
    d:
    system("clear");
    bool exit = false;
    while (!exit)
    {
        int purpose;
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        getCurrentTime(); // Function to get the current time

        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "NURSE MENU\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "[1] : Register a new nurse\n";
        cout << "[2] : Get nurse details\n";
        cout << "[3] : Remove a nurse\n";
        cout << "[4] : Fetch nurse details from history\n";
        cout << "[5] : Get details of all registered nurses\n\n";
        cout << "[0] : Back\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
        cout << "Enter your choice: ";
        cin >> purpose;
        while (cin.fail() || purpose < 0){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Your choice should be a number.\nEnter again!\n", cin >> purpose;
        }

        if (purpose == 1)
        {
            system("clear");
            nurse n;
            n.adduser();
        }
        else if (purpose == 2)
        {
            system("clear");
            nurse n;
            n.getDetails(1);
            n.printDetails();
        }
        else if (purpose == 3)
        {
            system("clear");
            nurse n;
            n.removeuser();
        }
        else if (purpose == 4)
        {
            system("clear");
            nurse n;
            n.getDetailsFromHistory();
        }
        else if (purpose == 5)
        {
            system("clear");
            hospital::printNurses();
        }
        else if (purpose == 0)
        {
            exit = true;
            break;
        }
        else
        {
            cout << "Invalid choice! Please try again.\n";
            sleep(1);
            cin.clear();
            system("clear");
            goto d;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clearing cin buffer;

        cout << endl;
        cout << "\nPress ENTER to continue...\n";
        cout << endl;

        getchar();
        system("clear");
    }
    return;
}

void driversMenu()
{
    e:
    system("clear");
    bool exit = false;
    while (!exit)
    {
        int purpose = 0;
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        getCurrentTime(); 

        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "DRIVER MENU\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "[1] : Register a new driver\n";
        cout << "[2] : Get driver details\n";
        cout << "[3] : Remove a driver\n";
        cout << "[4] : Fetch driver details from history\n";
        cout << "[5] : Get details of all registered drivers\n\n";
        cout << "[0] : Back\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
        cout << "Enter your choice: ";
        cin >> purpose;
        while (cin.fail() || purpose < 0){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Your choice should be a number.\nEnter again!\n", cin >> purpose;
        }

        if (purpose == 1)
        {
            system("clear");
            driver d;
            d.adduser();
        }
        else if (purpose == 2)
        {
            system("clear");
            driver d;
            d.getDetails(1);
            d.printDetails();
        }
        else if (purpose == 3)
        {
            system("clear");
            driver d;
            d.removeuser();
        }
        else if (purpose == 4)
        {
            system("clear");
            driver d;
            d.getDetailsFromHistory();
        }
        else if (purpose == 5)
        {
            system("clear");
            hospital::printDrivers();
        }
        else if (purpose == 0)
        {
            exit = true;
            break;
        }
        else
        {
            cout << "Invalid choice! Please try again.\n";
            sleep(1);
            cin.clear();
            system("clear");
            goto e;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clearing cin buffer;

        cout << endl;
        cout << "\nPress ENTER to continue...\n";
        cout << endl;

        getchar();
        system("clear");
    }
    return;
}

void ambulancesMenu()
{
    f:
    system("clear");
    bool exit = false;
    while (!exit)
    {
        int purpose = 0;
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        getCurrentTime(); // Function to get the current time


        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "AMBULANCE MENU\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "[1] : Add an ambulance\n";
        cout << "[2] : Send an ambulance\n";
        cout << "[3] : Get ambulance details\n";
        cout << "[4] : Report ambulance arrival\n";
        cout << "[5] : Remove an ambulance\n";
        cout << "[6] : Fetch ambulance details from history\n";
        cout << "[7] : Get details of all registered ambulances\n\n";
        cout << "[0] : Back\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
        cout << "Enter your choice: ";
        cin >> purpose;
        while (cin.fail() || purpose < 0){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Your choice should be a number.\nEnter again!\n", cin >> purpose;
        }

        if (purpose == 1)
        {
            system("clear");
            ambulance a;
            a.addAmbulance();
        }
        else if (purpose == 2)
        {
            system("clear");
            ambulance a;
            a.send();
        }
        else if (purpose == 3)
        {
            system("clear");
            ambulance a;
            a.getDetails(1);
            a.printDetails();
        }
        else if (purpose == 4)
        {
            system("clear");
            ambulance a;
            a.reportArrival();
        }
        else if (purpose == 5)
        {
            system("clear");
            ambulance a;
            a.removeAmbulance();
        }
        else if (purpose == 6)
        {
            system("clear");
            ambulance a;
            a.getDetailsFromHistory();
        }
        else if (purpose == 7)
        {
            system("clear");
            hospital::printAmbulances();
        }
        else if (purpose == 0)
        {
            exit = true;
            break;
        }
        else
        {
            cout << "Invalid choice! Please try again.\n";
            sleep(1);
            cin.clear();
            system("clear");
            goto f;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clearing cin buffer;

        cout << endl;
        cout << "\nPress ENTER to continue...\n";
        cout << endl;

        getchar();
        system("clear");
    }
    return;
}


void login(){
    system("clear");
    string user;
    char const *password;
    char const *pass= "password";
    int count = 0;
    cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    getCurrentTime();
    cout << "\tLogin\n";
    cout << "Enter user name: ";
    getline(cin, user);
    while (count < 5){
        cout << "\n";
        password = getpass("Enter password: ");
        
        cout << "\n";
        if (strcmp(password,pass)==0){
            cout << "Login successful";
            cout << "Welcome " << user << " to Hospital!!!";
            cout << "Please wait ";
            break;
        }
         else
        {
            cout << "Invalid password. Please try again.\n" << '\n';
            count++;
        }
    }
    if (count == 5)
    {
        cout << "Too many login attempts! The program will be exit.";
        exit(0);
    }

    cout << "Thank you for login.\n";
}

int main()
{
    {
        doctor d1;
        patient p;
        nurse n;
        driver d2;
        ambulance a1;
        appointment a2;
        d1.fillMap();
        p.fillMap();
        n.fillMap();
        d2.fillMap();
        a1.fillMap();
        a2.fillMap();
    }
    login();
    while (1)
    {
        system("clear");
        int category = 0;
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        getCurrentTime();

        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "\tMAIN MENU\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "[1] : APPOINTMENTS\n";
        cout << "[2] : PATIENTS\n";
        cout << "[3] : DOCTORS\n";
        cout << "[4] : NURSES\n";
        cout << "[5] : DRIVERS\n";
        cout << "[6] : AMBULANCES\n\n";
        cout << "[0] : EXIT\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
        cout << "Enter your choice: ";
        cin >> category;
        while (cin.fail() || category < 0){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Your choice should be a number.\nEnter again!\n", cin >> category;
        }
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "\n";
        if (category == 0)
        {
            cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            cout << "\nShutting Down System...\n";
            cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            break;
        }
        else if (category == 1)
        {
            system("clear");
            appointmentsMenu();
        }
        else if (category == 2)
        {
            system("clear");
            patientsMenu();
        }
        else if (category == 3)
        {
            system("clear");
            doctorsMenu();
        }
        else if (category == 4)
        {
            system("clear");
            nursesMenu();
        }
        else if (category == 5)
        {
            system("clear");
            driversMenu();
        }
        else if (category == 6)
        {
            system("clear");
            ambulancesMenu();
        }
        else
        {
            cout << "\nInvalid Choice!\n";
        }

        cout << endl;
    }

    {
        doctor d1;
        patient p;
        nurse n;
        driver d2;
        ambulance a1;
        appointment a2;
        d1.saveMap();
        p.saveMap();
        n.saveMap();
        d2.saveMap();
        a1.saveMap();
        a2.saveMap();
    }

    return 0;
}