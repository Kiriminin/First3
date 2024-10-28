#pragma once
#include "Human.h"

class Programmer : public Human
{
protected:
    char* companyName;

public:
    Programmer();
    Programmer(const char* n, int a, double sal, const char* companyN);
    ~Programmer();

    void Output();
    void Salary();

    void Input(const char* n, int a, double sal, const char* companyN);
};