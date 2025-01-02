#include "Billing.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function definitions
void addBilling() {
    FILE *file = fopen("billing.dat", "ab");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    Billing newBilling;
    printf("Enter Billing ID: ");
    scanf("%d", &newBilling.id);
    printf("Enter Patient ID: ");
    scanf("%d", &newBilling.patientId);
    printf("Enter Amount: ");
    scanf("%f", &newBilling.amount);
    printf("Enter Date (YYYY-MM-DD): ");
    scanf("%s", newBilling.date);

    fwrite(&newBilling, sizeof(Billing), 1, file);
    fclose(file);

    printf("Billing information added successfully!\n");
}

void viewBilling() {
    FILE *file = fopen("billing.dat", "rb");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    Billing billing;
    while (fread(&billing, sizeof(Billing), 1, file)) {
        printf("ID: %d\n", billing.id);
        printf("Patient ID: %d\n", billing.patientId);
        printf("Amount: %.2f\n", billing.amount);
        printf("Date: %s\n", billing.date);
        printf("------------------------\n");
    }
    fclose(file);
}

void updateBilling() {
    FILE *file = fopen("billing.dat", "rb+");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    int id;
    printf("Enter Billing ID to update: ");
    scanf("%d", &id);

    Billing billing;
    int found = 0;
    while (fread(&billing, sizeof(Billing), 1, file) && !found) {
        if (billing.id == id) {
            printf("Enter new Patient ID: ");
            scanf("%d", &billing.patientId);
            printf("Enter new Amount: ");
            scanf("%f", &billing.amount);
            printf("Enter new Date (YYYY-MM-DD): ");
            scanf("%s", billing.date);

            fseek(file, -sizeof(Billing), SEEK_CUR);
            fwrite(&billing, sizeof(Billing), 1, file);
            found = 1;
            printf("Billing information updated successfully!\n");
        }
    }

    if (!found) {
        printf("Billing information with ID %d not found!\n");
    }

    fclose(file);
}

void deleteBilling() {
    FILE *file = fopen("billing.dat", "rb");
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
    printf("Enter Billing ID to delete: ");
    scanf("%d", &id);

    Billing billing;
    int found = 0;
    while (fread(&billing, sizeof(Billing), 1, file)) {
        if (billing.id == id) {
            found = 1;
            continue;
        }
        fwrite(&billing, sizeof(Billing), 1, tempFile);
    }

    fclose(file);
    fclose(tempFile);

    remove("billing.dat");
    rename("temp.dat", "billing.dat");

    if (found) {
        printf("Billing information deleted successfully!\n");
    } else {
        printf("Billing information with ID %d not found!\n");
    }
}
