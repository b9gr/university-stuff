#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
/* ***************
    BUGRA ILHAN
      2315307
   *************** */

/* PLEASE MAKE SURE THAT THERE IS NO NEW LINE OPERATOR
AT THE END OF THE FILES. OTHERWISE IT WILL NOT WORK. */

struct date
{
    char day[5];
    char month[5];
    char year[10];
};

struct time
{
    char hour[5];
    char minute[5];
};

struct IGuser
{
    int uniqueID;
    char accountname[55];
    int postNo;
    int followingNo;
    int followerNo;
    struct date dateNum;
    struct time timeNum;
    struct IGuser *next;
};

struct list
{
    struct IGuser *head;
    struct IGuser *last;
    int size;
};

struct list *initialiseMyAccount(char filename[55])
{
    FILE *file;
    file = fopen (filename,"r"); /* opening file for reading */
    if (file == NULL)
    {
        printf("The file can not be opened!");
        exit(1);
    }
    int linenum=1;
    char ch;
    while(fscanf(file,"%c",&ch) != EOF)
    {
        if (ch==10)
            linenum++; /* counting how many accounts in file */
    }
    fclose(file); /* closing file */

    file = fopen (filename,"r"); /* opening again for actual reading */
    if (file == NULL)
    {
        printf("The file can not be opened!");
        exit(1);
    }

    int i;
    struct list *myList;
    myList = (struct list *) malloc(sizeof(struct list));
    myList->head = malloc(sizeof(struct IGuser)); /* my dummy node */
    myList->size = 0;
    myList->head->next = NULL;
    myList->last = myList->head; /* initializing list */

    struct IGuser *temp;
    char line[128];
    for(i=0;i<linenum;i++)
    {
        temp = (struct IGuser *) malloc(sizeof(struct IGuser)); /* the next node */

        fscanf(file,"%[^\n]s", line); /* read everything up until new line character */
        fgetc(file); /* move the new line character */

        /* dividing line by using strtok function for storing */
        /* atoi function takes string and makes it integer */
        char *parcel = strtok(line, ";");       /* int ID number */
        int intparcel = atoi(parcel);
        temp->uniqueID = intparcel;

        parcel = strtok(NULL, ";");             /* string account name */
        strcpy(temp->accountname,parcel);

        parcel = strtok(NULL, ";");             /* int post number */
        intparcel = atoi(parcel);
        temp->postNo = intparcel;

        parcel = strtok(NULL, ";");             /* int following number */
        intparcel = atoi(parcel);
        temp->followingNo = intparcel;

        parcel = strtok(NULL, ";");             /* int follower number */
        intparcel = atoi(parcel);
        temp->followerNo = intparcel;

        parcel = strtok(NULL, "/");             /* string date day */
        strcpy(temp->dateNum.day,parcel);

        parcel = strtok(NULL, "/");             /* string date month */
        strcpy(temp->dateNum.month,parcel);

        parcel = strtok(NULL, " ");             /* string date year */
        strcpy(temp->dateNum.year,parcel);

        parcel = strtok(NULL, ":");             /* string time hour */
        strcpy(temp->timeNum.hour,parcel);

        parcel = strtok(NULL, " ");             /* string time minute */
        strcpy(temp->timeNum.minute,parcel);

        temp->next = NULL;
        if(myList->head == NULL) /* if it is first node */
        {
            myList->head->next = temp;
            myList->last = temp;
        }
        else                     /* if it is not first node */
        {
            myList->last->next = temp;
            myList->last = temp;
        }
        (myList->size)++;
    }
    return myList;
}

int addAccount(struct list *takenlist, char dday[5], char mmonth[5], char yyear[10], char hhour[5], char mminute[5])
{
    struct IGuser *temp;   /* node which will be added */
    temp = (struct IGuser *) malloc(sizeof(struct IGuser));
    temp->uniqueID = (takenlist->last->uniqueID)+1;  /* node's id will be last node's Id + 1 */

    /* filling node */
    char account[55];
    printf("Enter name of the account:");
    scanf("%s", account);
    strcpy(temp->accountname,account);

    printf("Enter number of posts:");
    scanf("%d", &(temp->postNo));

    printf("Enter number of followers:");
    scanf("%d", &(temp->followerNo));

    printf("Enter number of following:");
    scanf("%d", &(temp->followingNo));

    /* error check for if the account exists */
    struct IGuser *pointer;
    pointer = malloc(sizeof(struct IGuser));
    pointer->next = takenlist->head->next;
    int i=0;
    while(pointer->next != NULL)
    {
        if(strcmp(pointer->next->accountname,account)==0)
        {
            if(pointer->next->postNo == temp->postNo)
            {
                if(pointer->next->followingNo == temp->followingNo)
                {
                    if(pointer->next->followerNo == temp->followerNo)
                    {
                        i=1;
                        break;
                    }
                }
            }
        }
        pointer->next = pointer->next->next;
    }
    free(pointer);

    /* if it is not exist add the node end of the list */
    if(i!=1)
    {
        strcpy(temp->dateNum.day,dday);
        strcpy(temp->dateNum.month,mmonth);
        strcpy(temp->dateNum.year,yyear);
        strcpy(temp->timeNum.hour,hhour);
        strcpy(temp->timeNum.minute,mminute);
        temp->next = NULL;
        takenlist->last->next = temp;
        takenlist->last = temp;
        (takenlist->size)++;
        return 2; // return for print message (following list or follower list )
    }
    else
    {
        printf("\nThe account already exists!!!");
        return 1; // for print message
    }

}

