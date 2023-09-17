/*
Bugra Ilhan - 2315307
I read and accept the submission rules and the extra rules specified in each question.This is my own work that
is done by myself only */


#include "helpers.h"


class adress
{
private:
	char* hexForm;
	bool* binaryForm;
public:
	adress(char*);
	/* These four operators' algorithms are slightly similar,  
	the indexes are different in their algorithm */
	friend void operator~(adress);
	friend void operator!(adress);
	friend void operator++(adress);
	friend void operator&(adress);

	/* These five operators' algorithms are similar,
	just 1 else block which changes logic is different between them. 
	There is an explanation their algorithm in operator% (Line 400) function. */
	friend void operator+(adress, adress);
	friend void operator*(adress, adress);
	friend void operator-(adress, adress);
	friend void operator/(adress, adress);
	friend void operator%(adress, adress);
	friend void operator^(adress, adress);

	void operator=(adress); // has to be member function
	friend void operator==(adress, adress);
	friend void operator!=(adress, adress);
	friend void operator<< (ostream&, adress);
	friend void operator>>(istream&, adress);

	
};

void operator>>(istream& i1, adress a1)
{
	char* temp;
	temp = new char[99];
	temp = errorchecks();
	strcpy(a1.hexForm, temp);
	delete[] temp;

	int i = 0, j = 4, k = 0;
	char ch;
	for (i; i < 39; i++)
	{
		ch = a1.hexForm[i];
		if (a1.hexForm[i] == ':')
		{
			j += 5;
		}
		else
		{
			/* filling binary form acording to its hexadecimal form */
			switch (ch)
			{
			case '0':
				a1.binaryForm[k * 4] = false;
				a1.binaryForm[k * 4 + 1] = false;
				a1.binaryForm[k * 4 + 2] = false;
				a1.binaryForm[k * 4 + 3] = false;
				k++;
				break;
			case '1':
				a1.binaryForm[k * 4] = false;
				a1.binaryForm[k * 4 + 1] = false;
				a1.binaryForm[k * 4 + 2] = false;
				a1.binaryForm[k * 4 + 3] = true;
				k++;
				break;
			case '2':
				a1.binaryForm[k * 4] = false;
				a1.binaryForm[k * 4 + 1] = false;
				a1.binaryForm[k * 4 + 2] = true;
				a1.binaryForm[k * 4 + 3] = false;
				k++;
				break;
			case '3':
				a1.binaryForm[k * 4] = false;
				a1.binaryForm[k * 4 + 1] = false;
				a1.binaryForm[k * 4 + 2] = true;
				a1.binaryForm[k * 4 + 3] = true;
				k++;
				break;
			case '4':
				a1.binaryForm[k * 4] = false;
				a1.binaryForm[k * 4 + 1] = true;
				a1.binaryForm[k * 4 + 2] = false;
				a1.binaryForm[k * 4 + 3] = false;
				k++;
				break;
			case '5':
				a1.binaryForm[k * 4] = false;
				a1.binaryForm[k * 4 + 1] = true;
				a1.binaryForm[k * 4 + 2] = false;
				a1.binaryForm[k * 4 + 3] = true;
				k++;
				break;
			case '6':
				a1.binaryForm[k * 4] = false;
				a1.binaryForm[k * 4 + 1] = true;
				a1.binaryForm[k * 4 + 2] = true;
				a1.binaryForm[k * 4 + 3] = false;
				k++;
				break;
			case '7':
				a1.binaryForm[k * 4] = false;
				a1.binaryForm[k * 4 + 1] = true;
				a1.binaryForm[k * 4 + 2] = true;
				a1.binaryForm[k * 4 + 3] = true;//
				k++;
				break;
			case '8':
				a1.binaryForm[k * 4] = true;
				a1.binaryForm[k * 4 + 1] = false;
				a1.binaryForm[k * 4 + 2] = false;
				a1.binaryForm[k * 4 + 3] = false;
				k++;
				break;
			case '9':
				a1.binaryForm[k * 4] = true;
				a1.binaryForm[k * 4 + 1] = false;
				a1.binaryForm[k * 4 + 2] = false;
				a1.binaryForm[k * 4 + 3] = true;
				k++;
				break;
			case 'A':
				a1.binaryForm[k * 4] = true;
				a1.binaryForm[k * 4 + 1] = false;
				a1.binaryForm[k * 4 + 2] = true;
				a1.binaryForm[k * 4 + 3] = false;
				k++;
				break;
			case 'B':
				a1.binaryForm[k * 4] = true;
				a1.binaryForm[k * 4 + 1] = false;
				a1.binaryForm[k * 4 + 2] = true;
				a1.binaryForm[k * 4 + 3] = true;
				k++;
				break;
			case 'C':
				a1.binaryForm[k * 4] = true;
				a1.binaryForm[k * 4 + 1] = true;
				a1.binaryForm[k * 4 + 2] = false;
				a1.binaryForm[k * 4 + 3] = false;
				k++;
				break;
			case 'D':
				a1.binaryForm[k * 4] = true;
				a1.binaryForm[k * 4 + 1] = true;
				a1.binaryForm[k * 4 + 2] = false;
				a1.binaryForm[k * 4 + 3] = true;
				k++;
				break;
			case 'E':
				a1.binaryForm[k * 4] = true;
				a1.binaryForm[k * 4 + 1] = true;
				a1.binaryForm[k * 4 + 2] = true;
				a1.binaryForm[k * 4 + 3] = false;
				k++;
				break;
			case 'F':
				a1.binaryForm[k * 4] = true;
				a1.binaryForm[k * 4 + 1] = true;
				a1.binaryForm[k * 4 + 2] = true;
				a1.binaryForm[k * 4 + 3] = true;
				k++;
				break;
			default:
				cout << "Does not matter" << endl;
				break;
			}
		}
	}
}

