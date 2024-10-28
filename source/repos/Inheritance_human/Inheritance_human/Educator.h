#pragma once
#include "Human.h"

class Educator : public Human
{
protected:
    char* Univer;
    char* Subject;

public:
    Educator();
    Educator(const char* n, int a, double _salary, const char* _univer, const char* _subject);
    ~Educator();

    void Output();
    void Salary();

    void Input(const char* n, int a, double _salary, const char* _univer, const char* _subject);
};