void printMyAccount(struct list *takenlist)
{
    /* printing list by using temporary pointer node */
    struct IGuser *pointer;
    pointer = malloc(sizeof(struct IGuser));
    pointer->next = takenlist->head->next;

    while(pointer->next != NULL)
    {
        printf("Account ID: %d\n" , pointer->next->uniqueID);
        printf("Account name: %s\n" , pointer->next->accountname);
        printf("Number of posts: %d\n" , pointer->next->postNo);
        printf("Number of following: %d\n" , pointer->next->followingNo);
        printf("Number of followers: %d\n" , pointer->next->followerNo);
        printf("Date: %s/" , pointer->next->dateNum.day);
        printf("%s/" , pointer->next->dateNum.month);
        printf("%s\n" , pointer->next->dateNum.year);
        printf("Time: %s:" , pointer->next->timeNum.hour);
        printf("%s\n " , pointer->next->timeNum.minute);
        printf("-------------------------------\n");
        pointer->next = pointer->next->next;
    }
    free(pointer);
}

void searchAccount(struct list *takenlist)
{
    /* searching list by using temporary pointer node */
    char account[55];
    printf("Enter Account name:");
    scanf("%s", account);

    struct IGuser *pointer;
    pointer = malloc(sizeof(struct IGuser));
    pointer->next = takenlist->head->next;

    int i=0;
    while(pointer->next != NULL)
    {
        if(strcmp(pointer->next->accountname,account)==0)
        {
            i=1;
            break;
        }
        pointer->next = pointer->next->next;
    }
    /* if it is found print it. */
    if(i==1)
    {
        printf("\nAccount ID: %d\n" , pointer->next->uniqueID);
        printf("Account name: %s\n" , pointer->next->accountname);
        printf("Number of posts: %d\n" , pointer->next->postNo);
        printf("Number of following: %d\n" , pointer->next->followingNo);
        printf("Number of followers: %d\n" , pointer->next->followerNo);
        printf("Date: %s/" , pointer->next->dateNum.day);
        printf("%s/" , pointer->next->dateNum.month);
        printf("%s\n" , pointer->next->dateNum.year);
        printf("Time: %s:" , pointer->next->timeNum.hour);
        printf("%s\n " , pointer->next->timeNum.minute);
    }
    else
        printf("\nThere is no account with this name in the list!!!!\n");
    free(pointer);
}

void deleteAccount(struct list *takenlist)
{
    int id_del;
    printf("Enter account ID:");
    scanf("%d", &id_del);

    struct IGuser *pointer, *remove;
    pointer = malloc(sizeof(struct IGuser));
    pointer = takenlist->head;
    int i=0;
    /* find node which will be deleted with temp.
    then make it remove node and after temp->next
    points to the remove->next, delete the remove node */
    while(pointer->next != NULL)
    {
        if(pointer->next->uniqueID == id_del)/* if the node is found */
        {
            remove = pointer->next; /* remove node is the node which will be deleted */
            if(remove->uniqueID == takenlist->last->uniqueID)/* controlling for removing last node */
            {
                pointer->next = NULL;
                takenlist->last = pointer;
            }
            else
                pointer->next = pointer->next->next;
            (takenlist->size)--;/* decrease the size */
            free(remove);/* delete it */
            i=1;
            break;
        }
        else
        {
            pointer = pointer->next;
        }
    }
    if(takenlist->size == 0)
        takenlist->last = takenlist->head;
    /* if i is 1, then we found and deleted the node. Otherwise error message */
    if(i==1)
        printf("\nAccount with ID %d has been deleted successfully.", id_del);
    else
        printf("\nAccount with ID %d does not exist.", id_del);

}