void operator<< (ostream& o1, adress a1)
{
	cout << "Hexadecimal" << endl;
	cout << a1.hexForm << endl;
	cout << "\nBinary" << endl;
	int i = 0;
	int j = 3;
	while (i < 128)
	{
		if (i == 64)
			cout << "\nInterface Identifier" << endl;
		if (a1.binaryForm[i] == true)
			cout << "1";
		else if (a1.binaryForm[i] == false)
			cout << "0";

		if (i % 16 == 15 && i != 127 && i != 63)
			cout << ":";
		else if (i % 4 == 3)
			cout << " ";
		i++;
	}

}


void operator!=(adress a1, adress a2)
{
	cout << "Result of A1 != A2: ";
	if (charArrayCompare(a1.hexForm, a2.hexForm) == 0)
		cout << " false" << endl;
	else
		cout << " true" << endl;

	cout << "Different sections: " << endl;
	int i = boolArrayCompare(a1.binaryForm, a2.binaryForm, 0, 2);
	if (i == -1)
	{
		cout << "FP" << endl;
	
	}
	i = boolArrayCompare(a1.binaryForm, a2.binaryForm, 3, 15);
	if (i == -1)
	{
		cout << "TLA ID" << endl;
	
	}
	i = boolArrayCompare(a1.binaryForm, a2.binaryForm, 16, 23);
	if (i == -1)
	{
		cout << "Res" << endl;
	
	}
	i = boolArrayCompare(a1.binaryForm, a2.binaryForm, 24, 47);
	if (i == -1)
	{
		cout << "NLA ID" << endl;

	}
	i = boolArrayCompare(a1.binaryForm, a2.binaryForm, 48, 63);
	if (i == -1)
	{
		cout << "SLA ID" << endl;

	}
	i = boolArrayCompare(a1.binaryForm, a2.binaryForm, 64, 127);
	if (i == -1)
	{
		cout << "Interface" << endl;

	}
}

void operator==(adress a1, adress a2)
{
	cout << "Result of A1 == A2: ";
	if (charArrayCompare(a1.hexForm, a2.hexForm) == 0)
		cout << " true" << endl;
	else
		cout << " false" << endl;

	cout << "Same sections: " << endl;
	int i = boolArrayCompare(a1.binaryForm, a2.binaryForm,0,2);
	if (i == 1)
	{
		cout << "FP" << endl;
	}
	i = boolArrayCompare(a1.binaryForm, a2.binaryForm, 3, 15);
	if (i == 1)
	{
		cout << "TLA ID" << endl;
	}
	i = boolArrayCompare(a1.binaryForm, a2.binaryForm, 16, 23);
	if (i == 1)
	{
		cout << "Res" << endl;
	}
	i = boolArrayCompare(a1.binaryForm, a2.binaryForm, 24, 47);
	if (i == 1)
	{
		cout << "NLA ID" << endl;
	}
	i = boolArrayCompare(a1.binaryForm, a2.binaryForm, 48, 63);
	if (i == 1)
	{
		cout << "SLA ID" << endl;
	}
	i = boolArrayCompare(a1.binaryForm, a2.binaryForm, 64, 127);
	if (i == 1)
	{
		cout << "Interface" << endl;
	}
}


void adress::operator=(adress a1)
{
	adress a3("0000:0000:0000:0000:0000:0000:0000:0000");
	cout << "Creating a new object! (A3)" << endl;
	cout << "Contents of A3" << endl;
	
	cout << "Hexadecimal" << endl;
	cout << a3.hexForm << endl;
	cout << "\nBinary\nFP,TLA,Res,NLA,SLA" << endl;
	int i = 0;
	int j = 3;
	while (i < 128)
	{
		if (i == 64)
			cout << "\nInterface Identifier" << endl;
		if (a3.binaryForm[i] == true)
			cout << "1";
		else if (a3.binaryForm[i] == false)
			cout << "0";

		if (i % 16 == 15 && i != 127 && i != 63)
			cout << ":";
		else if (i % 4 == 3)
			cout << " ";
		i++;
	}
	cout << "\n\nContents of A1 " << endl;
	cout << "\nHexadecimal" << endl;
	cout << this->hexForm << endl;
	cout << "\nBinary\nFP,TLA,Res,NLA,SLA" << endl;
	i = 0;
	j = 3;
	while (i < 128)
	{
		if (i == 64)
			cout << "\nInterface Identifier" << endl;
		if (this->binaryForm[i] == true)
			cout << "1";
		else if (this->binaryForm[i] == false)
			cout << "0";

		if (i % 16 == 15 && i != 127 && i != 63)
			cout << ":";
		else if (i % 4 == 3)
			cout << " ";
		i++;
	}
	i = 0;
	strcpy(a3.hexForm, this->hexForm);
	while (i < 128)
	{
		a3.binaryForm[i] = this->binaryForm[i];
		i++;
	}

	cout << "\n\nAfter A3 = A1 " << endl;
	cout << "\n\nContents of A3 " << endl;
	cout << "\nHexadecimal" << endl;
	cout << a3.hexForm << endl;
	cout << "\nBinary\nFP,TLA,Res,NLA,SLA" << endl;
	i = 0;
	j = 3;
	while (i < 128)
	{
		if (i == 64)
			cout << "\nInterface Identifier" << endl;
		if (a3.binaryForm[i] == true)
			cout << "1";
		else if (a3.binaryForm[i] == false)
			cout << "0";

		if (i % 16 == 15 && i != 127 && i != 63)
			cout << ":";
		else if (i % 4 == 3)
			cout << " ";
		i++;
	}
	cout << "\n\nContents of A1 " << endl;
	cout << "\nHexadecimal" << endl;
	cout << this->hexForm << endl;
	cout << "\nBinary\nFP,TLA,Res,NLA,SLA" << endl;
	i = 0;
	j = 3;
	while (i < 128)
	{
		if (i == 64)
			cout << "\nInterface Identifier" << endl;
		if (this->binaryForm[i] == true)
			cout << "1";
		else if (this->binaryForm[i] == false)
			cout << "0";

		if (i % 16 == 15 && i != 127 && i != 63)
			cout << ":";
		else if (i % 4 == 3)
			cout << " ";
		i++;
	}

	cout << "\n-----------------------------------" << endl;
}


