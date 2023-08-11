#ifndef CONDITIONS_H
#define CONDITIONS_H

#include <unordered_map>
#include <string>

class Conditions {
private:
    std::unordered_map<std::string, int> conditionsMap; // Store conditions and their urgencies

public:
    // Add or Remove a new condition with its associated urgency
    void addCondition(const std::string& conditionName, int urgency);
    void removeCondition(const std::string& conditionName);

    void removeAll();
    bool empty() const;
    // Get the urgency associated with a specific condition
    int getUrgency(const std::string& conditionName) const;
    // Print all stored conditions and their urgencies
    void printConditions() const;
    // Check if a specific condition exists
    bool hasCondition(const std::string& conditionName) const;
    // Update the urgency of an existing condition
    void updateConditionUrgency(const std::string& conditionName, int urgency);
    // Calculate and return the total urgency across all conditions
    int calculateTotalUrgency() const;
};

#endif
