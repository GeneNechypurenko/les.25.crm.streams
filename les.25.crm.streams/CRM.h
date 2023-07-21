#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <exception>

using namespace std;

class CRM
{
	char name[20];
	char position[20];
	double salary;

	static int size;

public:
	CRM();

	static int getSize();

	void input();
	void output() const;
	void add(CRM*& crm);

	void save(const string filename, CRM*& crm) const;
	void load(const string filename, CRM*& crm);
};

