#include <iostream>
#include <string>
#include "Patients.h"
#include "MaxHeap.h"

int main() {
    MaxHeap triageQueue;

    while (true) {
        std::cout << "1. Add Patient\n";
        std::cout << "2. Process Next Patient\n";
        std::cout << "3. Exit\n";
        std::cout << "Select an option: ";

        int choice;
        std::cin >> choice;

        if (choice == 1) {
            std::string name;
            int age;
            std::cout << "Enter patient's name: ";
            std::cin >> name;
            std::cout << "Enter patient's age: ";
            std::cin >> age;

            Patients patient(name, age);

            // Collect other patient information such as conditions, ailments, etc.
            // Add them to the patient instance.

            patient.calculateTriageValue();
            triageQueue.push(patient);

            std::cout << "Patient added to the queue.\n";
        }
        else if (choice == 2) {
            if (!triageQueue.empty()) {
                Patients nextPatient = triageQueue.pop();
                std::cout << "Processing next patient:\n";
                std::cout << "Name: " << nextPatient.getName() << "\n";
                std::cout << "Age: " << nextPatient.getAge() << "\n";
                // Display other patient information.
            }
            else {
                std::cout << "No patients in the queue.\n";
            }
        }
        else if (choice == 3) {
            std::cout << "Exiting...\n";
            break;
        }
        else {
            std::cout << "Invalid choice. Please select a valid option.\n";
        }
    }

    return 0;
}
