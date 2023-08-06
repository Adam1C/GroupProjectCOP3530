#ifndef PATIENTS_H
#define PATIENTS_H

#include "Conditions.h"
#include <string>
#include <vector>

class Patients {
private:
    std::string name;
    int age;
    int triageValue;
    std::unordered_map<std::string, Conditions> priorConditions;
    std::unordered_map<std::string, Conditions> currentConditions; 

public:
    Patients(const std::string& name, int age);

    // Getters
    std::string getName() const;
    int getAge() const;
    int getTriageValue() const;

    // Calculate triage value based on conditions
    void calculateTriageValue();

    // Hashmap
    void addPriorCondition(const Conditions& condition);
    void addCurrentCondition(const Conditions& condition);
    void removeCurrentCondition(const std::string& conditionName);
    bool hasPriorCondition(const std::string& conditionName) const;
    bool hasCurrentCondition(const std::string& conditionName) const;
};

#endif // PATIENTS_H
