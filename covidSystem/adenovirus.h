#include "mrna.h"
/* Bugra Ilhan 2315307
I read and accept the submission rules and the extra rules specified in each question. This is my
own work that is done by myself only */
class adenovirus :public Vaccine
{
private:
	int sideEffect; /*1 for blood clots, 2 for headache, 3 for stomachache*/
	double discountRate;
	double totalcost;
public:
	adenovirus();
	adenovirus(int, double, int, char*, char*, char*, char*, int, int, int, int, int, double, double);
	void setsideEffect(int);
	void setdiscountRate(double);
	int returnsideEffect();
	double returndiscountRate();
	double calculatetotalcost();
	void printVaccine();
};