#include <stdio.h>
#include "patient.h"
#include "appointment.h"
#include "billing.h"

int main() {
    int choice;

    do {
        printf("\nHospital Management System\n");
        printf("1. Manage Patients\n");
        printf("2. Schedule Appointments\n");
        printf("3. Billing\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                managePatients();
                break;
            case 2:
                scheduleAppointments();
                break;
            case 3:
                manageBilling();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
