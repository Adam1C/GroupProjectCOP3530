#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include "MaxHeap.h"
#include "Patients.h"
#include "Conditions.h"
#include <limits>


int main() {
    MaxHeap maxHeap; // Create an instance of MaxHeap
    // Open the input text file
    std::string fileNumber;

    std::cout << "This code is supposed to represent how a doctor would treat patients in order of life-threatening conditions" << std::endl;
    std::cout << "The lower a priority value given to a condition the less life-threatening the condition is and vice versa" << std::endl;

    std::ifstream inputFile;
    bool fileinputopen = false;
    while(!fileinputopen) {
        // having issues getting conditions and urgency values
        std::cout << "Enter the file number (1-5) or file name: ";
        std::cin >> fileNumber;
        if (fileNumber == "1")
            inputFile.open("C:\\Users\\masio\\CLionProjects\\GroupProjectCOP3530\\input1.txt");
        else if (fileNumber == "2")
            inputFile.open("C:\\Users\\masio\\CLionProjects\\GroupProjectCOP3530\\input2.txt");
        else if (fileNumber == "3")
            inputFile.open("C:\\Users\\masio\\CLionProjects\\GroupProjectCOP3530\\input3.txt");
        else if (fileNumber == "4")
            inputFile.open("C:\\Users\\masio\\CLionProjects\\GroupProjectCOP3530\\input4.txt");
        else if (fileNumber == "5")
            inputFile.open("C:\\Users\\masio\\CLionProjects\\GroupProjectCOP3530\\input5.txt");
        else
            inputFile.open("C:\\Users\\masio\\CLionProjects\\GroupProjectCOP3530\\" + fileNumber);
        if (!inputFile.is_open()) {
            std::cout << "Failed to open the input file." << std::endl;
        }
        else {
            fileinputopen = true;
        }
    }

    std::string line;

    while (std::getline(inputFile, line)) {
        Patients patient;
        std::istringstream iss(line);
        std::string section;
        iss >> section;

        if (section == "PatientInfo:") {
            std::string name;
            int age;
            iss >> name >> age;
            Patients patient(name, age);
        } else if (section == "PriorConditions:") {
            std::string condition;
            while (iss >> condition) {
                int urgency;
                iss >> urgency;
                patient.addPriorCondition(condition, urgency);
            }
        } else if (section == "CurrentConditions:") {
            std::string condition;
            while (iss >> condition) {
                int urgency;
                iss >> urgency;
                patient.addCurrentCondition( condition, urgency);
            }
            patient.calculateTriageValue();
            maxHeap.push(patient);
        }
    }

    inputFile.close(); // Close the input file
    bool quit = false;
    int patientNum = 0;
    while (!quit) {
        int updateUrgency;
        int userMenuSelect;
        std::cout << "Patient Number: " << patientNum + 1 << std::endl;
        std::cout << "Patient Name: " << maxHeap[patientNum].getName() << std::endl;
        std::cout << "Age: " << maxHeap[patientNum].getAge() << std::endl;
        maxHeap[patientNum].getPriorConditions();
        maxHeap[patientNum].getCurrentConditions();
        std::cout << "What would you like to do? " << std::endl;
        std::cout << "0) Quit " << std::endl;
        std::cout << "1) Update Current Conditions " << std::endl;
        std::cout << "2) Remove Patient from Triage " << std::endl;
        if (patientNum != maxHeap.size()) {
            std::cout << "3) View Next Patient " << std::endl;
        }
        if (patientNum != 0) {
            std::cout << "4) View Previous Patient " << std::endl;
        }
        std::cin >> userMenuSelect;
        Patients &patient = const_cast<Patients &>(maxHeap.peekAtPosition(patientNum));
        if (userMenuSelect == 0)
            quit = true;
        else if (userMenuSelect == 1) {
            bool validInput = false;
            while (!validInput) {
                std::cout << "Would you like to add (1) or remove (2) Current Conditions? (0 to quit)" << std::endl;
                std::cin >> userMenuSelect;
                if (userMenuSelect == 0)
                    validInput = true;
                else if (userMenuSelect == 1) {
                    validInput = true;
                    std::string conditionChoice;
                    int urgency;
                    std::cout << "Enter the name of the Condition you would like to add: " << std::endl;
                    std::cin >> conditionChoice;
                    if (maxHeap[patientNum].hasCurrentCondition(conditionChoice)) {
                        std::cout << "The patient already has the condition." << std::endl;
                        std::cout << "Would you like to update the urgency value? (yes: 1) (no: 0)" << std::endl;
                        std::cin >> updateUrgency;
                        if (updateUrgency == 1) {
                            std::cout << "Enter the new urgency value for the condition (1-200): ";
                            std::cin >> urgency;

                            // Check if the input is a valid integer and within the specified range
                            if (std::cin.fail() || urgency < 1 || urgency > 200) {
                                std::cin.clear(); // Clear error flags
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                                                '\n'); // Clear input buffer
                                std::cout << "Invalid input. Urgency value must be a valid integer between 1 and 200." << std::endl;
                            } else {
                                // Update the condition's urgency value
                                patient.updateCurrentConditionPriority(conditionChoice, urgency);
                                patient.calculateTriageValue();
                                maxHeap.heapifyUp(patientNum);
                                maxHeap.heapifyDown(patientNum);
                                std::cout << "Condition urgency updated successfully." << std::endl;
                            }
                        } else if (updateUrgency == 0) {
                            // No update, continue with the rest of the code
                        } else {
                            std::cout << "Invalid input. Please enter 1 or 0." << std::endl;
                        }
                    } else {
                        while (true) {
                            std::cout << "Enter the Urgency of the Condition (1-200, 200 being immediate care needed): ";
                            std::cin >> urgency;

                            // Check if the input is a valid integer and within the specified range
                            if (std::cin.fail() || urgency < 1 || urgency > 200) {
                                std::cin.clear(); // Clear error flags
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                                                '\n'); // Clear input buffer
                                std::cout << "Invalid input. Please enter a valid integer between 1 and 200."
                                          << std::endl;
                            } else {
                                break; // Valid input received, exit the loop
                            }
                        }
                        patient.addCurrentCondition(conditionChoice, urgency);
                    }
                } else if (userMenuSelect == 2) {
                    bool validInput = false;
                    while (!validInput) {
                        std::string conditionChoice;
                        int urgency;
                        std::cout << "Enter the name of the Current Condition you would like to remove: " << std::endl;
                        std::cin >> conditionChoice;
                        if (!maxHeap[patientNum].hasCurrentCondition(conditionChoice)) {
                            std::cout << "The patient does not have the condition." << std::endl;
                            validInput = true;
                        } else {
                            validInput = true;
                            patient.removeCurrentCondition(conditionChoice);
                            std::cout << "Successfully removed condition." << std::endl;
                        }
                    }
                }
                // Recalculate the triage value and adjust the max heap
                patient.calculateTriageValue();
                maxHeap.heapifyUp(patientNum);
                maxHeap.heapifyDown(patientNum);
            }
        } else if (userMenuSelect == 2) {
            maxHeap.removeAt(patientNum);
            patientNum = 0;
        } else if (userMenuSelect == 3) {
            patientNum++;
        } else if (userMenuSelect == 4) {
            patientNum--;
        }
    }
        return 0;
}

