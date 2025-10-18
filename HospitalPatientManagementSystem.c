#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATIENTS 100

typedef struct {
    int patientID;
    char name[50];
    int age;
    int severity;
} Patient;

Patient patients[MAX_PATIENTS];
int patientCount = 0;

// Swap two patients
void swap(Patient* a, Patient* b) {
    Patient temp = *a;
    *a = *b;
    *b = temp;
}

// Sort patients by severity (descending)
void sortPatients() {
    for (int i = 0; i < patientCount - 1; i++) {
        for (int j = i + 1; j < patientCount; j++) {
            if (patients[j].severity > patients[i].severity) {
                swap(&patients[i], &patients[j]);
            }
        }
    }
}

// Add a new patient
void addPatient(int id, char* name, int age, int severity) {
    if (patientCount >= MAX_PATIENTS) {
        printf("Hospital is full!\n");
        return;
    }
    patients[patientCount].patientID = id;
    strcpy(patients[patientCount].name, name);
    patients[patientCount].age = age;
    patients[patientCount].severity = severity;
    patientCount++;
    sortPatients(); // keep highest severity first
    printf("Patient %s added successfully!\n", name);
}

// Treat the most severe patient
void treatPatient() {
    if (patientCount == 0) {
        printf("No patients to treat.\n");
        return;
    }
    Patient p = patients[0];
    printf("Treating patient %s (ID: %d, Severity: %d)\n", p.name, p.patientID, p.severity);

    // Remove patient from array
    for (int i = 1; i < patientCount; i++) {
        patients[i - 1] = patients[i];
    }
    patientCount--;
}

// Display all patients
void displayPatients() {
    if (patientCount == 0) {
        printf("No patients in hospital.\n");
        return;
    }
    printf("Patients in hospital:\n");
    printf("ID\tName\t\tAge\tSeverity\n");
    for (int i = 0; i < patientCount; i++) {
        printf("%d\t%s\t\t%d\t%d\n", patients[i].patientID, patients[i].name, patients[i].age, patients[i].severity);
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n=== Hospital Management ===\n");
        printf("1. Add Patient\n");
        printf("2. Treat Most Severe Patient\n");
        printf("3. Display Patients\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            int id, age, severity;
            char name[50];
            printf("Enter Patient ID: "); scanf("%d", &id);
            printf("Enter Name: "); scanf("%s", name);
            printf("Enter Age: "); scanf("%d", &age);
            printf("Enter Disease Severity: "); scanf("%d", &severity);
            addPatient(id, name, age, severity);
        } else if (choice == 2) {
            treatPatient();
        } else if (choice == 3) {
            displayPatients();
        } else if (choice == 4) {
            printf("Exiting...\n");
            break;
        } else {
            printf("Invalid choice!\n");
        }
    }
    return 0;
}
