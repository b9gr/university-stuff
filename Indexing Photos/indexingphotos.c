#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avltree.h"
#include "otheradt.h"
// BUGRA ILHAN 2315307
// PLEASE MAKE SURE THAT THERE IS NO NEW LINE CHARACTER AT THE END OF FILE.


// returns list
// called only once in main
struct list *returnList()
{
    struct list *myList;
    myList = malloc(sizeof(struct list));
    if(myList == NULL)
    {
        printf("There is a memory problem!");
        exit(1);
    }
    myList->head = myList->tail = NULL;
    myList->size = 0;
    return myList;
}

// returns a node with a new year string
struct popularYearNode *returnYearNode(char year[15])
{
    struct popularYearNode *temp;
    temp = malloc(sizeof(struct popularYearNode));
    if(temp == NULL)
    {
        printf("There is a memory problem!");
        exit(5);
    }
    temp->repetition = 1;
    strcpy(temp->popYear, year);
    temp->next = NULL;
    return temp;
}

// it counts how many photos in file
// called once in readData function
int countPhotos(char nameOfFile[15])
{
    FILE *file;
    file = fopen(nameOfFile, "r");
    if(file==NULL)
    {
        printf("File can't be opened!");
        exit(2);
    }
    int lineNum=1;
    char ch;
    while(fscanf(file,"%c",&ch) != EOF)
    {
        if(ch==10)
            lineNum++;
    }
    fclose(file);
    return lineNum; // counted how many photos in the file
}

// returns country of the next row in file
char *countryName(char line[128])
{
    char *country = strtok(line, ",");
    country = strtok(NULL, ",");
    country = strtok(NULL, ",");
    country = strtok(NULL, ",");
    country = strtok(NULL, ",");
    return country;
}

// returns tree node according to file
struct treeNode *returnPhoto(char line[128])
{
    struct treeNode *temp;
    temp = malloc(sizeof(struct treeNode));
    if(temp==NULL)
    {
        printf("There is a memory problem!");
        exit(1);
    }
    char *parcel = strtok(line, ",");
    strcpy(temp->phName, parcel);

    parcel = strtok(NULL, ",");
    strcpy(temp->phDimension, parcel);

    parcel = strtok(NULL, ",");
    strcpy(temp->phSize, parcel);

    parcel = strtok(NULL, ",");
    strcpy(temp->phCity, parcel);

    parcel = strtok(NULL, ",");
    strcpy(temp->phCountry, parcel);

    parcel = strtok(NULL, ",");
    strcpy(temp->phYear, parcel);

    temp->photoNum = 1;
    temp->left = temp->right = temp->next = NULL;
    return temp;
}

// to rotate tree right
struct treeNode *rotateRight(struct treeNode *firstElement)
{
    struct treeNode *temp = firstElement->left;
    struct treeNode *restOfTree = temp->right; // might be NULL

    temp->right = firstElement;
    firstElement->left = restOfTree; // might be NULL again

    return temp;
}

// to rotate tree left
struct treeNode *rotateLeft(struct treeNode *firstElement)
{
    struct treeNode *temp = firstElement->right;
    struct treeNode *restOfTree = temp->left;  // might be NULL

    temp->left = firstElement;
    firstElement->right = restOfTree; // might be NULL again

    return temp;
}

// to find a particular node's depth
// we will use it to calculate balance factor later
int maxDepth(struct treeNode *currentNode)
{
    int rightDepth, leftDepth;
    if(currentNode == NULL)
        return 0;
    else
    {
        leftDepth = maxDepth(currentNode->left);
        rightDepth = maxDepth(currentNode->right);
        if(leftDepth > rightDepth)
            return (leftDepth+1);
        else
            return (rightDepth+1);
    }
}

// to calculate balance factor
int balanceFactor(struct treeNode *currentNode)
{
    if (currentNode == NULL)
        return 0;
    else
        return maxDepth(currentNode->left)-maxDepth(currentNode->right);
}

// inserting node to tree and balance if necessary
struct treeNode *insertPhoto(struct treeNode *root, char line[128])
{
    char lineCopy[128];
    strcpy(lineCopy,line);
    char *currentCountry = countryName(lineCopy); // to make comparison with the root

