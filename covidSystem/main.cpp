#include "vaccCenter.h"
/* Bugra Ilhan 2315307
I read and accept the submission rules and the extra rules specified in each question. This is my
own work that is done by myself only */
void menu()
{
	std::cout << "\n1. Create a vaccine";
	std::cout << "\n2. Create a batch";
	std::cout << "\n3. Search a type of vaccine by ID, provide the total number of items in stock";
	std::cout << "\n4. List all types of vaccines and the number of items in stock";
	std::cout << "\n5. List total cost of the stock";
	std::cout << "\n6. List all types in a given batch";
	std::cout << "\n7. List all types of vaccines and the number of them according to their expiry date for a specific batch";
	std::cout << "\n8. Exit";
}

int main()
{
	vaccCenter myCenter;
	Vaccine* vaccines[10];
	int vaccinesType[10];
	int vacindex = 0, batchindex = 0, barrayindex=0;
	int option = 0;
	int batchidd;
	int typeselector;
	int st_temp, reDesign;
	int sideEf;
	double discount;
	int inType;
	double mlVacc;
	char vName[20], vCName[20], vCountry[20], vCTel[20];
	int d, m, y;
	int dosNeeded;
	int timedos;
	double cosT, efff;
	while (option != 8)
	{
		menu();
		std::cout << "\nEnter your selection:";
		std::cin >> option;
		if (option == 1)
		{
			int id;
			std::cout << "\nEnter Vaccine ID:";
			std::cin >> id; /* NEED ERROR CHECK*/
			
			std::cout << "\nSelect Vaccine Type (1)mRNA,(2)Adenovirus-Based,(3)Inactivated:";
			std::cin >> typeselector;
			if (typeselector == 1)
			{
				std::cout << "Storage Temperature:";
				std::cin >> st_temp;
				std::cout << "Time to re-design to combat mutations:";
				std::cin >> reDesign;
			}
			else if (typeselector == 2)
			{
				std::cout << "Side effect (1)BloodClots,(2)Headache,(3)Stomachache:";
				std::cin >> sideEf;
				std::cout << "Discount Rate:";
				std::cin >> discount;
			}
			else if (typeselector == 3)
			{
				std::cout << "Inactivated Type (1)Sars-COV-2,(2)Weakened COV-19:";
				std::cin >> inType;
				std::cout << "Mililitres of vaccine:";
				std::cin >> mlVacc;
			}
			/*vName[20], vCName[20], vCountry[20], vCTel[20];*/
			std::cout << "Enter Vaccine Name:";
			std::cin.getline(vName, 20);
			std::cout << "Enter Producer Company Name:";
			std::cin.getline(vCName, 20);
			std::cout << "Enter Country of Origin:";
			std::cin.getline(vCountry, 20);
			std::cout << "Contact Telephone Number:";
			std::cin.getline(vCTel, 20);
			std::cout << "EUA date (write 3 numbers as day/month/year):";
			std::cin >> d;
			std::cin >> m;
			std::cin >> y;
			std::cout << "Number of doses needed:";
			std::cin >> dosNeeded;
			std::cout << "Time between doses:";
			std::cin >> timedos;
			std::cout << "Cost:";
			std::cin >> cosT;
			std::cout << "Efficacy:";
			std::cin >> efff;
			if (typeselector == 1)
			{
				vaccines[vacindex] = new mrna(st_temp, reDesign, id, vName, vCName, vCountry, vCTel, d, m, y, dosNeeded, timedos, cosT, efff);
				vaccinesType[vacindex] = 1;
			}
			else if (typeselector == 2)
			{
				vaccines[vacindex] = new adenovirus(sideEf, discount, id, vName, vCName, vCountry, vCTel, d, m, y, dosNeeded, timedos, cosT, efff);
				vaccinesType[vacindex] = 2;
			}
			else if (typeselector == 3)
			{
				vaccines[vacindex] = new inactivated(inType, mlVacc, id, vName, vCName, vCountry, vCTel, d, m, y, dosNeeded, timedos, cosT, efff);
				vaccinesType[vacindex] = 3;
			}
			vacindex++;
			std::cout << "\nThe vaccine witd ID " << id << " has been added to system successfully!";
			std::cout << "\n-------------------------------------------------------------------\n";
		}
		else if (option == 2) 
		{
			char ch = 'Y';
			int batchid, lookingid, amounthh, dy, mh, yr;
			std::cout << "BATCH ID:";
			std::cin >> batchid;
			myCenter.addBatch(batchid);
			barrayindex = 0;
			do
			{
				int i = 0;
				std::cout << "Add a vaccine with ID:";
				std::cin >> lookingid;
				std::cout << "Amount:";
				std::cin >> amounthh;
				std::cout << "Expiry Date (Just enter 3 numbers with spaces):";
				std::cin >> dy;
				std::cin >> mh;
				std::cin >> yr;
				for (i; i < vacindex; i++)
				{
					if (lookingid == (*vaccines[i]).returnID())
					{
						myCenter.addelement(batchindex, barrayindex, vaccinesType[i], vaccines[i], dy, mh, yr, amounthh);
						break;
					}
				}
				barrayindex++;
				std::cout << "\n" << amounthh << " vials of  " << (*vaccines[i]).returnVacName() << " whose company " << (*vaccines[i]).returnVacComp() << " is added to Batch!";
				std::cout << "\nWould you like to add another vaccine? (Y/N) ";
				std::cin >> ch;
			} while (ch == 'Y');
			std::cout << "Batch with id " << batchid << " has been added to system successfully!";
			std::cout << "\n-------------------------------------------------------------------\n";
			batchindex++;
		}
		else if (option == 3)
		{
			int vaCiD,j=0;
			std::cout << "Please enter vaccine ID:";
			std::cin >> vaCiD;
			std::cout << "\n\nVAC INDEX IS " << vacindex;
			for (j; j < vacindex; j++)
			{/*
				std::cout << "\n" << (*vaccines[j]).returnID();
				std::cout << "\n" << (*vaccines[j]).returnVacName();
				std::cout << "\n" << vaccinesType[j] << "is the type";*/
				std::cout << " \nvaCiD is " << vaCiD << " and the next is " << (*vaccines[j]).returnID();
				if (vaCiD == (*vaccines[j]).returnID())
				{
					if (vaccinesType[j] == 1)
						std::cout << "Type: mRNA";
					else if (vaccinesType[j] == 2)
						std::cout << "Type: Adenovirus";
					else if (vaccinesType[j] == 3)
						std::cout << "Type: Inactivated";

					std::cout << " \nvaCiD is " << vaCiD << " and the next is " << vaccinesType[j] << " and last one " << batchindex;
					myCenter.searchDetails(vaCiD, vaccinesType[j],batchindex);
					break;
				}
			}
		}
		else if (option == 4)
		{
			std::cout << "Enter batch id:";
			std::cin >> batchidd;
			myCenter.findArr(batchidd);
		}
		else if (option == 5)
		{
			int i = 0, total = 0 ,id;
			while (i < batchindex) // traversing batches.
			{
				id = myCenter.batchArr[i].returnbatchID();
				std::cout << "\n BATCH WITH ID " << id << " is " << myCenter.calculatecost(id);
				total += myCenter.calculatecost(id);
				i++;
			}
			std::cout << "\nTotal cost of the stock is: " << total;
		}
		else if (option == 6)
		{
			std::cout << "Enter batch id:";
			std::cin >> batchidd;
			myCenter.printTypes(batchidd);
		}
		else if (option == 7)
		{
			std::cout << "Enter batch id:";
			std::cin >> batchidd;
			myCenter.sortBatch(batchidd);
			myCenter.findArr(batchidd);
		}
		else if (option == 8)
		{
			//nothing
		}
		else
			std::cout << "\nPlease enter valid input!";
	}
	delete[] vaccines;
	delete[] vaccinesType;
	return 0;
}