void operator%(adress a1, adress a2)
{
	adress temp("0000:0000:0000:0000:0000:0000:0000:0000"); /* creating object */
	int i = 0;
	for (i; i < 128; i++)
	{
		if (i < 64) /* filling first 64 bits for both hexadecimal and binary form */
		{
			if (i < 20)
				temp.hexForm[i] = a1.hexForm[i];
			temp.binaryForm[i] = a1.binaryForm[i];
		}
		else /* applying XOR operation to temporary object according to 2 objects for last 64 bits, storing in binary form */
		{
			/* THESE PART DIFFER BETWEEN THESE OPERATORS (%, - , +, ^, *, /) ACCORDING TO LOGIC */
			if ((a1.binaryForm[i] == true && a2.binaryForm[i] == true) || (a1.binaryForm[i] == false && a2.binaryForm[i] == false))
				temp.binaryForm[i] = false;
			else
				temp.binaryForm[i] = true;
		}
	} 
	int k = 20;
	i = 64;
	while (k < 39)
	{
		if (k % 5 != 4) /* filling hexadecimal form according to its binary form (4 bit by 4 bit)*/
		{
			/* false(0),false(0),false(0),false(0) ---> '0' 
			   false(0),false(0),false(0),true(1) ---> '1'
			   ...
			   true(1),true(1),true(1),true(1)  ----> 'A'  */
			if (temp.binaryForm[i] == false && temp.binaryForm[i + 1] == false && temp.binaryForm[i + 2] == false && temp.binaryForm[i + 3] == false)
				temp.hexForm[k] = '0';
			else if (temp.binaryForm[i] == false && temp.binaryForm[i + 1] == false && temp.binaryForm[i + 2] == false && temp.binaryForm[i + 3] == true)
				temp.hexForm[k] = '1';
			else if (temp.binaryForm[i] == false && temp.binaryForm[i + 1] == false && temp.binaryForm[i + 2] == true && temp.binaryForm[i + 3] == false)
				temp.hexForm[k] = '2';
			else if (temp.binaryForm[i] == false && temp.binaryForm[i + 1] == false && temp.binaryForm[i + 2] == true && temp.binaryForm[i + 3] == true)
				temp.hexForm[k] = '3';
			else if (temp.binaryForm[i] == false && temp.binaryForm[i + 1] == true && temp.binaryForm[i + 2] == false && temp.binaryForm[i + 3] == false)
				temp.hexForm[k] = '4';
			else if (temp.binaryForm[i] == false && temp.binaryForm[i + 1] == true && temp.binaryForm[i + 2] == false && temp.binaryForm[i + 3] == true)
				temp.hexForm[k] = '5';
			else if (temp.binaryForm[i] == false && temp.binaryForm[i + 1] == true && temp.binaryForm[i + 2] == true && temp.binaryForm[i + 3] == false)
				temp.hexForm[k] = '6';
			else if (temp.binaryForm[i] == false && temp.binaryForm[i + 1] == true && temp.binaryForm[i + 2] == true && temp.binaryForm[i + 3] == true)
				temp.hexForm[k] = '7';
			else if (temp.binaryForm[i] == true && temp.binaryForm[i + 1] == false && temp.binaryForm[i + 2] == false && temp.binaryForm[i + 3] == false)
				temp.hexForm[k] = '8';
			else if (temp.binaryForm[i] == true && temp.binaryForm[i + 1] == false && temp.binaryForm[i + 2] == false && temp.binaryForm[i + 3] == true)
				temp.hexForm[k] = '9';
			else if (temp.binaryForm[i] == true && temp.binaryForm[i + 1] == false && temp.binaryForm[i + 2] == true && temp.binaryForm[i + 3] == false)
				temp.hexForm[k] = 'A';
			else if (temp.binaryForm[i] == true && temp.binaryForm[i + 1] == false && temp.binaryForm[i + 2] == true && temp.binaryForm[i + 3] == true)
				temp.hexForm[k] = 'B';
			else if (temp.binaryForm[i] == true && temp.binaryForm[i + 1] == true && temp.binaryForm[i + 2] == false && temp.binaryForm[i + 3] == false)
				temp.hexForm[k] = 'C';
			else if (temp.binaryForm[i] == true && temp.binaryForm[i + 1] == true && temp.binaryForm[i + 2] == false && temp.binaryForm[i + 3] == true)
				temp.hexForm[k] = 'D';
			else if (temp.binaryForm[i] == true && temp.binaryForm[i + 1] == true && temp.binaryForm[i + 2] == true && temp.binaryForm[i + 3] == false)
				temp.hexForm[k] = 'E';
			else if (temp.binaryForm[i] == true && temp.binaryForm[i + 1] == true && temp.binaryForm[i + 2] == true && temp.binaryForm[i + 3] == true)
				temp.hexForm[k] = 'F';
			i += 4;
			k++;
		}
		else
			temp.hexForm[k++] = ':';
	}
	/* printing temporary object */
	cout << "Hexadecimal: " << endl;
	for (i = 0; i < 39; i++)
		cout << temp.hexForm[i];
	cout << "\nBinary\nFP,TLA,Res,NLA,SLA" << endl;
	for (i = 0; i < 128; i++)
	{
		if (i == 64)
			cout << "\nInterface Identifier" << endl;
		if (temp.binaryForm[i] == true) /* it is is true print 1 */
			cout << "1";
		else
			cout << "0";
		if (i % 16 == 15 && i != 127 && i != 63)
			cout << ":";
		else if (i % 4 == 3)
			cout << " ";
	}
	cout << "\n-----------------------------------" << endl;
}

