#pragma once
#include "Human.h"

class Director : public Human
{
protected:
    char* Firm;
public:
    Director();
    Director(const char* n, int a, double sal, const char* companyN);
    ~Director();

    void Output();
    void Salary();

    void Input(const char* n, int a, double sal, const char* companyN);
};