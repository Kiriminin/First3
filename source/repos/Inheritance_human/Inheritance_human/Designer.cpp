#include "Designer.h"
#include <iostream>
#include <cstring>
using namespace std;

Designer::Designer() : Human()
{
    cout << "Construct Designer\n";
    companyName = nullptr;
    programm = nullptr;
    skills = nullptr;
}

Designer::Designer(const char* n, int a, double sal, const char* companyN, const char* prog, const char* skillset)
    : Human(n, a, sal)
{
    cout << "Construct Designer\n";

    companyName = new char[strlen(companyN) + 1];
    strcpy_s(companyName, strlen(companyN) + 1, companyN);

    programm = new char[strlen(prog) + 1];
    strcpy_s(programm, strlen(prog) + 1, prog);

    skills = new char[strlen(skillset) + 1];
    strcpy_s(skills, strlen(skillset) + 1, skillset);
}

Designer::~Designer()
{
    delete[] companyName;
    delete[] programm;
    delete[] skills;
    cout << "Destruct Designer\n";
}

void Designer::Output()
{
    cout << "Output Designer\n";
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Salary: " << salary << endl;
    cout << "Company Name: " << companyName << endl;
    cout << "Program Used: " << programm << endl;
    cout << "Skills: " << skills << endl;
}

void Designer::Salary()
{
    cout << "Designer's salary: " << salary << endl;
}

void Designer::Input(const char* n, int a, double sal, const char* companyN, const char* prog, const char* skillset)
{
    if (name != nullptr) delete[] name;
    if (companyName != nullptr) delete[] companyName;
    if (programm != nullptr) delete[] programm;
    if (skills != nullptr) delete[] skills;

    name = new char[strlen(n) + 1];
    strcpy_s(name, strlen(n) + 1, n);
    age = a;
    salary = sal;

    companyName = new char[strlen(companyN) + 1];
    strcpy_s(companyName, strlen(companyN) + 1, companyN);

    programm = new char[strlen(prog) + 1];
    strcpy_s(programm, strlen(prog) + 1, prog);

    skills = new char[strlen(skillset) + 1];
    strcpy_s(skills, strlen(skillset) + 1, skillset);
}