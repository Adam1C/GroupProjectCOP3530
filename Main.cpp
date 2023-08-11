#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include "MaxHeap.h"
#include "Patients.h"
#include "Conditions.h"
#include <limits>



int main() {
    MaxHeap maxHeap; // Create a max heap to store patients
    std::string fileNumber; // To store the user's input for file selection

    // Introduction messages
    std::cout << "This code is supposed to represent how a doctor would treat patients in order of life-threatening conditions" << std::endl;
    std::cout << "The lower a priority value given to a condition the less life-threatening the condition is and vice versa" << std::endl;

    // Select and open the input file
    std::ifstream inputFile;
    bool fileinputopen = false;
    while(!fileinputopen) {
        std::cout << "Enter the file number (1-5) or file name: ";
        std::cin >> fileNumber;
        if (fileNumber == "1")
            inputFile.open("C:\\Users\\masio\\CLionProjects\\GroupProjectCOP3530\\input6.txt");
        else if (fileNumber == "2")
            inputFile.open("C:\\Users\\masio\\CLionProjects\\GroupProjectCOP3530\\input7.txt");
        else if (fileNumber == "3")
            inputFile.open("C:\\Users\\masio\\CLionProjects\\GroupProjectCOP3530\\input8.txt");
        else if (fileNumber == "4")
            inputFile.open("C:\\Users\\masio\\CLionProjects\\GroupProjectCOP3530\\input9.txt");
        else if (fileNumber == "5")
            inputFile.open("C:\\Users\\masio\\CLionProjects\\GroupProjectCOP3530\\input11.txt");
        else
            inputFile.open(fileNumber);
        if (!inputFile.is_open()) {
            std::cout << "Failed to open the input file." << std::endl;
        }
        else {
            fileinputopen = true; // Exit loop when file is successfully opened
        }
    }
    std::string line;
    Patients patient;
    // Read patient information from the input file
    int counter = 1;
    while (getline(inputFile, line)) {
        if (line.find("PatientInfo:") != std::string::npos)
        {
            Patients& pat = patient; // Create a new patient object
            size_t nameStart = line.find("PatientInfo:") + 12;
            size_t ageStart = line.find_first_of("0123456789", nameStart);
            pat.setName(line.substr(nameStart, ageStart - nameStart));
            pat.setAge(line.substr((ageStart)));
        }
        if (line.find("PriorConditions:") != std::string::npos) // Extract and add prior conditions for the patient
        {
            std::stringstream ss(line.substr(line.find("PriorConditions:") + 16));
            std::string condition;
            while (getline(ss, condition, ')'))
            {
                size_t startPos = condition.rfind('(');
                if (startPos != std::string::npos)
                {
                    Patients& pat = patient;
                    std::string conditionName = condition.substr(0, startPos);
                    int urgencyValue;
                      std::stringstream(condition.substr(startPos + 1)) >> urgencyValue;
                    pat.addPriorCondition(conditionName, urgencyValue);
                }
            }
        }
        if (line.find("CurrentConditions:") != std::string::npos) // Extract and add current conditions for the patient
        {
            std::stringstream ss(line.substr(line.find("CurrentConditions:") + 19));
            std::string condition;
            while (getline(ss, condition, ')'))
            {
                size_t startPos = condition.rfind('(');
                if (startPos != std::string::npos)
                {
                    Patients& pat = patient;
                    std::string conditionName = condition.substr(0, startPos);
                    int urgencyValue;
                    std::stringstream(condition.substr(startPos + 1)) >> urgencyValue;
                    pat.addCurrentCondition(conditionName, urgencyValue);
                }
            }
        }
        if (!patient.emptyConditions()) {
            patient.calculateTriageValue();
            Patients x = patient;
            maxHeap.push(x);
            patient.removeAllConditions();
        }
        counter++;
       // Push the patient into the max heap
    }
    inputFile.close(); // Close the input file

    // Menu loop
    bool quit = false;
    int patientNum = 0;
    while (!quit) {
        int updateUrgency;
        int userMenuSelect;
        std::cout << "Patient Number: " << patientNum + 1 << std::endl;
        std::cout << "Patient Name: " << maxHeap[patientNum].getName() << std::endl;
        std::cout << "Age: " << maxHeap[patientNum].getAge() << std::endl;
        maxHeap[patientNum].getPriorConditions(); // Print prior conditions
        maxHeap[patientNum].getCurrentConditions(); // Print current conditions
        // Display menu options
        std::cout << std::endl << "What would you like to do? " << std::endl;
        std::cout << "0) Quit " << std::endl;
        std::cout << "1) Update Current Conditions " << std::endl;
        std::cout << "2) Treat Patient from Triage 1" << std::endl;
        // Display additional options if applicable
        if (patientNum != maxHeap.size()) {
            std::cout << "3) View Next Patient " << std::endl;
        }
        if (patientNum != 0) {
            std::cout << "4) View Previous Patient " << std::endl;
        }
        std::cin >> userMenuSelect; // Read user menu choice
        // Get a reference to the patient object
        Patients &patient = const_cast<Patients &>(maxHeap.peekAtPosition(patientNum));
        if (userMenuSelect == 0)
            quit = true; // Exit loop
        else if (userMenuSelect == 1)
        {
            // Update current conditions
            bool validInput = false;
            while (!validInput) {
                std::cout << "Would you like to add (1) or remove (2) Current Conditions? (0 to quit)" << std::endl;
                std::cin >> userMenuSelect;
                if (userMenuSelect == 0) // Quit changing conditions
                    validInput = true;
                else if (userMenuSelect == 1) // Add Current Condition
                {
                    validInput = true;
                    std::string conditionChoice;
                    int urgency;
                    std::cout << "Enter the name of the Condition you would like to add: " << std::endl;
                    std::cin >> conditionChoice;
                    if (patient.hasCurrentCondition(conditionChoice)) // Checks if patient already has Condition
                    {
                        std::cout << "The patient already has the condition." << std::endl;
                        std::cout << "Would you like to update the urgency value? (yes: 1) (no: 0)" << std::endl;
                        std::cin >> updateUrgency;
                        if (updateUrgency == 1) // Update existing urgency value
                        {
                            std::cout << "Enter the new urgency value for the condition (1-200): ";
                            std::cin >> urgency; // new urgency value
                            if (std::cin.fail() || urgency < 1 || urgency > 200) // invalid input
                            {
                                std::cin.clear();
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                                std::cout << "Invalid input. Urgency value must be a valid integer between 1 and 200." << std::endl;
                            }
                            else // valid input
                            {
                                patient.updateCurrentConditionPriority(conditionChoice, urgency);
                                patient.calculateTriageValue();
                                maxHeap.heapifyUp(patientNum);
                                maxHeap.heapifyDown(patientNum);
                                std::cout << "Condition urgency updated successfully." << std::endl;
                            }
                        }
                        else if (updateUrgency == 0)
                        {
                            // No change, continue with the rest of the code
                        }
                        else // Invalid input
                        {
                            std::cout << "Invalid input. Please enter 1 or 0." << std::endl;
                        }
                    }
                    else // Patient doesn't have the condition you want to add now takes urgency of new condition
                    {
                        while (true)
                        {
                            std::cout << "Enter the Urgency of the Condition (1-200, 200 being immediate care needed): ";
                            std::cin >> urgency;
                            if (std::cin.fail() || urgency < 1 || urgency > 200) // checks for invalid input
                            {
                                std::cin.clear(); // Clear error flags
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                                                '\n'); // Clear input buffer
                                std::cout << "Invalid input. Please enter a valid integer between 1 and 200." << std::endl;
                            }
                            else // valid input
                            {
                                break;
                            }
                        }
                        patient.addCurrentCondition(conditionChoice, urgency);
                    }
                } else if (userMenuSelect == 2) { // Remove a condition
                    bool validInput = false;
                    while (!validInput) {
                        std::string conditionChoice;
                        int urgency;
                        std::cout << "Enter the name of the Current Condition you would like to remove: " << std::endl;
                        std::cin >> conditionChoice; // condition you want to remove
                        if (!patient.hasCurrentCondition(conditionChoice)) // checks if patient does not condition
                        {
                            std::cout << "The patient does not have the condition." << std::endl;
                        }
                        else // catches if patient has condition
                        {
                            validInput = true;
                            patient.removeCurrentCondition(conditionChoice);
                            std::cout << "Successfully removed condition." << std::endl;
                        }
                    }
                }
                patient.calculateTriageValue();
                maxHeap.heapifyUp(patientNum);
                maxHeap.heapifyDown(patientNum);
            }
        } else if (userMenuSelect == 2) { // remove patient at this location
            if (patientNum == 0) {
                maxHeap.pop();
                patientNum = 0;
            }
            else
                std::cout << "You need to treat the highest priority patient first";
        } else if (userMenuSelect == 3) { // next patient
            patientNum++;
        } else if (userMenuSelect == 4) { // previous patient
            patientNum--;
        }
    }
    return 0;
}

