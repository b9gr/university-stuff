#ifndef INITAL_H
#define INITAL_H

struct patient
{
    int patientType; // 3 for severe, 2 for moderate, 1 for mild
    int arrivalTime;
    int serviceTime;
    int serviceStartTime;
    int finishTime; // extra parameter
    int waitingTime; // extra parameter
    int ventilatorID;
    int patientGender; // 2 for male, 1 for female
    int patientAgeGroup; // 3 for elderly, 2 for adult, 1 for young
    struct patient *next;
};

struct list
{
    struct patient *head;
    struct patient *tail;
    int size;
};


struct queue
{
    struct patient *front;
    struct patient *rear;
    int size;
};



#endif // INITAL_H
