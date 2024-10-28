#include "Educator.h"
#include <iostream>
#include <cstring>

using namespace std;

Educator::Educator() : Human()
{
    cout << "Construct Educator\n";
    Univer = nullptr;
    Subject = nullptr;
}

Educator::Educator(const char* n, int a, double _salary, const char* _univer, const char* _subject)
    : Human(n, a, _salary)
{
    cout << "Construct Educator\n";

    Univer = new char[strlen(_univer) + 1];
    strcpy_s(Univer, strlen(_univer) + 1, _univer);

    Subject = new char[strlen(_subject) + 1];
    strcpy_s(Subject, strlen(_subject) + 1, _subject);
}

Educator::~Educator()
{
    delete[] Univer;
    delete[] Subject;
    cout << "Destruct Educator\n";
}

void Educator::Output()
{
    cout << "Output Educator\n";
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Salary: " << salary << endl;
    cout << "University: " << Univer << endl;
    cout << "Subject: " << Subject << endl << endl;
}

void Educator::Salary()
{
    cout << "Educator's salary: " << salary << endl;
}

void Educator::Input(const char* n, int a, double _salary, const char* _univer, const char* _subject)
{
    if (name != nullptr) delete[] name;
    if (Univer != nullptr) delete[] Univer;
    if (Subject != nullptr) delete[] Subject;

    name = new char[strlen(n) + 1];
    strcpy_s(name, strlen(n) + 1, n);
    age = a;
    salary = _salary;

    Univer = new char[strlen(_univer) + 1];
    strcpy_s(Univer, strlen(_univer) + 1, _univer);

    Subject = new char[strlen(_subject) + 1];
    strcpy_s(Subject, strlen(_subject) + 1, _subject);
}