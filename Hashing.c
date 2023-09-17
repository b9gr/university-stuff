#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
// BUGRA ILHAN - 2315307

struct Student
{
    char studentID[4];
    char name[41];
    char depCode[4];
};

// initializing table and returns pointer to it
struct Student **initializaTable(int *size)
{
    struct Student **temp;
    temp = (struct Student **) malloc((*size) * sizeof(struct Student *));
    for (int i = 0; i < *size; i++)
        temp[i] = NULL;

    return temp;
}

// asking for hashing in case of collision, called in main
int hashingMethod()
{
    int choice;
    while (1)
    {
        printf("1 for double hashing, 2 for quadratic probing: ");
        scanf("%d", &choice);
        fflush(stdin);
        if (choice == 1 || choice == 2)
            break;
        else
            printf("Invalid input!\n");
    }
    return choice;
}

// menu and its input, called in main
int menu()
{
    int choice;
    while (1)
    {
        printf("\n1. Add a student ");
        printf("\n2. Search for a student using ID ");
        printf("\n3. Print Table ");
        printf("\n4. Exit ");
        printf("\nYour choice: ");
        scanf("%d", &choice);
        fflush(stdin);
        if (choice == 1 || choice == 2 || choice == 3 || choice == 4)
            break;
        else
            printf("Invalid input!\n");
    }
    return choice;
}

// checking number is prime or not
int isPrime(int number)
{
    int i;
    for (int i = 2; i < number; i++)
    {
        if (number % i == 0 && i != number)
            return 0;
    }
    return 1;
}

// to calculate new size. it uses isPrime function
// otherwise it is adding 1 to it and checks again
int nextSize(int size)
{
    int newSize = 2 * size;
    while (isPrime(newSize) == 0)
    {
        newSize++;
    }
    return newSize;
}

// returns the key for hashing
int returnKey(char *ID)
{
    char *p = ID;
    int num;
    int key = 0;
    while (*p)
    {
        if (isdigit(*p))
        {
            num = (*p) - '0';
            key += num;
        }
        else
            key += *p;
        p++;
    }
    return key - 65;
}

// returns the student node for adding hash table with its inputs in it
struct Student *newStudent()
{
    struct Student *temp;
    temp = malloc(sizeof(struct Student));

    printf("ID:"); // getting id
    gets(temp->studentID);
    fflush(stdin); // clearing buffer

    printf("Name:");
    fgets(temp->name, 41, stdin); // getting line as a input

    strtok(temp->name,"\n");     // removing new line from it
    fflush(stdin);

    printf("Department:"); // getting department
    gets(temp->depCode);
    fflush(stdin);

    return temp;
}

// for adding the student node to hash table. addOrRehash variable is 0 means that it is called in main with NULL node.
// otherwise means that it is called in rehashTable function with every node for rehashing with new size.
struct Student **addStudent(struct Student **Table, int size, int choice, int *studentsAdded, int addOrRehash, struct Student *st)
{
    struct Student *stud;
    if (addOrRehash == 0)
        stud = newStudent();
    else
        stud = st;


    int index = 0, key = 0;
    int i = 0;
    key = returnKey(stud->studentID);
    index = (2 * key) % size;
    if (Table[index] == NULL) // space is available
    {
        Table[index] = stud;
    }
    else if (choice == 1) // Double hashing collision
    {
        while (1)
        {
            i++;
            index = (7 - (key % 7)) * i;
            if (Table[index] == NULL) // space is available
            {
                Table[index] = stud;
                break;
            }
            else
                index = (index / i) - 7 + (key % 7);
        }
    }
    else // Quadratic probing collision
    {
        while (1)
        {
            i++;
            index = index + i * i;
            if (Table[index] == NULL) // space is available
            {
                Table[index] = stud;
                break;
            }
            else
                index = index - i * i;
        }
    }
    *studentsAdded += 1;
    return Table;
}

// prints hash table
void printTable(struct Student **Table, int size)
{
    printf("Index\tID\tName\tDepartment\n");

    int i = 0;
    for (i; i < size; i++)
    {
        printf("%d\t", i);
        if (Table[i] == NULL)
            printf("\n");
        else
        {
            printf("%s\t", Table[i]->studentID);
            printf("%s\t", Table[i]->name);
            printf("%s", Table[i]->depCode);
            printf("\n");
        }
    }
}

// search the student in table
void searchStudent(struct Student **Table, int size, int choice)
{
    char ID[4];
    printf("Student ID for searching:");
    scanf("%s", ID);
    fflush(stdin);
    int key = returnKey(ID);
    int index = (2 * key) % size;
    int i = 0;
    int found = 0;
    if(choice==1) // searching according to double hashing
    {
        // i variable updated according to double hashing
        for(index; index<size; index = (7 - (key % 7)) * (++i))
        {
            if(Table[index] != NULL)
            {
                if(strcmp(Table[index]->studentID,ID)==0) // found
                {
                    printf("\nStudent ID: %s", Table[index]->studentID);
                    printf("\nStudent Name: %s", Table[index]->name);
                    printf("\nStudent Department: %s\n", Table[index]->depCode);
                    found = 1;
                    break;
                }
                else if(i>0)
                    index = (index / i) - 7 + (key % 7);
                // if index is updated but the student could not found
                // index is reverted for proper searching with the new i variable
            }
        }
    }
    else // searching according to quadratic probing
    {
        for(index; index<size; index = index + pow(++i, 2))
        {
            if(Table[index] != NULL)
            {
                // same logic explained in double hashing
                if(strcmp(Table[index]->studentID,ID)==0) // found
                {
                    printf("\nStudent ID: %s", Table[index]->studentID);
                    printf("\nStudent Name: %s", Table[index]->name);
                    printf("\nStudent Department: %s", Table[index]->depCode);
                    found = 1;
                    break;
                }
                else if(i>0)
                    index = index - i * i;
            }
        }
    }
    if (found == 0) // if it is not in table
        printf("There is no student with ID: %s", ID);
}

struct Student **rehashTable(struct Student **Table, int *size, int choice, int *studentsAdded)
{
    int newSize = nextSize(*size); // New size for rehashing
    struct Student **newTable = initializaTable(&newSize); // initializing new table with new size

    int i = 0;
    for(i;i<*size;i++)
    {
        if(Table[i] != NULL)
        {
            // rehashing the new table according to previous table
            // sending non-NULL nodes to addStudent function
            addStudent(newTable, newSize, choice, studentsAdded, 1, Table[i]);
        }
    }

    *size = newSize; // updating size
    return newTable;
}

int main()
{
    int choice = hashingMethod(); // getting hashing method in case of collision

    int size = 11;                  // initial size
    int studentsAdded = 0;          // initial students inside of a table

    struct Student **Table = initializaTable(&size);

    float loadFactor;

    int selection;
    do
    {
        selection = menu();
        fflush(stdin);
        if (selection == 1) // add student
        {
            loadFactor = (float)studentsAdded / size;
            if(loadFactor > 0.5)
                Table = rehashTable(Table,&size,choice,&studentsAdded);

            addStudent(Table, size, choice, &studentsAdded, 0, NULL);
        }
        else if (selection == 2) // search student
        {
            searchStudent(Table, size, choice);
        }
        else if (selection == 3) // print table
        {
            printTable(Table, size);
        }
    } while (selection != 4);
    free(Table);

    return 0;
}
