#ifndef OTHERADT_H_DEF
#define OTHERADT_H_DEF

// created to find popular country
struct popularCountryNode
{
    struct treeNode *addressOfTreeNode;
    int photoNumber;
};

// created to find popular year
struct popularYearNode
{
    char popYear[15];
    int repetition;
    struct popularYearNode *next;
};

// list for keep track of photos years
struct list
{
    struct popularYearNode *head;
    struct popularYearNode *tail;
    int size;
};

struct list *returnList();
struct popularYearNode *returnYearNode(char *);
struct popularCountryNode *checkPopCountry(struct treeNode **, int , struct popularCountryNode *);
struct popularCountryNode *popularCountry(struct treeNode *, struct popularCountryNode *);
struct list *addToList(struct list *, char *);
struct list *checkpopYear(struct list *, char *);
struct list *popularYear(struct list *, struct treeNode *);
void printfpopularYear(char *, struct treeNode *);
void findPopularYear(struct list *, struct treeNode *);

#endif // OTHERADT_H_DEF
