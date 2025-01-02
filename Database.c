#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Database.h"

// Structure definitions for Patient, Appointment, and Billing
typedef struct {
    int id;
    char name[50];
    int age;
    char gender[10];
    char disease[50];
} Patient;

typedef struct {
    int id;
    int patient_id;
    char date[20];
    char time[10];
    char doctor[50];
} Appointment;

typedef struct {
    int id;
    int patient_id;
    double amount;
    char date[20];
} Billing;

// Function to add a new patient
void addPatient(Patient *patient) {
    FILE *file = fopen("patients.dat", "ab");
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    fwrite(patient, sizeof(Patient), 1, file);
    fclose(file);
}

// Function to retrieve all patients
void getPatients() {
    FILE *file = fopen("patients.dat", "rb");
    if (file == NULL) {
        printf("No patient records found.\n");
        return;
    }
    Patient patient;
    printf("Patients:\n");
    while (fread(&patient, sizeof(Patient), 1, file)) {
        printf("ID: %d, Name: %s, Age: %d, Gender: %s, Disease: %s\n",
               patient.id, patient.name, patient.age, patient.gender, patient.disease);
    }
    fclose(file);
}

// Function to add a new appointment
void addAppointment(Appointment *appointment) {
    FILE *file = fopen("appointments.dat", "ab");
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    fwrite(appointment, sizeof(Appointment), 1, file);
    fclose(file);
}

// Function to retrieve all appointments
void getAppointments() {
    FILE *file = fopen("appointments.dat", "rb");
    if (file == NULL) {
        printf("No appointment records found.\n");
        return;
    }
    Appointment appointment;
    printf("Appointments:\n");
    while (fread(&appointment, sizeof(Appointment), 1, file)) {
        printf("ID: %d, Patient ID: %d, Date: %s, Time: %s, Doctor: %s\n",
               appointment.id, appointment.patient_id, appointment.date, appointment.time, appointment.doctor);
    }
    fclose(file);
}

// Function to add a new billing record
void addBilling(Billing *billing) {
    FILE *file = fopen("billings.dat", "ab");
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    fwrite(billing, sizeof(Billing), 1, file);
    fclose(file);
}

// Function to retrieve all billing records
void getBillings() {
    FILE *file = fopen("billings.dat", "rb");
    if (file == NULL) {
        printf("No billing records found.\n");
        return;
    }
    Billing billing;
    printf("Billings:\n");
    while (fread(&billing, sizeof(Billing), 1, file)) {
        printf("ID: %d, Patient ID: %d, Amount: %.2f, Date: %s\n",
               billing.id, billing.patient_id, billing.amount, billing.date);
    }
    fclose(file);
}
