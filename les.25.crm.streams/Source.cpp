#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <exception>

#include "CRM.h"

using namespace std;

int main()
{
	string filename = "save.bin";

	CRM* crm = nullptr;

	try
	{
		crm->load(filename, crm);
	}
	catch (const char* error_read_from_file)
	{
		cout << endl << error_read_from_file << endl << endl;
	}

	system("pause");

	int select = 0;

	const char* menu[] = {"1. Add",	"2. Print", "3. Exit"};

	while (true)
	{
		system("cls");

		for (int i = 0; i < 3; i++)
		{
			cout << menu[i] << endl;
		}

		select = _getch();

		switch (select)
		{
		case '1':

			system("cls");
			try 
			{
				crm->add(crm);
			}
			catch (const char* error_input)
			{
				cout << endl << error_input << endl << endl;
			}
			system("pause");

			break;

		case '2':

			system("cls");
			for (int i = 0; i < CRM::getSize(); i++)
			{
				crm[i].output();
			}
			system("pause");

			break;

		case '3':

			system("cls");
			try
			{
				crm->save(filename, crm);
			}
			catch (const char* error_write_to_file)
			{
				cout << endl << error_write_to_file << endl << endl;
			}
			system("pause");

			delete[]crm;

			return 0;
		}
	}
	return 0;
}