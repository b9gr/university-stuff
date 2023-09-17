#include "batch.h"
/* Bugra Ilhan 2315307
I read and accept the submission rules and the extra rules specified in each question. This is my
own work that is done by myself only */
Batch::Batch()
{
	batchID = -1;
	int i = 0;
	for (i; i < 10; i++)
	{
		numOfItems[i] = -1;
		dataType[i] = -1;
	}
}

Batch::Batch(int id)
{
	batchID = id;
	int i = 0;
	for (i; i < 10; i++)
	{
		numOfItems[i] = -1;
		dataType[i] = -1;
	}
}

void Batch::setbatchID(int newid)
{
	batchID = newid;
}
int Batch::returnbatchID()
{
	return batchID;
}

void Batch::addType(int type)
{
	int i = 0;
	while (dataType[i] != -1) /* finds new empty location */
		i++;

	if (type == 1)
	{
		vaccArr[i] = new mrna();
		dataType[i] = 1;
	}
	else if (type == 2)
	{
		vaccArr[i] = new adenovirus();
		dataType[i] = 2;
	}
	else if (type == 3)
	{
		vaccArr[i] = new inactivated();
		dataType[i] = 3;
	}
	else
		std::cout << "\nno typeeeeeeeeeeeeeeeeeeeeeeeeeeeee";
		
}

void Batch::increaseNumofVacc(int type, int newnum)
{
	int i = 0;
	while (i < 10)
	{
		if ((dataType[i] == 1) && (type == 1))
		{
			numOfItems[i] = newnum;
		}
		else if ((dataType[i] == 2) && (type == 2))
		{
			numOfItems[i] = newnum;
		}
		else if ((dataType[i] == 3) && (type == 3))
		{
			numOfItems[i] = newnum;
		}
		i++;
	}
}

void Batch::printVacDetails()
{
	int i = 0;
	while ((i < 10) && (dataType[i]!=-1))
	{
		if (dataType[i] == 1)
		{
			std::cout << "\nTYPE 1: mRNA";
			std::cout << "\nStock: "<< numOfItems[i];
			vaccArr[i]->printVaccine();
		}
		else if (dataType[i] == 2)
		{
			std::cout << "\nTYPE 2: Adenovirus";
			std::cout << "\nStock: " << numOfItems[i];
			vaccArr[i]->printVaccine();
		}
		else if (dataType[i] == 3)
		{
			std::cout << "\nTYPE 3: Inactivated";
			std::cout << "\nStock: " << numOfItems[i];
			vaccArr[i]->printVaccine();
		}
		else
			std::cout << "\nTERRRRRRRRRRRRRRRRRRRRRRRRRRRRIBLE";
		i++;
	}
}

double Batch::calculateCost()
{
	int i = 0;
	double costofbatch = 0;
	while ((i < 10) && (dataType[i] != -1))
	{
		if (dataType[i] == 1)
		{
			costofbatch += numOfItems[i] * (vaccArr[i]->calculatetotalcost());
			std::cout << "\nThere are " << numOfItems[i] << "mrna vaccines and each of them " << (vaccArr[i]->calculatetotalcost()) << "so far cost is " << costofbatch;
		}
		else if (dataType[i] == 2)
		{
			costofbatch += vaccArr[i]->calculatetotalcost();
		}
		else if (dataType[i] == 3)
		{
			costofbatch += vaccArr[i]->calculatetotalcost();
		}
		else
			std::cout << "\nCOSTTTTTTTTTTTTTTTTTT PROBLEMATIC";

		i++;
	}
	return costofbatch;
}

void Batch::isIntheBatch(int vaccid)
{
	int i = 0, j=0;
	while ((i < 10) && (dataType[i] != -1))
	{
		if (vaccArr[i]->returnID() == vaccid)
		{
			vaccArr[i]->printVaccine();
			j = 1;
		}
		i++;
	}
	if(j==0)
		std::cout << "\nNO VACC FOUND!";
}

