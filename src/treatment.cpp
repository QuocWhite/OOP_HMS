#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Treatment {
private:
    string name;
    string description;
    double cost;

public:
    // Constructor
    Treatment(string n, string d, double c) {
        name = n;
        description = d;
        cost = c;
    }

    // Getter functions
    string getName() {
        return name;
    }

    string getDescription() {
        return description;
    }

    double getCost() {
        return cost;
    }

    // Setter functions
    void setName(string n) {
        name = n;
    }

    void setDescription(string d) {
        description = d;
    }

    void setCost(double c) {
        cost = c;
    }

    // Display information
    void displayInfo() {
        cout << "Treatment Name: " << name << endl;
        cout << "Description: " << description << endl;
        cout << "Cost: $" << cost << endl;
    }
};

int main() {
    vector<Treatment> treatments;
    int choice;

    do {
        cout << "1. Add Treatment" << endl;
        cout << "2. Edit Treatment" << endl;
        cout << "3. Delete Treatment" << endl;
        cout << "4. Display All Treatments" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // clear the newline character from the input buffer

        switch (choice) {
        case 1: {
            string name, description;
            double cost;

            cout << "Enter treatment name: ";
            getline(cin, name);
            cout << "Enter treatment description: ";
            getline(cin, description);
            cout << "Enter treatment cost: ";
            cin >> cost;
            cin.ignore(); // clear the newline character from the input buffer

            Treatment newTreatment(name, description, cost);
            treatments.push_back(newTreatment);
            cout << "Treatment added successfully!" << endl;
            break;
        }
        case 2: {
            int index;
            string name, description;
            double cost;

            cout << "Enter the index of the treatment to edit: ";
            cin >> index;
            cin.ignore(); // clear the newline character from the input buffer

            if (index >= 0 && index < treatments.size()) {
                cout << "Enter new treatment name: ";
                getline(cin, name);
                cout << "Enter new treatment description: ";
                getline(cin, description);
                cout << "Enter new treatment cost: ";
                cin >> cost;
                cin.ignore(); // clear the newline character from the input buffer

                treatments[index].setName(name);
                treatments[index].setDescription(description);
                treatments[index].setCost(cost);
                cout << "Treatment updated successfully!" << endl;
            } else {
                cout << "Invalid index." << endl;
            }
            break;
        }
        case 3: {
            int index;

            cout << "Enter the index of the treatment to delete: ";
            cin >> index;
            cin.ignore(); // clear the newline character from the input buffer

            if (index >= 0 && index < treatments.size()) {
                treatments.erase(treatments.begin() + index);
                cout << "Treatment deleted successfully!" << endl;
            } else {
                cout << "Invalid index." << endl;
            }
            break;
        }
        case 4: {
            if (treatments.empty()) {
                cout << "No treatments available." << endl;
            } else {
                cout << "All Treatments:" << endl;
                for (int i = 0; i < treatments.size(); i++) {
                    cout << "Treatment " << i << ":" << endl;
                    treatments[i].displayInfo();
                    cout << endl;
                }
            }
            break;
        }
        case 5: {
            cout << "Exiting..." << endl;
            break;
        }
        default: {
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
        }

    } while (choice != 5);

    return 0;
}
