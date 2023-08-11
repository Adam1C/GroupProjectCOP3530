#ifndef PATIENTS_H
#define PATIENTS_H

#include "Conditions.h"
#include <string>
#include <iostream>

class Patients {
private:
    int triageValue; //  Stores the calculated triage value that determines location in maxheap
    Conditions priorConditions; // Stores the patient's prior medical conditions
    Conditions currentConditions; // Stores the patient's current medical conditions
    std::string name; // Stores the patient's name
    int age; // Stores the patient's age

public:
    Patients(); // Default constructor
    Patients(const std::string& name, int age); // Constructor with name and age parameters
    // Getters
    std::string getName() const;
    int getAge() const;
    int getTriageValue() const;
    void getPriorConditions() const;
    void getCurrentConditions() const;
    // Setters
    void setAge(const std::string& age);
    void setName(const std::string& name);

    void calculateTriageValue(); // Calculate and set the triage value based on conditions

    // Use Conditions methods for adding, removing, and updating conditions
    void addPriorCondition(const std::string& conditionName, int urgency); // Add a prior medical condition
    void addCurrentCondition(const std::string& conditionName, int urgency); // Add a current medical condition
    void removeCurrentCondition(const std::string& conditionName); // Remove a current medical condition
    bool hasPriorCondition(const std::string& conditionName) const; // Check if the patient has a specific prior condition
    bool hasCurrentCondition(const std::string& conditionName) const; // Check if the patient has a specific current condition
    void updateCurrentConditionPriority(const std::string& conditionName, int urgency); // Update the urgency of a current condition
    bool emptyConditions() const; // checks if there are both current and prior conditions
    void removeAllConditions(); // removes all conditions from a patient
};

#endif // PATIENTS_H
