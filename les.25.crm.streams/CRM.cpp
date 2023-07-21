#include "CRM.h"

int CRM::size = 0;

CRM::CRM()
    :
    salary(0)
{
    strcpy_s(name, " ");
    strcpy_s(position, " ");
}

int CRM::getSize()
{
    return size;
}

void CRM::input()
{
    cout << "enter name: ";
    cin.getline(name, sizeof(name));

    cout << "enter position: ";
    cin.getline(position, sizeof(position));

    cout << "enter salary: ";
    cin >> salary;
    cin.ignore();

    if (cin.fail() || salary < 0)
    {
        const char error[50] = "Error! Invalid input salary! Please retry!";

        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        throw error;
    }

    system("cls");
}

void CRM::output() const
{
    cout << "______________" << endl;
	cout << name << endl;
	cout << position << endl;
	cout << salary << endl;
    cout << "______________" << endl;
}

void CRM::add(CRM*& crm)
{
    CRM employee;

    employee.input();

    CRM* temp = new CRM[size + 1];

    for (int i = 0; i < size; i++)
    {
        temp[i] = crm[i];
    }

    temp[size] = employee;
    size++;

    delete[] crm;
    crm = temp;
}

void CRM::save(const string filename, CRM*& crm) const
{
    ofstream save(filename, ios::binary);

    if (!save)
    {
        const char error[40] = "Error: Cannot open file for writing.";
        
        throw error;
    }

    save.write(reinterpret_cast<const char*>(&size), sizeof(int));

    for (int i = 0; i < size; i++)
    {
        save.write(reinterpret_cast<const char*>(&crm[i]), sizeof(CRM));
    }

    cout << "Data saved to " << filename << " successfully." << endl;

    save.close();
}

void CRM::load(const string filename, CRM*& crm)
{
    ifstream load(filename, ios::binary);

    if (!load.is_open())
    {
        const char error[40] = "Error: Cannot open file for reading.";

        throw error;
    }

    load.read(reinterpret_cast<char*>(&size), sizeof(int));

    crm = new CRM[size];

    for (int i = 0; i < size; i++)
    {
        load.read(reinterpret_cast<char*>(&crm[i]), sizeof(CRM));
    }

    cout << "Data loaded from '" << filename << "' successfully." << endl;

    load.close();
}
