#include "Patients.h"

Patients::Patients() 
    : name(""), age(0), triageValue(0) {} 

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
    triageValue += condition.getPriority();
    calculateTriageValue();
}

void Patients::addCurrentCondition(const Conditions& condition) { 
    currentConditions[condition.getName()] = condition; 
    triageValue += condition.getPriority();
    calculateTriageValue(); 
}

void Patients::removeCurrentCondition(const std::string& conditionName) {
    if (currentConditions.find(conditionName) != currentConditions.end()) 
    {
        triageValue -= currentConditions[conditionName].getPriority();
        currentConditions.erase(conditionName);
        calculateTriageValue();
    }
}

bool Patients::hasPriorCondition(const std::string& conditionName) const {
    return priorConditions.find(conditionName) != priorConditions.end();
}

bool Patients::hasCurrentCondition(const std::string& conditionName) const {
    return currentConditions.find(conditionName) != currentConditions.end();
}

void Patients::getPriorConditions() const {
    std::cout << "Prior Conditions:" << std::endl;
    for (const auto& entry : priorConditions) 
    {
        const Conditions& condition = entry.second;
        std::cout << condition.getName() << "-" << condition.getPriority() << std::endl;
    }
}

void Patients::getCurrentConditions() const {
    std::cout << "Current Conditions:" << std::endl;
    for (const auto& entry : currentConditions) 
    {
        const Conditions& condition = entry.second;
        std::cout << condition.getName() << "-" << condition.getPriority() << std::endl;
    }
}

void Patients::updateCurrentConditionPriority(const std::string& conditionName, int urgency) {
    if (currentConditions.find(conditionName) != currentConditions.end()) 
    {
        triageValue -= currentConditions[conditionName].getPriority();
        currentConditions[conditionName].setPriority(urgency);
        triageValue += urgency;
        calculateTriageValue();
    }
}

void Patients::calculateTriageValue() {
    int triageValue = 0;

    // Calculate triage value based on Prior Conditions
    for (const auto& entry : priorConditions) 
    {
        const Conditions& condition = entry.second;
        triageValue += condition.getPriority();
    }

    // Calculate triage value based on Current Conditions
    for (const auto& entry : currentConditions) 
    {
        const Conditions& condition = entry.second;
        triageValue += condition.getPriority();
    }

    this->triageValue = triageValue;
}
