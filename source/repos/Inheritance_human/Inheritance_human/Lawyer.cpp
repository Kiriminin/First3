#include "Lawyer.h"
#include <iostream>
#include <cstring>

using namespace std;

Lawyer::Lawyer() : Human()
{
    cout << "Construct Lawyer\n";
    company = nullptr;
    finishedUniversity = false;
}

Lawyer::Lawyer(const char* n, int a, double sal, const char* comp, bool finish)
    : Human(n, a, sal)
{
    cout << "Construct Lawyer\n";

    company = new char[strlen(comp) + 1];
    strcpy_s(company, strlen(comp) + 1, comp);
    finishedUniversity = finish;
}

Lawyer::~Lawyer()
{
    delete[] company;
    cout << "Destruct Lawyer\n";
}

void Lawyer::Output()
{
    cout << "Output Lawyer\n";
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Salary: " << salary << endl;
    cout << "Company: " << company << endl;
    cout << "Finished University: " << (finishedUniversity ? "Yes" : "No") << endl << endl;
}

void Lawyer::Salary()
{
    cout << "Lawyer's salary: " << salary << endl;
}

void Lawyer::Input(const char* n, int a, double sal, const char* comp, bool finish)
{
    if (name != nullptr) delete[] name;
    if (company != nullptr) delete[] company;

    name = new char[strlen(n) + 1];
    strcpy_s(name, strlen(n) + 1, n);
    age = a;
    salary = sal;

    company = new char[strlen(comp) + 1];
    strcpy_s(company, strlen(comp) + 1, comp);
    finishedUniversity = finish;
}