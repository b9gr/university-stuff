#include "adenovirus.h"
/* Bugra Ilhan 2315307
I read and accept the submission rules and the extra rules specified in each question. This is my
own work that is done by myself only */
class inactivated :public Vaccine
{
private:
	int inactivatedType; /* 1 for Sars-COV-2, 2 for Weakened COV-19 */
	double mlofVacc;
	double totalcost;
public:
	inactivated();
	inactivated(int, double, int, char*, char*, char*, char*, int, int, int, int, int, double, double);
	void setinactivatedType(int);
	void setmlofVacc(double);
	int returninactivatedType();
	double returnmlofVacc();
	double calculatetotalcost();
	void printVaccine();
};