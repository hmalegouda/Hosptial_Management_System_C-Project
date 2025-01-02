#ifndef PATIENT_H
#define PATIENT_H

typedef struct {
    int id;
    char name[50];
    int age;
    char gender[10];
    char address[100];
} Patient;

// Function declarations
void addPatient();
void viewPatients();
void updatePatient();
void deletePatient();

#endif
