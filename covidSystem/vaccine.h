#include <iostream>
/* Bugra Ilhan 2315307
I read and accept the submission rules and the extra rules specified in each question. This is my
own work that is done by myself only */
class Date
{
private:
	int day;
	int month;
	int year;
public:
	Date();
	Date(int, int, int);
	void setDate(int, int, int);
	void printDate() const;
};

class Vaccine
{
protected:
	int ID;
	char vaccName[20];
	char vaccCompany[20];
	char vaccCountry[20];
	char vaccTelNum[20];
	Date EUAdate;
	int numOfDoses;
	int timeBDoses;
	double cost;
	double efficacy;
public:
	Vaccine();
	Vaccine(int, char*, char*, char*, char*, int, int, int, int, int, double, double);
	Vaccine(const Vaccine& v2);
	/*setters*/ 
	void setID(int);
	void setVacName(char*);
	void setVacComp(char*);
	void setVacCountry(char*);
	void setVacTelNum(char*);
	void setDateEUA(int , int , int);
	void setNOD(int);
	void setTBD(int);
	void setCost(double);
	void setEff(double);
	/*printer*/
	virtual void printVaccine();
	virtual double calculatetotalcost();
	/*getters*/
	int returnID();
	char* returnVacName();
	char* returnVacComp();
	char* returnVacCountry();
	char* returnVacTelNum();
	void returnDate();
	int returnNOD();
	int returnTBD();
	double returnCost();
	double returnEff();
};