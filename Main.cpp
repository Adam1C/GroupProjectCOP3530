#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include "MaxHeap.h" 
#include "Patients.h"

void heapToSortedArray(std::vector<int>& heap) {
    std::sort_heap(heap.begin(), heap.end());
}

int main() {
    MaxHeap maxHeap; // Create an instance of MaxHeap

    // Open the input text file
    std::string fileNumber; 
    std::cout << "Enter the file number (1-5) or file name: ";
    std::cin >> fileNumber;
    if (fileNumber == "1")
        std::ifstream inputFile("input1.txt");
    else if (fileNumber == "2")
        std::ifstream inputFile("input2.txt");
    else if (fileNumber == "3")
        std::ifstream inputFile("input3.txt");
    else if (fileNumber == "4")
        std::ifstream inputFile("input4.txt");
    else if (fileNumber == "5")
        std::ifstream inputFile("input5.txt");
    else
        std::ifstream inputFile(fileName);

    if (!inputFile.is_open()) {
        std::cout << "Failed to open the input file." << std::endl;
        return 1;
    }

    std::string line;
    Patients patient("", 0); // Initialize a patient object

    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        std::string section;
        iss >> section;

        if (section == "PatientInfo:") {
            std::string name;
            int age;
            iss >> name >> age;
            patient = Patients(name, age);
        }
        else if (section == "PriorConditions:") {
            std::string condition;
            while (iss >> condition) {
                patient.addPriorCondition(condition);
            }
        }
        else if (section == "CurrentConditions:") {
            std::string condition;
            while (iss >> condition) {
                patient.addCurrentCondition(condition);
            }
            maxHeap.insert(patient); // Insert the patient into the max heap
        }
        patient.calculateTriageValue();
        maxHeap.push(patient);
    }
    inputFile.close(); // Close the input file
    bool quit = false;
    int patientNum = 0;
    int userMenuSelect;
    while (!quit)
    {
        std::cout << "Patient Number: " << patientNum + 1 << std::endl; 
        std::cout << "Patient Name: " << maxHeap[patientNum].getName() << std::endl; 
        std::cout << "Age: " << maxHeap[patientNum].getAge() << std::endl; 
        std::cout << "Prior Conditions: " << maxHeap[patientNum].getPriorConditions() << std::endl; 
        std::cout << "Current Conditions: " << maxHeap[patientNum].getCurrentConditions() << std::endl; 
        std::cout << "What would you like to do? " << std::endl; 
        std::cout << "0) Quit " << std::endl; 
        std::cout << "1) Update Current Conditions " << std::endl; 
        std::cout << "2) Remove Patient from Triage " << std::endl; 
        std::cout << "3) View Next Patient " << std::endl;
        if (patientNum != 0)
            std::cout << "4) View previous Patient " << std::endl; 
        std::cin << userMenuSelect; 
        if (userMenuSelect == 0)
            quit = true;
        else if (userMenuSelect == 1) {
            bool validInput = false;
            while (!validInput) {
                std::cout << "Would you like to add (1) or remove (2) Current Conditions?" << std::endl;
                std::cin << userMenuSelect;
                if (userMenuSelect == 1) {
                    validInput = true;
                    std::string conditionChoice;
                    int urgancy;
                    std::cout << "Enter the name of the Condition you would like to add: " << std::endl;
                    std::cin >> conditionChoice;
                    if (maxHeap[patientNum].hasCurrentCondition(conditionChoice)) {
                        std::cout << "The patient already has the condition." << std::endl;
                        std::cout << "Would you like to update the priority value? (yes: 1) (no: 0)" << std::endl;
                        int updatePriority;
                        std::cin >> updatePriority;
                        if (updatePriority == 1) {
                            std::cout << "Enter the new priority value for the condition (1-200): ";
                            std::cin >> urgency;

                            // Check if the input is a valid integer and within the specified range
                            if (std::cin.fail() || urgency < 1 || urgency > 200) {
                                std::cin.clear(); // Clear error flags
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer 
                                std::cout << "Invalid input. Priority value must be a valid integer between 1 and 200." << std::endl;
                            }
                            else {
                                // Update the condition's priority value
                                maxHeap[patientNum].updateCurrentConditionPriority(conditionChoice, urgency);
                                maxHeap[patientNum].calculateTriageValue();
                                maxHeap.heapifyUp(patientNum);
                                maxHeap.heapifyDown(patientNum);
                                std::cout << "Condition priority updated successfully." << std::endl;
                            }
                        }
                        else if (updatePriority == 0) {
                            // No update, continue with the rest of the code
                        }
                        else {
                            std::cout << "Invalid input. Please enter 1 or 0." << std::endl;
                        }
                    }
                    else {
                        while (true) {
                            std::cout << "Enter the Severity of the Condition (1-200, 200 being immediate care needed): ";
                            std::cin >> urgancy;

                            // Check if the input is a valid integer and within the specified range
                            if (std::cin.fail() || urgancy < 1 || urgancy > 200) {
                                std::cin.clear(); // Clear error flags
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer
                                std::cout << "Invalid input. Please enter a valid integer between 1 and 200." << std::endl;
                            }
                            else {
                                break; // Valid input received, exit the loop
                            }

                        }
                    }

                }
            }
        }
        else if (userMenuSelect == 2) {
            while (!validInput) {}
            std::string conditionChoice;
            int urgancy;
            std::cout << "Enter the name of the Current Condition you would like to remove: " << std::endl;
            std::cin >> conditionChoice;
            if (!maxHeap[patientNum].hasCurrentCondition(conditionChoice)) {
                std::cout << "The patient does not have the condition." << std::endl;
            }
            else {
                validInput = true;
                maxHeap[patientNum].removeCurrentCondition(conditionChoice);
                std::cout << "Successfully removed condition." << endl;
            }
        }
            // Recalculate the triage value and adjust the max heap
            maxHeap[patientNum].calculateTriageValue();
            maxHeap.heapifyUp(patientNum);
            maxHeap.heapifyDown(patientNum);
    }

        else if (userMenuSelect == 2)
            maxHeap.removeAt(patientNum);
        else if (userMenuSelect == 3)
            patientNum++;
        else if (userMenuSelect == 4)
            patientNum--;
    }

    // Now you have populated your max heap with patients and their conditions from the file
    // Perform any operations you need with the max heap

    return 0;
}
