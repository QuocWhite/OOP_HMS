#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

// Define a class "Appointment" to represent individual appointments
class Appointment {
private:
	// Private member variables for appointment details
    int id;
    string date;
    string time;
    string description;

public:
	// Constructor to initialize appointment details
    Appointment(int id, const string &date, const string &time, const string &description)
        : id(id), date(date), time(time), description(description) {}
        
	// Getter methods to access appointment details
    int getId() const {
        return id;
    }

    string getDate() const {
        return date;
    }

    string getTime() const {
        return time;
    }

    string getDescription() const {
        return description;
    }
	// Method to display appointment details
    void showDetail() const {
        cout << "ID: " << id << ", Date: " << date << ", Time: " << time << ", Description: " << description << endl;
    }
	// Method to save appointment details to a file
    void saveToFile(ofstream &outFile) const {
        outFile << id << endl;
        outFile << date << endl;
        outFile << time << endl;
        outFile << description << endl;
    }

	// Static method to load appointment details from a file
    static Appointment loadFromFile(ifstream &inFile) {
        int id;
        string date, time, description;
        inFile >> id;
        inFile.ignore();  
        getline(inFile, date);
        getline(inFile, time);
        getline(inFile, description);
        return Appointment(id, date, time, description);
    }
};
	// Define a class "AppointmentManager" to manage a collection of appointments
class AppointmentManager {
private:
	// Private member variables for appointment management
    vector<Appointment> appointments;
    const string filename = "appointments.txt";  

public:
	// Constructor to load appointments from file when instantiated
    AppointmentManager() {
        loadAppointmentsFromFile();
    }
	// Method to check if appointment ID already exists
    bool isIdExists(int id) const {
        for (const auto &appointment : appointments) {
            if (appointment.getId() == id) {
                return true;
            }
        }
        return false;
    }

	// Method to book a new appointment
    void bookAppointment(int id, const string &date, const string &time, const string &description) {
        if (isIdExists(id)) {
            cout << "Appointment with ID " << id << " already exists. Please choose a different ID." <<endl;
            return;
        }
        Appointment newAppointment(id, date, time, description);
        appointments.push_back(newAppointment);

        ofstream outFile(filename, ios::app);  
        if (outFile.is_open()) {
            newAppointment.saveToFile(outFile);
            outFile.close();
        }
        std::cout << "Appointment booked successfully with ID: " << newAppointment.getId() << std::endl;
    }

	// Method to retrieve and display appointment details by ID
    void getDetailAppointment(int id) const {
        ifstream inFile(filename);
        if (inFile.is_open()) {
            while (!inFile.eof()) {
                Appointment appointment = Appointment::loadFromFile(inFile);
                if (appointment.getId() == id) {
                    appointment.showDetail();
                    inFile.close();
                    return;
                }
            }
            inFile.close();
        }
        cout << "Appointment not found." << endl;
    }
	
	// Method to display details of all appointments
    void showAllAppointments() const {
        ifstream inFile(filename);
        if (inFile.is_open()) {
            while (!inFile.eof()) {
                Appointment appointment = Appointment::loadFromFile(inFile);
                appointment.showDetail();
            }
            inFile.close();
        } else {
            cout << "No appointments available." << endl;
        }
    }
	
	// Method to load appointments from file
    void loadAppointmentsFromFile() {
        ifstream inFile(filename);
        if (inFile.is_open()) {
            while (!inFile.eof()) {
                Appointment appointment = Appointment::loadFromFile(inFile);
                appointments.push_back(appointment);
            }
            inFile.close();
        }
    }
};

int main() {
	// Create an instance of AppointmentManager
    AppointmentManager manager;
	
	// Variables to store user input and choice
    int choice;
    string date, time, description;
    int id;
	
	// Menu-driven loop for user interaction
    do {
        cout << "1. Book Appointment" << std::endl;
        cout << "2. Get Detail Appointment by ID" << std::endl;
        cout << "3. Show All Appointments" << std::endl;
        cout << "4. Exit" << std::endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  

        switch (choice) {
            case 1:
                cout << "Enter appointment ID: ";
                cin >> id;
                cin.ignore();  
                cout << "Enter date (YYYY-MM-DD): ";
                getline(cin, date);
                cout << "Enter time (HH:MM): ";
                getline(cin, time);
                cout << "Enter description: ";
                getline(cin, description);
                manager.bookAppointment(id, date, time, description);
                break;
            case 2:
                cout << "Enter appointment ID: ";
                cin >> id;
                cin.ignore();  
                manager.getDetailAppointment(id);
                break;
            case 3:
                manager.showAllAppointments();
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
