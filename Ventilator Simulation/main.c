#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "initial.h"
#include "queue.h"
// BUGRA ILHAN
// 2315307


// if patients has a vent, this function pops it from the q and it adds the node a different list.
void servePatient(struct queue *ourQueue, struct list *popped, int *ventNum, int *ventilatorList, int *ventilatorDoneTime)
{
    struct patient *node;
    node = popQueue(ourQueue);

    ventilatorList[node->ventilatorID-1] = 1; // make vent available
    ventilatorDoneTime[node->ventilatorID-1] = 0;
    (*ventNum)++;
    printf("One patient popped our q!\n");
    printf("Vent id%d is available! There are %d available vents!\n", node->ventilatorID, (*ventNum));
    if(popped->head->next==NULL)
    {
        popped->head->next = node;
        popped->tail = node;
    }
    else
    {
        popped->tail->next = node;
        popped->tail = node;
    }
    popped->size++;
}

// it returns the closest available time for vent
int ventFreeAt(int *ventilatorList, int *ventilatorDoneTime, int noOfVentilators)
{
    int i=0;
    int smallest = ventilatorDoneTime[i++];
    while(i<noOfVentilators)
    {
        if(ventilatorDoneTime[i]<smallest)
            smallest= ventilatorDoneTime[i];
        i++;
    }
    return smallest;
}

// it parses the inputs and sets the beginning values
void parseInput(int numOfPointers, char **arrayOfPointers, int *noOfPatients, int *noOfVentilators, int *maxArrivalTime, int *maxServiceTime )
{
    if(numOfPointers != 5)
    {
        printf("Wrong entry for initialization! Please run it again!");
        exit(1);
    }
    // index 0 is program name
    *noOfPatients = atoi(arrayOfPointers[1]);  // making string value integer with atoi function
    *noOfVentilators = atoi(arrayOfPointers[2]);
    *maxArrivalTime = atoi(arrayOfPointers[3]);
    *maxServiceTime = atoi(arrayOfPointers[4]);
}

// it sorts the list ascending order based on arrival time.
void sortList(struct patient *patientHead)
{
    struct patient *tempNode; // for swapping data
    tempNode=malloc(sizeof(struct patient));
    if(tempNode==NULL)
    {
        printf("There is a memory problem!");
        exit(1);
    }
    struct patient *current, *currentPlus; // 2 pointers to nodes which will be swap
    current = patientHead->next;
    while(current != NULL)
    {
        currentPlus = current->next;
        while(currentPlus != NULL)
        {
            if(current->arrivalTime > currentPlus->arrivalTime)
            {
                // first node's arrivalTime into temporary node
                tempNode->arrivalTime = current->arrivalTime;
                tempNode->next = NULL;

                // 2nd node's arrivalTime into 1st node
                current->arrivalTime = currentPlus->arrivalTime;

                // 1st node's arrivalTime which is stored in temporary node into 2nd node
                currentPlus->arrivalTime = tempNode->arrivalTime;
            }
            currentPlus = currentPlus->next;
        }
        current = current->next;
    }
    free(tempNode);
}

// creates list, adds nodes, calls the sortlist function and returns list to the main.
struct list *createPatientList(int noOfPatients, int maxArrivalTime, int maxServiceTime)
{
    // Creating/Initializing List
    struct list *patientList;
    patientList = malloc(sizeof(struct list));
    if(patientList == NULL)
    {
        printf("There is a memory problem!");
        exit(1);
    }
    patientList->head = malloc(sizeof(struct patient));
    patientList->head->next = NULL;
    patientList->tail = patientList->head;
    patientList->size = 0;
    //End Of Creating/Initializing List

    //Adding Patients into List
    struct patient *temporary;
    int i=0;
    for(i;i<noOfPatients;i++)
    {
        temporary = malloc(sizeof(struct patient));
        if(temporary == NULL)
        {
            printf("There is a memory problem!");
            exit(1);
        }
        temporary->patientType = rand()%3+1;
        temporary->arrivalTime = rand()%maxArrivalTime+1;
        temporary->serviceTime = rand()%maxServiceTime+1;
        temporary->serviceStartTime = 0;
        temporary->finishTime = 0;
        temporary->waitingTime = 0;
        temporary->ventilatorID = 0;
        temporary->patientGender = rand()%2+1;
        temporary->patientAgeGroup = rand()%3+1;
        temporary->next = NULL;

        if(patientList->head->next == NULL)
        {
            patientList->head->next = temporary;
            patientList->tail = temporary;
        }
        else
        {
            patientList->tail->next = temporary;
            patientList->tail = temporary;
        }
        patientList->size++;
    }
    //Sorting list according to arrival time
    sortList(patientList->head);
    return patientList;
}

