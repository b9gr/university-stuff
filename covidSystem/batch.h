#include "inactivated.h"
/* Bugra Ilhan 2315307
I read and accept the submission rules and the extra rules specified in each question. This is my
own work that is done by myself only */
class Batch
{
private:
	friend class vaccCenter;
	int batchID;
	Vaccine* vaccArr[10];
	Date dateArr[10];
	int numOfItems[10];
	int dataType[10];
public:
	Batch();
	Batch(int);
	void setbatchID(int);
	int returnbatchID();
	void addType(int);
	void increaseNumofVacc(int,int);
	void printVacDetails();
	double calculateCost();
	void isIntheBatch(int);
	
};
