#pragma once
#include "Human.h"

class Designer : public Human
{
protected:
    char* companyName;
    char* programm;
    char* skills;

public:
    Designer();
    Designer(const char* n, int a, double sal, const char* companyN, const char* prog, const char* skillset);
    ~Designer();

    void Output();
    void Salary();

    void Input(const char* n, int a, double sal, const char* companyN, const char* prog, const char* skillset);
};
