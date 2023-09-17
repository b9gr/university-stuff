#include "mrna.h"
/* Bugra Ilhan 2315307
I read and accept the submission rules and the extra rules specified in each question. This is my
own work that is done by myself only */
mrna::mrna()
{
	Store_temp = 0;
	TimeforReDesign = 0;
	ID = 0;
	strcpy(vaccName, "Empty");
	strcpy(vaccCompany, "Empty");
	strcpy(vaccCountry, "Empty");
	strcpy(vaccTelNum, "Empty");
	EUAdate.setDate(0, 0, 0);
	numOfDoses = 0;
	timeBDoses = 0;
	cost = 0.0;
	efficacy = 0.0;
}

mrna::mrna(const mrna& v2)
{
	Store_temp = v2.Store_temp;
	TimeforReDesign = v2.TimeforReDesign;
	ID = v2.ID;
	strcpy(vaccName, v2.vaccName);
	strcpy(vaccCompany, v2.vaccCompany);
	strcpy(vaccCountry, v2.vaccCountry);
	strcpy(vaccTelNum, v2.vaccTelNum);
	//
	numOfDoses = v2.numOfDoses;
	timeBDoses = v2.timeBDoses;
	cost = v2.cost;
	efficacy = v2.efficacy;
}

mrna::mrna(int st, int tfrd, int id, char* vacn, char* vaccomp, char* vaccount, char* telnum, int d, int m, int y, int nod, int tbd, double c, double eff)
{
	Store_temp = st;
	TimeforReDesign = tfrd;
	ID = id;
	strcpy(vaccName, vacn);
	strcpy(vaccCompany, vaccomp);
	strcpy(vaccCountry, vaccount);
	strcpy(vaccTelNum, telnum);
	EUAdate.setDate(d, m, y);
	numOfDoses = nod;
	timeBDoses = tbd;
	cost = c;
	efficacy = eff;
}

void mrna::setStore_Temp(int st)
{
	Store_temp = st;
}

void mrna::setTimeforReDesign(int tfrd)
{
	TimeforReDesign = tfrd;
}

int mrna::returnStore_temp()
{
	return Store_temp;
}
int mrna::returnTimeforReDesign()
{
	return TimeforReDesign;
}

double mrna::calculatetotalcost()
{
	return returnCost();
}

void mrna::printVaccine()
{
	std::cout << "\nStorage temparature: " << Store_temp;
	std::cout << "\nTime for Redesign(day): " << TimeforReDesign;
	std::cout << "\nVaccine ID: " << ID;
	std::cout << "\nVaccine Name: " << vaccName;
	std::cout << "\nCompany: " << vaccCompany;
	std::cout << "\nCountry of Origin: " << vaccCountry;
	std::cout << "\nContact Telephone Number: " << vaccTelNum;
	EUAdate.printDate();
	std::cout << "\nNumber of Doses: " << numOfDoses;
	std::cout << "\nTime Between Doses: " << timeBDoses;
	std::cout << "\nCost per vial: " << cost;
	std::cout << "\nEfficacy is: %" << 100 * efficacy;
}