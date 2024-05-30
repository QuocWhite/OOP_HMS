#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <unistd.h> 
#include <ios>    //used to get stream size
#include <limits> //used to get numeric limits
#include <ctime> // used to get the current time and date
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
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
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

        if (purpose == 1)
        {
            appointment a;
            a.book();
        }
        else if (purpose == 2)
        {
            appointment a;
            a.getDetails();
            a.printDetails();
        }
        else if (purpose == 3)
        {
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
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
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

        if (purpose == 1)
        {
            patient p;
            p.adduser();
        }
        else if (purpose == 2)
        {
            patient p;
            p.getDetails(1);
            p.printDetails();
        }
        else if (purpose == 3)
        {
            patient p;
            p.hospitalize();
        }
        else if (purpose == 4)
        {
            patient p;
            p.reportADeath();
        }
        else if (purpose == 5)
        {
            patient p;
            p.removeuser();
        }
        else if (purpose == 6)
        {
            patient p;
            p.getDetailsFromHistory();
        }
        else if (purpose == 7)
        {
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
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
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

        if (purpose == 1)
        {
            doctor d;
            d.adduser();
        }
        else if (purpose == 2)
        {
            doctor d;
            d.getDetails(1);
            d.printDetails();
        }
        else if (purpose == 3)
        {
            doctor d;
            d.removeuser();
        }
        else if (purpose == 4)
        {
            doctor d;
            d.getDetailsFromHistory();
        }
        else if (purpose == 5)
        {
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
        int purpose = 0;
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
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

        if (purpose == 1)
        {
            nurse n;
            n.adduser();
        }
        else if (purpose == 2)
        {
            nurse n;
            n.getDetails(1);
            n.printDetails();
        }
        else if (purpose == 3)
        {
            nurse n;
            n.removeuser();
        }
        else if (purpose == 4)
        {
            nurse n;
            n.getDetailsFromHistory();
        }
        else if (purpose == 5)
        {
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
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
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

        if (purpose == 1)
        {
            driver d;
            d.adduser();
        }
        else if (purpose == 2)
        {
            driver d;
            d.getDetails(1);
            d.printDetails();
        }
        else if (purpose == 3)
        {
            driver d;
            d.removeuser();
        }
        else if (purpose == 4)
        {
            driver d;
            d.getDetailsFromHistory();
        }
        else if (purpose == 5)
        {
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
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
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

        if (purpose == 1)
        {
            ambulance a;
            a.addAmbulance();
        }
        else if (purpose == 2)
        {
            ambulance a;
            a.send();
        }
        else if (purpose == 3)
        {
            ambulance a;
            a.getDetails(1);
            a.printDetails();
        }
        else if (purpose == 4)
        {
            ambulance a;
            a.reportArrival();
        }
        else if (purpose == 5)
        {
            ambulance a;
            a.removeAmbulance();
        }
        else if (purpose == 6)
        {
            ambulance a;
            a.getDetailsFromHistory();
        }
        else if (purpose == 7)
        {
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
    while (1)
    {
        system("clear");
        int category = 0;
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        // cout << "\nSelect a category:\n\n";
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
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "\n";
        if (category == 0)
        {
            cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            cout << "\nShutting Down System...\n";
            cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            break;
        }
        else if (category == 1)
        {
            appointmentsMenu();
        }
        else if (category == 2)
        {
            patientsMenu();
        }
        else if (category == 3)
        {
            doctorsMenu();
        }
        else if (category == 4)
        {
            nursesMenu();
        }
        else if (category == 5)
        {
            driversMenu();
        }
        else if (category == 6)
        {
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