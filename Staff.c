#include "Staff.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function definitions
void addStaff() {
    FILE *file = fopen("staff.dat", "ab");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    Staff newStaff;
    printf("Enter Staff ID: ");
    scanf("%d", &newStaff.id);
    printf("Enter Staff Name: ");
    scanf("%s", newStaff.name);
    printf("Enter Position: ");
    scanf("%s", newStaff.position);
    printf("Enter Department: ");
    scanf("%s", newStaff.department);

    fwrite(&newStaff, sizeof(Staff), 1, file);
    fclose(file);

    printf("Staff member added successfully!\n");
}

void viewStaff() {
    FILE *file = fopen("staff.dat", "rb");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    Staff staff;
    while (fread(&staff, sizeof(Staff), 1, file)) {
        printf("ID: %d\n", staff.id);
        printf("Name: %s\n", staff.name);
        printf("Position: %s\n", staff.position);
        printf("Department: %s\n", staff.department);
        printf("------------------------\n");
    }
    fclose(file);
}

void updateStaff() {
    FILE *file = fopen("staff.dat", "rb+");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    int id;
    printf("Enter Staff ID to update: ");
    scanf("%d", &id);

    Staff staff;
    int found = 0;
    while (fread(&staff, sizeof(Staff), 1, file) && !found) {
        if (staff.id == id) {
            printf("Enter new name: ");
            scanf("%s", staff.name);
            printf("Enter new position: ");
            scanf("%s", staff.position);
            printf("Enter new department: ");
            scanf("%s", staff.department);

            fseek(file, -sizeof(Staff), SEEK_CUR);
            fwrite(&staff, sizeof(Staff), 1, file);
            found = 1;
            printf("Staff member updated successfully!\n");
        }
    }

    if (!found) {
        printf("Staff member with ID %d not found!\n");
    }

    fclose(file);
}

void deleteStaff() {
    FILE *file = fopen("staff.dat", "rb");
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
    printf("Enter Staff ID to delete: ");
    scanf("%d", &id);

    Staff staff;
    int found = 0;
    while (fread(&staff, sizeof(Staff), 1, file)) {
        if (staff.id == id) {
            found = 1;
            continue;
        }
        fwrite(&staff, sizeof(Staff), 1, tempFile);
    }

    fclose(file);
    fclose(tempFile);

    remove("staff.dat");
    rename("temp.dat", "staff.dat");

    if (found) {
        printf("Staff member deleted successfully!\n");
    } else {
        printf("Staff member with ID %d not found!\n");
    }
}
