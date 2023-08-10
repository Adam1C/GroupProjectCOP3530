#include "Patients.h"
#include <iostream>
#include <string>

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

void Patients::addPriorCondition(const std::string& conditionName, int urgency) {
    priorConditions.addCondition(conditionName, urgency);
    triageValue += urgency;
    calculateTriageValue();
}

void Patients::addCurrentCondition(const std::string& conditionName, int urgency) {
    currentConditions.addCondition(conditionName, urgency);
    triageValue += urgency;
    calculateTriageValue();
}

void Patients::removeCurrentCondition(const std::string& conditionName) {
    if (currentConditions.hasCondition(conditionName)) {
        triageValue -= currentConditions.getUrgency(conditionName);
        currentConditions.removeCondition(conditionName);
        calculateTriageValue();
    }
}

bool Patients::hasPriorCondition(const std::string& conditionName) const {
    return priorConditions.hasCondition(conditionName);
}

bool Patients::hasCurrentCondition(const std::string& conditionName) const {
    return currentConditions.hasCondition(conditionName);
}

void Patients::getPriorConditions() const {
    std::cout << "Prior Conditions:" << std::endl;
    priorConditions.printConditions();
}

void Patients::getCurrentConditions() const {
    std::cout << "Current Conditions:" << std::endl;
    currentConditions.printConditions();
}

void Patients::updateCurrentConditionPriority(const std::string& conditionName, int urgency) {
    if (currentConditions.hasCondition(conditionName)) {
        triageValue -= currentConditions.getUrgency(conditionName);
        currentConditions.updateConditionUrgency(conditionName, urgency);
        triageValue += urgency;
        calculateTriageValue();
    }
}

void Patients::calculateTriageValue() {
    triageValue = priorConditions.calculateTotalUrgency() + currentConditions.calculateTotalUrgency();
}
