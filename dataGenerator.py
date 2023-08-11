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
    "High Fever", "Seizures", "Severe Allergic Reactions",
    "Trauma or Injury", "Coughing/Vomiting Blood",
    "Suicidal Thoughts or Self-Harm", "Severe Dehydration", "Severe Burns"
]
names = [
    "Alice", "Bob", "Charlie", "David", "Emma", "Frank", "Grace", "Henry", "Ivy", "Jack",
    "Kate", "Liam", "Mia", "Noah", "Olivia", "Sophia", "William", "Ava", "James", "Isabella",
    "Benjamin", "Sophie", "Alexander", "Charlotte", "Daniel", "Amelia", "Matthew", "Ella",
    "Michael", "Emily", "Andrew", "Grace", "Joseph", "Lily", "Ethan", "Chloe", "Henry", "Lucy",
    "Samuel", "Zoe", "Christopher", "Hannah", "William", "Harper", "Daniel", "Lillian",
    "Matthew", "Nora", "Aiden", "Evelyn", "David", "Victoria", "Elijah", "Aria", "James",
    "Scarlett", "Joseph", "Madison", "John", "Layla", "Robert", "Penelope", "Matthew",
    "Riley", "Anthony", "Ellie", "Richard", "Aurora", "Charles", "Nova", "Thomas", "Emilia",
    "Connor", "Stella", "Isaac", "Claire", "Owen", "Hazel", "Caleb", "Lucy", "Ryan", "Lillian",
    "Nathan", "Zara", "Nicholas", "Skylar", "Leo", "Luna", "Henry", "Leah", "Jack", "Violet",
    "Andrew", "Savannah", "Dylan", "Addison", "Gabriel", "Maya", "Eli", "Elena", "Samuel",
    "Elizabeth", "Joshua", "Naomi", "Max", "Alice", "Joseph", "Eva", "William", "Anna",
    "Sebastian", "Sarah"
]
urgency_range = (0, 200)

# Generate 100000 data points
data_points = []
for _ in range(100000):
    name = random.choice(names)
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

    data_points.append(
        f"PatientInfo: {name} {age}\nPriorConditions: {' '.join(prior_conditions)}\nCurrentConditions: {' '.join(current_conditions)}")

# Save the data points to a file
with open("generated_data_with_urgency.txt", "w") as file:
    for data in data_points:
        file.write(data + "\n\n")