    if(root==NULL)
        root = returnPhoto(line);
    else if(strcmp(currentCountry, root->phCountry) > 0)
        root->right = insertPhoto(root->right, line);
    else if(strcmp(currentCountry, root->phCountry) < 0)
        root->left = insertPhoto(root->left, line);
    else
    {
        // if the same country comes, add it to the linked list
        // and add head node's photoNum 1. because we will use
        // photoNum to find popular country later
        root->photoNum += 1;
        root->next = insertPhoto(root->next, line);
    }


    int BF = balanceFactor(root);

    // we control the balance factor and place where the node added
    // if balancing are needed, there are 4 cases
    if(BF>1 && (strcmp(currentCountry, root->phCountry) < 0)) // left left insertion
    {
        root = rotateRight(root);
    }
    else if(BF>1 && (strcmp(currentCountry, root->phCountry) > 0)) // left right insertion
    {
        root->left = rotateLeft(root->left);
        root = rotateRight(root);
    }
    else if(BF<-1 && (strcmp(currentCountry, root->phCountry) > 0)) // right right insertion
    {
        root = rotateLeft(root);
    }
    else if(BF<-1 && (strcmp(currentCountry, root->phCountry) < 0)) // right left insertion
    {
        root->right = rotateRight(root->right);
        root = rotateLeft(root);
    }
    return root;
}

// after we know how many photos in file (countPhotos)
// read the data and send it to tree for insert
struct treeNode *readData(char nameOfFile[15])
{
    int photoNum = countPhotos(nameOfFile);
    FILE *file;
    file = fopen(nameOfFile, "r"); // reopened file to bring to cursor to the beginning
    if(file == NULL)
    {
        printf("File can't be opened!");
        exit(3);
    }

    struct treeNode *root = NULL;
    int i=0;
    char line[128];
    for(i;i<photoNum;i++)
    {
        fscanf(file,"%[^\n]s", line); // read everything up until new line character
        fgetc(file);                 // move the new line character
        root = insertPhoto(root, line); // insert
    }
    fclose(file);
    return root;
}

// print the tree (already sorted alphabetically based on their country)
void displayIndex(struct treeNode *root)
{
    if(root == NULL)
        exit(1);

    if(root->left != NULL)
        displayIndex(root->left);
    printf("%s, %s, %s, ", root->phName, root->phDimension, root->phSize);
    printf("%s, %s, %s\n", root->phCity, root->phCountry, root->phYear);
    if(root->next != NULL)
        displayIndex(root->next);
    if(root->right != NULL)
        displayIndex(root->right);
}

void menu()
{
    printf("\n--Menu--\n");
    printf("1. Display the full index of photos\n");
    printf("2. Display the photos of popular country\n");
    printf("3. Display the photos of popular year\n");
    printf("4. Exit\n");
}

// if you find a node with more photoNum, update the oneNode
// called once in popularCountry function
// ( please look at main function for detailed explanation )
struct popularCountryNode *checkPopCountry(struct treeNode **root, int rootNum, struct popularCountryNode *oneNodeNum)
{
    if(rootNum > oneNodeNum->photoNumber)
    {
        oneNodeNum->addressOfTreeNode = *root;
        oneNodeNum->photoNumber = rootNum;
    }
    return oneNodeNum;
}

// traverse tree and call checkPopCountry function for check
struct popularCountryNode *popularCountry(struct treeNode *root, struct popularCountryNode *oneNode)
{
    if(root->left != NULL)
        popularCountry(root->left, oneNode);

    oneNode = checkPopCountry(&root, root->photoNum, oneNode);

    if(root->right != NULL)
        popularCountry(root->right, oneNode);
    return oneNode;
}

// add year to list
struct list *addToList(struct list *myList, char year[15])
{
    struct popularYearNode *temp;
    temp = malloc(sizeof(struct popularYearNode));
    if(temp == NULL)
    {
        printf("There is a memory problem!");
        exit(1);
    }
    strcpy(temp->popYear, year);
    temp->repetition = 1;
    temp->next = NULL;

    if(myList->head == NULL)
    {
        myList->head = temp;
        myList->tail = temp;
    }
    else
    {
        myList->tail->next = temp;
        myList->tail = temp;
    }
    myList->size++;
    return myList;
}

// update list
//( please look at main function for detailed explanation )
struct list *checkpopYear(struct list *listofYears, char year[15])
{
    if(listofYears->head != NULL)
    {
        struct popularYearNode *temp = listofYears->head;
        while(temp != NULL)
        {
            if(strcmp(temp->popYear, year)==0)
            {
                temp->repetition++;
                return listofYears;

            }
            temp = temp->next;
        }
        listofYears = addToList(listofYears, year);
        return listofYears;
    }
    else
    {
        listofYears = addToList(listofYears, year);
        return listofYears;
    }
}

