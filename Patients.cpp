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

void Patients::addPriorCondition(const std::string& condition) {
    preexistingConditions[condition] = true;
}

void Patients::addCurrentCondition(const std::string& condition) {
    currentConditions[condition] = true;
}

bool Patients::hasPriorCondition(const std::string& condition) {
    return preexistingConditions.find(condition) != preexistingConditions.end();
}

bool Patients::hasCurrentCondition(const std::string& condition) {
    return currentConditions.find(condition) != currentConditions.end();
}

void Patients::calculateTriageValue() {
    // Creating booleans for Prior Conditions
    bool hasRespiratoryConditions = hasPriorCondition("Respiratory Conditions"); 
    bool hasHeartFailure = hasPriorCondition("Heart Failure"); 
    bool hasCancer = hasPriorCondition("Cancer"); 
    bool hasKidneyDisease = hasPriorCondition("Kidney Disease"); 
    bool hasDiabetes = hasPriorCondition("Diabetes"); 
    bool hasImmunosuppressiveConditions = hasPriorCondition("Immunosuppressive Conditions"); 
    bool hasNeurologicalConditions = hasPriorCondition("Neurological Conditions"); 
    bool hasAutoimmuneDiseases = hasPriorCondition("Autoimmune Diseases"); 
    bool hasHIVAIDS = hasPriorCondition("HIV/AIDS"); 
    bool hasStroke = hasPriorCondition("Stroke"); 
    bool hasHemophilia = hasPriorCondition("Hemophilia and Other Bleeding Disorders"); 
    bool hasSevereMentalHealth = hasPriorCondition("Severe Mental Health Disorders"); 
    bool hasSevereAllergicReactions = hasPriorCondition("Severe Allergic Reactions"); 
    bool hasSevereObesity = hasPriorCondition("Severe Obesity"); 

    // Creating booleans for Current Conditions
    bool hasChestPain = hasCurrentCondition("Chest Pain or Discomfort");
    bool hasDifficultyBreathing = hasCurrentCondition("Difficulty Breathing or shortness of Breath"); 
    bool hasUncontrolledBleeding = hasCurrentCondition("Uncontrolled Bleeding"); 
    bool hasSevereAbdominalPain = hasCurrentCondition("Severe Abdominal Pain"); 
    bool hasSuddenSevereHeadache = hasCurrentCondition("Sudden Severe Headache"); 
    bool hasWeaknessOrNumbness = hasCurrentCondition("Weakness or Numbness on One Side of the Body"); 
    bool hasLossOfConsciousness = hasCurrentCondition("Loss of Consciousness or Fainting"); 
    bool hasHighFever = hasCurrentCondition("High Fever"); 
    bool hasSeizures = hasCurrentCondition("Seizures"); 
    bool hasSevereAllergicReactions = hasCurrentCondition("Severe Allergic Reactions (Anaphylaxis)"); 
    bool hasTraumaOrInjury = hasCurrentCondition("Trama or Injury (Broken Bones or Severe cuts)"); 
    bool hasCoughingOrVomitingBlood = hasCurrentCondition("Coughing/Vomiting Blood"); 
    bool hasSuicidalThoughts = hasCurrentCondition("Suicidal Thoughts or Self-Harm"); 
    bool hasSevereDehydration = hasCurrentCondition("Severe Dehydration"); 
    bool hasSevereBurns = hasCurrentCondition("Severe Burns"); 



    if (hasRespiratoryConditions) {
        triageValue += 5
    }
    
    return triageValue;
}
