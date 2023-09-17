/*
Bugra Ilhan - 2315307
I read and accept the submission rules and the extra rules specified in each question.This is my own work that
is done by myself only */

#include "adressHeader.h"


int main()
{
	char* forA1;
	char* forA2;
	forA1 = new char[39];
	forA2 = new char[39];
	cout << "For A1:\n";
	forA1 = errorchecks();
	adress a1(forA1);
	cout << "Successfully created!\n----------------------------------\n" << endl;
	cout << "For A2:\n";
	forA2 = errorchecks();
	adress a2(forA2);
	cout << "Successfully created!\n----------------------------------\n" << endl;
	delete[] forA1;
	delete[] forA2;
	
	// MENU LOOP
	int option = 55;
	int opt2;
	while (option != 0)
	{
		menu();
		cout << "Please select: ";
		cin >> option;
		cout << "\n";
		if (option == 1)
		{
			cout << "Please enter 1 for A1, 2 for A2: ";
			cin >> opt2;
			if (opt2 == 1)
			{
				cout << "Classification of A1 is: ";
				~a1;
			}
			else if (opt2 == 2)
			{
				cout << "Classification of A2 is: ";
				~a2;
			}
			cout << "\n---------------------------------------\n";
		}
		else if (option == 2)
		{
			cout << "Please enter 1 for A1, 2 for A2: ";
			cin >> opt2;
			if (opt2 == 1)
			{
				cout << "TLA ID of A1" << endl;
				!a1;
			}
			else if (opt2 == 2)
			{
				cout << "TLA ID of A2" << endl;
				!a2;
			}
			cout << "\n---------------------------------------\n";
		}
		else if (option == 3)
		{
			cout << "Please enter 1 for A1, 2 for A2: ";
			cin >> opt2;
			if (opt2 == 1)
			{
				cout << "NLA ID of A1" << endl;
				++a1;
			}
			else if (opt2 == 2)
			{
				cout << "NLA ID of A2" << endl;
				++a2;
			}
			cout << "\n---------------------------------------\n";
		}
		else if (option == 4)
		{
			cout << "Please enter 1 for A1, 2 for A2: ";
			cin >> opt2;
			if (opt2 == 1)
			{
				cout << "SLA ID of A1" << endl;
				&a1;
			}
			else if (opt2 == 2)
			{
				cout << "SLA ID of A2" << endl;
				&a2;
			}
			cout << "\n---------------------------------------\n";
		}
		else if (option == 5)
		{
			cout << "\n Result of A1 + A2" << endl;
			a1 + a2;
		}
		else if (option == 6)
		{
			cout << "\n Result of A1 * A2" << endl;
			a1 * a2;
		}
		else if (option == 7)
		{
			cout << "\n Result of A1 - A2" << endl;
			a1 - a2;
		}
		else if (option == 8)
		{
			cout << "\n Result of A1 / A2" << endl;
			a1 / a2;
		}
		else if (option == 9)
		{
			cout << "\n Result of A1 % A2" << endl;
			a1 % a2;
		}
		else if (option == 10)
		{
			cout << "\n Result of A1 ^ A2" << endl;
			a1 ^ a2;
		}
		else if (option == 11)
		{
			a1 = a2;
		}
		else if (option == 12)
		{
			a1 == a2;
			cout << "\n---------------------------------------\n";
		}
		else if (option == 13)
		{
			a1 != a2;
			cout << "\n---------------------------------------\n";
		}
		else if (option == 14)
		{
			cout << "Please enter 1 for A1, 2 for A2: ";
			cin >> opt2;
			if (opt2 == 1)
			{
				cout << a1;
			}
			else if (opt2 == 2)
			{
				cout << a2;
			}
			cout << "\n---------------------------------------\n";
		}
		else if (option == 15)
		{
			cout << "Please enter 1 for A1, 2 for A2: ";
			cin >> opt2;
			if (opt2 == 1)
			{
				cin >> a1;
			}
			else if (opt2 == 2)
			{
				cin >> a2;
			}

			cout << "\nSuccessfully created!" << endl;
			cout << "\n---------------------------------------\n";
		}
		else if (option == 0)
		{
			//nothing
		}
		else
			cout << "Invalid input! Please re-enter: " << endl;
	}
	cout << "\n\nGoodbye!" << endl;

	return 0;
}