void operator^(adress a1, adress a2)
{
	adress temp("0000:0000:0000:0000:0000:0000:0000:0000");
	int i = 0;
	for (i; i < 128; i++)
	{
		if (i < 64)
		{
			if (i < 20)
				temp.hexForm[i] = a1.hexForm[i];
			temp.binaryForm[i] = a1.binaryForm[i];
		}
		else
		{
			if ((a1.binaryForm[i] == true && a2.binaryForm[i] == true)|| (a1.binaryForm[i] == false && a2.binaryForm[i] == false))
				temp.binaryForm[i] = true;
			else
				temp.binaryForm[i] = false;
		}
	} // copying first half and finishing binary form
	int k = 20;
	i = 64;
	while (k < 39)
	{
		if (k % 5 != 4)
		{
			if (temp.binaryForm[i] == false && temp.binaryForm[i + 1] == false && temp.binaryForm[i + 2] == false && temp.binaryForm[i + 3] == false)
				temp.hexForm[k] = '0';
			else if (temp.binaryForm[i] == false && temp.binaryForm[i + 1] == false && temp.binaryForm[i + 2] == false && temp.binaryForm[i + 3] == true)
				temp.hexForm[k] = '1';
			else if (temp.binaryForm[i] == false && temp.binaryForm[i + 1] == false && temp.binaryForm[i + 2] == true && temp.binaryForm[i + 3] == false)
				temp.hexForm[k] = '2';
			else if (temp.binaryForm[i] == false && temp.binaryForm[i + 1] == false && temp.binaryForm[i + 2] == true && temp.binaryForm[i + 3] == true)
				temp.hexForm[k] = '3';
			else if (temp.binaryForm[i] == false && temp.binaryForm[i + 1] == true && temp.binaryForm[i + 2] == false && temp.binaryForm[i + 3] == false)
				temp.hexForm[k] = '4';
			else if (temp.binaryForm[i] == false && temp.binaryForm[i + 1] == true && temp.binaryForm[i + 2] == false && temp.binaryForm[i + 3] == true)
				temp.hexForm[k] = '5';
			else if (temp.binaryForm[i] == false && temp.binaryForm[i + 1] == true && temp.binaryForm[i + 2] == true && temp.binaryForm[i + 3] == false)
				temp.hexForm[k] = '6';
			else if (temp.binaryForm[i] == false && temp.binaryForm[i + 1] == true && temp.binaryForm[i + 2] == true && temp.binaryForm[i + 3] == true)
				temp.hexForm[k] = '7';
			else if (temp.binaryForm[i] == true && temp.binaryForm[i + 1] == false && temp.binaryForm[i + 2] == false && temp.binaryForm[i + 3] == false)
				temp.hexForm[k] = '8';
			else if (temp.binaryForm[i] == true && temp.binaryForm[i + 1] == false && temp.binaryForm[i + 2] == false && temp.binaryForm[i + 3] == true)
				temp.hexForm[k] = '9';
			else if (temp.binaryForm[i] == true && temp.binaryForm[i + 1] == false && temp.binaryForm[i + 2] == true && temp.binaryForm[i + 3] == false)
				temp.hexForm[k] = 'A';
			else if (temp.binaryForm[i] == true && temp.binaryForm[i + 1] == false && temp.binaryForm[i + 2] == true && temp.binaryForm[i + 3] == true)
				temp.hexForm[k] = 'B';
			else if (temp.binaryForm[i] == true && temp.binaryForm[i + 1] == true && temp.binaryForm[i + 2] == false && temp.binaryForm[i + 3] == false)
				temp.hexForm[k] = 'C';
			else if (temp.binaryForm[i] == true && temp.binaryForm[i + 1] == true && temp.binaryForm[i + 2] == false && temp.binaryForm[i + 3] == true)
				temp.hexForm[k] = 'D';
			else if (temp.binaryForm[i] == true && temp.binaryForm[i + 1] == true && temp.binaryForm[i + 2] == true && temp.binaryForm[i + 3] == false)
				temp.hexForm[k] = 'E';
			else if (temp.binaryForm[i] == true && temp.binaryForm[i + 1] == true && temp.binaryForm[i + 2] == true && temp.binaryForm[i + 3] == true)
				temp.hexForm[k] = 'F';
			i += 4;
			k++;
		}
		else
			temp.hexForm[k++] = ':';
	}
	cout << "Hexadecimal: " << endl;
	for (i = 0; i < 39; i++)
		cout << temp.hexForm[i];
	cout << "\nBinary\nFP,TLA,Res,NLA,SLA" << endl;
	for (i = 0; i < 128; i++)
	{
		if (i == 64)
			cout << "\nInterface Identifier" << endl;
		if (temp.binaryForm[i] == true)
			cout << "1";
		else
			cout << "0";
		if (i % 16 == 15 && i != 127 && i != 63)
			cout << ":";
		else if (i % 4 == 3)
			cout << " ";
	}
	cout << "\n-----------------------------------" << endl;
}

