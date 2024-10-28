#include "Human.h"
#include<iostream>
using namespace std;

Human::Human()
{
    cout << "Construct Human\n";
    name = nullptr;
    age = 0;
    salary = 0.0;
}

Human::Human(const char* Name, int Age, double Salary)
{
    cout << "Construct Human\n";
    name = new char[strlen(Name) + 1];
    strcpy_s(name, strlen(Name) + 1, Name);
    age = Age;
    salary = Salary;
}

void Human::Input()
{
    if (name != nullptr)
    {
        delete[] name;
    }

    char buff[20];
    cout << "Enter name -> ";
    cin >> buff;
    name = new char[strlen(buff) + 1];
    strcpy_s(name, strlen(buff) + 1, buff);

    cout << "Enter age -> ";
    cin >> age;

    cout << "Enter salary -> ";
    cin >> salary;
}

Human::~Human()
{
    delete[] name;
    cout << "Destruct Human\n";
}