#include "Student.h"
#include <iostream>
#include <cstring>
using namespace std;

Student::Student() : Human()
{
    cout << "Construct Student\n";
    Univer = nullptr;
}

Student::Student(const char* n, int a, double sal, const char* U)
    : Human(n, a, sal)
{
    cout << "Construct Student\n";
    Univer = new char[strlen(U) + 1];
    strcpy_s(Univer, strlen(U) + 1, U);
}

Student::~Student()
{
    delete[] Univer;
    cout << "Destruct Student\n";
}

void Student::Output()
{
    cout << "Output Student\n";
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Salary: " << salary << endl;
    cout << "University: " << Univer << endl << endl;
}

void Student::Salary()
{
    cout << "Student's scholarship: " << salary << endl;
}

void Student::Input(const char* n, int a, double sal, const char* U)
{
    if (name != nullptr) delete[] name;
    if (Univer != nullptr) delete[] Univer;

    name = new char[strlen(n) + 1];
    strcpy_s(name, strlen(n) + 1, n);
    age = a;
    salary = sal;

    Univer = new char[strlen(U) + 1];
    strcpy_s(Univer, strlen(U) + 1, U);
}