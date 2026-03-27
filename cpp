#include <iostream>
#include <vector>
using namespace std;

struct Patient {
    string name;
    int age;
    string phone;
};

struct Appointment {
    string patientName;
    string date;
};

vector<Patient> patients;
vector<Appointment> appointments;

// Add Patient
void addPatient() {
    Patient p;
    cout << "Enter patient name: ";
    cin >> p.name;
    cout << "Enter age: ";
    cin >> p.age;
    if(p.age <= 0){
    cout << "Invalid age!\n";
    return;
}
 #include <cctype>

cout << "Enter phone number: ";
cin >> p.phone;

bool valid = true;

if(p.phone.length() != 11){
    valid = false;
} else {
    for(char c : p.phone){
        if(!isdigit(c)){
            valid = false;
            break;
        }
    }
}

if(!valid){
    cout << "Invalid phone number! It must contain exactly 11 digits.\n";
    return;
}   
    
    patients.push_back(p);
    cout << "Patient added successfully.\n";
}

// Show Patients
void showPatients() {
    if (patients.empty()) {
        cout << "No patients found.\n";
        return;
    }

    for (int i = 0; i < patients.size(); i++) {
        cout << i << "- " << patients[i].name
             << " | Age: " << patients[i].age
             << " | Phone: " << patients[i].phone << endl;
    }
}

// Delete Patient
void deletePatient() {
    int index;
    showPatients();
    cout << "Enter patient number to delete: ";
    cin >> index;

    if (index >= 0 && index < patients.size()) {
        patients.erase(patients.begin() + index);
        cout << "Patient deleted.\n";
    } else {
        cout << "Invalid number.\n";
    }
}

// Add Appointment
void addAppointment() {
    Appointment a;
    cout << "Enter patient name: ";
    cin >> a.patientName;
    cout << "Enter appointment date (YYYY-MM-DD): ";
    cin >> a.date;

    appointments.push_back(a);
    cout << "Appointment booked successfully.\n";
}

// Show Appointments
void showAppointments() {
    if (appointments.empty()) {
        cout << "No appointments found.\n";
        return;
    }

    for (int i = 0; i < appointments.size(); i++) {
        cout << i << "- " << appointments[i].patientName
             << " | Date: " << appointments[i].date << endl;
    }
}

// Delete Appointment
void deleteAppointment() {
    int index;
    showAppointments();
    cout << "Enter appointment number to delete: ";
    cin >> index;

    if (index >= 0 && index < appointments.size()) {
        appointments.erase(appointments.begin() + index);
        cout << "Appointment deleted.\n";
    } else {
        cout << "Invalid number.\n";
    }
}

// Main Menu
int main() {
    int choice;

    do {
      cout << "Welcome to Clinic Management System!\n";  
        cout << "\n=== Clinic Management System ===\n";
        cout << "Total appointments: " << appointments.size() << "\n";
        cout << "1- Add Patient\n";
        cout << "2- Show Patients\n";
        cout << "3- Delete Patient\n";
        cout << "4- Book Appointment\n";
        cout << "5- Show Appointments\n";
        cout << "6- Delete Appointment\n";
        cout << "0- Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addPatient(); break;
            case 2: showPatients(); break;
            case 3: deletePatient(); break;
            case 4: addAppointment(); break;
            case 5: showAppointments(); break;
            case 6: deleteAppointment(); break;
            case 0: cout << "Exiting system.\n"; break;
            default: cout << "Invalid choice.\n";
        }

    } while (choice != 0);

    return 0;
}
