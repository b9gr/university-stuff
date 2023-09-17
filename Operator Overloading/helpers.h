/* 
Bugra Ilhan - 2315307
I read and accept the submission rules and the extra rules specified in each question.This is my own work that
is done by myself only */


#include <iostream>
using namespace std;

void menu()
{
	cout << "\na. Change Address of A1 " << endl;
	cout << "b. Change Address of A2 " << endl;
	cout << "1. Print result of classification" << endl;
	cout << "2. Print TLA ID" << endl;
	cout << "3. Print NLA ID" << endl;
	cout << "4. Print SLA ID" << endl;
	cout << "5. Bitwise disjunction" << endl;
	cout << "6. Bitwise conjuction" << endl;
	cout << "7. Bitwise NOR" << endl;
	cout << "8. Bitwise NAND " << endl;
	cout << "9. Bitwise XOR" << endl;
	cout << "10. Bitwsse XNOR" << endl;
	cout << "11.Copy contents of first address to another" << endl;
	cout << "12. Compare if A1 == A2" << endl;
	cout << "13. Compare if A1 != A2 " << endl;
	cout << "14. Print Address" << endl;
	cout << "15.Enter an Address" << endl;
	cout << "0. Exit" << endl;
}

/* it is called in errorchecks() function */
int checkvalid(char* temp)
{
	int i = 0;
	while (i < 39)
	{
		if (('A' <= temp[i] && temp[i] <= 'F') || (temp[i] == ':') || ('0' <= temp[i] && temp[i] <= '9'))
		{
			i++;
		}
		else
		{
			return 0;
		}
	}
	return 1;
}

char* errorchecks()
{
	cout << "Please enter address in hexadecimal,\nseparated with ':' every 4 digits: " << endl;
	char* temp;
	temp = new char[99];
	int con1 = 1;
	while (con1)
	{
		cin >> temp;
		if (strlen(temp) != 39)
		{
			cout << "\nInvalid input! Length of input must be 39 characters!" << endl;
			cout << "Please re-enter:" << endl;
		}
		else if (checkvalid(temp) == 0)
		{
			cout << "\nInvalid input! Please only use A-F and 0-9 characters!" << endl;
			cout << "Please re-enter:" << endl;
		}
		else
			con1 = 0;
	}
	return temp;
}

int charArrayCompare(char* str1, char* str2)
{
	int i = 0, j = 0;
	while (j == 0)
	{
		if (str1[i] != str2[i])
			j = -1;
		if (str1[i] == '\0' || str2[i] == '\0')
			break;
		i++;
	}
	return j;
}

int boolArrayCompare(bool* arr1, bool* arr2,int index1, int index2)
{
	int i = index1;
	while (i <= index2)
	{
		if (arr1[i] != arr2[i])
			return -1;
		i++;
	}
	return 1;
}
