#ifndef PATIENTS_H
#define PATIENTS_H

#include "Conditions.h"
#include <string>
#include <iostream>

class Patients {
private:
    int triageValue;
    Conditions priorConditions;
    Conditions currentConditions;
    std::string name;

public:
    Patients();
    Patients(const std::string& name, int age);
    int age;

    // Getters
    std::string getName() const;
    int getAge() const;
    int getTriageValue() const;
    void getPriorConditions() const;
    void getCurrentConditions() const;
    void setAge(const std::string& age);
    void setName(const std::string& name);

    // Calculate triage value based on conditions
    void calculateTriageValue();

    // Use Conditions methods for adding, removing, and updating conditions
    void addPriorCondition(const std::string& conditionName, int urgency);
    void addCurrentCondition(const std::string& conditionName, int urgency);
    void removeCurrentCondition(const std::string& conditionName);
    bool hasPriorCondition(const std::string& conditionName) const;
    bool hasCurrentCondition(const std::string& conditionName) const;
    void updateCurrentConditionPriority(const std::string& conditionName, int urgency);
};

#endif // PATIENTS_H
