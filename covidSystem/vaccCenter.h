#include "batch.h"
/* Bugra Ilhan 2315307
I read and accept the submission rules and the extra rules specified in each question. This is my
own work that is done by myself only */
class vaccCenter
{
public:
	Batch batchArr[10];
	int index = 0;
	void addBatch(int);
	void searchDetails(int,int,int);
	int printTypes(int);
	double calculatecost(int);
	void addelement(int,int,int, Vaccine*,int,int,int,int);
	void findArr(int batchid);
	void sortBatch(int id);
	void printcosts();
	void printwholebatches();
};