// traverse tree and check years
struct list *popularYear(struct list *listofYears, struct treeNode *root)
{
    if(root->left != NULL)
        popularYear(listofYears, root->left);

    listofYears = checkpopYear(listofYears , root->phYear);

    if(root->next != NULL)
        popularYear(listofYears, root->next);
    if(root->right != NULL)
        popularYear(listofYears, root->right);
    return listofYears;
}

// traverse the tree and print
void printfpopularYear(char year[15], struct treeNode *root)
{
    if(root->left != NULL)
        printfpopularYear(year, root->left);

    if(strcmp(root->phYear, year) == 0)
    {
        printf("%s, %s, %s, ", root->phName, root->phDimension, root->phSize);
        printf("%s, %s, %s\n", root->phCity, root->phCountry, root->phYear);
    }
    if(root->next != NULL)
        printfpopularYear(year, root->next);
    if(root->right != NULL)
        printfpopularYear(year, root->right);
}

// after list is done, find popular year
void findPopularYear(struct list *listofYears, struct treeNode *root)
{
    int mostrepetition;
    char mostpopular[15];
    struct popularYearNode *temp = listofYears->head;
    strcpy(mostpopular, temp->popYear);
    mostrepetition = temp->repetition;
    temp = temp->next;
    while(temp != NULL)
    {
        if(temp->repetition > mostrepetition)
            strcpy(mostpopular, temp->popYear);
        temp = temp->next;
    }
    printfpopularYear(mostpopular, root); // to print
}

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Wrong entry for initalization! Please run it again!\n");
        exit(1);
    }
    struct treeNode *root = readData(argv[1]); // 0 is the program name
    int option;

    printf(">>>Welcome to photo indexing!<<<\n");
    do
    {
        menu();
        printf("\nOption:");
        scanf("%d", &option);
        if(option==1)
        {
            printf("Photo Index:\n");
            displayIndex(root);
        }
        else if(option==2)
        {
            // make a oneNode which contains an address(=NULL at first) and int photo number(=0 at first)
            // if you find a node with more photoNum ( means there are more photos with the same country ) while traversing tree,
            // put the address of it to the oneNode with the photoNum

            // DISCUSSION COMPLEXITY
            // This function checks only tree nodes (not their linked list if exists) but time complexity is O(n) in the worst case(all countries has 1 photo)
            // For best case, it would be constant since there would be just 1 photo. If i haven't got a photoNum in struct, i would need to traverse
            // whole tree. But now, i am traversing just the nodes in tree. It is more efficient for time.
            printf("\nPhotos of popular country:\n");
            struct popularCountryNode *oneNode;
            oneNode = malloc(sizeof(struct popularCountryNode));
            if(oneNode == NULL)
            {
                printf("There is a memory problem!");
                exit(1);
            }
            oneNode->addressOfTreeNode = NULL;
            oneNode->photoNumber = 0;
            oneNode = popularCountry(root, oneNode);
            struct treeNode *temp = oneNode->addressOfTreeNode; // address of the node which has biggest photoNum
            while(temp != NULL)
            {
                // print
                printf("%s, %s, %s, ", temp->phName, temp->phDimension, temp->phSize);
                printf("%s, %s, %s\n", temp->phCity, temp->phCountry, temp->phYear);
                temp = temp->next;
            }
            free(oneNode);
        }
        else if(option==3)
        {
            // make a list for years. While traversing, if the node's year exists in the list make it repetition value += 1,
            // if not return a new node of popular year with that year to the end of the list. after the list is complete, find the year which has
            // biggest repetition value(popular year). After this, traverse tree again and if the current node has the same year with
            // the popular year, print it.

            // DISCUSSION COMPLEXITY
            // This function traversing tree 2 times but it similar to popular country function. Again, for the worst case time complexity is O(n)
            // and for the best base it would be constant since there would be just 1 photo. If i would make linked list while reading file
            // traversing the tree twice would be unnecessary. It is not the most efficient time management clearly :D
            printf("\nPhotos of popular year:\n");
            struct list *listofYears = returnList();
            listofYears = popularYear(listofYears, root);
            findPopularYear(listofYears,root);
            free(listofYears);
        }
        else if(option==4)
        {
            // literally nothing
        }
        else
            printf("Invalid Input! Please try again!\n");
    }while(option!=4);
    return 0;
}
