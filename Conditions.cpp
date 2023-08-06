#include "Conditions.h"

Conditions::Conditions(const std::string& name, int priority)
    : name(name), priority(priority) {}

std::string Conditions::getName() const {
    return name;
}

int Conditions::getPriority() const {
    return priority;
}

void Conditions::setPriority(int newPriority) {
    priority = newPriority;
}
