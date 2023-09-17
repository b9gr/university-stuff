#include "vaccCenter.h"
/* Bugra Ilhan 2315307
I read and accept the submission rules and the extra rules specified in each question. This is my
own work that is done by myself only */
void vaccCenter::addBatch(int iD)
{
	batchArr[index] = Batch(iD);
	index++;
}


void vaccCenter::addelement(int bbindex, int bindex, int tyyype,Vaccine* element, int d,int m, int y, int itemNum)
{
	batchArr[bindex].addType(tyyype);
	batchArr[bindex].vaccArr[bindex] = element;
	batchArr[bindex].dateArr[bindex].setDate(d, m, y);
	batchArr[bindex].numOfItems[bindex] = itemNum;
}

void vaccCenter::searchDetails(int id, int giventype, int batchindex) // 1 1
{
	int i = 0, k = 0;
	while (i < batchindex)
	{
		if (id == (batchArr[i]).returnbatchID())
			break;
		i++;
	}
	while (k < batchindex)
	{
		if ((batchArr[i]).dataType[k] == giventype)
			(batchArr[i]).vaccArr[k]->printVaccine();
		k++;
	}
}

void vaccCenter::findArr(int batchid)
{
	int i = 0;
	while (i < 10 && batchArr[i].batchID != -1)
	{
		if (batchid == batchArr[i].returnbatchID())
			batchArr[i].printVacDetails();
		i++;
	}
}

void vaccCenter::printwholebatches()
{
	int i = 0, j = 0, k=0;
	while (i < index) // traversing batches.
	{
		std::cout << "\n BATCH ARRAY " << i + 1;
		while(j!=-1) // traversing batches' arrays. 
		{
			std::cout << "\n Element " << k + 1;
			std::cout << "\nVaccine's ID : " << batchArr[i].vaccArr[j]->returnID();
			std::cout << "\nVaccine's name : " << batchArr[i].vaccArr[j]->returnVacName();
			std::cout << "\nVaccine's Company  : " <<batchArr[i].vaccArr[j]->returnVacComp();
			std::cout << "\nVaccine's Cost : " << batchArr[i].vaccArr[j]->returnCost();
			std::cout << "\nVaccine's Date: ";
			batchArr[i].dateArr[j].printDate();
			std::cout << "\n" << batchArr[i].dataType[j] << " is the type!";
			std::cout << "\n" << batchArr[i].numOfItems[j] << " is the number of items!";

			j = batchArr[i+1].returnbatchID();
			k ++ ;
		}
	}
}



int vaccCenter::printTypes(int id)
{
	int i = 0, k = 0;
	while (i < 10)
	{
		if (id == (batchArr[i]).returnbatchID())
			break;
		i++;
	}
	while (k < 10)
	{
		if ((batchArr[i]).dataType[k] == -1)
			break;
		else if ((batchArr[i]).dataType[k] != -1)
		{
			if ((batchArr[i]).dataType[k] == 1)
			{
				std::cout << "\nTYPE 1: MRNA";
				return 1;
			}
			else if ((batchArr[i]).dataType[k] == 2)
			{
				std::cout << "\nTYPE 2: ADENOVIRUS";
				return 2;
			}
			else if ((batchArr[i]).dataType[k] == 3)
			{
				std::cout << "\nTYPE 3: INACTIVATED";
				return 3;
			}
		}
		k++;
	}
	return 0;
}

double vaccCenter::calculatecost(int id)
{
	int i = 0, k = 0;
	while (i < 10)
	{
		if (id == (batchArr[i]).returnbatchID())
			break;
		i++;
	}
	double cost=0;
	while (k < 10)
	{
		if ((batchArr[i]).dataType[k] == -1)
			break;
		else if ((batchArr[i]).dataType[k] != -1)
				cost += (batchArr[i]).vaccArr[k]->calculatetotalcost();
		k++;
	}
	std::cout << "\nCOST OF THIS BATCH IS: " << cost;
	return cost;
}

void vaccCenter::printcosts()
{
	int y = 0, z=0;
	while (y < index)
	{
		calculatecost((batchArr[y]).returnbatchID());
		y++;
		z = 1;
	}
	if (z == 0)
		std::cout << "\nBatch array is empty";

}

void vaccCenter::sortBatch(int id)
{
	int i = 0,j=0;
	while (i < index) // finds the batch
	{
		if (id == (batchArr[i]).returnbatchID())
			break;
		i++;
	}
	
	Date temp = (batchArr[i]).dateArr[j]; // sorting
	while (j != -1)
	{
		if ((batchArr[j]).dateArr > (batchArr[j + 1]).dateArr)
		{
			(batchArr[i]).dateArr[j] = (batchArr[i]).dateArr[j+1];
			(batchArr[i]).dateArr[j+1] = temp;
		}
	}
}
