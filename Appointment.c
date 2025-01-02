#include "Appointment.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function definitions
void addAppointment() {
    FILE *file = fopen("appointments.dat", "ab");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    Appointment newAppointment;
    printf("Enter Appointment ID: ");
    scanf("%d", &newAppointment.id);
    printf("Enter Patient ID: ");
    scanf("%d", &newAppointment.patientId);
    printf("Enter Staff ID: ");
    scanf("%d", &newAppointment.staffId);
    printf("Enter Date (YYYY-MM-DD): ");
    scanf("%s", newAppointment.date);
    printf("Enter Time (HH:MM): ");
    scanf("%s", newAppointment.time);

    fwrite(&newAppointment, sizeof(Appointment), 1, file);
    fclose(file);

    printf("Appointment added successfully!\n");
}

void viewAppointments() {
    FILE *file = fopen("appointments.dat", "rb");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    Appointment appointment;
    while (fread(&appointment, sizeof(Appointment), 1, file)) {
        printf("ID: %d\n", appointment.id);
        printf("Patient ID: %d\n", appointment.patientId);
        printf("Staff ID: %d\n", appointment.staffId);
        printf("Date: %s\n", appointment.date);
        printf("Time: %s\n", appointment.time);
        printf("------------------------\n");
    }
    fclose(file);
}

void updateAppointment() {
    FILE *file = fopen("appointments.dat", "rb+");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    int id;
    printf("Enter Appointment ID to update: ");
    scanf("%d", &id);

    Appointment appointment;
    int found = 0;
    while (fread(&appointment, sizeof(Appointment), 1, file) && !found) {
        if (appointment.id == id) {
            printf("Enter new Patient ID: ");
            scanf("%d", &appointment.patientId);
            printf("Enter new Staff ID: ");
            scanf("%d", &appointment.staffId);
            printf("Enter new Date (YYYY-MM-DD): ");
            scanf("%s", appointment.date);
            printf("Enter new Time (HH:MM): ");
            scanf("%s", appointment.time);

            fseek(file, -sizeof(Appointment), SEEK_CUR);
            fwrite(&appointment, sizeof(Appointment), 1, file);
            found = 1;
            printf("Appointment updated successfully!\n");
        }
    }

    if (!found) {
        printf("Appointment with ID %d not found!\n");
    }

    fclose(file);
}

void deleteAppointment() {
    FILE *file = fopen("appointments.dat", "rb");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    FILE *tempFile = fopen("temp.dat", "wb");
    if (tempFile == NULL) {
        printf("Error opening temporary file!\n");
        fclose(file);
        return;
    }

    int id;
    printf("Enter Appointment ID to delete: ");
    scanf("%d", &id);

    Appointment appointment;
    int found = 0;
    while (fread(&appointment, sizeof(Appointment), 1, file)) {
        if (appointment.id == id) {
            found = 1;
            continue;
        }
        fwrite(&appointment, sizeof(Appointment), 1, tempFile);
    }

    fclose(file);
    fclose(tempFile);

    remove("appointments.dat");
    rename("temp.dat", "appointments.dat");

    if (found) {
        printf("Appointment deleted successfully!\n");
    } else {
        printf("Appointment with ID %d not found!\n");
    }
}
