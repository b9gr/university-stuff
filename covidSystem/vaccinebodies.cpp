/* Bugra Ilhan 2315307
I read and accept the submission rules and the extra rules specified in each question. This is my
own work that is done by myself only */
/*			DATE			*/
#include "vaccine.h"
Date::Date()
{
	day = 0;
	month = 0;
	year = 0;
}
Date::Date(int a, int b, int c)
{
	day = a;
	month = b;
	year = c;
}

void Date::setDate(int d, int m, int y)
{
	day = d;
	month = m;
	year = y;
}

void Date::printDate() const
{
	std::cout << "\nEUA Date is: " << day << "/" << month << "/" << year;
}


/*			VACCINE			*/
 
Vaccine::Vaccine()
{
	ID = 0;
	strcpy(vaccName, "Empty");
	strcpy(vaccCompany, "Empty");
	strcpy(vaccCountry, "Empty");
	strcpy(vaccTelNum, "Empty");
	EUAdate.setDate(0,0,0);
	numOfDoses = 0;
	timeBDoses = 0;
	cost = 0.0;
	efficacy = 0.0;
}

Vaccine::Vaccine(int id, char* name, char* comp, char* count, char* telNum, int d, int m, int y, int nod, int tbd, double c, double ef)
{
	ID = id;
	strcpy(vaccName, name);
	strcpy(vaccCompany, comp);
	strcpy(vaccCountry, count);
	strcpy(vaccTelNum, telNum);
	EUAdate.setDate(d, m, y);
	numOfDoses = nod;
	timeBDoses = tbd;
	cost = c;
	efficacy = ef;
}

Vaccine::Vaccine(const Vaccine& v2)
{
	ID = v2.ID;
	strcpy(vaccName, v2.vaccName);
	strcpy(vaccCompany, v2.vaccCompany);
	strcpy(vaccCountry, v2.vaccCountry);
	strcpy(vaccTelNum, v2.vaccTelNum);
	numOfDoses = v2.numOfDoses;
	timeBDoses = v2.timeBDoses;
	cost = v2.cost;
	efficacy = v2.efficacy;
}

void Vaccine::printVaccine()
{
	std::cout << "\nVaccine ID: " << ID;
	std::cout << "\nVaccine Name: " << vaccName;
	std::cout << "\nCompany: " << vaccCompany;
	std::cout << "\nCountry of Origin: " << vaccCountry;	
	std::cout << "\nContact Telephone Number: " << vaccTelNum;
	EUAdate.printDate();
	std::cout << "\nNumber of Doses: " << numOfDoses;
	std::cout << "\nTime Between Doses: " << timeBDoses;
	std::cout << "\nCost per vial: " << cost;
	std::cout << "\nEfficacy is: %" << 100*efficacy;
}

double Vaccine::calculatetotalcost()
{
	return cost;
}

/*			SETTERS			 */
void Vaccine::setDateEUA(int day, int month, int year)
{
	EUAdate.setDate(day, month, year);
}

void Vaccine::setID(int id)
{
	ID = id;
}

void Vaccine::setVacName(char* vacname)
{
	strcpy(vaccName, vacname);
}

void Vaccine::setVacComp(char* vaccomp)
{
	strcpy(vaccCompany, vaccomp);
}

void Vaccine::setVacCountry(char* vaccountry)
{
	strcpy(vaccCountry, vaccountry);
}
void Vaccine::setVacTelNum(char* telnum)
{
	strcpy(vaccTelNum, telnum);
}

void Vaccine::setNOD(int n)
{
	numOfDoses = n;
}
void Vaccine::setTBD(int t)
{
	timeBDoses = t;
}
void Vaccine::setCost(double sc)
{
	cost = sc;
}

void Vaccine::setEff(double eff)
{
	efficacy = eff;
}

/*			GETTERS			 */		

int Vaccine::returnID() 
{
	return ID;
}

char* Vaccine::returnVacName()
{
	return vaccName;
}
char* Vaccine::returnVacComp()
{
	return vaccCompany;
}
char* Vaccine::returnVacCountry()
{
	return vaccCountry;
}
char* Vaccine::returnVacTelNum()
{
	return vaccTelNum;
}

void Vaccine::returnDate()
{
	EUAdate.printDate();
}

int Vaccine::returnNOD()
{
	return numOfDoses;
}
int Vaccine::returnTBD()
{
	return timeBDoses;
}
double Vaccine::returnCost()
{
	return cost;
}
double Vaccine::returnEff()
{
	return efficacy;
}