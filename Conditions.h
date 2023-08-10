#ifndef CONDITIONS_H
#define CONDITIONS_H

#include <unordered_map>
#include <string>

class Conditions {
private:
    std::unordered_map<std::string, int> conditionsMap;

public:
    void addCondition(const std::string& conditionName, int urgency);
    void removeCondition(const std::string& conditionName);
    int getUrgency(const std::string& conditionName) const;
    void printConditions() const;
    bool hasCondition(const std::string& conditionName) const;
    void updateConditionUrgency(const std::string& conditionName, int urgency);
    int calculateTotalUrgency() const;
};

#endif // CONDITIONS_H