void operator/(adress a1, adress a2)
{
	adress temp("0000:0000:0000:0000:0000:0000:0000:0000");
	int i = 0;
	for (i; i < 128; i++)
	{
		if (i < 64)
		{
			if (i < 20)
				temp.hexForm[i] = a1.hexForm[i];
			temp.binaryForm[i] = a1.binaryForm[i];
		}
		else
		{
			if ((a1.binaryForm[i] == true && a2.binaryForm[i] == true))
				temp.binaryForm[i] = false;
			else
				temp.binaryForm[i] = true;
		}
	} // copying first half and finishing binary form
	int k = 20;
	i = 64;
	while (k < 39)
	{
		if (k % 5 != 4)
		{
			if (temp.binaryForm[i] == false && temp.binaryForm[i + 1] == false && temp.binaryForm[i + 2] == false && temp.binaryForm[i + 3] == false)
				temp.hexForm[k] = '0';
			else if (temp.binaryForm[i] == false && temp.binaryForm[i + 1] == false && temp.binaryForm[i + 2] == false && temp.binaryForm[i + 3] == true)
				temp.hexForm[k] = '1';
			else if (temp.binaryForm[i] == false && temp.binaryForm[i + 1] == false && temp.binaryForm[i + 2] == true && temp.binaryForm[i + 3] == false)
				temp.hexForm[k] = '2';
			else if (temp.binaryForm[i] == false && temp.binaryForm[i + 1] == false && temp.binaryForm[i + 2] == true && temp.binaryForm[i + 3] == true)
				temp.hexForm[k] = '3';
			else if (temp.binaryForm[i] == false && temp.binaryForm[i + 1] == true && temp.binaryForm[i + 2] == false && temp.binaryForm[i + 3] == false)
				temp.hexForm[k] = '4';
			else if (temp.binaryForm[i] == false && temp.binaryForm[i + 1] == true && temp.binaryForm[i + 2] == false && temp.binaryForm[i + 3] == true)
				temp.hexForm[k] = '5';
			else if (temp.binaryForm[i] == false && temp.binaryForm[i + 1] == true && temp.binaryForm[i + 2] == true && temp.binaryForm[i + 3] == false)
				temp.hexForm[k] = '6';
			else if (temp.binaryForm[i] == false && temp.binaryForm[i + 1] == true && temp.binaryForm[i + 2] == true && temp.binaryForm[i + 3] == true)
				temp.hexForm[k] = '7';
			else if (temp.binaryForm[i] == true && temp.binaryForm[i + 1] == false && temp.binaryForm[i + 2] == false && temp.binaryForm[i + 3] == false)
				temp.hexForm[k] = '8';
			else if (temp.binaryForm[i] == true && temp.binaryForm[i + 1] == false && temp.binaryForm[i + 2] == false && temp.binaryForm[i + 3] == true)
				temp.hexForm[k] = '9';
			else if (temp.binaryForm[i] == true && temp.binaryForm[i + 1] == false && temp.binaryForm[i + 2] == true && temp.binaryForm[i + 3] == false)
				temp.hexForm[k] = 'A';
			else if (temp.binaryForm[i] == true && temp.binaryForm[i + 1] == false && temp.binaryForm[i + 2] == true && temp.binaryForm[i + 3] == true)
				temp.hexForm[k] = 'B';
			else if (temp.binaryForm[i] == true && temp.binaryForm[i + 1] == true && temp.binaryForm[i + 2] == false && temp.binaryForm[i + 3] == false)
				temp.hexForm[k] = 'C';
			else if (temp.binaryForm[i] == true && temp.binaryForm[i + 1] == true && temp.binaryForm[i + 2] == false && temp.binaryForm[i + 3] == true)
				temp.hexForm[k] = 'D';
			else if (temp.binaryForm[i] == true && temp.binaryForm[i + 1] == true && temp.binaryForm[i + 2] == true && temp.binaryForm[i + 3] == false)
				temp.hexForm[k] = 'E';
			else if (temp.binaryForm[i] == true && temp.binaryForm[i + 1] == true && temp.binaryForm[i + 2] == true && temp.binaryForm[i + 3] == true)
				temp.hexForm[k] = 'F';
			i += 4;
			k++;
		}
		else
			temp.hexForm[k++] = ':';
	}
	cout << "Hexadecimal: " << endl;
	for (i = 0; i < 39; i++)
		cout << temp.hexForm[i];
	cout << "\nBinary\nFP,TLA,Res,NLA,SLA" << endl;
	for (i = 0; i < 128; i++)
	{
		if (i == 64)
			cout << "\nInterface Identifier" << endl;
		if (temp.binaryForm[i] == true)
			cout << "1";
		else
			cout << "0";
		if (i % 16 == 15 && i != 127 && i != 63)
			cout << ":";
		else if (i % 4 == 3)
			cout << " ";
	}
	cout << "\n-----------------------------------" << endl;
}

void operator-(adress a1, adress a2)
{
	adress temp("0000:0000:0000:0000:0000:0000:0000:0000");
	int i = 0;
	for (i; i < 128; i++)
	{
		if (i < 64)
		{
			if (i < 20)
				temp.hexForm[i] = a1.hexForm[i];
			temp.binaryForm[i] = a1.binaryForm[i];
		}
		else
		{
			if ((a1.binaryForm[i] == false && a2.binaryForm[i] == false))
				temp.binaryForm[i] = true;
			else
				temp.binaryForm[i] = false;
		}
	} // copying first half and finishing binary form
	int k = 20;
	i = 64;
	while (k < 39)
	{
		if (k % 5 != 4)
		{
			if (temp.binaryForm[i] == false && temp.binaryForm[i + 1] == false && temp.binaryForm[i + 2] == false && temp.binaryForm[i + 3] == false)
				temp.hexForm[k] = '0';
			else if (temp.binaryForm[i] == false && temp.binaryForm[i + 1] == false && temp.binaryForm[i + 2] == false && temp.binaryForm[i + 3] == true)
				temp.hexForm[k] = '1';
			else if (temp.binaryForm[i] == false && temp.binaryForm[i + 1] == false && temp.binaryForm[i + 2] == true && temp.binaryForm[i + 3] == false)
				temp.hexForm[k] = '2';
			else if (temp.binaryForm[i] == false && temp.binaryForm[i + 1] == false && temp.binaryForm[i + 2] == true && temp.binaryForm[i + 3] == true)
				temp.hexForm[k] = '3';
			else if (temp.binaryForm[i] == false && temp.binaryForm[i + 1] == true && temp.binaryForm[i + 2] == false && temp.binaryForm[i + 3] == false)
				temp.hexForm[k] = '4';
			else if (temp.binaryForm[i] == false && temp.binaryForm[i + 1] == true && temp.binaryForm[i + 2] == false && temp.binaryForm[i + 3] == true)
				temp.hexForm[k] = '5';
			else if (temp.binaryForm[i] == false && temp.binaryForm[i + 1] == true && temp.binaryForm[i + 2] == true && temp.binaryForm[i + 3] == false)
				temp.hexForm[k] = '6';
			else if (temp.binaryForm[i] == false && temp.binaryForm[i + 1] == true && temp.binaryForm[i + 2] == true && temp.binaryForm[i + 3] == true)
				temp.hexForm[k] = '7';
			else if (temp.binaryForm[i] == true && temp.binaryForm[i + 1] == false && temp.binaryForm[i + 2] == false && temp.binaryForm[i + 3] == false)
				temp.hexForm[k] = '8';
			else if (temp.binaryForm[i] == true && temp.binaryForm[i + 1] == false && temp.binaryForm[i + 2] == false && temp.binaryForm[i + 3] == true)
				temp.hexForm[k] = '9';
			else if (temp.binaryForm[i] == true && temp.binaryForm[i + 1] == false && temp.binaryForm[i + 2] == true && temp.binaryForm[i + 3] == false)
				temp.hexForm[k] = 'A';
			else if (temp.binaryForm[i] == true && temp.binaryForm[i + 1] == false && temp.binaryForm[i + 2] == true && temp.binaryForm[i + 3] == true)
				temp.hexForm[k] = 'B';
			else if (temp.binaryForm[i] == true && temp.binaryForm[i + 1] == true && temp.binaryForm[i + 2] == false && temp.binaryForm[i + 3] == false)
				temp.hexForm[k] = 'C';
			else if (temp.binaryForm[i] == true && temp.binaryForm[i + 1] == true && temp.binaryForm[i + 2] == false && temp.binaryForm[i + 3] == true)
				temp.hexForm[k] = 'D';
			else if (temp.binaryForm[i] == true && temp.binaryForm[i + 1] == true && temp.binaryForm[i + 2] == true && temp.binaryForm[i + 3] == false)
				temp.hexForm[k] = 'E';
			else if (temp.binaryForm[i] == true && temp.binaryForm[i + 1] == true && temp.binaryForm[i + 2] == true && temp.binaryForm[i + 3] == true)
				temp.hexForm[k] = 'F';
			i += 4;
			k++;
		}
		else
			temp.hexForm[k++] = ':';
	}
	cout << "Hexadecimal: " << endl;
	for (i = 0; i < 39; i++)
		cout << temp.hexForm[i];
	cout << "\nBinary\nFP,TLA,Res,NLA,SLA" << endl;
	for (i = 0; i < 128; i++)
	{
		if (i == 64)
			cout << "\nInterface Identifier" << endl;
		if (temp.binaryForm[i] == true)
			cout << "1";
		else
			cout << "0";
		if (i % 16 == 15 && i != 127 && i != 63)
			cout << ":";
		else if (i % 4 == 3)
			cout << " ";
	}
	cout << "\n-----------------------------------" << endl;
}

