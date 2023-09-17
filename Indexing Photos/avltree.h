#ifndef AVLTREE_H_DEF
#define AVLTREE_H_DEF
struct treeNode
{
    char phName[15];
    char phDimension[15];
    char phSize[15];
    char phCity[15];
    char phCountry[15];
    char phYear[15];
    int photoNum;
    struct treeNode *left;
    struct treeNode *right;
    struct treeNode *next;
};

int countPhotos(char *);
char *countryName(char *);
struct treeNode *returnPhoto(char *);
struct treeNode *rotateRight(struct treeNode *);
struct treeNode *rotateLeft(struct treeNode *);
int maxDepth(struct treeNode *);
int balanceFactor(struct treeNode *);
struct treeNode *insertPhoto(struct treeNode *, char *);
struct treeNode *readData(char *);
void displayIndex(struct treeNode *);

#endif // AVLTREE_H_DEF
