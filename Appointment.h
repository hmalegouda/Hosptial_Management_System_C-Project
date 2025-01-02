#ifndef APPOINTMENT_H
#define APPOINTMENT_H

typedef struct {
    int id;
    int patientId;
    int staffId;
    char date[20];
    char time[10];
} Appointment;

// Function declarations
void addAppointment();
void viewAppointments();
void updateAppointment();
void deleteAppointment();

#endif