void operator*(adress a1, adress a2)
{
	adress temp("0000:0000:0000:0000:0000:0000:0000:0000");
	int i = 0;
	for (i; i < 128; i++)
	{
		if (i < 64)
		{
			if (i < 20)
				temp.hexForm[i] = a1.hexForm[i];
			temp.binaryForm[i] = a1.binaryForm[i];
		}
		else
		{
			if (a1.binaryForm[i] == false || a2.binaryForm[i] == false)
				temp.binaryForm[i] = false;
			else
				temp.binaryForm[i] = true;
		}
	} // copying first half and finishing binary form
	int k = 20;
	i = 64;
	while (k < 39)
	{
		if (k % 5 != 4)
		{
			if (temp.binaryForm[i] == false && temp.binaryForm[i + 1] == false && temp.binaryForm[i + 2] == false && temp.binaryForm[i + 3] == false)
				temp.hexForm[k] = '0';
			else if (temp.binaryForm[i] == false && temp.binaryForm[i + 1] == false && temp.binaryForm[i + 2] == false && temp.binaryForm[i + 3] == true)
				temp.hexForm[k] = '1';
			else if (temp.binaryForm[i] == false && temp.binaryForm[i + 1] == false && temp.binaryForm[i + 2] == true && temp.binaryForm[i + 3] == false)
				temp.hexForm[k] = '2';
			else if (temp.binaryForm[i] == false && temp.binaryForm[i + 1] == false && temp.binaryForm[i + 2] == true && temp.binaryForm[i + 3] == true)
				temp.hexForm[k] = '3';
			else if (temp.binaryForm[i] == false && temp.binaryForm[i + 1] == true && temp.binaryForm[i + 2] == false && temp.binaryForm[i + 3] == false)
				temp.hexForm[k] = '4';
			else if (temp.binaryForm[i] == false && temp.binaryForm[i + 1] == true && temp.binaryForm[i + 2] == false && temp.binaryForm[i + 3] == true)
				temp.hexForm[k] = '5';
			else if (temp.binaryForm[i] == false && temp.binaryForm[i + 1] == true && temp.binaryForm[i + 2] == true && temp.binaryForm[i + 3] == false)
				temp.hexForm[k] = '6';
			else if (temp.binaryForm[i] == false && temp.binaryForm[i + 1] == true && temp.binaryForm[i + 2] == true && temp.binaryForm[i + 3] == true)
				temp.hexForm[k] = '7';
			else if (temp.binaryForm[i] == true && temp.binaryForm[i + 1] == false && temp.binaryForm[i + 2] == false && temp.binaryForm[i + 3] == false)
				temp.hexForm[k] = '8';
			else if (temp.binaryForm[i] == true && temp.binaryForm[i + 1] == false && temp.binaryForm[i + 2] == false && temp.binaryForm[i + 3] == true)
				temp.hexForm[k] = '9';
			else if (temp.binaryForm[i] == true && temp.binaryForm[i + 1] == false && temp.binaryForm[i + 2] == true && temp.binaryForm[i + 3] == false)
				temp.hexForm[k] = 'A';
			else if (temp.binaryForm[i] == true && temp.binaryForm[i + 1] == false && temp.binaryForm[i + 2] == true && temp.binaryForm[i + 3] == true)
				temp.hexForm[k] = 'B';
			else if (temp.binaryForm[i] == true && temp.binaryForm[i + 1] == true && temp.binaryForm[i + 2] == false && temp.binaryForm[i + 3] == false)
				temp.hexForm[k] = 'C';
			else if (temp.binaryForm[i] == true && temp.binaryForm[i + 1] == true && temp.binaryForm[i + 2] == false && temp.binaryForm[i + 3] == true)
				temp.hexForm[k] = 'D';
			else if (temp.binaryForm[i] == true && temp.binaryForm[i + 1] == true && temp.binaryForm[i + 2] == true && temp.binaryForm[i + 3] == false)
				temp.hexForm[k] = 'E';
			else if (temp.binaryForm[i] == true && temp.binaryForm[i + 1] == true && temp.binaryForm[i + 2] == true && temp.binaryForm[i + 3] == true)
				temp.hexForm[k] = 'F';
			i += 4;
			k++;
		}
		else
			temp.hexForm[k++] = ':';
	}
	cout << "Hexadecimal: " << endl;
	for (i = 0; i < 39; i++)
		cout << temp.hexForm[i];
	cout << "\nBinary\nFP,TLA,Res,NLA,SLA" << endl;
	for (i = 0; i < 128; i++)
	{
		if (i == 64)
			cout << "\nInterface Identifier" << endl;
		if (temp.binaryForm[i] == true)
			cout << "1";
		else
			cout << "0";
		if (i % 16 == 15 && i != 127 && i != 63)
			cout << ":";
		else if (i % 4 == 3)
			cout << " ";
	}
	cout << "\n-----------------------------------" << endl;



}

