
/* Bugra Ilhan 2315307
I read and accept the submission rules and the extra rules specified in each question. This is my
own work that is done by myself only */
#include "adenovirus.h"
adenovirus::adenovirus()
{
	sideEffect = 0;
	discountRate = 0;
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

adenovirus::adenovirus(int se, double dr, int id, char* vacn, char* vaccomp, char* vaccount, char* telnum, int d, int m, int y, int nod, int tbd, double c, double eff)
{
	sideEffect = se;
	discountRate = dr;
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

void adenovirus::setsideEffect(int se)
{
	sideEffect = se;
}
void adenovirus::setdiscountRate(double dr)
{
	discountRate = dr;
}

int adenovirus::returnsideEffect()
{
	return sideEffect;
}
double adenovirus::returndiscountRate()
{
	return discountRate;
}

double adenovirus::calculatetotalcost()
{
	if (sideEffect == 2)
		totalcost = cost + (cost * discountRate);
	else if (sideEffect == 3)
		totalcost = cost + (cost * discountRate * 1.5);
	else if (sideEffect == 1)
		totalcost = cost + (cost * discountRate * 2);
	else
		std::cout << "\nPlease initialize side effect type!";
	return totalcost;
}

void adenovirus::printVaccine()
{
	std::cout << "\nSide effect: " << sideEffect;
	std::cout << "\nDiscount rate is: " << discountRate;
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