// creates queue and returns queue to main.
// i could not do initialization for ventlist
// and ventlistdone because global variables
// are restricted( i could write them in header file).
struct queue *initialiseSimulator()
{
    struct queue *patientQueue;
    patientQueue = createQueue(); // queue created
    return patientQueue;
}

// add's new patient to the queue, sets the time depends on the situation,
// sets patient's vent id, makes that vent busy, sets that vent free time,
// and sets the priority if there are more than 2 patients waiting.
void newPatient(struct queue *ourQueue, struct list *popped, struct patient *listNode, int *ventNum, int *ventilatorList, int *ventilatorDoneTime, int noOfVentilators, int *simulationTime, int j)
{
    if(j!=1)
        *simulationTime = listNode->arrivalTime;
    printf("Time set ---> %d\n", *simulationTime);
    int i=0;
    if(IsEmptyQueue(ourQueue)==1)
    {
        printf("Right now queue is empty! All ventilators available(%d)!\n", noOfVentilators);
        addQueue(ourQueue, listNode);
        for(i;i<noOfVentilators;i++)
        {
            if(ventilatorList[i]==1)
            {
                ourQueue->front->next->ventilatorID = i+1;
                ourQueue->front->next->finishTime = listNode->arrivalTime+ listNode->serviceTime;
                ventilatorList[i]=0;
                ventilatorDoneTime[i]=listNode->arrivalTime+ listNode->serviceTime;
                printf("Patient just added\n");
                printf("Vent id%d will be busy until %d\n", i+1, ventilatorDoneTime[i]);
                (*ventNum) -= 1;
                printf("%d Vents available!\n", (*ventNum));
                break;
            }
        }
    }
    else
    {
        printf("There is/are %d person in queue.", ourQueue->size);
        if((*ventNum)!=0)
        {
            addQueue(ourQueue, listNode);
            printf("But there is/are %d vents available!\n",(*ventNum));
            for(i;i<noOfVentilators;i++)
            {
                if(ventilatorList[i]==1)
                {
                    ourQueue->rear->ventilatorID = i+1;
                    ourQueue->rear->finishTime = listNode->arrivalTime+ listNode->serviceTime;
                    ventilatorList[i]=0;
                    ventilatorDoneTime[i]=listNode->arrivalTime+listNode->serviceTime;
                    printf("Patient just added\n");
                    printf("Vent id%d will be busy until %d\n", i+1, ventilatorDoneTime[i]);
                    (*ventNum) -= 1;
                    printf("%d Vents available!\n", (*ventNum));
                    break;
                }
            }
        }
        else
        {
            ourQueue->rear->waitingTime = ventFreeAt(ventilatorList,ventilatorDoneTime,noOfVentilators) - ourQueue->rear->arrivalTime;
            printf("This customer will wait %d seconds OR until %d!\n",ourQueue->rear->waitingTime,ventFreeAt(ventilatorList,ventilatorDoneTime, noOfVentilators));
            if(*simulationTime==ventFreeAt(ventilatorList,ventilatorDoneTime, noOfVentilators))
                servePatient(ourQueue, popped, ventNum, ventilatorList, ventilatorDoneTime);
            printf("Yet there is no available vents!\n");
            addQueue(ourQueue, listNode);
            prioQueue(ourQueue); // sorting queue according to priority
        }
    }
}

// reporting the statistics
void reportStatistics(struct list *lastList, int noOfVentilators, int noOfPatients)
{
    struct patient *listP = lastList->head->next;
    printf("\n ***************************REPORT***************************\n");
    printf("Number of ventilators: %d\n", noOfVentilators);
    printf("Number of patients: %d\n", noOfPatients);
    int waiting=0;
    float totalwaiting=0;
    int type1=0,type2=0,type3=0;
    int male=0, female=0;
    int elderly=0, adult=0, young=0;
    while(listP!=NULL)
    {
        if(listP->patientType == 1)
            type1++;
        else if(listP->patientType == 2)
            type2++;
        else if(listP->patientType == 3)
            type3++;

        if(listP->patientGender == 1)
            female++;
        else if(listP->patientGender == 2)
            male++;
        if(listP->patientAgeGroup == 1)
            young++;
        else if(listP->patientAgeGroup == 2)
            adult++;
        else if(listP->patientAgeGroup == 3)
            elderly++;
        if(listP->waitingTime > waiting)
            waiting = listP->waitingTime;
        totalwaiting = totalwaiting + listP->waitingTime;
        listP = listP->next;
    }
    int completion = lastList->tail->finishTime;

    printf("Number of patients for each patient type:\n");
    printf("     Severe: %d\n", type3);
    printf("     Moderate: %d\n", type2);
    printf("     Mild: %d\n", type1);
    listP = lastList->head->next;
    int i=0, j;
    while(i<noOfVentilators)
    {
        j=0;
        listP = lastList->head->next;
        while(listP!=NULL)
        {
            if(listP->ventilatorID == i+1)
                j++;

            listP = listP->next;
        }
        printf("Vent id %d is used(times): %d\n", i+1, j);
        i++;
    }
    printf("Completion time(Everything finished): %d\n", completion);
    printf("Average time spent in queue: %.2f \n", (totalwaiting/noOfPatients));
    if(male>female)
        printf("Most gender usage is male!\n");
    else if(female>male)
        printf("Most gender usage is female!\n");
    else
        printf("Gender usage is equal!\n");

    if(elderly>adult)
    {
        if(adult>young)
        {
             printf("Most usage is elderly!\n");
        }
        else if(adult<young)
        {
            if(elderly>young)
                printf("Most usage is elderly!\n");
            else if(elderly<young)
                printf("Most usage is young!\n");
        }
    }
    else if(adult>elderly)
    {
        if(elderly>young)
        {
            printf("Most usage is adult!\n");
        }
        else if(elderly>young)
        {
            if(adult<young)
                printf("Most usage is young!\n");
            else if(adult>young)
                printf("Most usage is adult!\n");
        }
    }
    else
    {
        printf("Most usage genders are equal!\n");
    }
}


