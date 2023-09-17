#include "vaccine.h"
/* Bugra Ilhan 2315307
I read and accept the submission rules and the extra rules specified in each question. This is my
own work that is done by myself only */
class mrna : public Vaccine
{
private:
	int Store_temp;
	int TimeforReDesign;
public:
	mrna();
	mrna(int, int,int, char*, char*, char*, char*, int, int, int, int, int, double, double);
	mrna(const mrna& v2);
	void setStore_Temp(int);
	void setTimeforReDesign(int);
	double calculatetotalcost();
	int returnStore_temp();
	int returnTimeforReDesign();
	void printVaccine();
};