void operator+(adress a1, adress a2)
{
	adress temp("0000:0000:0000:0000:0000:0000:0000:0000");
	int i = 0;
	for (i; i < 128; i++)
	{
		if (i < 64)
		{
			if (i < 20)
				temp.hexForm[i] = a1.hexForm[i];
			temp.binaryForm[i] = a1.binaryForm[i];
		}
		else
		{
			if ((a1.binaryForm[i] || a2.binaryForm[i]) == true)
				temp.binaryForm[i] = true;
			else
				temp.binaryForm[i] = false;
		}
	} // copying first half and finishing binary form
	int k = 20;
	i = 64;
	while(k<39)
	{
		if (k % 5 != 4)
		{
			if (temp.binaryForm[i] == false && temp.binaryForm[i + 1] == false && temp.binaryForm[i + 2] == false && temp.binaryForm[i + 3] == false)
				temp.hexForm[k] = '0';
			else if (temp.binaryForm[i] == false && temp.binaryForm[i + 1] == false && temp.binaryForm[i + 2] == false && temp.binaryForm[i + 3] == true)
				temp.hexForm[k] = '1';
			else if (temp.binaryForm[i] == false && temp.binaryForm[i + 1] == false && temp.binaryForm[i + 2] == true && temp.binaryForm[i + 3] == false)
				temp.hexForm[k] = '2';
			else if (temp.binaryForm[i] == false && temp.binaryForm[i + 1] == false && temp.binaryForm[i + 2] == true && temp.binaryForm[i + 3] == true)
				temp.hexForm[k] = '3';
			else if (temp.binaryForm[i] == false && temp.binaryForm[i + 1] == true && temp.binaryForm[i + 2] == false && temp.binaryForm[i + 3] == false)
				temp.hexForm[k] = '4';
			else if (temp.binaryForm[i] == false && temp.binaryForm[i + 1] == true && temp.binaryForm[i + 2] == false && temp.binaryForm[i + 3] == true)
				temp.hexForm[k] = '5';
			else if (temp.binaryForm[i] == false && temp.binaryForm[i + 1] == true && temp.binaryForm[i + 2] == true && temp.binaryForm[i + 3] == false)
				temp.hexForm[k] = '6';
			else if (temp.binaryForm[i] == false && temp.binaryForm[i + 1] == true && temp.binaryForm[i + 2] == true && temp.binaryForm[i + 3] == true)
				temp.hexForm[k] = '7';
			else if (temp.binaryForm[i] == true && temp.binaryForm[i + 1] == false && temp.binaryForm[i + 2] == false && temp.binaryForm[i + 3] == false)
				temp.hexForm[k] = '8';
			else if (temp.binaryForm[i] == true && temp.binaryForm[i + 1] == false && temp.binaryForm[i + 2] == false && temp.binaryForm[i + 3] == true)
				temp.hexForm[k] = '9';
			else if (temp.binaryForm[i] == true && temp.binaryForm[i + 1] == false && temp.binaryForm[i + 2] == true && temp.binaryForm[i + 3] == false)
				temp.hexForm[k] = 'A';
			else if (temp.binaryForm[i] == true && temp.binaryForm[i + 1] == false && temp.binaryForm[i + 2] == true && temp.binaryForm[i + 3] == true)
				temp.hexForm[k] = 'B';
			else if (temp.binaryForm[i] == true && temp.binaryForm[i + 1] == true && temp.binaryForm[i + 2] == false && temp.binaryForm[i + 3] == false)
				temp.hexForm[k] = 'C';
			else if (temp.binaryForm[i] == true && temp.binaryForm[i + 1] == true && temp.binaryForm[i + 2] == false && temp.binaryForm[i + 3] == true)
				temp.hexForm[k] = 'D';
			else if (temp.binaryForm[i] == true && temp.binaryForm[i + 1] == true && temp.binaryForm[i + 2] == true && temp.binaryForm[i + 3] == false)
				temp.hexForm[k] = 'E';
			else if (temp.binaryForm[i] == true && temp.binaryForm[i + 1] == true && temp.binaryForm[i + 2] == true && temp.binaryForm[i + 3] == true)
				temp.hexForm[k] = 'F';
			i += 4;
			k++;
		}
		else
			temp.hexForm[k++] = ':';
	}
	cout << "Hexadecimal: " << endl;
	for (i = 0; i < 39; i++)
		cout << temp.hexForm[i];
	cout << "\nBinary\nFP,TLA,Res,NLA,SLA" << endl;
	for (i = 0; i < 128; i++)
	{
		if (i == 64)
			cout << "\nInterface Identifier" << endl;
		if (temp.binaryForm[i] == true)
			cout << "1";
		else
			cout << "0";
		if (i % 16 == 15 && i != 127 && i!=63)
			cout << ":";
		else if (i % 4 == 3)
			cout << " ";
	}
	cout << "\n-----------------------------------" << endl;
}

