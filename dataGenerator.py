import random

# Lists of possible conditions and their urgency ranges
prior_conditions_list = [
    "Respiratory Conditions", "Heart Failure", "Cancer", "Kidney Disease",
    "Immunosuppressive Conditions", "Neurological Conditions", "Autoimmune Diseases",
    "Stroke", "Hemophilia and Other Bleeding Disorders", "Severe Mental Disorders",
    "Severe Allergic Reactions", "Severe Obesity"
]

current_conditions_list = [
    "Chest Pain or Discomfort", "Difficulty Breathing or Shortness of Breath",
    "Uncontrolled Bleeding", "Severe Abdominal Pain", "Sudden Severe Headache",
    "Weakness or Numbness on One Side of the Body", "Loss of Consciousness or Fainting",
    "High Fever", "Seizures", "Severe Allergic Reactions (Anaphylaxis)",
    "Trauma or Injury (Broken Bones or Severe Cuts)", "Coughing/Vomiting Blood",
    "Suicidal Thoughts or Self-Harm", "Severe Dehydration", "Severe Burns"
]

urgency_range = (0, 200)

# Generate 100000 data points
data_points = []
for _ in range(100000):
    name = "Patient"  # You can modify this to generate random names if needed
    age = random.randint(1, 90)
    
    # Generate urgency values for prior conditions
    prior_conditions = []
    for condition in prior_conditions_list:
        urgency = random.randint(*urgency_range)
        prior_conditions.append(f"{condition} ({urgency})")
    
    # Generate urgency values for current conditions
    current_conditions = []
    for condition in current_conditions_list:
        urgency = random.randint(*urgency_range)
        current_conditions.append(f"{condition} ({urgency})")
    
    data_points.append(f"PatientInfo: {name} {age}\nPriorConditions: {' '.join(prior_conditions)}\nCurrentConditions: {' '.join(current_conditions)}")

# Save the data points to a file
with open("generated_data_with_urgency.txt", "w") as file:
    for data in data_points:
        file.write(data + "\n\n")
