#include "stdafx.h"
#include <iostream>
#include <string>
#include <cctype>
#include <conio.h>

using namespace std;

int main()
{

	const int succeed = 0;
	const int errorName = 1;
	const int errorPhone = 2;
	const int phoneLength = 6;

	string lastName, phoneNumber;
	cout << "Enter your Last Name and phone number: ";
	cin >> lastName >> phoneNumber;

	//Loop to verify lastName contains alphabetic symbols only
	for (int i = 0; i < lastName.length(); i++)
	{
		if (!isalpha(lastName[i]))
		{
			cout << "Your Last Name contains non-latin letters or any other symbols!" << endl;
			cout << "Press any key to continue" << endl;
			while (!_kbhit());
			return errorName;
		}
	}

	//Loop to verify phoneNumber contains digits only
	for (int i = 0; i < phoneNumber.length(); i++)
	{
		if (!isdigit(phoneNumber[i]))
		{
			cout << "Phone number should contain only digits!" << endl;
			cout << "Press any key to continue" << endl;
			while (!_kbhit());
			return errorPhone;
		}
	}

	//Veifying lastName starts with a capital letter
	if (!isupper(lastName[0]))
	{
		cout << "Your Last Name does not start with a capital letter!" << endl;
		cout << "Press any key to continue" << endl;
		while (!_kbhit());
		return errorName;
	}

	//Verifying phoneNumber is 6-digit long
	if (phoneNumber.length() != phoneLength)
	{
		cout << "Your phone number is not 6-digit long!" << endl;
		cout << "Press any key to continue" << endl;
		while (!_kbhit());
		return errorPhone;
	}

	cout << lastName << endl << phoneNumber << endl;
	cout << "Press any key to continue" << endl;
	while (!_kbhit());

	return succeed;
}