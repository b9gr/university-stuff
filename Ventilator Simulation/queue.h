#include "initial.h"
#ifndef QUEUE_H

// creating empty queue
struct queue *createQueue()
{
    struct queue *patientQueue;
    patientQueue = malloc(sizeof(struct queue));
    if(patientQueue==NULL)
    {
        printf("There is a memory problem!");
        exit(1);
    }
    patientQueue->front = malloc(sizeof(struct patient));
    if(patientQueue->front == NULL)
    {
        printf("There is a memory problem!");
        exit(1);
    }
    patientQueue->front->next = NULL;
    patientQueue->rear = patientQueue->front;
    patientQueue->size=0;
    return patientQueue;
}

int IsEmptyQueue(struct queue *ptQueue)
{
    if(ptQueue->size==0)
        return 1;
    else
        return 0;
}


// adding element to queue
void addQueue(struct queue *ptQueue, struct patient *ptNode)
{
    struct patient *temporary;
    temporary=malloc(sizeof(struct patient));
    if(temporary==NULL)
    {
        printf("There is a memory problem!");
        exit(1);
    }

    temporary->patientType = ptNode->patientType;
    temporary->arrivalTime = ptNode->arrivalTime;
    temporary->serviceTime = ptNode->serviceTime;
    temporary->serviceStartTime = ptNode->serviceStartTime;
    temporary->finishTime = ptNode->finishTime;
    temporary->waitingTime = ptNode->waitingTime;
    temporary->ventilatorID = ptNode->ventilatorID;
    temporary->patientGender = ptNode->patientGender;
    temporary->patientAgeGroup = ptNode->patientAgeGroup;
    temporary->next=NULL;

    if(ptQueue->front->next == NULL)
    {
        ptQueue->front->next = temporary;
        ptQueue->rear = temporary;
    }
    else
    {
        ptQueue->rear->next = temporary;
        ptQueue->rear = temporary;
    }
    ptQueue->size++;

}

struct patient *popQueue(struct queue *ptQueue)
{
    struct patient *temporary, *pointer;
    pointer = ptQueue->front->next;
    temporary = malloc(sizeof(struct patient));
    if(temporary==NULL)
    {
        printf("There is a memory problem!");
        exit(1);
    }

    temporary->patientType = pointer->patientType;
    temporary->arrivalTime = pointer->arrivalTime;
    temporary->serviceTime = pointer->serviceTime;
    temporary->serviceStartTime = pointer->serviceStartTime;
    temporary->waitingTime = pointer->waitingTime;
    temporary->finishTime = pointer->finishTime;
    temporary->ventilatorID = pointer->ventilatorID;
    temporary->patientGender = pointer->patientGender;
    temporary->patientAgeGroup = pointer->patientAgeGroup;
    temporary->next=NULL;

    if(ptQueue->front->next->next==NULL)// there is just 1 node in q
    {
        ptQueue->rear=ptQueue->front;
        ptQueue->front->next = NULL;
    }
    else // if there is not just 1 node in 1
    {
        ptQueue->front->next = ptQueue->front->next->next;
    }

    free(pointer);
    ptQueue->size--;
    return temporary;
}

void prioQueue(struct queue *q)
{
    struct patient *tempNode; // temporary node
    tempNode=malloc(sizeof(struct patient));
    if(tempNode==NULL)
    {
        printf("There is a memory problem!");
        exit(1);
    }
    struct patient *node1, *node2; // 2 pointers to nodes which will be swap
    node1 = q->front->next;  // first node which need to go back
    while(node1 != NULL)
    {
        node2 = node1->next;// 2nd node which needs to be front
        while(node2 != NULL)
        {
            if(node1->patientType < node2->patientType)
            {

                tempNode->arrivalTime = node1->arrivalTime;
                tempNode->serviceTime = node1->serviceTime;
                tempNode->serviceStartTime = node1->serviceStartTime;
                tempNode->finishTime = node1->finishTime;
                tempNode->waitingTime = node1->waitingTime;
                tempNode->ventilatorID = node1->ventilatorID;
                tempNode->patientGender = node1->patientGender;
                tempNode->patientAgeGroup = node1->patientAgeGroup;
                tempNode->next = node1->next;



                node1->arrivalTime = node2->arrivalTime;
                node1->serviceTime = node2->serviceTime;
                node1->serviceStartTime = node2->serviceStartTime;
                node1->finishTime = node2->finishTime;
                node1->waitingTime = node2->waitingTime;
                node1->ventilatorID = node2->ventilatorID;
                node1->patientGender = node2->patientGender;
                node1->patientAgeGroup = node2->patientAgeGroup;
                node1->next = node2->next;



                node2->arrivalTime = tempNode->arrivalTime;
                node2->serviceTime = tempNode->serviceTime;
                node2->serviceStartTime = tempNode->serviceStartTime;
                node2->finishTime = tempNode->finishTime;
                node2->waitingTime = tempNode->waitingTime;
                node2->ventilatorID = tempNode->ventilatorID;
                node2->patientGender = tempNode->patientGender;
                node2->patientAgeGroup = tempNode->patientAgeGroup;
                node2->next = tempNode->next;
            }
            node2 = node2->next;
        }
        node1 = node1->next;
    }
    free(tempNode);
}

#endif // QUEUE_H
