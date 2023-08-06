#ifndef CONDITIONS_H
#define CONDITIONS_H

#include <string>

class Conditions {
private:
    std::string name;
    int priority;

public:
    Conditions(const std::string& name, int priority);

    // Getters
    std::string getName() const;
    int getPriority() const;
};

#endif // CONDITIONS_H
