#include "Patients.h"

Patients::Patients(const std::string& name, int age)
    : name(name), age(age), triageValue(0) {}

std::string Patients::getName() const {
    return name;
}

int Patients::getAge() const {
    return age;
}

int Patients::getTriageValue() const {
    return triageValue;
}

void Patients::addPriorCondition(const Conditions& condition) {
    priorConditions[condition.getName()] = condition;
}

void Patients::addCurrentCondition(const Conditions& condition) {
    currentConditions[condition.getName()] = condition;
}

void Patients::removeCurrentCondition(const std::string& conditionName) {
    currentConditions.erase(conditionName);
}

bool Patients::hasPriorCondition(const std::string& conditionName) const {
    return priorConditions.find(conditionName) != priorConditions.end();
}

bool Patients::hasCurrentCondition(const std::string& conditionName) const {
    return currentConditions.find(conditionName) != currentConditions.end();
}


void Patients::calculateTriageValue() {
    int triageValue = 0;

    // Calculate triage value based on Prior Conditions
    for (const auto& entry : priorConditions) {
        const Conditions& condition = entry.second;
        triageValue += condition.getPriority();
    }

    // Calculate triage value based on Current Conditions
    for (const auto& entry : currentConditions) {
        const Conditions& condition = entry.second;
        triageValue += condition.getPriority();
    }

    this->triageValue = triageValue;
}
