#include "Programmer.h"
#include <iostream>
using namespace std;

Programmer::Programmer() : Human()
{
    cout << "Construct programmer\n";
    companyName = nullptr;
}

Programmer::Programmer(const char* n, int a, double sal, const char* companyN)
    : Human(n, a, sal)
{
    cout << "Construct programmer\n";
    companyName = new char[strlen(companyN) + 1];
    strcpy_s(companyName, strlen(companyN) + 1, companyN);
}

Programmer::~Programmer()
{
    delete[] companyName;
    cout << "Destruct programmer\n";
}

void Programmer::Output()
{
    cout << "Output programmer\n";
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Salary: " << salary << endl;
    cout << "Company name: " << companyName << endl;
}

void Programmer::Salary()
{
    cout << "Programmer's salary: " << salary << endl;
}

void Programmer::Input(const char* n, int a, double sal, const char* companyN)
{
    if (name != nullptr)
    {
        delete[] name;
    }
    if (companyName != nullptr)
    {
        delete[] companyName;
    }

    name = new char[strlen(n) + 1];
    strcpy_s(name, strlen(n) + 1, n);
    age = a;
    salary = sal;

    companyName = new char[strlen(companyN) + 1];
    strcpy_s(companyName, strlen(companyN) + 1, companyN);
}