int main(int argc, char *argv[])
{
    int noOfPatients, noOfVentilators, maxArrivalTime, maxServiceTime;
    srand(time(NULL));
    parseInput(argc, argv, &noOfPatients, &noOfVentilators, &maxArrivalTime, &maxServiceTime);  // argv is an array of pointers to string

    // list for popped nodes from queue
    struct list *poppedList;
    poppedList = malloc(sizeof(struct list));
    if(poppedList == NULL)
    {
        printf("There is a memory problem!");
        exit(1);
    }
    poppedList->head = malloc(sizeof(struct patient));
    poppedList->head->next = NULL;
    poppedList->tail = poppedList->head;
    poppedList->size = 0;
    // end of list for popped nodes from queue

    // created vent lists here because  i could
    // not allocate memory without using global
    // variable ( declare them in header file )
    // for them.
    int *ventilatorList, *ventilatorDoneTime;
    int availableVentNum = noOfVentilators;
    ventilatorList = malloc(sizeof(int)*noOfVentilators);
    ventilatorDoneTime = malloc(sizeof(int)*noOfVentilators);
    if(ventilatorList==NULL)
    {
        printf("There is a memory problem!");
        exit(1);
    }

    int i=0;
    for(i;i<noOfVentilators;i++)
    {
        ventilatorList[i]=1;
        ventilatorDoneTime[i]=0;
    }
    // end of vent lists


    struct list *listOfPatients;
    listOfPatients = createPatientList(noOfPatients, maxArrivalTime, maxServiceTime); // sorted list of patients is ready
    struct patient *currentListNode=listOfPatients->head->next;


    struct queue *queueOfPatients; // main queue
    queueOfPatients =  initialiseSimulator();

    int simulationTime=0;
    int totalQueued=0, poppedPatients=0; // counting the patients
    int j, stop=1; // stop condition
    // SIMULATION BEGINS
    while(stop)
    {
        newPatient(queueOfPatients, poppedList,currentListNode, &availableVentNum, ventilatorList, ventilatorDoneTime, noOfVentilators, &simulationTime, j);
        j=0;
        printf("There is %d person in queue!\n", queueOfPatients->size);

        printf("\nSIM TIME : %d         FINISH1 TIME : %d \n",simulationTime, queueOfPatients->front->next->finishTime );

        if(simulationTime >= queueOfPatients->front->next->finishTime)
        {
            servePatient(queueOfPatients, poppedList, &availableVentNum, ventilatorList, ventilatorDoneTime);
            poppedPatients++;
        }
        else // if someone's job would finish before the next patients comes, its makes j to finish time
        {    // because i want that vent empty if it's possible before some one comes. j is a switch.
            simulationTime = queueOfPatients->front->next->finishTime;
            j=1;
        }

        if(totalQueued==4 && queueOfPatients->size > 0)// if there is no one left to add, pop the patients in order
        {
            while(queueOfPatients->front->next != NULL)
            {
                simulationTime = maxArrivalTime+maxServiceTime+1;
                servePatient(queueOfPatients, poppedList, &availableVentNum, ventilatorList, ventilatorDoneTime);
            }
            if(queueOfPatients->front->next == NULL)
            {
                printf("!!!!!!!!!!!ALL PATIENTS POPPED!!!!!!!!!!!!!!!!!!!\n");
                stop = 0;
            }
        }
        totalQueued++;
        currentListNode = currentListNode->next;
    }
    reportStatistics(poppedList, noOfVentilators, noOfPatients);

    return 0;
}








