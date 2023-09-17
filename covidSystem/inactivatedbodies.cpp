#include "inactivated.h"
/* Bugra Ilhan 2315307
I read and accept the submission rules and the extra rules specified in each question. This is my
own work that is done by myself only */
inactivated::inactivated()
{
	inactivatedType = 0;
	mlofVacc = 0;
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
	totalcost = 0.0;
}

inactivated::inactivated(int intype, double ml, int id, char* vacn, char* vaccomp, char* vaccount, char* telnum, int d, int m, int y, int nod, int tbd, double c, double eff)
{
	inactivatedType = intype;
	mlofVacc = ml;
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
	totalcost = 0.0;
}

void inactivated::setinactivatedType(int intype)
{
	inactivatedType = intype;
}

void inactivated::setmlofVacc(double ml)
{
	mlofVacc = ml;
}

int inactivated::returninactivatedType()
{
	return inactivatedType;
}

double inactivated::returnmlofVacc()
{
	return mlofVacc;
}

double inactivated::calculatetotalcost()
{
	if (inactivatedType == 1)
		totalcost = (mlofVacc / (100.0)) * cost;
	else if (inactivatedType == 2)
		totalcost = (mlofVacc / (100.0)) * cost * (1.5);
	else
		std::cout << "Please initialize cost for inactivated";
	return totalcost;
}

void inactivated::printVaccine()
{
	std::cout << "\nInactivated type: " << inactivatedType;
	std::cout << "\nHow mililitres: " << mlofVacc;
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