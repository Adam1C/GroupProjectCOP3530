#include "Patients.h"
#include <iostream>
#include <string>
#include <cstdlib>

Patients::Patients()
        : name(""), age(0), triageValue(0) {} // Default constructor initializes member variables

Patients::Patients(const std::string& name, int age)
        : name(name), age(age), triageValue(0) {} // Constructor with parameters initializes member variables

std::string Patients::getName() const {
    return name; // Return the patient's name
}

void Patients::setName(const std::string& name) {
    this->name = name; // Set the patient's name
}

int Patients::getAge() const {
    return age; // Return the patient's age
}

void Patients::setAge(const std::string& age) {
    this->age = std::atoi(age.c_str()); // Convert and set the patient's age from string to int
}

int Patients::getTriageValue() const {
    return triageValue; // Return the calculated triage value
}

void Patients::addPriorCondition(const std::string& conditionName, int urgency) {
    priorConditions.addCondition(conditionName, urgency); // Add a prior condition
    triageValue += urgency; // Update the triage value
    calculateTriageValue(); // Recalculate the total triage value
}

void Patients::addCurrentCondition(const std::string& conditionName, int urgency) {
    currentConditions.addCondition(conditionName, urgency); // Add a current condition
    triageValue += urgency; // Update the triage value
    calculateTriageValue(); // Recalculate the total triage value
}

void Patients::removeCurrentCondition(const std::string& conditionName) {
    if (currentConditions.hasCondition(conditionName))
    {
        triageValue -= currentConditions.getUrgency(conditionName); // Reduce triage value by removed condition's urgency
        currentConditions.removeCondition(conditionName); // Remove the current condition
        calculateTriageValue(); // Recalculate the total triage value
    }
}

bool Patients::hasPriorCondition(const std::string& conditionName) const {
    return priorConditions.hasCondition(conditionName); // Check if the patient has a specific prior condition
}

bool Patients::hasCurrentCondition(const std::string& conditionName) const {
    return currentConditions.hasCondition(conditionName); // Check if the patient has a specific current condition
}

void Patients::getPriorConditions() const {
    std::cout << "Prior Conditions:" << std::endl; // Formatting
    priorConditions.printConditions();  // Print the patient's prior conditions
}

void Patients::getCurrentConditions() const {
    std::cout << std::endl <<"Current Conditions:" << std::endl; // Formatting
    currentConditions.printConditions();  // Print the patient's current conditions
}

void Patients::updateCurrentConditionPriority(const std::string& conditionName, int urgency) {
    if (currentConditions.hasCondition(conditionName))
    {
        triageValue -= currentConditions.getUrgency(conditionName); // Reduce triage value by old condition's urgency
        currentConditions.updateConditionUrgency(conditionName, urgency); // Update the urgency of a current condition
        triageValue += urgency; // Update triage value with the new urgency
        calculateTriageValue(); // Recalculate the total triage value
    }
}

void Patients::calculateTriageValue() {
    triageValue = priorConditions.calculateTotalUrgency() + currentConditions.calculateTotalUrgency(); // Calculate the total triage value
}