void operator&(adress a1)
{
	int i;
	cout << "Hexadecimal: ";
	for (i = 15; i < 19; i++)
			cout << a1.hexForm[i];
	cout << "\nBinary: ";
	for (i = 48; i < 64; i++)
	{
		if (a1.binaryForm[i] == true)
			cout << "1";
		else
			cout << "0";
		if (i % 4 == 3)
			cout << " ";
	}
}

void operator++(adress a1)
{
	int i;
	cout << "Hexadecimal: ";
	for (i = 7; i < 14; i++)
	{
		if(a1.hexForm[i] != ':')
			cout << a1.hexForm[i];
	}
	cout << "\nBinary: ";
	for (i = 24; i < 48; i++)
	{
		if (a1.binaryForm[i] == true)
			cout << "1";
		else
			cout << "0";
		if (i % 4 == 3)
			cout << " ";
	}
}

void operator!(adress a1)
{
	int i;
	cout << "Hexadecimal: ";
	for (i = 0; i < 4; i++)
		cout << a1.hexForm[i];
	cout << "\nBinary: ";
	for (i = 3; i < 16; i++)
	{
		if (a1.binaryForm[i] == true)
			cout << "1";
		else
			cout << "0";
		if (i % 4 == 3)
			cout << " ";
	}
}

void operator~(adress a1)
{
	int i = 2, num = 0, addingnum=1;
	for (i; i >= 0; i--)
	{
		if (a1.binaryForm[i] == true)
		{
			num+=addingnum;
		}
		addingnum *= 2;
	} // first 3 bit's decimal value calculated.

	if (num == 1)
		cout << "Unicast " << endl;
	else if(num > 4)
		cout << "Multicast " << endl;
	else
		cout << "Anycast " << endl;
}

adress::adress(char* str)
{
	hexForm = new char[39];      //1080:0000:0000:0000:0008:0800:200C:417A
	strcpy(this->hexForm, str); // hexadecimal form is done.
	binaryForm = new bool[128]; // allocationg memory for binary form
	
	int i = 0, j = 4, k = 0;
	char ch;

	/* Filling its binary form according to its hexadecimal form */
	for(i;i<39;i++)
	{
		ch = hexForm[i];
		if (hexForm[i] == ':')
		{
			j += 5;
		}
		else
		{
			switch (ch)
			{
			case '0':
				binaryForm[k*4] = false;
				binaryForm[k * 4 + 1] = false;
				binaryForm[k * 4 + 2] = false;
				binaryForm[k * 4 + 3] = false;
				k++;
				break;
			case '1':
				binaryForm[k * 4] = false;
				binaryForm[k * 4 + 1] = false;
				binaryForm[k * 4 + 2] = false;
				binaryForm[k * 4 + 3] = true;
				k++;
				break;
			case '2':
				binaryForm[k * 4] = false;
				binaryForm[k * 4 + 1] = false;
				binaryForm[k * 4 + 2] = true;
				binaryForm[k * 4 + 3] = false;
				k++;
				break;
			case '3':
				binaryForm[k * 4] = false;
				binaryForm[k * 4 + 1] = false;
				binaryForm[k * 4 + 2] = true;
				binaryForm[k * 4 + 3] = true;
				k++;
				break;
			case '4':
				binaryForm[k * 4] = false;
				binaryForm[k* 4 + 1] = true;
				binaryForm[k * 4 + 2] = false;
				binaryForm[k * 4 + 3] = false;
				k++;
				break;
			case '5':
				binaryForm[k * 4] = false;
				binaryForm[k * 4 + 1] = true;
				binaryForm[k * 4 + 2] = false;
				binaryForm[k * 4 + 3] = true;
				k++;
				break;
			case '6':
				binaryForm[k * 4] = false;
				binaryForm[k * 4 + 1] = true;
				binaryForm[k * 4 + 2] = true;
				binaryForm[k * 4 + 3] = false;
				k++;
				break;
			case '7':
				binaryForm[k * 4] = false;
				binaryForm[k * 4 + 1] = true;
				binaryForm[k * 4 + 2] = true;
				binaryForm[k * 4 + 3] = true;//
				k++;
				break;
			case '8':
				binaryForm[k * 4] = true;
				binaryForm[k * 4 + 1] = false;
				binaryForm[k * 4 + 2] = false;
				binaryForm[k * 4 + 3] = false;
				k++;
				break;
			case '9':
				binaryForm[k * 4] = true;
				binaryForm[k * 4 + 1] = false;
				binaryForm[k * 4 + 2] = false;
				binaryForm[k * 4 + 3] = true;
				k++;
				break;
			case 'A':
				binaryForm[k * 4] = true;
				binaryForm[k * 4 + 1] = false;
				binaryForm[k * 4 + 2] = true;
				binaryForm[k * 4 + 3] = false;
				k++;
				break;
			case 'B':
				binaryForm[k * 4] = true;
				binaryForm[k * 4 + 1] = false;
				binaryForm[k * 4 + 2] = true;
				binaryForm[k * 4 + 3] = true;
				k++;
				break;
			case 'C':
				binaryForm[k * 4] = true;
				binaryForm[k * 4 + 1] = true;
				binaryForm[k * 4 + 2] = false;
				binaryForm[k * 4 + 3] = false;
				k++;
				break;
			case 'D':
				binaryForm[k * 4] = true;
				binaryForm[k * 4 + 1] = true;
				binaryForm[k * 4 + 2] = false;
				binaryForm[k * 4 + 3] = true;
				k++;
				break;
			case 'E':
				binaryForm[k * 4] = true;
				binaryForm[k * 4 + 1] = true;
				binaryForm[k * 4 + 2] = true;
				binaryForm[k * 4 + 3] = false;
				k++;
				break;
			case 'F':
				binaryForm[k * 4] = true;
				binaryForm[k * 4 + 1] = true;
				binaryForm[k * 4 + 2] = true;
				binaryForm[k * 4 + 3] = true;
				k++;
				break;
			default:
				cout << "Does not matter" << endl;
				break;
			}
		}
	}
}

