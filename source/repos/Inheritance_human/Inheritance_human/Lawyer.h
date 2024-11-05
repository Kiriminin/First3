#pragma once
#include "Human.h"

class Lawyer : public Human
{
protected:
    char* company;
    bool finishedUniversity;

public:
    Lawyer();
    Lawyer(const char* n, int a, double sal, const char* comp, bool finish);
    ~Lawyer();

    void Output();
    void Salary();

    void Input(const char* n, int a, double sal, const char* comp, bool finish);
}; 
