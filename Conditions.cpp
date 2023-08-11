#include "Conditions.h"
#include <iostream>

void Conditions::addCondition(const std::string& conditionName, int urgency) {
    conditionsMap[conditionName] = urgency;
}

void Conditions::removeCondition(const std::string& conditionName) {
    conditionsMap.erase(conditionName);
}

int Conditions::getUrgency(const std::string& conditionName) const {
    if (conditionsMap.find(conditionName) != conditionsMap.end()) {
        return conditionsMap.at(conditionName);
    }
    return -1; // Indicate that the condition doesn't exist
}

void Conditions::printConditions() const {
    for (const auto& entry : conditionsMap) {
        std::cout << entry.first << "-" << entry.second << std::endl;
    }
}

bool Conditions::hasCondition(const std::string& conditionName) const {
    return conditionsMap.find(conditionName) != conditionsMap.end();
}

void Conditions::updateConditionUrgency(const std::string& conditionName, int urgency) {
    if (conditionsMap.find(conditionName) != conditionsMap.end()) {
        conditionsMap[conditionName] = urgency;
    }
}

int Conditions::calculateTotalUrgency() const {
    int totalUrgency = 0;
    for (const auto& entry : conditionsMap) {
        totalUrgency += entry.second;
    }
    return totalUrgency;
}
