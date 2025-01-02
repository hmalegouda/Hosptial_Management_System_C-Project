#ifndef BILLING_H
#define BILLING_H

typedef struct {
    int id;
    int patientId;
    float amount;
    char date[20];
} Billing;

// Function declarations
void addBilling();
void viewBilling();
void updateBilling();
void deleteBilling();

#endif
