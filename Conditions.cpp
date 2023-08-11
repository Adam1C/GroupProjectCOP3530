#include "Conditions.h"
#include <iostream>

// Add a new condition with its associated urgency
void Conditions::addCondition(const std::string& conditionName, int urgency) {
    conditionsMap[conditionName] = urgency;
}

// Remove a condition and its associated urgency
void Conditions::removeCondition(const std::string& conditionName) {
    conditionsMap.erase(conditionName);
}

// Get the urgency associated with a specific condition
int Conditions::getUrgency(const std::string& conditionName) const {
    if (conditionsMap.find(conditionName) != conditionsMap.end())
    {
        return conditionsMap.at(conditionName);
    }
    return -1; // Return -1 if condition is not found
}

// Print all stored conditions and their urgencies
void Conditions::printConditions() const { // this functions prints out all conditions
    for (const auto& entry : conditionsMap)
    {
        std::cout << ' ' << entry.first << "-" << entry.second << ' ';  // Print the condition name and its urgency
    }
}

// Check if a specific condition exists
bool Conditions::hasCondition(const std::string& conditionName) const {
    return conditionsMap.find(conditionName) != conditionsMap.end();
}

// Update the urgency of an existing condition
void Conditions::updateConditionUrgency(const std::string& conditionName, int urgency) {
    if (conditionsMap.find(conditionName) != conditionsMap.end()) {
        conditionsMap[conditionName] = urgency; // Update the urgency of the specified condition
    }
}

// Calculate and return the total urgency across all conditions
int Conditions::calculateTotalUrgency() const {
    int totalUrgency = 0;
    for (const auto& entry : conditionsMap)
    {
        totalUrgency += entry.second; // Sum up all urgencies to calculate the total
    }
    return totalUrgency;
}