void OverwriteMyAccount(struct list *takenlist, char filename[25])
{
    /* Overwriting files by using temporary pointer node */
    struct IGuser *pointer;
    pointer = takenlist->head;
    FILE *file;
    file = fopen(filename,"w");
    if(file==NULL)
    {
        printf("\nThere is a memory problem");
        exit(1);
    }
    while(pointer->next != NULL)
    {
        /* writing in the file */
        fprintf(file,"%d;", pointer->next->uniqueID);
        fprintf(file,"%s;", pointer->next->accountname);
        fprintf(file,"%d;", pointer->next->postNo);
        fprintf(file,"%d;", pointer->next->followingNo);
        fprintf(file,"%d;", pointer->next->followerNo);
        fprintf(file,"%s/", pointer->next->dateNum.day);
        fprintf(file,"%s/", pointer->next->dateNum.month);
        fprintf(file,"%s ", pointer->next->dateNum.year);
        fprintf(file,"%s:", pointer->next->timeNum.hour);
        fprintf(file,"%s\n", pointer->next->timeNum.minute);
        pointer = pointer->next;
    }
    fclose(file);
}

void menu()
{
    printf("\n----- MENU-----\n");
    printf("1. Add a new Account\n");
    printf("2. Print My Account Info\n");
    printf("3. Search Account\n");
    printf("4. Delete Account\n");
    printf("5. Exit\n");
}

int main()
{
    time_t ti = time(NULL); /* */
    struct tm t = *localtime(&ti);
    /* itoa function used for making time and date values string */
    char dday[5], mmonth[5], yyear[10], hhour[5], mminute[5];
    itoa(t.tm_mday, dday, 10); /* itoa takes 1 integer and makes it string and stores buffer */
    itoa(t.tm_mon+1, mmonth, 10); /* middle part is buffer */
    itoa(t.tm_year+1900, yyear, 10); /* it can transform in base 2 , 10 and 16 */
    itoa(t.tm_hour, hhour, 10); /* that 10 means that in decimal */
    itoa(t.tm_min, mminute, 10); /* they are string now, which means i can add them to the struct */

    /* declaring and initializing my lists */
    struct list *forfollowing, *forfollowers;
    forfollowing = malloc(sizeof(struct list));
    forfollowers = malloc(sizeof(struct list));
    forfollowing = initialiseMyAccount("following.txt");
    forfollowers = initialiseMyAccount("followers.txt");
    printf("The following.txt file has been loaded successfully!");
    printf("\nThe followers.txt file has been loaded successfully!\n");

    /* selection switches */
    int option, option2, option3, option4, option5, acc_exist;
    do
    {
        menu();
        printf("Enter your option:");
        scanf("%d", &option);
        fflush(stdin);
        if(option==1)
        {
            printf("\n(1) Add a following account");
            printf("\n(2) Add a followers account");
            printf("\nEnter your option:");
            scanf("%d", &option2);
            /* Sending string date and time values to the add function for storing */
            if(option2==1)
            {
                acc_exist = addAccount(forfollowing, dday, mmonth, yyear, hhour, mminute);
                if(acc_exist == 2)
                    printf("The account has been added to following list!!");
            }
            else if(option2==2)
            {
                acc_exist = addAccount(forfollowers, dday, mmonth, yyear, hhour, mminute);
                if(acc_exist == 2)
                    printf("The account has been added to follower list!!");
            }
            fflush(stdin);
        }
        else if(option==2)
        {
            printf("\n(1)  Print following list");
            printf("\n(2)  Print followers list");
            printf("\nEnter your option:");
            scanf("%d", &option3);

            if(option3==1)
            {
                printf("\n------- My following list -------\n");
                printMyAccount(forfollowing);
            }
            else if(option3==2)
            {
                printf("\n------- My followers list -------\n");
                printMyAccount(forfollowers);
            }
            fflush(stdin);
        }
        else if(option==3)
        {
            printf("\n(1)  Search following list");
            printf("\n(2)  Search followers list");
            printf("\nEnter your option:");
            scanf("%d", &option4);

            if(option4==1)
            {
                searchAccount(forfollowing);
            }
            else if(option4==2)
            {
                searchAccount(forfollowers);
            }
            fflush(stdin);
        }
        else if(option==4)
        {
            printf("\n(1)  Delete account from following list");
            printf("\n(2)  Delete account from follower list");
            printf("\nEnter your option:");
            scanf("%d", &option5);

            if(option5==1)
            {
                deleteAccount(forfollowing);
            }
            else if(option5==2)
            {
                deleteAccount(forfollowers);
            }
            fflush(stdin);
        }
        else if(option==5)
        {
            OverwriteMyAccount(forfollowing, "following.txt");
            OverwriteMyAccount(forfollowers, "followers.txt");
            printf("The following.txt has been updated successfully!");
            printf("\nThe follower.txt has been updated successfully!\n");
        }
        else
        {
            printf("Invalid Input!\n");
        }
    }while(option!=5);
    return 0;
}
