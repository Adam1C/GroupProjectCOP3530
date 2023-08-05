#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include "MaxHeap.h" 

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
    }
    inputFile.close(); // Close the input file


    // Now you have populated your max heap with patients and their conditions from the file
    // Perform any operations you need with the max heap

    return 0;
}
