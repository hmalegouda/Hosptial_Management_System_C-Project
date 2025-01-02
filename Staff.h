#ifndef STAFF_H
#define STAFF_H

typedef struct {
    int id;
    char name[50];
    char position[50];
    char department[50];
} Staff;

// Function declarations
void addStaff();
void viewStaff();
void updateStaff();
void deleteStaff();

#endif
