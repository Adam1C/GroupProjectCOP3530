#ifndef PATIENTS_H
#define PATIENTS_H

#include <string>
#include <vector>

class Patients {
private:
    std::string name;
    int age;
    int triageValue;
    std::unordered_map<std::string, bool> priorConditions;
    std::unordered_map<std::string, bool> currentConditions; 

public:
    Patients(const std::string& name, int age);

    // Getters
    std::string getName() const;
    int getAge() const;
    int getTriageValue() const;

    // Calculate triage value based on conditions
    void calculateTriageValue();

    // Hashmap
    void addPriorCondition(const std::string& condition);
    void addCurrentCondition(const std::string& condition);
    bool hasPriorCondition(const std::string& condition); 
    bool hasCurrentCondition(const std::string& condition); 
};

#endif // PATIENTS_H
